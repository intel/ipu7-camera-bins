/*
 * Copyright (C) 2019-2024 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IIPUAIC_H_
#define IIPUAIC_H_

#include "ia_aic_class.h"
#include "ia_ccat_types.h"
#include "CCAStorage.h"
#include "IntelCCATypes.h"
#include "ia_coordinate.h"
#include "ia_aic_types.h"

#ifndef ENABLE_CUSTOMIZED_STD_LIB
#include <map>
#else
#include "FixedMap.h"
#include "FixedList.h"
#endif

namespace cca {

typedef struct {
    uint32_t cb_num;
    int32_t group_id[MAX_PG_NUM];
    aic::IaAic* handle_ptr;
} cca_aic_handle;

/*!
 * \brief configure the kernels in cb for AIC
 */
typedef struct {
    int group_id;
    int fragment_count;
    aic::ImagingKernelGroup *kernel_group;
} cca_cb_config;

/*!
 * \brief configure the kernels in whole pipe for AIC
 */
typedef struct {
    uint32_t cb_num;
    cca_cb_config cb_config[MAX_PG_NUM];
} cca_aic_config;

/*!
 * \brief terminal buffer struct
 */
typedef struct {
    uint32_t terminal_index;
    size_t buf_size;
    aic::IaAicBuffer *payload;
    uint32_t fragment_index;
} cca_terminal_buf;

/*!
 * \brief terminals for one cb
 */
typedef struct {
    int group_id;
    uint32_t num_terminal;
    cca_terminal_buf terminal_buf[MAX_PG_TERMINAL_NUM];
} cca_cb_termal_buf;

typedef struct {
    uint32_t cb_num;
    cca_cb_termal_buf cb_terminal_buf[MAX_PG_NUM];
} cca_aic_terminal_config;

/*!
 * \brief kernel offset config for AIC
 */
typedef struct {
    int uuid;
    aic::IaAicBufferTypes terminal_type;
    uint32_t terminal_index;
    uint32_t *offsets;
    uint32_t *sizes;
    uint32_t num_offsets;
    uint32_t fragment;
} cca_kernel_offset;

/*!
 * \brief kernel offset config for special cb
 */
typedef struct {
    int group_id;
    uint32_t num_kernels;
    cca_kernel_offset kernels_offset[MAX_KERNEL_NUM_IN_PG];
} cca_cb_kernel_offset;

/*!
 * \brief configure the all kernel offsets in whole pipe for AIC
 */
typedef struct {
    uint32_t cb_num;
    cca_cb_kernel_offset cb_kernel_offset[MAX_PG_NUM];
} cca_aic_kernel_offset;

/*!
 * \brief struct of PAL bin dump
 */
typedef struct {
    int group_id;
    aic::IaBinaryData bin;
}cca_pal_output;

typedef struct {
    uint32_t cb_num;
    cca_pal_output cb_output[MAX_PG_NUM];
}cca_multi_pal_output;

struct cca_frame_stats {
    ia_ccat_frame_statistics stats; /*!< Mandatory. filled by calling decodeStats */
    uint32_t illuminated;           /*!< Optional.  filled by driver/Hal */
    uint32_t flashStage;            /*!< Optional.  filled by driver/Hal */
    float analogGain;               /*!< Optional.  filled by driver/Hal */
    float digitalGain;              /*!< Optional.  filled by driver/Hal */
};

struct cca_stats {
    cca_frame_stats frameStats;
    bool isFilled;
    bool isUsing;
};

/*!
 * \brief intel 3a plus results for AIC run
 */
typedef struct {
    ia_aiq_frame_params* frame_info;
    unsigned long long frame_timestamp;
    ia_aiq_pa_results_v1* pa_results;
    ia_aiq_awb_results* awb_results;
    ia_aiq_ae_results* aec_results;
    ia_aiq_af_results* af_results;
    ia_aiq_gbce_results* gbce_results;
    ia_aiq_sa_results_v1 *sa_results;
    ia_ltm_drc_params* drc_params;
    ia_ltm_results* ltm_results;
    ia_dvs_morph_table* morph_table;
    ia_dvs_image_transformation* dvs_image_transform;
    ia_bcomp_results* bcomp_results;
} cca_3a_plus_results;

enum cca_stats_buf_status {
    STATS_BUF_FILLED,
    STATS_BUF_EMPTY,
    STATS_BUF_USING,
    STATS_BUF_LATEST
};

/*!
 * \brief Pure interface exposed to IntelCCA for AIC operations.
 */
class IPU7Aic {
public:
    IPU7Aic();
    virtual ~IPU7Aic();

    /*!
     * \brief init all the IPU handles with aiqb/cmc.
     *
     * \param[in] aiqb                   Mandatory.\n
     *                                   tuning file.
     * \param[in] cmc                    Mandatory.\n
     *                                   CCA global initial parameters.
     * \param[in] max_stats_width        Mandatory.\n
     *                                   max statistics grid width.
     * \param[in] max_stats_height       Mandatory.\n
     *                                   max statistics grid height.
     * \param[in] max_num_stats_in       Mandatory.\n
     *                                   max number of stats related to hdr/multi-sensor.
     * \param[in] mkn                    Mandatory.\n
     *                                   maker note buffer.
     * \param[in] aic_stream_ids         Optional.\n
     *                                   stream id info for aic handle.
     * \return                           Error code.
     */
    ia_err init(const ia_binary_data *aiqb, const ia_cmc_t *cmc, uint32_t max_stats_width,
                uint32_t max_stats_height, uint32_t max_num_stats_in, const ia_mkn *mkn,
                const cca_stream_ids& aic_stream_ids);

    /*!
    *
    * \brief reinit aic
    *
    * \param [in]  aic_id       Mandatory.\n
    * \return                   Error code for status. zero on success, non-zero on failure
    */
    ia_err reInit(const ia_binary_data *aiqb, const ia_cmc_t *cmc, uint32_t max_stats_width,
                  uint32_t max_stats_height, uint32_t max_num_stats_in, const ia_mkn *mkn,
                  const int32_t aic_id = -1);

    /*!
     * \brief update tuning file aiqb.
     *
     * \param[in] aiqb                       Mandatory.\n
     *                                       Tuning file.
     * \param[in] cmc                        Mandatory.\n
     *                                       Parsed cmc data.
     * \param[in] streamId                   Optional.\n
     *                                       The stream id for aic handle.
     * \return                               Error code.
     */
    ia_err updateTuning(const ia_binary_data *aiqb, const ia_cmc_t *cmc,
                        int32_t streamId = -1);

    /*!
     * \brief pass parameters for statistic analysis.
     *
     * \param[in] params                     Mandatory.\n
     *                                       parameters for statistis.
     * \param[in] aiqResults                 Mandatory.\n
     *                                       last AIQ results for reference.
     * \return                               Error code.
     */
    ia_err setStatsParams(ia_aiq* aiqHandle, const cca_stats_params &params,
                          const cca_aiq_results_storage &aiqResults);

    /*!
     * \brief decode statistics for a specific type(AIQ, LTM, DVS stats).
     *
     * \param[in] groupId                Mandatory.\n
     *                                   group id of CB.
     * \param[in] seqId                  Mandatory.\n
     *                                   sequence id for streaming.
     * \param[in] aicId                  Optional.\n
     *                                   id for aic handle.
     * \return                           Error code.
     */
    ia_err decodeStats(int32_t groupId, int64_t seqId, int32_t aicId = -1);
    cca_stats* queryStatsBuf(cca_stats_buf_status status, uint64_t frame_id = cca::INVALID_FRAME_ID);

    /*!
     * \brief run AIC parameters with graph config & Intel3A results.
     *
     * \param[in] params                 Mandatory.\n
     *                                   AIQ plus parameters and manual settings.
     * \param[in] aaaResults             Mandatory.\n
     *                                   AIQ plus results.
     *  \param[in] bitmap                Mandatory.\n
     *                                   Bitmap to decide which CB will be run.
     * \param[in] aicId                  Optional.\n
     *                                   id for aic handle.
     * \param[out] pal                   Mandatory.\n
     *                                   AIC results for each CB.
     * \return                           Error code.
     */
    ia_err run(const cca_pal_input_params& params, cca_3a_plus_results& aaaResults,
               cca_multi_pal_output& output, uint8_t bitmap, int32_t aicId = -1);

    /*!
    * \brief run AIC parameters with graph config & Intel3A results.
    *
    * \param[in] params                 Mandatory.\n
    *                                   AIQ plus parameters and manual settings.
    * \param[in] aaaResults             Mandatory.\n
    *                                   AIQ plus results.
    * \param[in] aicId                  Optional.\n
    *
    * \return                           Error code.
    */
    ia_err runAic(const cca_pal_input_params &params, cca_3a_plus_results &aaaResults, int32_t aicId = -1);

    /*!
     *
     * \brief  run AIC to get PAL binary for IPU7 HW.
     *  Calculate the PAL parameters according to 3A+ results and manual settings
     *
     * \param [in]  groupId      statistics binary generated by CB (groupId)
     * \param [in]  frameId      indicate PAL results for specia frame
     * \param [in]   aicId       Optional. id for aic handle.
     * \param [out] output_data  binary array of IPU parameters for each CB
     *
     * \return                   Error code for status. zero on success, non-zero on failure
     */
    ia_err runKernels(uint32_t groupId, uint64_t frameId, cca_binary_data *output_data, uint32_t fragment_index = 0U, int32_t aicId = -1);

    /*!
     * \brief configure cb including kernels group and kernels offset.
     *
     * \param[in] conf                          Mandatory.\n
     *                                          graph config for all kernels.
     * \param[in] offset                        Mandatory.\n
     *                                          buffer offsets for all kernels.
     * \param[out] termConfig                   Mandatory.\n
     *                                          the memory needed by terminals of cb.
     * \param[in] aicId                         Optional.\n
     *                                          id for aic handle.
     * \param statsBufTypeToTermId              Optional.\n
     * \return                                  Error code.
     */
    ia_err config(const cca_aic_config &conf,  const cca_aic_kernel_offset &offset,
                  cca_aic_terminal_config &termConfig, int32_t aicId = -1, const int32_t* statsBufTypeToTermId = nullptr);
    ia_err UpdateConfigurationResolutions(const cca_aic_config& conf, bool isKeyResolutionChanged, int32_t aicId = -1);

    /*!
     * \brief register terminal buffers.
     *
     * \param[in] termConfig                    Mandatory.\n
     *                                          the memory needed by terminals of cb.
     * \param[in] aicId                         Optional.\n
     *                                          id for aic handle.
     * \return                                  Error code.
     */
    ia_err registerBuf(const cca_aic_terminal_config &termConfig, int32_t aicId = -1);

    /*!
     * \brief get AIC buffers for FW input after runing PAL.
     *
     * \param[out] termConfig                   Mandatory.\n
     *                                          terminal memory of cb filled with IPU params.
     * \param[in] aicId                         Optional.\n
     *                                          id for aic handle.
     * \return                                  Error code.
     */
    ia_err getBuf(cca_aic_terminal_config &termConfig, int32_t aicId);

    /*!
    * \brief deinit all the AIC handles.
    */
    void deinit();

    /*!
     * \brief get the IPU HW version.
     *
     * \return                                  IPU HW version.
     */
    const char* getVersion() const;

    /*!
    * \brief get the max bin index of non-zero element.
    *
    * \param[out] stats                 Mandatory.\n
    *                                   output the max bin index.
    * \return                           Error code.
    */
    ia_err getBrightestIndex(uint32_t* outMaxBin);


    /*!
     * \brief calc the total pixel number in range [luminance_low, luminance_high]
     *
     * \param[in] luminance_low          Mandatory.\n
     *                                   the low pixel value
     *
     * \param[in] luminance_high         Mandatory.\n
     *                                   the high pixel value
     *
     * \param[out] outTotalPixels        Mandatory.\n
     *                                   the total pixel number in range [luminance_low, luminance_high]
     *
     * \return                           Error code.
     */
    ia_err getPixelCount(uint32_t luminance_low, uint32_t luminance_high, uint32_t *outTotalPixels);
    ia_err getDvsStats(ia_dvs_statistics* stats);
    static uint32_t getPalSize(const cca_program_group& programGroup);

private:
    void initStatsList(uint32_t len);
    void deInitStatsList();
    void releaseStatsBuf(cca_stats_buf_status status, cca_stats *ccaStats);
    ia_err deepCopyAecResults(const ia_aiq_ae_results &src, ia_aec_results *dst);
    ia_err deepFaceInfo(const cca_face_state &src, ia_face_roi (&dst)[IA_CCAT_FACES_MAX_NUM], bool &updated, bool &is_video_conf, FD_IMPL_TYPE& fd_algo) const;
    cca_aic_handle* getAicHandle(int32_t aicId = -1);

private:
    static const char* IPU_VER;
    //aiq statistics
#ifndef ENABLE_CUSTOMIZED_STD_LIB
    std::list<cca_stats*> mCCAStatsList;
    std::map<int32_t, cca_aic_handle> mAicHandleMap;
#else
    FixedList<cca_stats*, MAX_NUM_STATS> mCCAStatsList;
    FixedMap<int32_t, cca_aic_handle, MAX_STREAM_NUM> mAicHandleMap;
#endif
    //buffer feed to AIQ
    cca_stats *mStatsAiqBuf;
    mutex_t mStatsListMutex;
    ia_ccat_frame_parameters *mFrameParameters;

#ifdef ENABLE_DVS
    ia_dvs_statistics mDvsStatistics{};
#endif
};

}//cca
#endif //IIPUAIC_H_