/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2012-2026 Intel Corporation
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
    ia_ccat_histogram_type_cc_rgb_combined = ia_ccat_histogram_type_cc_start, /*!< Color corrected and weighted R, G and B histograms summed into one histogram. */
    ia_ccat_histogram_type_cc_y,                                              /*!< Color corrected and weighted R, G and B histograms converted to Y (luminance) histogram. */
    ia_ccat_histogram_type_cc_end,
    ia_ccat_histogram_type_raw_start = ia_ccat_histogram_type_cc_end,
#ifdef IA_CCAT_RGBS_GRID_ENABLED
    ia_ccat_histogram_type_raw_y = ia_ccat_histogram_type_cc_end,             /*!< Raw (calculated from RGBS grid before color correction) R, G and B histograms converted to Y (luminance) histogram. */
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
#ifdef IA_CCAT_HSV_GRID_ENABLED_OLD
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
    int32_t cropped_image_height;                                                /*!< Mandatory. Width of the statistics area. */
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
    ia_acs_stats acs_stats;                                                     /*!< Optional. Statistics from the ACS sensor (if available) .*/
} ia_ccat_frame_statistics;

typedef struct
{
    ia_aec_results aec_results;                                              /*!< Mandatory. Exposure parameters used to capture the frame. */
    ia_aiq_pa_results_v1 pa_results;                                         /*!< Optional. */
    ia_aiq_sa_results_v1 sa_results;                                         /*!< Optional. */
    ia_aiq_awb_results awb_results;                                          /*!< Optional. */
    ia_aiq_af_results af_results;                                            /*!< Optional. */
    bool bAssitLightOn;                                                      /*!< True if the af assist light is on, false otherwise .*/
    bool zoom_on;                                                           /*!< True if the camera is zooming, false otherwise .*/
#ifdef IA_CCAT_FACE_ANALYSIS_ENABLED
    ia_face_roi faces[IA_CCAT_FACES_MAX_NUM];                                /*!< Optional. Face coordinates from external face detector. NULL if not available. */
    bool updated;                                                            /*!< The update status of face. true is the real statistics, and false is the false statistics that have not been updated.*/
    bool is_video_conf;                                                      /*!< video confenerce mode. */
    FD_IMPL_TYPE fd_algo;                                                    /*!< face detection algo type. */
#endif
} ia_ccat_frame_parameters;

#ifdef IA_CCAT_FACE_ANALYSIS_ENABLED
typedef enum {
    IA_CCAT_FACE_MODE_FD,      /*!< Face rects from FD only, no segmap weighting. */
    IA_CCAT_FACE_MODE_SAP,     /*!< Face rects and pixel mask derived from SAP segmap. */
    IA_CCAT_FACE_MODE_FD_SAP,  /*!< Face rects from FD, pixel mask from SAP segmap. */
} ia_ccat_face_mode_t;

/*!
 * \brief Per-frame face tracker events.
 * Computed once per frame by analyze_face_events() and cached in frame_info_t.
 * Read by any subsystem via ia_ccat_get_face_events().
 */
typedef struct
{
    bool    biggest_face_gone;     /*!< Face[0] was present last frame, absent this frame. */
    bool    biggest_face_appeared; /*!< No face last frame, face[0] present this frame. */
    bool    biggest_face_changed;  /*!< Face[0] shifted beyond the cell threshold for enough frames. */
    bool    faces_merged;          /*!< Count fell and face[0] area grew — spots joined into one. */
    bool    faces_split;           /*!< Count rose and face[0] area shrank — spot broke into two. */
    uint8_t face_lost_mask;        /*!< Bit i: prev face i has no IoU match in current frame. */
    uint8_t face_exited_mask;      /*!< Bit i: lost face i was last seen near the frame boundary. */
    uint8_t face_turned_mask;      /*!< Bit i: lost face i had a small spot at last sighting (turned away). */
} ia_ccat_face_events_t;

/*!
 * \brief Per-frame person tracker events.
 * Superset of ia_ccat_face_events_t extended with SAP-based disappearance classification
 * and continuous person-presence events.
 *
 * Disappearance mask bits use the *previous-frame* face index j.
 * face_partially_covered_mask bits use the *current-frame* face index k.
 */
typedef struct
{
    /* --- Face-level events (same semantics as ia_ccat_face_events_t) ---------- */
    bool    biggest_face_gone;
    bool    biggest_face_appeared;
    bool    biggest_face_changed;
    bool    faces_merged;
    bool    faces_split;
    uint8_t face_lost_mask;
    uint8_t face_exited_mask;
    uint8_t face_turned_mask;
    /* --- SAP-based disappearance classification (mutually exclusive per bit) -- */
    uint8_t face_covered_by_hand_mask; /*!< Bit j: SKIN cells appeared in prev face j area — hand in front of face. */
    uint8_t face_turned_away_mask;     /*!< Bit j: HAIR cells appeared in prev face j area — head rotated away. */
    uint8_t person_hidden_mask;        /*!< Bit j: CLOTH moved into prev face j area — person ducked/slid down. */
    uint8_t face_occluded_mask;        /*!< Bit j: CLOTH still below prev face j — object occlusion. */
    uint8_t person_exited_frame_mask;  /*!< Bit j: face j exited AND cloth was also at frame edge. */
    /* --- Continuous / independent events -------------------------------------- */
    uint8_t face_partially_covered_mask; /*!< Bit k: current face k matched but SKIN cells overlap its bbox. */
    bool    person_approaching;          /*!< Face[0]+cloth bounding area growing — person moving closer. */
    bool    person_receding;             /*!< Face[0]+cloth bounding area shrinking — person moving away. */
    bool    person_present_no_face;      /*!< No face detected but HAIR or CLOTH found in previous face region. */
} ia_ccat_person_events_t;
#endif

#if defined(IA_CCAT_FACE_ANALYSIS_ENABLED) && defined(IA_CCAT_EXTERNAL_SEGMAP_ENABLED)
/*!
 * \brief Bounding box and cell count for one SAP segmap label class adjacent to a face.
 * area is zero-initialised when cells == 0.
 */
typedef struct
{
    ia_rectangle area;  /*!< Bounding box in IA coordinates. */
    uint32_t     cells; /*!< Number of segmap cells for this label assigned to this face. */
} ia_ccat_label_region_t;

/*!
 * \brief Per-face person attribute regions derived from SAP segmap adjacent labels.
 * One entry per face in resolved_faces[], filled by fill_resolved_person_attr_from_sap().
 */
typedef struct
{
    ia_ccat_label_region_t hair;        /*!< HAIR (7) cells — scalp hair above/around the face. */
    ia_ccat_label_region_t facial_hair; /*!< FACIAL_HAIR (4) cells — beard/moustache on the face. */
    ia_ccat_label_region_t skin;        /*!< SKIN (3) cells — neck and other exposed non-facial skin. */
    ia_ccat_label_region_t cloth;       /*!< CLOTH (6) cells — shoulders and clothing below the face. */
} ia_ccat_person_attr_t;
#endif

#ifdef IA_CCAT_EXTERNAL_SENSORS_ENABLED
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
#endif

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
    ccat_project_adaption_bitmap_6 = 1 << 6,   /*!< is for wfov skin tone alignment */
    ccat_project_adaption_bitmap_7 = 1 << 7,   /*!< is CAF fine-search bitmap on - if on use CAF to perform fine search after PDAF */
    ccat_project_adaption_bitmap_8 = 1 << 8,   /*!< is to skip the logic that sets stable face signal when MSFT is updated. */
    ccat_project_adaption_bitmap_9 = 1 << 9,     /*!< TBD */
    ccat_project_adaption_bitmap_10 = 1 << 10,   /*!< TBD */
    ccat_project_adaption_bitmap_11 = 1 << 11,   /*!< is world facing camera */
    ccat_project_adaption_bitmap_12 = 1 << 12,   /*!< face mode LSB: bits [13:12] select face mode (0=FD,1=SAP,2=FD_SAP) when segmap enabled */
    ccat_project_adaption_bitmap_13 = 1 << 13,   /*!< face mode MSB: bits [13:12] select face mode (0=FD,1=SAP,2=FD_SAP) when segmap enabled */
    ccat_project_adaption_bitmap_14 = 1 << 14,   /*!< TBD */
    ccat_project_adaption_bitmap_15 = 1 << 15    /*!< TBD */
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
#ifdef IA_CCAT_EXTERNAL_SEGMAP_ENABLED
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

/* supported features of the SAP network
 * 3A code need to check the existence of STATS
 * feature, then all the below segments my appear
 * in the input segment map
*/
typedef enum
{
    BASIC = 0,
    MEMORY = 1,
    STATS = 2,
    FACE = 3
} AlgoSapSuportedFeatures;

/* available segments of STATS segment map to be used
 * for mapping between class_code from the segmap to
 * Known segment from the below list
*/
typedef enum
{
    BACKGROUND = 0,
    FACIAL_SKIN = 1,
    FOLIAGE = 2,
    SKIN = 3,
    FACIAL_HAIR = 4,
    SKY = 5,
    CLOTH = 6,
    HAIR = 7,
    OBJECTS = 8,
    NOT_VALID_CLASS_CODE = -1
} SegmentsNumbersMapping;

typedef struct {
    bool isEnabled;
    uint8_t num_of_class_codes;
    int8_t class_code_segments_mapping[SEG_NET_MAX_SEGMENTS];
} ia_ccat_3a_segmap_info;
#define SEGMAP_CLASS_ID_CONF_TO_CLASS_ID(class_id_conf) ((class_id_conf & 0xf0) >> 4)
#define SEGMAP_CLASS_ID_CONF_TO_CONF(class_id_conf) ((class_id_conf & 0xf))
#define SEGMAP_CLASS_ID_CONF_TO_SEGMENT_CONF(segment, class_id_conf) (((segment) << 4) | (class_id_conf & 0x0f))
#define SEGMAP_AND_CONF_TO_SEGMENT_CONF(segment, conf) (((segment) << 4) | conf)
#endif
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
