/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2012-2025 Intel Corporation
 *
 * This software and the related documents are Intel copyrighted materials,
 * and your use of them is governed by the express license under which they
 * were provided to you ("License"). Unless the License provides otherwise,
 * you may not use, modify, copy, publish, distribute, disclose or transmit
 * this software or the related documents without Intel's prior written permission.
 * This software and the related documents are provided as is, with no express
 * or implied warranties, other than those that are expressly
 * stated in the License.
 */

/*!
 * \file ia_ccat.h
 * \brief Definitions of common analysis types used by Intel 3A modules.
*/

#ifndef IA_CCAT_TYPES_H_
#define IA_CCAT_TYPES_H_

#include "ia_configuration.h"
#include "ia_statistics_types.h"
#include "ia_aiq_types.h"
#include "ia_aec_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    ia_ccat_frame_type_nonflash,
#ifdef IA_AEC_FEATURE_FLASH
    ia_ccat_frame_type_flash,
#endif
    ia_ccat_frame_type_count
} ia_ccat_frame_type;

typedef enum
{
    ia_ccat_histogram_type_cc_start = 0,
    ia_ccat_histogram_type_cc_rgb_averaged = ia_ccat_histogram_type_cc_start, /*!< Color corrected and weighted R, G and B histograms averaged into one histogram. */
    ia_ccat_histogram_type_cc_rgb_combined,                                   /*!< Color corrected and weighted R, G and B histograms summed into one histogram. */
    ia_ccat_histogram_type_cc_y,                                              /*!< Color corrected and weighted R, G and B histograms converted to Y (luminance) histogram. */
    ia_ccat_histogram_type_cc_end,
    ia_ccat_histogram_type_raw_start = ia_ccat_histogram_type_cc_end,
#ifdef IA_CCAT_RGBS_GRID_ENABLED
    ia_ccat_histogram_type_raw_rgb_averaged = ia_ccat_histogram_type_cc_end,  /*!< Raw (calculated from RGBS grid before color correction) R, G and B histograms averaged into one histogram. */
    ia_ccat_histogram_type_raw_rgb_combined,                                  /*!< Raw (calculated from RGBS grid before color correction) R, G and B histograms summed into one histogram. */
    ia_ccat_histogram_type_raw_y,                                             /*!< Raw (calculated from RGBS grid before color correction) R, G and B histograms converted to Y (luminance) histogram. */
    ia_ccat_histogram_type_uncorrected_raw_y,                                 /*!< Raw (calculated from RGBS grid before LSC and color correction) R, G and B histograms converted to Y (luminance) histogram. */
    ia_ccat_histogram_type_raw_end,
#else
    ia_ccat_histogram_type_raw_end = ia_ccat_histogram_type_raw_start,
    ia_ccat_histogram_type_raw_rgb_averaged = ia_ccat_histogram_type_raw_end,
    ia_ccat_histogram_type_raw_rgb_combined = ia_ccat_histogram_type_raw_end,
    ia_ccat_histogram_type_raw_y = ia_ccat_histogram_type_raw_end,
    ia_ccat_histogram_type_uncorrected_raw_y = ia_ccat_histogram_type_raw_end,
#endif
    ia_ccat_histogram_type_count = ia_ccat_histogram_type_raw_end,
    ia_ccat_histogram_type_invalid = ia_ccat_histogram_type_count,
} ia_ccat_histogram_type;

typedef struct
{
    ia_histogram r;
    ia_histogram g;
    ia_histogram b;
} ia_ccat_histograms;

#ifdef IA_CCAT_RGBS_GRID_ENABLED
#ifdef IA_CCAT_HSV_GRID_ENABLED
typedef struct
{
    float h;
    float s;
    float v;
} ia_ccat_hsv_channels;

/*!
* \brief HSV grid structure.
*/
typedef struct
{
    unsigned int grid_width;                        /*! Width of the grid. */
    unsigned int grid_height;                       /*! Height of the grid. */
    ia_ccat_hsv_channels data[IA_RGBS_GRID_SIZE];   /*! Grid data. */
} ia_ccat_hsv_grid;
#endif
#endif

#if defined IA_CCAT_RGBS_GRID_ENABLED || defined IA_CCAT_LUMINANCE_GRID_ENABLED || defined IA_CCAT_IR_GRID_ENABLED
/*!
 * \brief Generic 8 bit grid structure.
 */
typedef struct ia_ccat_grid_char
{
    unsigned int grid_width;                    /*! Width of the grid. */
    unsigned int grid_height;                   /*! Height of the grid. */
    unsigned char data[IA_RGBS_GRID_SIZE];      /*! Grid data. */
} ia_ccat_grid_char;

/*!
* \brief Generic 16 bit grid structure.
*/
typedef struct
{
    unsigned int grid_width;                    /*! Width of the grid. */
    unsigned int grid_height;                   /*! Height of the grid. */
    unsigned short data[IA_RGBS_GRID_SIZE];     /*! Grid data. */
} ia_ccat_grid_short;

/*!
 * \brief Generic grid structure with floating point values.
 */
typedef struct
{
    unsigned int grid_width;                    /*! Width of the grid. */
    unsigned int grid_height;                   /*! Height of the grid. */
    float data[IA_RGBS_GRID_SIZE];              /*! Grid data in floating point format. */
} ia_ccat_grid_float;

typedef struct
{
    ia_ccat_grid_char grid_data;
    float i_per_y;
    float out_ir_compgain_isp;
} ia_ccat_ir_grid;

#endif

typedef struct
{
    bool frame_parameters_available;                                            /*!< Mandatory. Flag indicating that frame parameters can be used by CCAT. Set to false to invalidate frame parameters. */
    bool shading_corrected;                                                     /*!< Mandatory. Flag indicating if statistics were calculated using lens shading corrected data. */
    bool stitched_stats;                                                        /*!< RGBS stats for multi-exposures in stitched stats. */
    ia_ccat_frame_type frame_type;                                              /*!< Mandatory. Indicates if statistics were captured from non-flash or flash illuminated frame. */
    uint64_t frame_id;                                                          /*!< Mandatory. ID for the captured frame. */
    uint64_t frame_timestamp;                                                   /*!< Mandatory. Time stamp for captured frame. */
    ia_rectangle statistics_crop_area;                                          /*!< Mandatory. RGBS and AF grid area crop with respect to full field of view of sensor output using (relative)ranges from ia_coordinate.h. */
    float32_t stitched_stats_norm_factor;                                        /*!< Mandatory. For companded pipe usually statistivs represent more than 16bits then factor > 1 depends on highest bit represent by stat. */                                     
    uint32_t rgbs_stats_bit_depth;                                               /*!< Mandatory. indicate the bit depth of rgbs stats */
    int32_t cropped_image_height;                                               /*!< Mandatory. Cropped RGBS raw height */
#ifdef IA_CCAT_EXTERNAL_RGB_HISTOGRAMS_ENABLED
    ia_ccat_histograms rgb_histograms[IA_CCAT_STATISTICS_MAX_NUM];              /*!< Optional. RGB histograms pointer for each exposure statistics. */
#endif
#ifdef IA_CCAT_EXTERNAL_LUMINANCE_HISTOGRAM_ENABLED
    ia_histogram y_histogram[IA_CCAT_STATISTICS_MAX_NUM];                       /*!< Optional. Luminance histogram. */
#endif
#ifdef IA_CCAT_RGBS_GRID_ENABLED
    ia_rgbs_grid rgbs_grids[IA_CCAT_STATISTICS_MAX_NUM];                        /*!< Optional. RGBS grids for each exposure statistics. */
#endif
#ifdef IA_CCAT_CONVOLUTION_FILTER_GRID_ENABLED
    ia_filter_response_grid af_grids[IA_CCAT_STATISTICS_MAX_NUM];               /*!< Optional. AF grids for each exposure statistics. */
#endif
#ifdef IA_CCAT_EXTERNAL_LUMINANCE_GRID_ENABLED
    ia_ccat_grid_char y_grid[IA_CCAT_STATISTICS_MAX_NUM];                       /*!< Optional. Luminance (LSC and color corrected) grids for each exposure statistics. */
#endif
#ifdef IA_CCAT_IR_GRID_ENABLED
    ia_ccat_ir_grid ir_grid;                                                    /*!< Optional. Ir grid (Non LSC corrected grid). */
#endif
#ifdef IA_CCAT_DEPTH_GRID_ENABLED
    ia_depth_grid depth_grid;                                                   /*!< Optional. Depth grid. */
#endif
    ia_acs_stats acs_stats;                                                     /*!< Optional. Statistics from the ACS sensor (if avaialble) .*/
} ia_ccat_frame_statistics;

typedef struct
{
    ia_aec_results aec_results;                                              /*!< Mandatory. Exposure parameters used to capture the frame. */
    ia_aiq_pa_results_v1 pa_results;                                         /*!< Optional. */
    ia_aiq_sa_results_v1 sa_results;                                         /*!< Optional. */
    ia_aiq_awb_results awb_results;                                          /*!< Optional. */
    ia_aiq_af_results af_results;                                            /*!< Optional. */
    bool bAssitLightOn;                                                      /*!< True if the af assist light is on, false otherwise .*/
#ifdef IA_CCAT_FACE_ANALYSIS_ENABLED
    ia_face_roi faces[IA_CCAT_FACES_MAX_NUM];                                /*!< Optional. Face coordinates from external face detector. NULL if not available. */
    bool updated;                                                            /*!< The update status of face. true is the real statistics, and false is the false statistics that have not been updated.*/
    bool is_video_conf;                                                      /*!< video confenerce mode. */
    FD_IMPL_TYPE fd_algo;                                                    /*!< face detection algo type. */
#endif
} ia_ccat_frame_parameters;

/*!
 * \brief Structure for various motion sensors
 * Accelerometer Events:
 *  - The data holds information on the acceleration of the device in mg/sec (miligravity per second). Acceleration = Gravity + Linear Acceleration.
 * Gravity Events:
 *  - The data holds information on the gravitation of the device in mg/sec (miligravity per second).
 * Gyroscope Events:
 *  - The data holds information on the angular velocity of the device in rad/sec.
 */
typedef struct
{
    uint64_t ts;  /*!< Time stamp in usec (microseconds) */
    float x;                /*!< Sensor Data in X direction depending on the type of the sensor */
    float y;                /*!< Sensor Data in Y direction depending on the type of the sensor */
    float z;                /*!< Sensor Data in Z direction depending on the type of the sensor */
    float sensitivity;      /*!< Sensitivity of the sensor */
    uint64_t fs;  /*!< Frame stamp in usec (microseconds) */
} ia_ccat_motion_sensor_event;

/*!
 * \brief Ambient Light Events
 * NOTE: This should always match to libsensorhub API
 * TODO: Update the structure according to the API
 */
typedef struct
{
    uint64_t ts;  /*!< Time stamp in usec (microseconds) */
    float data;             /*!< Ambient Light data ? */
    float sensitivity;      /*!< Sensitivity of Ambient Light sensor */
    uint64_t fs;  /*!< Frame stamp in usec (microseconds) */
} ia_ccat_ambient_light_event;

typedef struct ia_ccat_lse_size_t
{
    uint16_t width;
    uint16_t height;
} ia_ccat_lse_size_t;

typedef struct ia_ccat_color_order_bayer_t
{
    uint8_t r;
    uint8_t gr;
    uint8_t gb;
    uint8_t b;
} ia_ccat_color_order_bayer_t;

/*!
*  \brief enum for accurate or preferred CCM interpolation
*/
typedef enum
{
    ia_ccat_ccm_type_accurate = 0,       /*!< Label for accurate CCM interpolation. */
    ia_ccat_ccm_type_preferred = 1,      /*!< Label for preferred CCM interpolation. */
} ia_ccat_ccm_type_t;

/*!
*  \brief enum for accurate or preferred CCM interpolation
*/
typedef enum
{
    ia_ccat_point_type_rg_bg = 0,       /*!< Label for using RperG, BperG point for CCM interpolation. */
    ia_ccat_point_type_cie_xy = 1,      /*!< Label for using CieXY point for CCM interpolation. */
} ia_ccat_point_type_t;

typedef enum
{
    ccat_project_adaption_bitmap_0 = 1 << 0,   /*!< is special bw chart detection on */
    ccat_project_adaption_bitmap_1 = 1 << 1,   /*!< is wb face_base bitmap on - if on not give priority to face in LSC */
    ccat_project_adaption_bitmap_2 = 1 << 2,   /*!< is for sthdr ae skip */
    ccat_project_adaption_bitmap_3 = 1 << 3,   /*!< is for vcx */
    ccat_project_adaption_bitmap_4 = 1 << 4,   /*!< is for AF document mode in IPU6 */
    ccat_project_adaption_bitmap_5 = 1 << 5,   /*!< is for MSFT OV02C10 NVM issue */
    ccat_project_adaption_bitmap_6 = 1 << 6,   /*!< is for flicker v2 mode */
    ccat_project_adaption_bitmap_7 = 1 << 7,   /*!< TBD */
    ccat_project_adaption_bitmap_8 = 1 << 8,   /*!< TBD */
    ccat_project_adaption_bitmap_9 = 1 << 9,   /*!< TBD */
    ccat_project_adaption_bitmap_10 = 1 << 10,   /*!< TBD */
    ccat_project_adaption_bitmap_11 = 1 << 11,   /*!< TBD */
    ccat_project_adaption_bitmap_12 = 1 << 12,   /*!< TBD */
    ccat_project_adaption_bitmap_13 = 1 << 13,   /*!< TBD */
    ccat_project_adaption_bitmap_14 = 1 << 14,   /*!< TBD */
    ccat_project_adaption_bitmap_15 = 1 << 15   /*!< TBD */
} ccat_project_adaption_bitmap_reg_t;

#ifdef IA_CCAT_LIGHT_SOURCE_ESTIMATION_ENABLED
typedef struct {
    light_source_t light_source[CMC_NUM_LIGHTSOURCES];            /* Weights per each light source type */
    unsigned short likelihood[CMC_NUM_LIGHTSOURCES];              /* Likelihood based on CCT for different light source */
    float confidence;                                             /* Confidence of LSE result */
} ia_ccat_lse_results_t;
#endif

/*!
* \brief Map data from SAP
*/
typedef struct
{
    uint32_t grid_width;
    uint32_t grid_height;
    uint32_t stride;
    ia_binary_data* segmap_data;
    ia_rectangle segmap_crop_area;

    uint32_t rgbs_grid_width;
    uint32_t rgbs_grid_height;
    ia_rectangle rgbs_crop_area;

    uint64_t frame_id;
}ia_aiq_segmap_input_params;

#if 0
/*!
 * \brief Face rectangle
 * Range of rectangle values is defined in ia_coordinate.h:
 * IA_COORDINATE_TOP, IA_COORDINATE_LEFT, IA_COORDINATE_BOTTOM, IA_COORDINATE_RIGHT
 */
typedef struct
{
    int tracking_id;                   /*!< Tracking id of the face. */
    ia_rectangle face_area;            /*!< Bounding box of the face in the coordination system where (0,0) indicates left-top position. */
    ia_coordinate mouth;               /*!< Mid-point of the mouth. */
    ia_coordinate left_eye;            /*!< Left eye */
    ia_coordinate right_eye;           /*!< Right eye */
    bool eye_validity;                 /*!< Indicates whether a face was processed to get eye positions */
    float skin_type_dark_likelihood;   /*!< Likelihood of skin type being dark [0.0, 1.0]. Bright skin likelihood = 1.0 - dark_skin_type_likelihood */
    bool skin_type_validity;           /*!< Indicates whether a face was processed to get skin likelihood */
} ia_face_roi;
#endif
#ifdef __cplusplus
}
#endif

#endif /* IA_CCAT_H_ */
