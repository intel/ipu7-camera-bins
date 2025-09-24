/*
 * Copyright 2023-2025 Intel Corporation
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

/*!
 * \file ia_tnr7_types.h
 * \brief Common TNR7 enumerations and structures.
*/


#ifndef IA_CAMERA_TYPES_H_
#define IA_CAMERA_TYPES_H_

#include <stdint.h>
#include "ia_types.h"

#ifdef __cplusplus
extern "C" {
#endif


#define IA_CAMERA_PARAMETERS_CAMERA_CONFIG_ROTATION_MATRIX_SIZE (3)
#define IA_CAMERA_PARAMETERS_RADIAL_DISTORTION_LUT_SIZE_MAX     (2048)
#define IA_CAMERA_INVALID_COORD_SIZE (3)


typedef struct
{
    float32_t x;        // X value in pixels
    float32_t y;        // Y value in pixels

} ia_camera_point_t;

typedef struct
{
    ia_camera_point_t       focal_length;           // Focal Length (in pixels)
    ia_camera_point_t       principal_point;        // Principal Point (in pixels)
    float32_t               rotation_matrix[IA_CAMERA_PARAMETERS_CAMERA_CONFIG_ROTATION_MATRIX_SIZE][IA_CAMERA_PARAMETERS_CAMERA_CONFIG_ROTATION_MATRIX_SIZE];

} ia_camera_config_t;

typedef struct
{
    int32_t num_lut_elements;       // Number of LDC(R) LUT elements
    float32_t focal_length;         // Camera module Focal Length. Range is from CMC_OpticsAndMechanics section in CPFF
    float32_t max_fov_lut;          // LUT Max incident angle (in degrees)
    float32_t max_fov_lens;         // Lens Max incident angle (in degrees)
    float32_t ldc_r_lut[IA_CAMERA_PARAMETERS_RADIAL_DISTORTION_LUT_SIZE_MAX];   // LDC(R) LUT table in pixels

} ia_camera_radial_distortion_t;

typedef struct
{
    int32_t enable;

    ia_camera_config_t  camera_params_sensor;
    ia_camera_config_t  camera_params_view;

    ia_camera_radial_distortion_t  camera_radial_distortion;

    int32_t invalid_coordinate_mask[IA_CAMERA_INVALID_COORD_SIZE]; /*!< Used to fill for each color channel when coordinates falls out of bounds */

} ia_camera_parameters_t;

//GDC Rectification parameters:

typedef struct
{
    ia_camera_point_t       focal_length;           // Focal Length (in pixels)
    ia_camera_point_t       principal_point;        // Principal Point (in pixels)
    float32_t               rotation_matrix[IA_CAMERA_PARAMETERS_CAMERA_CONFIG_ROTATION_MATRIX_SIZE][IA_CAMERA_PARAMETERS_CAMERA_CONFIG_ROTATION_MATRIX_SIZE];

    //Radial distrotion:
    float32_t radial_distortion_lut_range_degs; //"The angular range [degrees] covered by the LUT, relative to the optical center. The angles for which the LUT provides values : theta = linspace(0, lut_range_degs, 2048)"

    float32_t radial_distortion_lut_focal_length; //"The reference focal length used by the LUT [pixels]. The LUT values : Rd = distorted range from the optical center[pixels; refereing to lut_focal_length]"

} ia_rectify_sensor_t;

typedef struct {
    int32_t enable;

    int32_t invalid_coordinate_mask[IA_CAMERA_INVALID_COORD_SIZE]; /*!< Used to fill for each color channel when coordinates falls out of bounds */

    int32_t force_fov_symmetry; //A flag; if set, the output image will be centered around the optical center.

} ia_rectify_control_t;

typedef struct {
    ia_camera_point_t principal_point; // [px, py] [pixels] (= intrinsic_matrix([1, 2], 3)); 0 - based coordinates : [0, 0] = center of the top - left pixel

    ia_camera_point_t focal_length; //[fx, fy] [pixels] (= [intrinsic_matrix(1, 1), intrinsic_matrix(2, 2)])

    int32_t image_width; //width of the available field-of-view for the rectified images

    int32_t image_height; //height of the available field-of-view for the rectified images

} ia_rectify_calib_t;

typedef struct {
    float32_t rlut[IA_CAMERA_PARAMETERS_RADIAL_DISTORTION_LUT_SIZE_MAX]; //the rgb_rlut calibration table

    ia_rectify_sensor_t calib_sensor; //the "input" part in the RGB calibration table

    ia_rectify_calib_t calib_rectified; //the "rectified" part in the RGB calibration table

    ia_rectify_control_t control; //parameters configured by the control SW

} ia_rectify_parameters_t;

#ifdef __cplusplus
}
#endif

#endif // IA_CAMERA_TYPES_H_
