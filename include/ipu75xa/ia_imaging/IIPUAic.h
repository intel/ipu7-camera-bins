/*
 * Copyright (C) 2020-2024 Intel Corporation.
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

#ifdef ENABLE_CUSTOMIZED_STD_LIB
#include "FixedMap.h"
#include "FixedList.h"
#include "FixedVector.h"
#else
#include <map>
#include <vector>
#endif

namespace cca {

/*!
 * \brief Structure to hold AIC handle information.
 */
typedef struct {
    uint32_t cb_num; /*!< Number of cb. */
    int32_t group_id[MAX_PG_NUM]; /*!< Group IDs. */
    aic::IaAic* handle_ptr; /*!< Pointer to the AIC handle. */
} cca_aic_handle;

/*!
 * \brief configure the kernels in cb for AIC
 */
typedef struct {
    int group_id; /*!< Group ID. */
    int fragment_count; /*!< Number of fragments. */
    aic::ImagingKernelGroup *kernel_group; /*!< Pointer to the kernel group. */
} cca_cb_config;

/*!
 * \brief Configuration for the kernels in the entire pipeline for AIC.
 */
typedef struct {
    uint32_t cb_num; /*!< Number of cb. */
#ifdef ENABLE_STL_LIB
    std::vector<cca_cb_config> cb_config; /*!< Vector of cb configurations. */
#else
    cca_cb_config cb_config[MAX_PG_NUM]; /*!< Array of cb configurations. */
#endif
} cca_aic_config;

/*!
 * \brief Structure for terminal buffer.
 */
typedef struct {
    uint32_t terminal_index; /*!< Terminal index. */
    size_t buf_size; /*!< Buffer size. */
    aic::IaAicBuffer *payload; /*!< Pointer to the payload buffer. */
    uint32_t fragment_index; /*!< Fragment index. */
} cca_terminal_buf;

/*!
 * \brief Structure for terminals in a cb.
 */
typedef struct {
    int group_id; /*!< Group ID for the cb. */
    uint32_t num_terminal; /*!< Number of terminals. */
#ifdef ENABLE_STL_LIB
    std::vector<cca_terminal_buf> terminal_buf; /*!< Vector of terminal buffers. */
#else
    cca_terminal_buf terminal_buf[MAX_PG_TERMINAL_NUM * MAX_NUMBER_OF_FRAGMENTS]; /*!< Array of terminal buffers. */
#endif
} cca_cb_termal_buf;

/*!
 * \brief Configuration for terminals in the entire pipeline for AIC.
 */
typedef struct {
    uint32_t cb_num; /*!< Number of cb. */
#ifdef ENABLE_STL_LIB
    std::vector<cca_cb_termal_buf> cb_terminal_buf; /*!< Vector of control block terminal buffers. */
#else
    cca_cb_termal_buf cb_terminal_buf[MAX_PG_NUM]; /*!< Array of control block terminal buffers. */
#endif
} cca_aic_terminal_config;

/*!
 * \brief Structure for kernel offset configuration for AIC.
 */
typedef struct {
    int uuid; /*!< UUID for the kernel. */
    aic::IaAicBufferTypes terminal_type; /*!< Terminal type. */
    uint32_t terminal_index; /*!< Terminal index. */
    uint32_t *offsets; /*!< Pointer to the offsets array. */
    uint32_t *sizes; /*!< Pointer to the sizes array. */
    uint32_t num_offsets; /*!< Number of offsets. */
    uint32_t fragment; /*!< Fragment index. */
} cca_kernel_offset;

/*!
 * \brief Structure for kernel offset configuration for a specific cb.
 */
typedef struct {
    int group_id; /*!< Group ID for the cb. */
    uint32_t num_kernels; /*!< Number of kernels. */
#ifdef ENABLE_STL_LIB
    std::vector<cca_kernel_offset> kernels_offset; /*!< Vector of kernel offsets. */
#else
    cca_kernel_offset kernels_offset[MAX_KERNEL_NUM_IN_PG]; /*!< Array of kernel offsets. */
#endif
} cca_cb_kernel_offset;

/*!
 * \brief Configuration for all kernel offsets in the entire pipeline for AIC.
 */
typedef struct {
    uint32_t cb_num; /*!< Number of cb. */
#ifdef ENABLE_STL_LIB
    std::vector<cca_cb_kernel_offset> cb_kernel_offset; /*!< Vector of control block kernel offsets. */
#else
    cca_cb_kernel_offset cb_kernel_offset[MAX_PG_NUM]; /*!< Array of control block kernel offsets. */
#endif
} cca_aic_kernel_offset;

/*!
 * \brief Structure for PAL binary dump.
 */
typedef struct {
    int group_id; /*!< Group ID for the cb. */
    aic::IaBinaryData bin;
}cca_pal_output;

/*!
 * \brief Structure for multiple PAL outputs.
 */
typedef struct {
    uint32_t cb_num; /*!< Number of cb. */
    cca_pal_output cb_output[MAX_PG_NUM]; /*!< Array of cb outputs. */
} cca_multi_pal_output;

/*!
 * \brief Structure for frame statistics.
 */
struct cca_frame_stats {
    ia_ccat_frame_statistics stats; /*!< Frame statistics filled by calling decodeStats. */
    uint32_t illuminated; /*!< Optional. Filled by driver/HAL. */
    uint32_t flashStage; /*!< Optional. Filled by driver/HAL. */
    float analogGain; /*!< Optional. Filled by driver/HAL. */
    float digitalGain; /*!< Optional. Filled by driver/HAL. */
};

/*!
 * \brief Structure for statistics.
 */
struct cca_stats {
    cca_frame_stats frameStats; /*!< Frame statistics. */
    bool isFilled; /*!< Flag indicating if the statistics are filled. */
    bool isUsing; /*!< Flag indicating if the statistics are being used. */
};

/*!
 * \brief Structure for Intel 3A plus results for AIC run.
 */
typedef struct {
    ia_aiq_frame_params* frame_info; /*!< Frame information. */
    unsigned long long frame_timestamp; /*!< Frame timestamp. */
    ia_aiq_pa_results_v1* pa_results; /*!< PA results. */
    ia_aiq_awb_results* awb_results; /*!< AWB results. */
    ia_aiq_ae_results* aec_results; /*!< AE results. */
    ia_aiq_af_results* af_results; /*!< AF results. */
    ia_aiq_gbce_results* gbce_results; /*!< GBCE results. */
    ia_aiq_sa_results_v1 *sa_results; /*!< SA results. */
    ia_ltm_drc_params* drc_params; /*!< DRC parameters. */
    ia_ltm_results* ltm_results; /*!< LTM results. */
    ia_dvs_morph_table* morph_table; /*!< DVS morph table. */
    ia_dvs_image_transformation* dvs_image_transform; /*!< DVS image transformation. */
    ia_bcomp_results* bcomp_results; /*!< BCOMP results. */
} cca_3a_plus_results;

/*!
 * \brief Enumeration for statistics buffer status.
 */
enum cca_stats_buf_status {
    STATS_BUF_FILLED, /*!< Buffer is filled. */
    STATS_BUF_EMPTY, /*!< Buffer is empty. */
    STATS_BUF_USING, /*!< Buffer is being used. */
    STATS_BUF_LATEST /*!< Buffer is the latest. */
};

/*!
 * \brief Pure interface exposed to IntelCCA for AIC operations.
 */
class IPU7Aic {
public:
    /*!
     * \brief Constructor for IPU7Aic.
     */
    IPU7Aic();

    /*!
     * \brief Destructor for IPU7Aic.
     */
    virtual ~IPU7Aic();

    /*!
     * \brief Initialize all the IPU handles with AIQB/CMC.
     *
     * \param[in] aiqb Tuning file.
     * \param[in] cmc CCA global initial parameters.
     * \param[in] max_stats_width Maximum statistics grid width.
     * \param[in] max_stats_height Maximum statistics grid height.
     * \param[in] max_num_stats_in Maximum number of statistics related to HDR/multi-sensor.
     * \param[in] mkn Maker note buffer.
     * \param[in] aic_stream_ids (Optional) Stream ID info for AIC handle.
     * \return Error code.
     */
    ia_err init(const ia_binary_data *aiqb, const ia_cmc_t *cmc, uint32_t max_stats_width,
                uint32_t max_stats_height, uint32_t max_num_stats_in, const ia_mkn *mkn,
                const cca_stream_ids& aic_stream_ids);

    /*!
     * \brief Reinitialize AIC.
     *
     * \param[in] aiqb Tuning file.
     * \param[in] cmc CCA global initial parameters.
     * \param[in] max_stats_width Maximum statistics grid width.
     * \param[in] max_stats_height Maximum statistics grid height.
     * \param[in] max_num_stats_in Maximum number of statistics related to HDR/multi-sensor.
     * \param[in] mkn Maker note buffer.
     * \param[in] aic_id (Optional) The ID for AIC handle. Default is -1.
     * \return Error code for status. Zero on success, non-zero on failure.
     */
    ia_err reInit(const ia_binary_data *aiqb, const ia_cmc_t *cmc, uint32_t max_stats_width,
                  uint32_t max_stats_height, uint32_t max_num_stats_in, const ia_mkn *mkn,
                  const int32_t aic_id = -1);

    /*!
     * \brief Update tuning file AIQB.
     *
     * \param[in] aiqb Tuning file.
     * \param[in] cmc Parsed CMC data.
     * \param[in] streamId (Optional) The stream ID for AIC handle. Default is -1.
     * \return Error code.
     */
    ia_err updateTuning(const ia_binary_data *aiqb, const ia_cmc_t *cmc,
                        int32_t streamId = -1);

    /*!
     * \brief Get statistics parameters for a specific frame.
     *
     * \param[in] frame_id Frame ID for statistics.
     * \return Pointer to the statistics parameters.
     */
    cca_stats* getStatsParams(uint64_t frame_id);

    /*!
     * \brief Decode statistics for a specific type (AIQ, LTM, DVS stats).
     *
     * \param[in] groupId Group ID of CB.
     * \param[in] seqId Sequence ID for streaming.
     * \param[in] aicId (Optional) The ID for AIC handle. Default is -1.
     * \return Error code.
     */
    ia_err decodeStats(int32_t groupId, int64_t seqId, int32_t aicId = -1, bool skip = false);

    /*!
     * \brief Query statistics buffer.
     *
     * \param[in] status Statistics buffer status.
     * \param[in] frame_id Frame ID. Default is cca::INVALID_FRAME_ID.
     * \return Pointer to the statistics buffer.
     */

    cca_stats* queryStatsBuf(cca_stats_buf_status status, uint64_t frame_id = cca::INVALID_FRAME_ID);

    /*!
     * \brief Run AIC parameters with graph config and Intel 3A results.
     *
     * \param[in] params AIQ plus parameters and manual settings.
     * \param[in] aaaResults AIQ plus results.
     * \param[in] bitmap Bitmap to decide which CB will be run.
     * \param[in] aicId (Optional) The ID for AIC handle. Default is -1.
     * \param[out] output AIC results for each CB.
     * \return Error code.
     */
    ia_err run(const cca_pal_input_params& params, cca_3a_plus_results& aaaResults,
               cca_multi_pal_output& output, uint8_t bitmap, int32_t aicId = -1);

    /*!
     * \brief Run AIC parameters with graph config and Intel 3A results.
     *
     * \param[in] params AIQ plus parameters and manual settings.
     * \param[in] aaaResults AIQ plus results.
     * \param[in] aicId (Optional) The ID for AIC handle. Default is -1.
     * \return Error code.
     */
    ia_err runAic(const cca_pal_input_params &params, cca_3a_plus_results &aaaResults, int32_t aicId = -1);

    /*!
     * \brief Run AIC to get PAL binary for IPU7 HW.
     * Calculate the PAL parameters according to 3A+ results and manual settings.
     *
     * \param[in] groupId Statistics binary generated by CB (groupId).
     * \param[in] frameId Indicate PAL results for a specific frame.
     * \param[in] aicId (Optional) The ID for AIC handle. Default is -1.
     * \param[out] output_data Binary array of IPU parameters for each CB.
     * \param[in] fragment_index Fragment index. Default is 0U.
     * \return Error code for status. Zero on success, non-zero on failure.
     */
    ia_err runKernels(uint32_t groupId, uint64_t frameId, cca_binary_data *output_data, uint32_t fragment_index = 0U, int32_t aicId = -1);

    /*!
     * \brief Get PAL input data.
     *
     * \param[in] stream_id Stream ID.
     * \param[in] seq_id Sequence ID.
     * \param[out] aic_output_common AIC output common binary data.
     * \param[out] tuning_output Tuning output binary data.
     * \param[in] aicId (Optional) The ID for AIC handle. Default is -1.
     * \return Error code.
     */
    ia_err GetPalInputData(uint32_t stream_id, int32_t seq_id, ia_binary_data* aic_output_common, ia_binary_data* tuning_output, int32_t aicId = -1);

    /*!
     * \brief Configure control blocks including kernel groups and kernel offsets.
     *
     * \param[in] conf Graph config for all kernels.
     * \param[in] offset Buffer offsets for all kernels.
     * \param[out] termConfig The memory needed by terminals of control blocks.
     * \param[in] aicId (Optional) The ID for AIC handle. Default is -1.
     * \param[in] statsBufTypeToTermId (Optional) Mapping from statistics buffer type to terminal ID.
     * \return Error code.
     */
    ia_err config(const cca_aic_config &conf, const cca_aic_kernel_offset &offset,
                  cca_aic_terminal_config &termConfig, int32_t aicId = -1, const int32_t* statsBufTypeToTermId = nullptr);

    /*!
     * \brief Update configuration resolutions.
     *
     * \param[in] conf Configuration.
     * \param[in] isKeyResolutionChanged Flag indicating if key resolution has changed.
     * \param[in] aicId (Optional) The ID for AIC handle. Default is -1.
     * \return Error code.
     */
    ia_err UpdateConfigurationResolutions(const cca_aic_config& conf, bool isKeyResolutionChanged, int32_t aicId = -1);

    /*!
     * \brief Register terminal buffers.
     *
     * \param[in] termConfig The memory needed by terminals of control blocks.
     * \param[in] aicId (Optional) The ID for AIC handle. Default is -1.
     * \return Error code.
     */
    ia_err registerBuf(const cca_aic_terminal_config &termConfig, int32_t aicId = -1);

    /*!
     * \brief Get AIC buffers for FW input after running PAL.
     *
     * \param[out] termConfig Terminal memory of control blocks filled with IPU parameters.
     * \param[in] aicId (Optional) The ID for AIC handle. Default is -1.
     * \return Error code.
     */
    ia_err getBuf(cca_aic_terminal_config &termConfig, int32_t aicId);

    /*!
     * \brief Deinitialize all the AIC handles.
     */
    void deinit();

    /*!
     * \brief Get the IPU HW version.
     *
     * \return IPU HW version.
     */
    const char* getVersion() const;

    /*!
     * \brief Get the max bin index of non-zero element.
     *
     * \param[out] outMaxBin Output the max bin index.
     * \return Error code.
     */
    ia_err getBrightestIndex(uint32_t* outMaxBin);

    /*!
     * \brief Calculate the total pixel number in range [luminance_low, luminance_high].
     *
     * \param[in] luminance_low The low pixel value.
     * \param[in] luminance_high The high pixel value.
     * \param[out] outTotalPixels The total pixel number in range [luminance_low, luminance_high].
     * \return Error code.
     */
    ia_err getPixelCount(uint32_t luminance_low, uint32_t luminance_high, uint32_t *outTotalPixels);

    /*!
     * \brief Get DVS statistics.
     *
     * \param[out] stats Pointer to the DVS statistics.
     * \return Error code.
     */
    ia_err getDvsStats(ia_dvs_statistics* stats);

    /*!
     * \brief Get PAL size.
     *
     * \param[in] programGroup Program group.
     * \return PAL size.
     */
    static uint32_t getPalSize(const cca_program_group& programGroup);

private:
    /*!
     * \brief Initialize statistics list.
     *
     * \param[in] len Length of the statistics list.
     */
    void initStatsList(uint32_t len);

    /*!
     * \brief Deinitialize statistics list.
     */
    void deInitStatsList();

    /*!
     * \brief Release statistics buffer.
     *
     * \param[in] status Statistics buffer status.
     * \param[in] ccaStats Pointer to the statistics buffer.
     */
    void releaseStatsBuf(cca_stats_buf_status status, cca_stats *ccaStats);

    /*!
     * \brief Get AIC handle.
     *
     * \param[in] aicId (Optional) The ID for AIC handle. Default is -1.
     * \return Pointer to the AIC handle.
     */
    cca_aic_handle* getAicHandle(int32_t aicId = -1);

private:
    static const char* IPU_VER; /*!< IPU version. */
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

#ifdef ENABLE_DVS
    ia_dvs_statistics mDvsStatistics{};
#endif
};

}//cca
#endif //IIPUAIC_H_
