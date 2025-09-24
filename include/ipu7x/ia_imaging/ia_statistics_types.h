/*
 * Copyright 2018-2025 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __IA_STATISTICS_TYPES_H_
#define __IA_STATISTICS_TYPES_H_

#include "ia_types.h"
#include "ia_configuration.h"

#define IA_RGBS_GRID_SIZE ((IA_RGBS_GRID_WIDTH) * (IA_RGBS_GRID_HEIGHT))

 /*!
 * \brief Bayer color channels grouped into one structure.
 */
typedef struct
{
    unsigned char gr;
    unsigned char r;
    unsigned char b;
    unsigned char gb;
} ia_color_channels;

typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} ia_color_3channels;

/*!
 * \brief Statistics grid with averaged RGBS color channels and saturation percentage.
 * Total size of each color channel array is defined by width * height of the grid.
 */
typedef struct
{
    unsigned int grid_width;                        /*!< Mandatory. Width of RGBYS grids. */
    unsigned int grid_height;                       /*!< Mandatory. Height of RGBYS grids. */
    ia_color_channels avg[IA_RGBS_GRID_SIZE];       /*!< Mandatory. Averaged R, Gr, Gb and B channel data. */
    unsigned char sat[IA_RGBS_GRID_SIZE];           /*!< Mandatory. Saturation percentage of pixels within collected data. [0, 255] = [0, 100]%. */
} ia_rgbs_grid;

#define IA_FILTER_RESPONSE_GRID_SIZE (IA_FILTER_RESPONSE_GRID_WIDTH * IA_FILTER_RESPONSE_GRID_HEIGHT)

/*!
 * \brief Filter responses interleaved.
 */
typedef struct
{
    int filter_1;    /*!< Filter response of filter 1 (e.g. low pass, used by auto focus). */
    int filter_2;    /*!< Filter response of filter 2 (e.g. high pass, used by auto focus). */
} ia_filter_response;

/*!
 * \brief Convolution filter response statistics
 * As defined in the AIQ statistics specification.
 */
typedef struct
{
    unsigned int grid_width;                                    /*!< Number of block elements horizontally in a grid. */
    unsigned int grid_height;                                   /*!< Number of block elements vertically in a grid. */
    ia_filter_response responses[IA_FILTER_RESPONSE_GRID_SIZE]; /*!< Interleaved filter responses. */
} ia_filter_response_grid;

typedef struct
{
    unsigned int element_count;                     /*!< Number of elements in the histogram. */
    unsigned int bins[IA_HISTOGRAM_SIZE];           /*!< Histogram data. */
} ia_histogram;

typedef struct
{
    ia_rectangle   face_area;                 /*!< Bounding box of the face in the coordination system where (0,0) indicates left-top position. */
    int32_t        tracking_id;               /*!< Tracking id of the face. */
    int32_t        confidence;                /*!< Confidence in face detection result. */
    ia_coordinate  mouth;                     /*!< Mid-point of the mouth. */
    ia_coordinate  left_eye;                  /*!< Left eye */
    ia_coordinate  right_eye;                 /*!< Right eye */
    bool           eye_validity;              /*!< Indicates whether a face was processed to get eye positions */
    float          skin_type_dark_likelihood; /*!< Likelihood of skin type being dark. Bright skin likelihood = 100 - dark_skin_type_likelihood */
    bool           skin_type_validity;        /*!< Validity of the Skin Likelihood */
    int32_t        rip_angle;                /**< RIP (rotation in plane) angle in degrees. */
    int32_t        rop_angle;                /**< ROP (rotation out of plane) angle in degrees. */
} ia_face_roi;

typedef struct
{
    uint32_t num_faces;         /*!< Number of faces detected.*/
    ia_face_roi* faces;        /*!< ROI array of all detected faces.*/
}ia_faces_roi_results;

#define IA_DEPTH_GRID_SIZE (IA_DEPTH_GRID_WIDTH * IA_DEPTH_GRID_HEIGHT)

typedef enum
{
    ia_depth_data_type_vcm,     /*!< VCM units */
    ia_depth_data_type_mm,      /*!< Distance to the object in mm */
} ia_depth_data_type;

/*!
 * Depth statistics grid.
 */
typedef struct
{
    unsigned int grid_width;                      /*!< Number of grid elements horizontally */
    unsigned int grid_height;                     /*!< Number of grid elements vertically */
    ia_depth_data_type type;                      /*!< Data type (VCM units/mm)*/
    ia_rectangle grid_rect;                       /*!< ROI for the grid */
    int depth_data[IA_DEPTH_GRID_SIZE];           /*!< Depth data (type of data is defined by ia_depth_data_type) */
    unsigned char confidence[IA_DEPTH_GRID_SIZE]; /*!< Confidence level */
} ia_depth_grid;

/*!
 * \brief Statistics grid with Segmap including class and confidence level.
 * Total size is defined by 2 * width * height of the grid.
 */
typedef struct
{
    unsigned int grid_width;                             /*!< Mandatory. Width of segmap grids. */
    unsigned int grid_height;                            /*!< Mandatory. Height of segmap grids. */
    unsigned char class_id_conf[IA_RGBS_GRID_SIZE];           /*!< Mandatory. Class id and Confidence level data. [0, 15]. */
    uint64_t frame_id;
} ia_segmap_grid;

/*!
 * \brief ACS (ambient light sensor) statistics
 */
typedef struct
{
    bool        is_valid;       /*!< is ACS data valid*/
    float32_t   lux_level;      /*!< lux levels as measured by ACS sensor*/
    float64_t   cct;            /*!< Color correlated temperature (CCT) as measured by ACS sensor*/
    float64_t   chroma_x;       /*!< CIE1931 x coordinate as measured by ACS sensor*/
    float64_t   chroma_y;       /*!< CIE1931 y coordinate as measured by ACS sensor*/
    uint64_t    timestamp;      /*!< timestamp of the ACS sensor read*/
} ia_acs_stats;

#endif /* __IA_STATISTICS_TYPES_H_ */
