/*
 * Copyright (C) 2019-2025 Intel Corporation.
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

#ifndef INTELCCA_TYPES_H_
#define INTELCCA_TYPES_H_

#include "ia_configuration.h"
#include "ia_aiq.h"
#include "ia_types.h"
#include "ia_ob.h"
#include "ia_lard.h"
#ifndef PAC_ENABLE
#ifdef ENABLE_LTM
#include "ia_ltm.h"
#endif
#endif
#ifdef ENABLE_DVS
#include "ia_dvs.h"
#endif
#include "ia_view.h"
#include "ia_cmc_types.h"
#include "ia_cmc_parser.h"
#include "ia_bcomp.h"
#include "ia_mkn_encoder.h"
#ifdef PAC_ENABLE
#include "ia_aic_types.h"
#else
#include "ia_isp_bxt.h"
#include "ia_isp_types.h"
#endif
#include "ia_abstraction.h"
#include "CCAMacro.h"
#include "ia_emd_decoder.h"

namespace cca {

/*!
 * \brief Structure for CCA CPF data.
 */
typedef struct {
    size_t size;                /*!< Size of AIQB data. */
    uint8_t buf[MAX_CPF_LEN];   /*!< Buffer of AIQB data. */
} cca_cpf;

/*!
 * \brief Structure for CCA NVM data.
 */
typedef struct {
    size_t size;               /*!< Size of sensor NVM data. */
    uint8_t buf[MAX_NVM_LEN];  /*!< Buffer of sensor NVM data. */
} cca_nvm;

/*!
 * \brief Structure for AIQ data.
 */
typedef struct {
    size_t size;               /*!< Size of AIQ data. */
    uint8_t buf[MAX_AIQD_LEN]; /*!< Buffer of AIQ data. */
} cca_aiqd;

/*!
 * \brief Structure for MKN data.
 */
typedef struct {
    size_t size;               /*!< Size of MKN data. */
    uint8_t buf[MAX_MKN_LEN];  /*!< Buffer of MKN data. */
} cca_mkn;

/*!
 * \brief Structure for statistics data.
 */
typedef struct {
    size_t size;                /*!< Size of statistics binary data. */
    uint8_t buf[MAX_STATS_LEN]; /*!< Buffer of statistics data. */
} cca_stats_bin;

/*!
 * \brief Structure for stream IDs.
 */
typedef struct {
    size_t count;               /*!< Number of stream IDs. */
    int32_t ids[MAX_STREAM_NUM]; /*!< Array of stream IDs. */
} cca_stream_ids;

/*!
 * \brief Enumeration for CCA module bitmap.
 */
enum CCAModuleBitMap {
    CCA_MODULE_AE = 1,
    CCA_MODULE_AF = 1 << 1,
    CCA_MODULE_AWB = 1 << 2,
    CCA_MODULE_PA = 1 << 3,
    CCA_MODULE_SA = 1 << 4,
    CCA_MODULE_GBCE = 1 << 5,
    CCA_MODULE_LTM = 1 << 6,
    CCA_MODULE_DVS = 1 << 7,
    CCA_MODULE_OB = 1 << 8,
    CCA_MODULE_BCOM = 1 << 9,
    CCA_MODULE_LARD = 1 << 10,
    CCA_MODULE_EMDED = 1 << 11,
    CCA_MODULE_DSD = 1 << 12,
    CCA_MODULE_ALL = (1 << 13) - 1,
};

/*!
 * \brief Enumeration for AIQB contents.
 */
enum CCALardItem {
    CCA_LARD_NONE = 0,
    CCA_LARD_CMC = 1 << 0,
    CCA_LARD_AIQ = 1 << 1,
    CCA_LARD_ISP = 1 << 2,
    CCA_LARD_OTHER = 1 << 3
};

/*!
 * \brief Structure for LARD data.
 */
typedef struct {
    uint32_t cmc_count;                /*!< Number of CMC tags. */
    uint32_t cmc_tags[MAX_TAG_LIST_LEN]; /*!< Array of CMC tags. */
    uint32_t aiq_count;                /*!< Number of AIQ tags. */
    uint32_t aiq_tags[MAX_TAG_LIST_LEN]; /*!< Array of AIQ tags. */
    uint32_t isp_count;                /*!< Number of ISP indices. */
    uint32_t isp_index[MAX_TAG_LIST_LEN]; /*!< Array of ISP indices. */
    uint32_t other_count;              /*!< Number of other tags. */
    uint32_t other_tags[MAX_TAG_LIST_LEN]; /*!< Array of other tags. */
} cca_lard_data;

/*!
 * \brief Enumeration for CCA statistics type.
 */
enum CCAStatsType {
    CCA_STATS_RGBS = 1,
    CCA_STATS_HIST = 1 << 1,
    CCA_STATS_AF = 1 << 2,
    CCA_STATS_YV = 1 << 3,
    CCA_STATS_LTM = 1 << 4,
    CCA_STATS_DVS = 1 << 5,
    CCA_STATS_PDAF = 1 << 6,
    CCA_STATS_RGBIR_IR = 1 << 7
};

/*!
 * \brief Enumeration for CCA histogram type.
 */
enum CCAHISTType {
    CCA_HIST_NONE = 0,
    CCA_HIST_Y = 1 << 0,
    CCA_HIST_RGB = 1 << 1,
};

/*!
 * \brief Enumeration for DVS output type.
 */
enum CCADVSOutputType {
    CCA_DVS_MORPH_TABLE = 0,
    CCA_DVS_IMAGE_TRANSFORM
};

/*!
 * \brief Structure for DVS initialization parameters.
 */
typedef struct {
    float32_t dvs_zoom_ration;        /*!< DVS zoom ratio. */
    CCADVSOutputType dvs_output_type; /*!< DVS output type. */
} cca_dvs_init_param;

/*!
 * \brief Structure for AEC features input parameters.
 */
typedef struct {
    bool aec_features_enabled; /*!< Flag indicating if AEC features are enabled. */
    ia_aiq_ae_features aec_features; /*!< AEC features. */
} cca_ae_features;

/*!
 * \brief Structure for AEC input parameters.
 */
typedef struct {
    bool is_bypass; /*!< Flag indicating if AEC run is bypassed. */
    ia_aiq_frame_use frame_use; /*!< Target frame type of the AEC calculations (Preview, Still, video etc.). */
    uint32_t num_exposures; /*!< Number of exposure outputs to have. Must be positive. One for LDR, two or more for HDR/exposure bracketing. */
    ia_aiq_flash_mode flash_mode; /*!< Manual flash mode. If AEC should make flash decision, set mode to ia_aiq_flash_mode_auto. */
    ia_aiq_ae_metering_mode metering_mode; /*!< AEC metering mode. */
    ia_aiq_ae_priority_mode priority_mode; /*!< AEC priority mode. */
    ia_aiq_ae_operation_mode operation_mode; /*!< AEC operation mode. */
    ia_aiq_ae_flicker_reduction flicker_reduction_mode; /*!< AEC flicker reduction mode. */
    ia_aiq_exposure_sensor_descriptor sensor_descriptor[MAX_SENSOR]; /*!< Sensor specific descriptor and limits of the used sensor mode for target frame use. */
    uint32_t num_sensor_descriptors; /*!< Number of sensor descriptors given in the above pointer. */
    cca_ae_features aec_features; /*!< AEC features in use when calculating new exposure parameters. */
    ia_rectangle exposure_window; /*!< Rectangle of area which AEC uses to calculate new exposure parameters. */
    ia_coordinate exposure_coordinate; /*!< Coordinate for a point in which the exposure should be prioritized. */
    float32_t ev_shift; /*!< Exposure Value shift [-4,4]. */
    uint32_t manual_exposure_time_us[MAX_NUM_EXPOSURE]; /*!< Manual exposure time in microseconds. */
    float32_t manual_analog_gain[MAX_NUM_EXPOSURE]; /*!< Manual analog gain. */
    uint16_t manual_iso[MAX_NUM_EXPOSURE]; /*!< Manual ISO. Overrides manual_analog_gain. */
    ia_aiq_ae_manual_limits manual_limits[MAX_NUM_EXPOSURE]; /*!< Manual limits which override limits defined in AEC tunings. */
    uint32_t manual_total_target_exposure[MAX_NUM_EXPOSURE]; /*!< Manual total target exposure. */
    ia_aiq_ae_exposure_distribution_priority exposure_distribution_priority; /*!< AEC exposure distribution priority mode. */
    float32_t manual_convergence_time; /*!< Manual AEC convergence speed in seconds. */
    bool is_bypass_result; /*!< Flag indicating if AE result needs to be saved to IntelCCA. */
} cca_ae_input_params;

/*!
 * \brief Structure for AEC exposure results.
 */
typedef struct {
    unsigned int exposure_index; /*!< Exposure index which identifies the exposure. */
    ia_aiq_exposure_parameters exposure[MAX_EXPO_PLAN]; /*!< Exposure parameters to be used in the next frame in sensor specific format. */
    ia_aiq_exposure_sensor_parameters sensor_exposure[MAX_EXPO_PLAN]; /*!< Exposure parameters to be used in the next frame in sensor specific format. */
    float32_t distance_from_convergence; /*!< Distance of convergence as an EV shift value. Negative is underexposure, positive is overexposure. */
    bool converged; /*!< Flag indicating if the exposure has converged. */
} cca_ae_exposure;

/*!
 * \brief Structure for AEC histogram weight map.
 */
typedef struct {
    uint16_t width; /*!< Width of the weight grid. */
    uint16_t height; /*!< Height of the weight grid. */
    uint8_t weights[MAX_RGBS_STATS_GRID_SIZE]; /*!< Multipliers (weight) of RGB values in the grid. Values range [0, 15]. */
} cca_hist_weight_grid;

/*!
 * \brief Structure for AEC results.
 */
typedef struct {
    cca_ae_exposure exposures[MAX_SENSOR]; /*!< Exposure results to be used in the next frame. */
    uint32_t num_exposures; /*!< Number of calculated exposures. */
    ia_aiq_flash_parameters flashes[MAX_NUM_FLASH_LEDS]; /*!< Array of flash parameters for each flash to be used in the next frame. */
    uint32_t num_flashes; /*!< Number of flashes. */
    ia_aiq_bracket_mode multiframe; /*!< AEC may propose to use multiframe for optimal results. */
    float lux_level_estimate; /*!< Lux level estimation. */
    ia_aiq_aperture_control aperture_control; /*!< Aperture control parameters. */
    cca_hist_weight_grid weight_grid; /*!< AEC weight map used by the next frame. */
    ia_aiq_ae_flicker_reduction flicker_reduction_mode; /*!< Flicker reduction mode proposed by the AEC algorithm. */
    unsigned short shdr_ldr_mode; /*!< Staggered HDR LDR (low dynamic range) mode. 0 - HDR mode, 1 - LDR mode. */
} cca_ae_results;

/*!
 * \brief Structure for AF input parameters.
 */
typedef struct {
    ia_aiq_frame_use frame_use; /*!< Target frame type of the AF calculations (Preview, Still, video etc.). */
    uint32_t lens_position; /*!< Current lens position. */
    uint64_t lens_movement_start_timestamp; /*!< Lens movement start timestamp in microseconds. */
    ia_aiq_af_operation_mode focus_mode; /*!< Focusing mode. */
    ia_aiq_af_range focus_range; /*!< Focusing range. Only valid when focus_mode is ia_aiq_af_operation_mode_auto. */
    ia_aiq_af_metering_mode focus_metering_mode; /*!< Metering mode (multispot, touch). */
    ia_aiq_flash_mode flash_mode; /*!< User setting for flash. */
    ia_rectangle focus_rect; /*!< Focus rectangle. */
    ia_aiq_manual_focus_parameters manual_focus_parameters; /*!< Manual focus parameters (manual lens position, manual focusing distance). */
    bool trigger_new_search; /*!< Flag indicating if a new AF search is needed. */
    bool exit_success_state; /*!< Flag indicating if AF needs to exit the success state. */
} cca_af_input_params;

/*!
 * \brief Structure for AF results.
 */
typedef struct {
    ia_aiq_af_status status; /*!< Focus status. */
    uint16_t current_focus_distance; /*!< Current focusing distance [mm] between the lens and object plane. */
    uint32_t next_lens_position; /*!< Next lens position. */
    int32_t next_focus_distance; /*!< Next focusing distance [mm] between the lens and object plane. */
    ia_aiq_lens_driver_action lens_driver_action; /*!< Lens driver action. */
    bool use_af_assist; /*!< Flag indicating if the AF assist light is to be used at half press. */
    bool final_lens_position_reached; /*!< Flag indicating if the lens has reached the final lens position. */
} cca_af_results;

/*!
 * \brief Structure for AWB input parameters.
 */
typedef struct {
    bool is_bypass; /*!< Flag indicating if AWB run is bypassed. */
    ia_aiq_awb_operation_mode scene_mode; /*!< AWB scene mode. */
    ia_aiq_awb_manual_cct_range manual_cct_range; /*!< Manual CCT range. */
    ia_coordinate manual_white_coordinate; /*!< Manual white point coordinate relative to the full FOV of the scene. */
    float32_t manual_convergence_time; /*!< Manual AWB convergence speed in seconds. */
    bool have_manual_settings; /*!< Flag indicating if manual settings are used. */
} cca_awb_input_params;

/*!
 * \brief Structure for AWB results.
 */
typedef struct {
    float32_t accurate_r_per_g; /*!< Accurate White Point for the image. */
    float32_t accurate_b_per_g; /*!< Accurate White Point for the image. */
    float32_t final_r_per_g; /*!< Final White Point, including color appearance modeling. */
    float32_t final_b_per_g; /*!< Final White Point, including color appearance modeling. */
    uint32_t cct_estimate; /*!< Correlated Color Temperature estimate calculated from the accurate WP. */
    float32_t distance_from_convergence; /*!< Distance from convergence. Value 0.0f means converged. */
    float acs_usage; /*!< Indicates the acs weight for White Point calculation, along with the weights
                          for greyworld, RGB, and other factors. (supported systems only) */
} cca_awb_results;

/*!
 * \brief Structure for GBCE input parameters.
 */
typedef struct {
    bool is_bypass; /*!< Flag indicating if GBCE run is bypassed. */
    float32_t ev_shift; /*!< Exposure Value shift [-4,4]. */
    bool gbce_on; /*!< Flag indicating if GBCE is enabled. */
    bool athena_mode; /*!< Flag indicating if Athena mode is enabled in full GTM algorithm. */
    gtm_glare_detection_type glare_detect_type; /*!< Glare detection type. */
    uint32_t lux_level_sensors[2]; /*!< Sensor lux level based glare detection. */
    float32_t manual_gamma; /*!< Manual gamma for GTM. */
} cca_gbce_input_params;

/*!
 * \brief Structure for RGBS grid block.
 */
typedef struct {
    rgbs_grid_block blocks_ptr[MAX_RGBS_STATS_GRID_SIZE]; /*!< RGBS blocks. */
    unsigned short grid_width; /*!< Grid width. */
    unsigned short grid_height; /*!< Grid height. */
    bool shading_correction; /*!< Flag indicating if statistics were calculated using lens shading corrected data. */
} cca_rgbs_grid;

/*!
 * \brief Structure for HDR RGBS grid block.
 */
typedef struct {
    hdr_rgbs_grid_block blocks_ptr[MAX_RGBS_STATS_GRID_SIZE]; /*!< HDR RGBS blocks. */
    uint32_t grid_width; /*!< Grid width. */
    uint32_t grid_height; /*!< Grid height. */
    uint32_t grid_data_bit_depth; /*!< Bit depth of data in channel data. */
    bool shading_correction; /*!< Flag indicating if statistics were calculated using lens shading corrected data. */
} cca_hdr_rgbs_grid;

/*!
 * \brief Structure for AF statistics.
 */
typedef struct {
    uint16_t grid_width; /*!< Number of block elements horizontally in a grid. */
    uint16_t grid_height; /*!< Number of block elements vertically in a grid. */
    uint16_t block_width; /*!< Block width (bq per block element). */
    uint16_t block_height; /*!< Block height (bq per grid element). */
    int32_t filter_response_1[MAX_AF_STATS_GRID_SIZE]; /*!< Filter response of filter 1 (e.g. low pass, used by auto focus). */
    int32_t filter_response_2[MAX_AF_STATS_GRID_SIZE]; /*!< Filter response of filter 2 (e.g. high pass, used by auto focus). */
} cca_af_grid;

/*!
 * \brief Structure for face state data.
 */
typedef struct {
    uint32_t num_faces; /*!< Number of faces in the recently processed input frame. */
    ia_atbx_face faces[MAX_FACE_NUM]; /*!< Array of face information. */
    bool updated; /*!< Flag indicating if the face data is updated. */
    bool is_video_conf; /*!< Flag indicating if video conference mode is enabled. */
    FD_IMPL_TYPE fd_algo; /*!< Face detection algorithm type. */
} cca_face_state;

/*!
 * \brief Structure for statistics parameters.
 */
typedef struct {
    uint64_t frame_id; /*!< Frame identifier which identifies to which frame the given statistics correspond. */
    uint64_t frame_timestamp; /*!< Start of frame timestamp in microseconds. */
    cca_face_state faces; /*!< Face coordinates from external face detector. */
    ia_aiq_camera_orientation camera_orientation; /*!< Orientation of the camera. */
    cca_hist_weight_grid weight_grid; /*!< Weight map to be used in the next frame histogram calculation. */
    uint16_t dvs_stats_height; /*!< Height of DVS statistics. */
    uint16_t dvs_stats_width; /*!< Width of DVS statistics. */
    ia_rectangle statistics_crop_area; /*!< RGBS and AF grid area crop with respect to full field of view of sensor output. */
    bool using_rgbs_for_aec; /*!< Flag indicating if RGBS is used to generate the AE histogram. */
    uint32_t reset_hist; /*!< Flag indicating if the histogram should be reset. */
    bool bAssitLightOn; /*!< Flag indicating if the AF assist light is on. */
    uint8_t AECFrameDelay; /*!< Frame delay for auto exposure to take effect. */
    bool hasEmbeddedData; /*!< Flag indicating if embedded data is available. */
} cca_stats_params;

/*!
 * \brief Structure for output statistics.
 */
typedef struct {
    bool get_rgbs_stats; /*!< Flag indicating if RGBS statistics should be retrieved. */
    ia_aiq_rgbs_grid rgbs_grid[MAX_NUM_EXPOSURE]; /*!< RGBS grid. */
    rgbs_grid_block rgbs_blocks[MAX_NUM_EXPOSURE][BXT_RGBS_GRID_MAX_NUM_ELEMENTS]; /*!< RGBS blocks. */
} cca_out_stats;

/*!
 * \brief Structure for PA input parameters.
 */
typedef struct {
    float32_t extra_gain;  /*!< Use to recalculate the pa output color_gains. */
    ia_aiq_color_channels color_gains; /*!< RGB gains for each color channel. */
    bool enable_gtm_desaturation; /*!< Flag indicating if GTM desaturation is enabled. */
} cca_pa_input_params;

/*!
 * \brief Structure for SA input parameters.
 */
typedef struct {
    float32_t manual_convergence_time; /*!< Manual convergence time in seconds. Allows override of tunings for LSC transition interval. */
    bool lsc_on; /*!< Flag indicating if LSC results should be returned. */
} cca_sa_input_params;

/*!
 * \brief Structure for DSD (Determine scene) input and output parameters.
 */
typedef struct {
    ia_aiq_scene_mode scene_modes;  /*!<which scene modes should be detected or returned by DSD*/
} cca_dsd_params;

/*!
 * \brief Structure for SA results.
 */
typedef struct {
    uint16_t lsc_grid[MAX_LSC_DIM_SIZE][MAX_LSC_DIM_SIZE][MAX_LSC_GRID_SIZE]; /*!< Arrays of the LSC grid for all color channels. */
    uint16_t width; /*!< Width of LSC grid. */
    uint16_t height; /*!< Height of LSC grid. */
    cmc_bayer_order color_order; /*!< Bayer order of LSC grid. */
    bool lsc_update; /*!< Flag indicating if the LSC LUT is updated. */
} cca_sa_results;

/*!
 * \brief Structure for GBCE parameters.
 */
typedef struct {
    bool have_manual_settings; /*!< Flag indicating if manual settings are used. */
    float32_t r_gamma_lut[MAX_GAMMA_LUT_SIZE]; /*!< Gamma LUT for R channel. Range [0.0, 1.0]. */
    float32_t b_gamma_lut[MAX_GAMMA_LUT_SIZE]; /*!< Gamma LUT for B channel. Range [0.0, 1.0]. */
    float32_t g_gamma_lut[MAX_GAMMA_LUT_SIZE]; /*!< Gamma LUT for G channel. Range [0.0, 1.0]. */
    uint32_t gamma_lut_size; /*!< Size of gamma LUT. */
    float32_t tone_map_lut[MAX_TONE_MAP_LUT_SIZE]; /*!< GTM LUT. */
    uint32_t tone_map_lut_size; /*!< Size of GTM LUT. */
} cca_gbce_params;

/*!
 * \brief Structure for PA parameters.
 */
typedef struct {
    bool enable_manual_settings; /*!< Flag indicating if manual settings are enabled. */
    float32_t color_conversion_matrix[3][3]; /*!< Color conversion matrix. */
    ia_aiq_color_channels color_gains; /*!< RGB gains for each color channel. */
} cca_pa_params;

/*!
 * \brief Structure for AIQ input parameters.
 */
typedef struct {
    uint32_t bitmap; /*!< Bitmap to enable/disable algorithms (CCAModuleBitMap). */
    cca_af_input_params af_input; /*!< AF input parameters. */
    cca_awb_input_params awb_input; /*!< AWB input parameters. */
    cca_gbce_input_params gbce_input; /*!< GBCE input parameters. */
    cca_pa_input_params pa_input; /*!< PA input parameters. */
    cca_sa_input_params sa_input; /*!< SA input parameters. */
    cca_dsd_params dsd_input; /*!< DSD input parameters. */
} cca_aiq_params;

/*!
 * \brief Structure for AIQ results.
 */
typedef struct {
    cca_af_results af_output; /*!< AF algorithm output. */
    cca_awb_results awb_output; /*!< AWB algorithm output. */
    cca_sa_results sa_output; /*!< SA algorithm output. */
    cca_gbce_params gbce_output; /*!< GBCE algorithm output. */
    cca_pa_params pa_output; /*!< PA algorithm output. */
    cca_dsd_params dsd_output; /*!< DSD algorithm output. */
} cca_aiq_results;

/*!
 * \brief Structure for LTM statistics.
 */
typedef struct {
    ia_image_full_info image_info; /*!< Image information (e.g., image resolution). */
    uint32_t size; /*!< Length of SIS. */
    uint8_t data[MAX_SIS_FRAME_SIZE]; /*!< SIS frame. */
} cca_ltm_statistics;

/*!
 * \brief Structure for LTM input parameters.
 */
typedef struct {
    ia_ltm_level ltm_level; /*!< LTM level. -1 to use tuning defaults. */
    float32_t ev_shift; /*!< Exposure Value shift [-4,4]. */
    uint8_t ltm_strength_manual; /*!< User-defined manual control for LTM strength. Range [0, 200], default is 100. */
    int16_t frame_width; /*!< Width of the frame where the results will be applied. */
    int16_t frame_height; /*!< Height of the frame where the results will be applied. */
    cca_ltm_statistics sis; /*!< Downscaling raw image as LTM statistics. */
} cca_ltm_input_params;

/*!
 * \brief Structure for DVS statistics.
 */
typedef struct {
    uint32_t vector_count; /*!< Number of motion vectors. */
    ia_dvs_motion_vector motion_vectors[MAX_DVS_VECTOR_COUNT]; /*!< Table of local motion vectors. Contains [vector_count] values. */
} cca_dvs_statistics;

/*!
 * \brief Structure for GDC configuration.
 */
typedef struct {
    ia_isp_bxt_resolution_info_t gdc_resolution_history; /*!< GDC resolution history. */
    ia_isp_bxt_resolution_info_t gdc_resolution_info; /*!< GDC resolution information. */
    int32_t pre_gdc_top_padding; /*!< Pre-GDC top padding. */
    int32_t pre_gdc_bottom_padding; /*!< Pre-GDC bottom padding. */
    int32_t gdc_filter_width; /*!< GDC filter width. */
    int32_t gdc_filter_height; /*!< GDC filter height. */
    uint8_t splitMetadata[GDC_SPLIT_METADATA_LEN]; /*!< Split metadata. */
} cca_gdc_configuration;

/*!
 * \brief Structure for multi-stream GDC configuration.
 */
typedef struct {
    size_t count; /*!< Number of GDC configurations. */
    uint32_t ids[MAX_STREAM_NUM]; /*!< Array of stream IDs. */
    cca_gdc_configuration configs[MAX_STREAM_NUM]; /*!< Array of GDC configurations. */
} cca_gdc_configurations;

/*!
 * \brief Structure for DVS zoom parameters.
 */
typedef struct {
    float32_t digital_zoom_ratio; /*!< Digital zoom ratio. */
    float32_t digital_zoom_factor; /*!< Digital zoom factor. */
    ia_dvs_zoom_mode zoom_mode; /*!< Digital zooming mode. */
    ia_rectangle zoom_region; /*!< Zooming region which defines the area to be scaled for the output. */
    ia_coordinate zoom_coordinate; /*!< Zooming coordinate which defines the point where digital zoom is applied. */
} cca_dvs_zoom;

/*!
 * \brief Structure for PAL tuning parameters.
 */
typedef struct {
    size_t size; /*!< Size of the PAL tuning data. */
    uint8_t data[MAX_PAL_TUNING_SIZE]; /*!< Buffer of PAL tuning data. */
} cca_pal_tuning;

/*!
 * \brief Structure for custom control parameters.
 */
typedef struct {
    int count; /*!< Number of custom control parameters. */
    float32_t parameters[MAX_CUSTOM_CONTROLS_PARAM_SIZE]; /*!< Array of custom control parameters. */
} cca_custom_control_params;

/*!
 * \brief Structure for IA view parameters.
 */
typedef struct {
    bool enabled; /*!< Flag indicating if the feature is enabled. */
    ia_view_config_t view_config; /*!< Configuration of IA view. */
} cca_view_params;

#ifdef PAC_ENABLE
/*!
 * \brief Structure for camera rectification parameters.
 */
typedef struct {
    bool enabled; /*!< Flag indicating if the API is enabled. */
    ia_rectify_parameters_t rectify_params; /*!< Rectification parameters. */
} cca_rectification;

/*!
 * \brief Structure for neural network tone mapping parameters.
 */
typedef struct {
    float32_t* nn_coeff_out; /*!< Coefficients obtained from neural network inference. */
    int32_t coefficient_width; /*!< Width of the coefficients structure. */
    int32_t coefficient_height; /*!< Height of the coefficients structure. */
    int32_t coefficient_depth; /*!< Depth of the coefficients structure. */
} cca_nntm_params;
#endif

/*!
 * \brief Structure for program group of pipeline configuration (graph config).
 */
typedef struct {
    ia_isp_bxt_program_group base; /*!< Base program group. */
    ia_isp_bxt_run_kernels_t run_kernels[MAX_KERNEL_NUMBERS_IN_PIPE]; /*!< Array of kernels in the program group. */
    ia_isp_bxt_pipe_t pipe[MAX_KERNEL_NUMBERS_IN_PIPE]; /*!< Graph of kernels in the program group. */
    ia_isp_bxt_resolution_info_t resolution_info[MAX_KERNEL_NUMBERS_IN_PIPE]; /*!< Resolution change to be done in this kernel. */
    ia_isp_bxt_resolution_info_t resolution_history[MAX_KERNEL_NUMBERS_IN_PIPE]; /*!< Resolution changes done before the current kernel with respect to sensor output. */
} cca_program_group;

/*!
 * \brief Structure for AIC parameters input, including 3A and manual settings.
 */
typedef struct {
    ia_aiq_advanced_ccm_t preferred_acm; /*!< Optional. Manual setting for ACM to replace the ACM in PA results. */
    uint32_t stream_id; /*!< Optional. Stream ID used to fetch all the tunings for all the kernels associated with the stream ID. */
    uint64_t timestamp; /*!< Mandatory. Current timestamp (in microseconds) when ia_isp_bxt_run function is called. */
    uint64_t seq_id; /*!< Optional. Sequence number for AIC run. */
    uint32_t dvs_id; /*!< Optional. Sequence number for DVS. */
    int32_t ptz_zoom_active; /*!< Optional. b2i_DS need the parameter for calclate kernel_width. */
    ia_isp_feature_setting nr_setting; /*!< Mandatory. Feature setting for noise reduction algorithms. */
    ia_isp_feature_setting ee_setting; /*!< Mandatory. Feature setting for edge enhancement algorithms. */
    int8_t manual_brightness; /*!< Optional. Manual brightness value range [-128,127]. */
    int8_t manual_contrast; /*!< Optional. Manual contrast value range [-128,127]. */
    int8_t manual_hue; /*!< Optional. Manual hue value range [-128,127]. */
    int8_t manual_saturation; /*!< Optional. Manual saturation value range [-128,127]. */
    ia_isp_effect effects; /*!< Optional. Manual setting for special effects. */
    float32_t manual_digital_gain; /*!< Optional. Additional digital gain applied to all color channels of the image before ISP statistics collection. */
    ia_media_format media_format; /*!< Mandatory. Selected digital television output format (e.g., BT709). */
    cca_program_group program_group; /*!< Program group parameters for running AIC. */
    cca_custom_control_params custom_controls; /*!< Optional. Custom control parameters for interpolating between different tunings. */
    cca_pal_tuning pal_override; /*!< Optional. Set of parameters for overriding tunings from CPF. */
    cca_view_params view_params; /*!< Optional. View parameters for running in GDC5 mode. */
#ifdef PAC_ENABLE
    ia_camera_parameters_t camera_params; /*!< Optional. Sensor/view intrinsic/extrinsic parameters. */
    cca_rectification rectification; /*!< Optional. Rectification with intrinsic/LDC parameters. */
    uint32_t fragment_index; /*!< Optional. Indicates the current stripe index for parameter calculation. */
    ia_nntm_parameters_t nntm_params; /*!< Optional. Neural network tone mapping parameters. */
#endif
    ia_isp_bxt_gdc_limits gdc_mbr_limits; /*!< Optional. GDC MBR limits for WFOV use cases. */
    cca_pa_params manual_pa_setting; /*!< Optional. Manual settings (CCM & gain) for PA results. */
    cca_gbce_params manual_gbce_setting; /*!< Optional. Manual settings (gamma LUT) for GBCE results. */
    bool force_lsc_update; /*!< Optional. Flag indicating if LSC should be forcefully updated. */
    ia_isp_call_rate_control call_rate_control; /*!< Optional. Algorithm run frequency for power-saving purposes. */
    ia_isp_bxt_csc csc_matrix; /*!< Optional. Manual RGB to YUV matrix for BXT CSC. */
    uint32_t gain_id_gaic; /*!< Optional. Indicates which gain is used by generic AIC in multi-exposure cases. */
    ia_faces_roi_results face_roi; /*!< Optional. Face detection ROI parameters. */
} cca_pal_input_params;

/*!
 * \brief Structure for binary data.
 */
typedef struct {
    void *data; /*!< Pointer to the binary data. */
    unsigned int size; /*!< Size of the binary data. */
} cca_binary_data;

/*!
 * \brief Structure for CMC parsed data.
 */
typedef struct {
    uint16_t base_iso; /*!< Base ISO value. */
    cmc_optomechanics_t optics; /*!< Optomechanics data. */
    float32_t min_ag; /*!< Minimum analog gain. */
    float32_t max_ag; /*!< Maximum analog gain. */
    float32_t min_dg; /*!< Minimum digital gain. */
    float32_t max_dg; /*!< Maximum digital gain. */
    uint16_t lut_apertures; /*!< LUT apertures. */
    int32_t media_format; /*!< Media format. */
    int32_t media_format_stills; /*!< Media format for stills. */
    tnr7us_trigger_info_t tnr7us_trigger_info; /*!< TNR7US trigger information. */
    seg_net_info_t seg_net_info; /*!< SEG net information. */
} cca_cmc;

/*!
 * \brief Structure for CCA initialization parameters.
 */
struct cca_init_params {
    cca_cpf aiq_cpf; /*!< Tuning data. */
    cca_nvm aiq_nvm; /*!< Sensor NVM data. */
    cca_aiqd aiq_aiqd; /*!< AIQ algorithm calibration data. */
    uint32_t bitmap; /*!< List of components (CCAModuleBitMap) that need initialization. */
    ia_aiq_frame_params frameParams; /*!< Sensor frame parameters. */
    ia_aiq_frame_use frameUse; /*!< Scenario for use case (still/preview/video). */
    float32_t conversionGainRatio; /*!< Conversion gain ratio. */
    ia_bcomp_dol_mode_t dolMode; /*!< DOL mode. */
    CCADVSOutputType dvsOutputType; /*!< DVS algorithm output configuration. */
    float32_t dvsZoomRatio; /*!< Zoom factor. */
    bool enableVideoStablization; /*!< Flag indicating if video stabilization is enabled. */
    cca_gdc_configurations gdcConfigs; /*!< GDC resolution configuration. */
    uint8_t aiqStorageLen; /*!< Length of history to store algorithm results. */
    uint8_t aecFrameDelay; /*!< Frame delay for auto exposure to take effect. */
    cca_stream_ids aic_stream_ids; /*!< Stream ID for AIC handle. */
    bool disableMKN; /*!< Flag indicating if MKN dump for debug is disabled. */
    ia_lard_input_params lardInputParams; /*!< Initial LARD input parameters. */
    uint32_t num_exposures; /*!< Number of exposure results returned. */
    cca_init_params() :
        frameUse(ia_aiq_frame_use_preview),
        conversionGainRatio(1),
        dolMode(ia_bcomp_non_dol),
        dvsOutputType(CCA_DVS_IMAGE_TRANSFORM),
        dvsZoomRatio(1.0f),
        enableVideoStablization(false),
        aiqStorageLen(3),
        aecFrameDelay(2),
        disableMKN(false),
        num_exposures(1) {
            bitmap = CCA_MODULE_AE | CCA_MODULE_AF | CCA_MODULE_AWB |
                     CCA_MODULE_PA | CCA_MODULE_SA | CCA_MODULE_GBCE |
                     CCA_MODULE_LTM | CCA_MODULE_DVS | CCA_MODULE_OB |
                     CCA_MODULE_BCOM;
            lardInputParams = { IA_MKN_CHTOUL('D', 'F', 'L', 'T'), IA_MKN_CHTOUL('D', 'F', 'L', 'T'),
                                0, IA_MKN_CHTOUL('D', 'F', 'L', 'T') };
            IA_MEMSET(&aiq_cpf, 0, sizeof(aiq_cpf));
            IA_MEMSET(&aiq_nvm, 0, sizeof(aiq_nvm));
            IA_MEMSET(&aiq_aiqd, 0, sizeof(aiq_aiqd));
            IA_MEMSET(&frameParams, 0, sizeof(frameParams));
            IA_MEMSET(&gdcConfigs, 0, sizeof(gdcConfigs));
            IA_MEMSET(&aic_stream_ids, 0, sizeof(aic_stream_ids));
        }
};

/*!
 * \brief Enumeration for multi-CCA flow.
 */
typedef enum {
    front = 0,
    right,
    back,
    left,
} ccd_sv_id;

/*!
 * \brief Enumeration for multi-CCA mode.
 */
typedef enum {
    MultiCCA_Unknown = -1, /*!< Uninitialized mode. */
    MultiCCA_1X, /*!< 1:X mode. */
    MultiCCA_XX /*!< X:X mode. */
} cca_multi_mode;

/*!
 * \brief Structure for multi-CCA ID.
 */
typedef struct {
    uint8_t cam_idx; /*!< Multiple camera index. */
    bool main_cam_flag; /*!< Flag indicating if the current camera is the main camera. */
    ccd_sv_id sv_idx; /*!< Surround view camera index. */
} cca_multi_id;

/*!
 * \brief Structure for multi-CCA configuration.
 */
typedef struct {
    uint8_t cam_num; /*!< Maximum number of multiple cameras. */
    cca_multi_mode group_type; /*!< Group type (0: X:X, 1: 1:X). */
    cca_multi_id multi_id[MAX_CAM_NUM]; /*!< Array of multi-CCA IDs. */
    cca_init_params* init_params[MAX_CAM_NUM]; /*!< Array of initialization parameters for each camera. */
} cca_multi_cam;

} // namespace cca

#endif // INTELCCA_TYPES_H_
