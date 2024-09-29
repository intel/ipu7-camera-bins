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

/*!
 * \mainpage CCA Flow API documentation
 *
 * Browse Files and Classes tabs for details.
 *
 * \section general General info
 *
 * CCA Flow APIs have been designed to be re-entrant. Each algorithm function can be called multiple times per frame.
 * Input parameters for the algorithms define what is the output ie. running an algorithm with same input parameters
 * and same statistics produce the same output.
 *
 * CCA Flow (Camera Control Algorithms Flow) library contains several algorithm which are used to modify RAW image.
 * Currently following features and algorithms are supported:
 * - \ref aec (Automatic Exposure Control)
 * - \ref aiq (Algorithms and Image Quality Algorithm Group) including sub-algorithm
 *  - awb (Automatic White Balance)
 *  - af (Automatic Focus)
 *  - sa (Shading Adaptor)
 *  - pa (Parameter Adaptor)
 *  - gbce (Global Brightness and Contrast Enhancement)
 *
 * Running AIQ algorithms and other standalone algorithms (LTM/DVS) requires following steps:
 * - \ref init
 * - \ref stats
 * - \ref running
 * - \ref deinit
 *
 * Some AIQ algorithms require coordinates as inputs to specify a certain area in the image. Coordinates are relative to
 * the statistics thus not necessarily the whole sensor area. Coordinates are not absolute but relative. See \link ia_coordinate.h \endlink
 * for detailed description of the used coordinate system.
 * <br><hr><br>
 *
 * \section init Initialization of CCA Flow library
 *
 * \copybrief cca::IntelCCA::init
 * To create an instance of CCA Flow library one must call function:
 * \code cca::IntelCCA::init \endcode
 * \copydetails cca::IntelCCA::init
 *
 * <br><hr><br>
 *
 * \section stats Setting of frame statistics
 *
 * Algorithms depend on statistics collected from the RAW image. Some or all of the statistics are
 * calculated by the ISP after RAW image capture from camera sensor. These statistics are always collected from
 * captured image data.
 *
 * \copybrief setStatsParams
 * To set statistics for algorithms CCA Flow library, one must call function:
 * \code cca::IntelCCA::setStatsParams \endcode
 * \copydetails cca::IntelCCA::setStatsParams
 *
 * Algorithms can also utilize external sensor data for making better decisions. For example external light sensor
 * can be used by AEC to determine correct cold start exposure parameters when AEC is called the first time without
 * statistics.
 *
 * <br><hr><br>
 *
 * \section running Running AIQ/AEC/LTM/DVS/AIC algorithms
 *
 * Once the CCA Flow instance is initialized and statistics are set, algorithms can be run in any order. But AIC must be last one, because the algo shall
 * collect other algo results to generate the PAL for IPU HW.
 *
 * \subsection aiq AIQ
 * \copybrief cca::IntelCCA::runAIQ
 * \code cca::IntelCCA::runAIQ \endcode
 * \copydetails cca::IntelCCA::runAIQ
 *
 * \subsection aec AEC
 * \copybrief cca::IntelCCA::runAEC
 * \code cca::IntelCCA::runAEC \endcode
 * \copydetails cca::IntelCCA::runAEC
 *
 * \subsection ltm LTM
 * \copybrief cca::IntelCCA::runLTM
 * \code cca::IntelCCA::runLTM \endcode
 * \copydetails cca::IntelCCA::runLTM
 *
 * \subsection dvs DVS
 * \copybrief cca::IntelCCA::runDVS
 * \code cca::IntelCCA::runDVS \endcode
 * \copydetails cca::IntelCCA::runDVS
 *
 * \subsection aic AIC
 * \copybrief cca::IntelCCA::runAIC
 * \code cca::IntelCCA::runAIC \endcode
 * \copydetails cca::IntelCCA::runAIC
 *
 *
 * <br><hr><br>
 *
 * \section deinit De-initialization of CCA Flow library
 *
 * To de-initialize and free memory CCA Flow library instance has allocated, one must call function:
 * \code
 * cca::IntelCCA::deinit
 * \endcode
 *
 * After this call CCA Flow library instance is destroyed and can't be used.
 */

#ifndef INTEL_CCA_BASE_H_
#define INTEL_CCA_BASE_H_

#include "IntelCCATypes.h"
#include "IIPUAic.h"
#include "CCAStorage.h"

namespace cca {

class IntelDVS;

/*!
 * \brief main entrance of CCA Flow lib.
 */
class LIBEXPORT IntelCCABase {
public:
    IntelCCABase();
    virtual ~IntelCCABase();
    /*!
     * \brief initialize the CCA Flow and sub-algos.
     * This function must be called before any other function in the library. It allocates memories for all CCA Flow algorithms based on input parameters
     * given by the user. AIQB (from CPFF) and NVM data are parsed and combined resulting camera module specific tuning parameters which the
     * AIQ algorithms use. Initialization returns a handle to the CCA Flow instance, which is given as input parameter for all the
     * algorithms. Therefore, multiple instances of CCA Flow library can running simultaneously. For example one instance per camera.
     *
     * \param[in] initParams            Mandatory.\n
     *                                  Input parameters containing tuning/nvm and configuration for sub-algos.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err init(const cca_init_params& initParams);

    /*!
     * \brief reconfigure dol.
     *
     * \param[in] dolMode               Mandatory.\n
     * \param[in] conversionGainRatio   Mandatory.\n
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err reconfigDol(ia_bcomp_dol_mode_t dolMode, float32_t conversionGainRatio);

    /*!
     * \brief Set input statistics and information (e.g faces) about the captured image.
     * CCA Flow algorithms need various information about the conditions in which the frame and statistics were captured in order to
     * calculate new parameters.
     *
     * \param[in] params                Mandatory.\n
     *                                  Input parameters containing statistics information about a frame.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err setStatsParams(const cca_stats_params& params);


    /*!
     * \brief Set Sensor frame parameters. Describe frame scaling/cropping done in sensor.
     *
     * \param[in] frameParams           Mandatory.\n
     *
     */
    void   setAiqFrameParams(const ia_aiq_frame_params &frameParams);

    /*!
     * \brief AEC calculation based on input parameters and frame statistics.
     * AE calculates new exposure parameters to be used for the next frame based on previously given statistics and user parameters.
     *
     * \param[in] frameId               Mandatory.\n
     *                                  frame sequence Id.
     * \param[in] params                Mandatory.\n
     *                                  Input parameters for AEC calculations.
     * \param[out] results              Mandatory.\n
     *                                  Results from AEC calculations. Results can be used directly as input for AIC/sensor driver.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err runAEC(uint64_t frameId, const cca_ae_input_params& params, cca_ae_results *results);
    /*!
     * \brief Run AIQ (Algorithms and Image Quality) Algorithm Group about the captured image.
     * AIQ algorithms need various information about the conditions in which the frame and statistics were captured in order to
     * calculate new parameters.
     *
     * \param[in] frameId               Mandatory.\n
     *                                  run AIQ algo group for frame with frameId.
     * \param[in] params                Mandatory.\n
     *                                  Input parameters containing statistics information about a frame.
     * \param [out] results             Mandatory.\n
     *                                  AIQ results. AF results can be used by ACM driver.
     * \return                          Error code.
     */
    ia_err runAIQ(uint64_t frameId, const cca_aiq_params& params, cca_aiq_results *results);

    /*!
     * \brief reconfigure DVS configuration info when GDC configuration are changed.
     *
     * \param[in] dvsInitParam          Mandatory.\n
     * \param[in] gdcConfig             Mandatory.\n
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err reconfigDvs(const cca_dvs_init_param& dvsInitParam, const cca_gdc_configurations& gdcConfigs);
    /*!
     * \brief update zoom factor/region/coordinate.
     * DVS algo supports to zoom the image. Set the zoom params before calling runDVS.
     *
     * \param[in] StreamId              Mandatory.\n
     * \param[in] params                Mandatory.\n
     *                                  zoom related params.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err updateZoom(uint32_t DvsId, const cca_dvs_zoom& params);
    /*!
     * \brief DVS Algorithm calculation based on dvs statistics.
     * DVS uses frameId to search the DVS statistic that decoded and stored in CCA Flow,
     * then calculates the morph table or image transformation for whole image that used by GDC.
     *
     * \param[in] streamsId             Mandatory.\n
     * \param[in] frameId               Mandatory.\n
     *                                  frame sequence Id.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err runDVS(uint32_t DvsId, uint64_t frameId, bool enable_video_stablization = false);
    /*!
     * \need reconfigDvs params with usecase(zoom/digitial zoom/video stablization) changing.
     * driver update all related paramter, then call the interface.
     *
     *
     * \param[in] DvsId                 Mandatory.\n
     * \param[in] dvs_config            Mandatory.\n
     * \param[in] zoom_factor           Mandatory.\n
     *                                  dvs config params.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err ConfigDvs(uint32_t DvsId, ia_dvs_configuration_v1* dvs_config, float32_t zoom_factor);

    ia_err getDvsImageTransformationOutput(uint32_t DvsId, uint64_t frameId, ia_dvs_image_transformation **ImageTrans);

    /*!
     * \brief query the CMC data (camera module characteristic).
     * get the sensor specific data that stored in tuning file, for example optics/tnr...
     *
     * \param[out] cmc                  Mandatory.\n
     *                                  CMC data.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err getCMC(cca_cmc &cmc, const cca_cpf *aiq_cpf = nullptr);

    ia_err getCCTWhiteMapNode(uint32_t cur_cct, float32_t *r_g_gain, float32_t *b_g_gain);

    /*!
     * \brief query the MKN data (maker notes).
     * get the maker note data of AIQ generated by algorithms, mainly cover the exif info needs
     * by JPG and other data for debug purpose.
     *
     * \param[in] type                  Mandatory.\n
     *                                  mkn type.
     * \param[out] mkn                  Mandatory.\n
     *                                  mkn data.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err getMKN(ia_mkn_trg type, cca_mkn &mkn);

    /*!
     * \brief add MKN data
     *
     * \param[in] a_data_format_id      Mandatory.\n
     *                                  mkn format id
     * \param[in] a_data_name_id        Mandatory.\n
     *                                  mkn data name id
     * \param[in] a_data_ptr            Mandatory.\n
     *                                  pointer to data
     * \param[in] a_num_elements        Mandatory.\n
     *                                  element number
     * \param[in] a_key                 Mandatory.\n
     */
    ia_err addMKN(ia_mkn_dfid a_data_format_id, ia_mkn_dnid a_data_name_id, const void *a_data_ptr, uint32_t a_num_elements, const char *a_key);

    /*!
     * \brief get the AIQD (AIQ data).
     *  Contains various AIQ related information, collected during run-time and subject to
     *  be stored in a host file system. Host will copy this data, if ia_aiq_data->size > 0
     *  and ia_aiq_data->data != NULL; AIQ is responsible to deallocate data buffer
     *  during ia_aiq_deinit().
     *
     * \param[out] aiqd                 Mandatory.\n
     *                                  AIQD buffer.
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err getAiqd(cca_aiqd &aiqd);
    /*!
     * \brief Update tuning data in run time.
     *  Update the tuning data to CCA flow, the new tuning data will be taken effect immediately.
     *  For different use cases, the tuning data should be different, the function is used for the scenario.
     *
     * \param[in] tag                   Mandatory.\n
     *                                  the tag for updated group in tuning file.
     * \param[in] lardParams            Mandatory.\n
     *                                  lard data.
     * \param[in] nvm                   Mandatory.\n
     *                                  sensor nvm data.
     * \param[in] aicId                 Optional.\n
     *                                  the aic id for aic handle
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err updateTuning(uint8_t tag, ia_lard_input_params &lardParams, const cca_nvm &nvm, int32_t aicId = -1);

    /*!
     * \brief Update tuning data in run time.
     *  Update the tuning data to CCA flow, the new tuning data will be taken effect immediately.
     *  For different use cases, the tuning data should be different, the function is used for the scenario.
     *
     * \param[in] tag                   Mandatory.\n
     *                                  the tag for updated group in tuning file.
     * \param[in] lardParams            Mandatory.\n
     *                                  lard data.
     * \param[in] nvm                   Mandatory.\n
     *                                  sensor nvm data.
     * \param[in] aicId                 Optional.\n
     *                                  the aic id for aic handle
     * \param[out] pLardResults         Mandatory.\n
     *                                  lard results
     * \return                          Error code for status. zero on success, non-zero on failure
    */
    ia_err updateTuning(uint8_t tag, ia_lard_input_params &lardParams, const cca_nvm &nvm, ia_lard_results **pLardResults, int32_t aicId = -1);

    /*!
     * \brief parse embedded data in run time.
     *
     * \param[in] bin                       Mandatory.\n
     *                                      embedded data
     * \param[in] mode                      Mandatory.\n
     *
     * \param[in] SnrDesc                   Mandatory.\n
     *                                      Sensor specific descriptor and limits of the used sensor mode for target frame use.
     * \param[out] result                   Mandatory.\n
     *                                      embedded results
     * \return                              Error code for status. zero on success, non-zero on failure
     */
    ia_err runEmdDecoder(const ia_binary_data &bin, const ia_emd_mode_t &mode, const ia_aiq_exposure_sensor_descriptor &snrDesc, ia_emd_result_t **result);

    /*!
     * \brief De-initialize CCA Flow and its submodules.
     * All memory allocated by algoriths are freed. CCA Flow handle can no longer be used.
     *
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err deinit();

    /*!
     * \brief query the current CCA Flow version.
     *
     * \return                          version.
     */
    const char* getVersion() const;

    /*!
     * \brief Get lard data.
     *  Get lard results parsed from aiqb.
     *
     * \param[out] lard                 Mandatory.\n
     *                                  lard data
     * \return                          Error code for status. zero on success, non-zero on failure
     */
    ia_err getLardData(cca_lard_data *lard);

    /*!
    * \brief Get Aiq results.
    *  Get Aiq results parsed from CCAStorage.
    *
    * \param[in] frameId               Mandatory.\n
    *                                  Get Aiq result for frame with frameId.
    * \param[out] results              Mandatory.\n
    *                                  Aiq results
    * \return                          Error code for status. zero on success, non-zero on failure
    */
    ia_err queryAiqResults(uint64_t frameId, cca_aiq_results_storage* results);

    /*!
    * \brief Save Aiq results.
    *  Save Aiq results to internal CCAStorage.
    *
    * \param[out] results              Mandatory.\n
    *                                  Aiq results
    * \return                          Error code for status. zero on success, non-zero on failure
    */
    ia_err saveAiqResults(uint64_t frameId, const cca_aiq_results_storage &results);

    /*!
    * \brief Get Aiq results.
    *  assign external Aiq results to internal CCAStorage.
    *
    * \param[out] results              Mandatory.\n
    *                                  Aiq results
    * \return                          Error code for status. zero on success, non-zero on failure
    */
    ia_err assignAiqResults(uint64_t frameId, const cca_aiq_results_storage &results);

    /*!
    * \brief Reload new cpf data and updates ISP tuning for a specific aic id. Used for IQ simulator mid pipe injection.
    *  Assuming that only ISP tuning has changed from previous cpf. Keeps the same tuning mode that was used before the change.
    *  Does not reset any other Intel CCA state such as AIQ results or AIC configuration.
    *
    * \param[in] aiqCpf               Mandatory.\n
    *                                  New cpf binary data.
    * \param[in] aicId                Optional.\n
    *                                  Aic id to update the tuning for. If not provided, assuming that there is only one aic instance.
    * \return                          Error code for status. zero on success, non-zero on failure
    */
    ia_err reloadIspTuning(const cca_cpf& aiqCpf, int32_t aicId = -1);

    /*!
    *  \brief set cca log level
    *
    *  \param[in] log_level              Mandatory.\n
    *                                    0: disable log
    *                                    1: enable IA_CCA_LOG_ERROR
    *                                    2: enable IA_CCA_LOG
    *                                    3: enable IA_CCA_LOG & IA_CCA_LOG_ERROR
    */
    static void setCCALogLevel(int32_t log_level);

protected:
    ia_binary_data* getAiqData();
    ia_binary_data* getIspData();
    ia_binary_data* getOthersData();
    ia_err initCpfParse();
    void initSaResults();
    ia_err initIspAic(const cca_stream_ids& aic_stream_ids);
    void deInitIspAic();
    ia_err initAiq();
    void deinitAiq();
    void deleteSaResultsGrids();
    void copySaResults(const ia_aiq_sa_results_v1* saResult);
    void initAicb(const cca_cpf& aiqCpf);
    void deInitAicb();

protected:
    virtual ia_err setStatsToAiq(const cca_stats_params &params, const cca_aiq_results_storage &aiqResults) = 0;
    virtual ia_err setLtmTuning(const ia_binary_data *tuning_data_ptr) = 0;
    virtual void updateLtmResult(cca_3a_plus_results* results) = 0;

    ia_err initDVS(const cca_init_params& initParams);
    void deInitDvs();

    ia_err initBcomp(ia_bcomp_dol_mode_t mode, float32_t ratio);
    ia_err updateBcomp();
    void deinitBcomp();
    void runAIC_(uint64_t frameId, const cca_pal_input_params& params, cca_3a_plus_results* results);

    virtual void newAic() = 0;
    virtual void deleteAic() = 0;
    virtual ia_err initAic(const ia_binary_data *aiqb, const ia_cmc_t *cmc, uint32_t max_stats_width,
                           uint32_t max_stats_height, uint32_t max_num_stats_in, const ia_mkn *mkn,
                           const cca_stream_ids& aic_stream_ids) = 0;
    virtual ia_err updateAicTuning(const ia_binary_data *aiqb, const ia_cmc_t *cmc, int32_t streamId = -1) = 0;
    virtual ia_err getDvsStatsAic(ia_dvs_statistics* stats) = 0;

protected:
    CCAStorage *mCCAStorage;

    /*
     * aiqb and cmc
     */
    ia_binary_data mAicb;
    ia_cmc_t* mParsedCMC;
    bool mAicbInited;

    /*
     * NVM
     */
    ia_binary_data mNvmb;

    /*
     * aiqd
     */
    ia_binary_data mAiqd;

    /*
     * AIQ structs and params
     */
    bool mCCAIsEnabled;
    ia_aiq* mAiqHandle;
    uint8_t mAECFrameDelay;
    uint64_t mFrameTimestamp;
    ia_aiq_pa_results_v1* mPaResults;
    ia_aiq_awb_results* mAwbResults;
    ia_aiq_ae_results* mAeResults;
    ia_aiq_af_results *mAfResults;
    ia_aiq_gbce_results* mGbceResults;
    ia_aiq_sa_results_v1 mSaResults;
    ia_aiq_sa_results_v1 mSaFakeResults;

    ia_aiq_frame_params mAiqFrameParams;

    ia_aiq_awb_input_params_v1 mAwbInput;
    ia_aiq_ae_input_params_v1 mAeInput;
    ia_aiq_af_input_params mAfInput;
    ia_aiq_sa_input_params_v1 mSaInput;
    ia_aiq_gbce_input_params mGbceInput;
    ia_aiq_pa_input_params mPaInput;

    uint64_t mFrameIndex;
    uint32_t mMaxNumberOfStats;
    ia_mkn* mMknData;
    uint32_t mInitBitmap;
    cca_stream_ids mAicStreamIds;
#ifndef ENABLE_CUSTOMIZED_STD_LIB
    std::map<int32_t, uint32_t> *mAicTuningModeMap;
#else
    FixedMap<int32_t, uint32_t, MAX_STREAM_NUM> *mAicTuningModeMap;
#endif

    uint32_t mNumExpo;

    /*
     * RGBS grids
     */
    ia_aiq_grid** mCurrentIRGrid;

    /*
    * Bcomp structs
    */
    ia_bcomp* mBcompState;
    ia_bcomp_results* mBcompResults;

    /*
    * ia_lard - a library for parsing the cpff and loading it in a dynamic way
    */
    ia_lard* mLard;
    cca_lard_data mLardData;
    ia_lard_input_params mLardInputParams;

    /*
    * lard_result - the results which are returned after lard_run
    */
    ia_lard_results* mLardResult;

    IntelDVS* mIntelDVSHandles;

    ia_emd_decoder_t *mEmdDecoder;

    uint32_t m3AResultBitmap;

    /*
    * mEnableUsingLardResultToInitCCA - whether using lard result to init cca
    */
    bool mEnableUsingLardResultToInitCCA;
    int8_t reserve[24];
};
}//cca
#endif //INTEL_CCA_BASE_H_
