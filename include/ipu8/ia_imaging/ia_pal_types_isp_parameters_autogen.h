
/*
* INTEL CONFIDENTIAL
* Copyright (c) 2023 Intel Corporation
* All Rights Reserved.
*
* The source code contained or described herein and all documents related to
* the source code (Material) are owned by Intel Corporation or its
* suppliers or licensors. Title to the Material remains with Intel
* Corporation or its suppliers and licensors. The Material may contain trade
* secrets and proprietary and confidential information of Intel Corporation
* and its suppliers and licensors, and is protected by worldwide copyright
* and trade secret laws and treaty provisions. No part of the Material may be
* used, copied, reproduced, modified, published, uploaded, posted,
* transmitted, distributed, or disclosed in any way without Intel's prior
* express written permission.
*
* No license under any patent, copyright, trade secret or other intellectual
* property right is granted to or conferred upon you by disclosure or
* delivery of the Materials, either expressly, by implication, inducement,
* estoppel or otherwise. Any license under such intellectual property rights
* must be express and approved by Intel in writing.
*
* Unless otherwise agreed by Intel in writing, you may not remove or alter
* this notice or any other notice embedded in Materials by Intel or Intel's
* suppliers or licensors in any way.
*/

#ifndef IA_PAL_TYPES_ISP_PARAMETERS_AUTOGEN_H
#define IA_PAL_TYPES_ISP_PARAMETERS_AUTOGEN_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif


/*! \isp struct acm_1_2

*/
typedef struct
{
    /*!< bypass Block bypass for HW use*/
    int32_t bypass;
    /*!< enable_chroma_lut Enable Chroma adaptation by LUT*/
    int32_t enable_chroma_lut;
    /*!< enable_luma_lut Enable Luma adaptation by LUT*/
    int32_t enable_luma_lut;
    /*!< enable_negative_pixels enable negative pixels in output*/
    int32_t enable_negative_pixels;
    /*!< enable_chroma_low_light_mode Enable Chroma adaptation in low light mode*/
    int32_t enable_chroma_low_light_mode;
    /*!< enable_luma_low_light_mode Enable Luma adaptation in low light mode*/
    int32_t enable_luma_low_light_mode;
    /*!< num_of_sectors number of sectors, U5.0*/
    int32_t num_of_sectors;
    /*!< chromagrid2uniformlut_cu_x[9] U12.0*/
    int32_t chromagrid2uniformlut_cu_x[9];
    /*!< chromagrid2uniformlut_cu_a[8] S4.10*/
    int32_t chromagrid2uniformlut_cu_a[8];
    /*!< lumagrid2uniformlut_cu_x[9] U12.0*/
    int32_t lumagrid2uniformlut_cu_x[9];
    /*!< lumagrid2uniformlut_cu_a[8] S4.10*/
    int32_t lumagrid2uniformlut_cu_a[8];
    /*!< ccm_matrix_arr[216] CCM's table (one per sector), S3.11*/
    int32_t ccm_matrix_arr[216];
    /*!< hue_boundary_arr[24] Table of sectors boundaries, U11.0*/
    int32_t hue_boundary_arr[24];
    /*!< ccm_index_arr[25] Table of the sectors indices, U5.0*/
    int32_t ccm_index_arr[25];
    /*!< offr CCM bias for R, S13.0*/
    int32_t offr;
    /*!< offg CCM bias for G, S13.0*/
    int32_t offg;
    /*!< offb CCM bias for B, S13.0*/
    int32_t offb;
    /*!< luma_coeff_arr[3] Luna coefficients (weights), U0.8*/
    int32_t luma_coeff_arr[3];
    /*!< adapt_chroma_lut[81] Chroma adaptation LUT, U2.7*/
    int32_t adapt_chroma_lut[81];
    /*!< adapt_luma_lut[81] Luma adaptation LUT, S13.0*/
    int32_t adapt_luma_lut[81];
    /*!< enable_low_light_mode Enable CC's adaptation low light mode*/
    int32_t enable_low_light_mode;
    /*!< enable_compand enable for the (de)companding*/
    int32_t enable_compand;
    /*!< cu_compression_x[13] U.24 linear, default log-limited*/
    int32_t cu_compression_x[13];
    /*!< cu_compression_y[12] U.15 companded output*/
    int32_t cu_compression_y[12];
    /*!< cu_compression_slope[12] U1.14 15bit slopes for companding*/
    int32_t cu_compression_slope[12];
    /*!< cu_decompression_x[13] U.15 companded input, default log-limited*/
    int32_t cu_decompression_x[13];
    /*!< cu_decompression_y[12] U.24 linear*/
    int32_t cu_decompression_y[12];
    /*!< cu_decompression_slope[12] U20.6 26bit slopes for decompanding*/
    int32_t cu_decompression_slope[12];
    /*!< linear_pedestal Pedestal subtracted (and added later) in linear domain, U.24*/
    int32_t linear_pedestal;
    /*!< use_pedestal If true, pedestal is used and the companded signal should be U15. If false, linear_pedestal should be 0*/
    int32_t use_pedestal;
    /*!< is_segmentation_aware enable for the segment aware processing*/
    int32_t is_segmentation_aware;
    /*!< luts_input_mode input mode ofr chroma and luma LUTs*/
    int32_t luts_input_mode;
    /*!< ccm_matrix_per_class[324] CCM's table (one per class), S3.11*/
    int32_t ccm_matrix_per_class[324];
    /*!< ccm_index_per_class[36] Table of the sectors indices per class, S6.0*/
    int32_t ccm_index_per_class[36];

} ia_pal_isp_acm_1_2_t;

/*! \isp struct aestatistics_2_1
AE Statistics (histogram)
*/
typedef struct
{
    /*!< cell0[96] weighted histogram grid values*/
    int32_t cell0[96];
    /*!< cell1[96] weighted histogram grid values*/
    int32_t cell1[96];
    /*!< cell2[96] weighted histogram grid values*/
    int32_t cell2[96];
    /*!< cell3[96] weighted histogram grid values*/
    int32_t cell3[96];
    /*!< cell4[96] weighted histogram grid values*/
    int32_t cell4[96];
    /*!< cell5[96] weighted histogram grid values*/
    int32_t cell5[96];
    /*!< cell6[96] weighted histogram grid values*/
    int32_t cell6[96];
    /*!< cell7[96] weighted histogram grid values*/
    int32_t cell7[96];
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128, 256)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128, 256)*/
    int32_t block_height;
    /*!< ae_en 0: FF will not write to the AE  array; 1: FF will write*/
    int32_t ae_en;
    /*!< rst_hist_array 1: triggers the reset mechanism for the GLB_HIST*/
    int32_t rst_hist_array;
    /*!< x_start X top left corner of the grid*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid*/
    int32_t y_end;
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;
    /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_00;
    /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_01;
    /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_02;
    /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_03;
    /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_10;
    /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_11;
    /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_12;
    /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_13;
    /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_20;
    /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_21;
    /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_22;
    /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_23;
    /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_30;
    /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_31;
    /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_32;
    /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_33;
    /*!< shift_id[8] shifter for the histograms per color channel*/
    int32_t shift_id[8];

} ia_pal_isp_aestatistics_2_1_t;

/*! \isp struct b2i_ds_1_1

*/
typedef struct
{
    /*!< enable enable scaling filter*/
    int32_t enable;
    /*!< scaling_ratio Scaling factor, 16bit fixed point, greater than 1*/
    int32_t scaling_ratio;
    /*!< horizontal_offset Position of first output pixel for scaler*/
    int32_t horizontal_offset;
    /*!< vertical_offset Position of first output line for scaler*/
    int32_t vertical_offset;
    /*!< output_height Output image height for scaler*/
    int32_t output_height;
    /*!< output_width Output image width for scaler*/
    int32_t output_width;
    /*!< vkernel_LUT[129] interpolation vertical kernel coefficients for scaler*/
    int32_t vkernel_LUT[129];
    /*!< hkernel_LUT[129] interpolation horizontal kernel coefficients for scaler*/
    int32_t hkernel_LUT[129];
    /*!< input_height input image height*/
    int32_t input_height;

} ia_pal_isp_b2i_ds_1_1_t;

/*! \isp struct bgb_1_0

*/
typedef struct
{
    /*!< enable enables the filter, if disabled the output is identical to input*/
    int32_t enable;

} ia_pal_isp_bgb_1_0_t;

/*! \isp struct bnlm_3_4
noise reduction
*/
typedef struct
{
    /*!< bayer_fmt Bayer format*/
    int32_t bayer_fmt;
    /*!< bypass bypass*/
    int32_t bypass;
    /*!< run_on_y a flag that indicates if the block used on Y input*/
    int32_t run_on_y;
    /*!< hv_edge_density_thr Edge density noise sigma thr*/
    int32_t hv_edge_density_thr;
    /*!< minmax_hv_edge_density_thr Edge density delta max - min thr*/
    int32_t minmax_hv_edge_density_thr;
    /*!< d_edge_density_thr Diagonal edge density noise sigma thr*/
    int32_t d_edge_density_thr;
    /*!< minmax_d_edge_density_thr Diagonal edge density delta max - min thr*/
    int32_t minmax_d_edge_density_thr;
    /*!< sigma_flat sigma flat*/
    int32_t sigma_flat;
    /*!< sigma_slope sigma slope*/
    int32_t sigma_slope;
    /*!< sigma_edge sigma edge*/
    int32_t sigma_edge;
    /*!< sigma_texture sigma texture*/
    int32_t sigma_texture;
    /*!< delta_flat delta flat*/
    int32_t delta_flat;
    /*!< delta_slope delta slope*/
    int32_t delta_slope;
    /*!< delta_edge delta edge*/
    int32_t delta_edge;
    /*!< delta_texture delta texture*/
    int32_t delta_texture;
    /*!< alpha_flat alpha flat*/
    int32_t alpha_flat;
    /*!< alpha_slope alpha slope*/
    int32_t alpha_slope;
    /*!< alpha_edge alpha edge*/
    int32_t alpha_edge;
    /*!< alpha_texture alpha texture*/
    int32_t alpha_texture;
    /*!< sigma_s spatial sigma of uniform filter*/
    int32_t sigma_s;
    /*!< sigma_s_b narrow sigma of elliptical filter*/
    int32_t sigma_s_b;
    /*!< sigma_s_a wide sigma of elliptical filter*/
    int32_t sigma_s_a;
    /*!< rx_sqr_start initial value of Rx^2*/
    int32_t rx_sqr_start;
    /*!< ry_sqr_start initial value of Ry^2*/
    int32_t ry_sqr_start;
    /*!< coordinates_shift coordinates shift*/
    int32_t coordinates_shift;
    /*!< color_penalty_weight color penalty weight*/
    int32_t color_penalty_weight;
    /*!< alpha_i_max alpha I max*/
    int32_t alpha_i_max;
    /*!< cu_ed_measure_x[4] edge density config unit - x values*/
    int32_t cu_ed_measure_x[4];
    /*!< cu_ed_measure_y[3] edge density config unit - y values*/
    int32_t cu_ed_measure_y[3];
    /*!< cu_ed_measure_slope[3] edge density config unit - slope values*/
    int32_t cu_ed_measure_slope[3];
    /*!< cu_ed_dir_measure_x[4] directional measure config unit - x values*/
    int32_t cu_ed_dir_measure_x[4];
    /*!< cu_ed_dir_measure_y[3] directional measure config unit - y values*/
    int32_t cu_ed_dir_measure_y[3];
    /*!< cu_ed_dir_measure_slope[3] directional measure config unit - slopes values*/
    int32_t cu_ed_dir_measure_slope[3];
    /*!< cu_alpha_i_x[4] alpha change with intensity config unit - x values*/
    int32_t cu_alpha_i_x[4];
    /*!< cu_alpha_i_y[3] alpha change with intensity config unit - y values*/
    int32_t cu_alpha_i_y[3];
    /*!< cu_alpha_i_slope[3] alpha change with intensity config unit - slopes values*/
    int32_t cu_alpha_i_slope[3];
    /*!< start_col The distance along the vertical axis of the first pixel of the frame*/
    int32_t start_col;
    /*!< start_row The distance along the horizontal axis of the first pixel of the frame*/
    int32_t start_row;
    /*!< delta_y_counter crop supporting register*/
    int32_t delta_y_counter;
    /*!< delta_x_counter crop supporting register*/
    int32_t delta_x_counter;
    /*!< cu_nm_patch_x[10] noise model config unit - x values*/
    int32_t cu_nm_patch_x[10];
    /*!< cu_nm_patch_y[9] noise model config unit - y values*/
    int32_t cu_nm_patch_y[9];
    /*!< cu_nm_patch_slope[9] noise model config unit - slope values*/
    int32_t cu_nm_patch_slope[9];
    /*!< cu_nm_block_x[10] content detectors noise model config unit - x values*/
    int32_t cu_nm_block_x[10];
    /*!< cu_nm_block_y[9] content detectors noise model config unit - y values*/
    int32_t cu_nm_block_y[9];
    /*!< cu_nm_block_slope[9] content detectors noise model config unit - slope values*/
    int32_t cu_nm_block_slope[9];
    /*!< cu_input_compression_x[16] input compression function (16 to 12 bits) - x values*/
    int32_t cu_input_compression_x[16];
    /*!< cu_input_compression_y[15] input compression function (16 to 12 bits) - y values*/
    int32_t cu_input_compression_y[15];
    /*!< cu_input_compression_slope[15] input compression function (16 to 12 bits) - slope values*/
    int32_t cu_input_compression_slope[15];
    /*!< cu_input_decompression_x[16] input decompression function (16 to 24 bits) - x values*/
    int32_t cu_input_decompression_x[16];
    /*!< cu_input_decompression_y[15] input decompression function (16 to 24 bits) - y values*/
    int32_t cu_input_decompression_y[15];
    /*!< cu_input_decompression_slope[15] input decompression function (16 to 24 bits) - slope values*/
    int32_t cu_input_decompression_slope[15];
    /*!< cu_output_compression_x[16] output compression function (24 to 16 bits) - x values*/
    int32_t cu_output_compression_x[16];
    /*!< cu_output_compression_y[15] output compression function (24 to 16 bits) - y values*/
    int32_t cu_output_compression_y[15];
    /*!< cu_output_compression_slope[15] output compression function (24 to 16 bits) - slope values*/
    int32_t cu_output_compression_slope[15];
    /*!< nm_norm_scale Amount of bits to normalize the noise model*/
    int32_t nm_norm_scale;
    /*!< lsc_coeff_lut_gr[32] Shading coeffcients along the distance from the frame optical center*/
    int32_t lsc_coeff_lut_gr[32];
    /*!< lsc_coeff_lut_gb[32] Shading coeffcients along the distance from the frame optical center*/
    int32_t lsc_coeff_lut_gb[32];
    /*!< lsc_coeff_lut_r[32] Shading coeffcients along the distance from the frame optical center*/
    int32_t lsc_coeff_lut_r[32];
    /*!< lsc_coeff_lut_b[32] Shading coeffcients along the distance from the frame optical center*/
    int32_t lsc_coeff_lut_b[32];
    /*!< lin_slope_measure_slope_a slope measure based on linear eq - slope value*/
    int32_t lin_slope_measure_slope_a;
    /*!< lin_slope_measure_x0 slope measure based on linear eq - x0 value*/
    int32_t lin_slope_measure_x0;
    /*!< lin_slope_edge_measure_slope_a edge measure based on linear eq - slope value*/
    int32_t lin_slope_edge_measure_slope_a;
    /*!< lin_slope_edge_measure_x0 edge measure based on linear eq - x0 value*/
    int32_t lin_slope_edge_measure_x0;
    /*!< var_measure_slope_a variance measure based on linear eq - slope value*/
    int32_t var_measure_slope_a;
    /*!< var_measure_x0 variance measure based on linear eq - x0 value*/
    int32_t var_measure_x0;
    /*!< var_edge_measure_slope_a variance edge measure based on linear eq - slope value*/
    int32_t var_edge_measure_slope_a;
    /*!< var_edge_measure_x0 variance edge  measure based on linear eq - x0 value*/
    int32_t var_edge_measure_x0;
    /*!< is_segmentation_aware If 1, the filter works in the segmentation-aware mode, if 0 the filter ignores the seg-map input completely and goes to non-segmentation-aware mode*/
    int32_t is_segmentation_aware;
    /*!< sigma_flat_class[16] sigma flat for each class - SAP*/
    int32_t sigma_flat_class[16];
    /*!< sigma_slope_class[16] sigma slope for each class - SAP*/
    int32_t sigma_slope_class[16];
    /*!< sigma_edge_class[16] sigma edge for each class - SAP*/
    int32_t sigma_edge_class[16];
    /*!< sigma_texture_class[16] sigma texture for each class - SAP*/
    int32_t sigma_texture_class[16];
    /*!< delta_flat_class[16] delta flat for each class - SAP*/
    int32_t delta_flat_class[16];
    /*!< delta_slope_class[16] delta slope for each class - SAP*/
    int32_t delta_slope_class[16];
    /*!< delta_edge_class[16] delta edge for each class - SAP*/
    int32_t delta_edge_class[16];
    /*!< delta_texture_class[16] delta texture for each class - SAP*/
    int32_t delta_texture_class[16];
    /*!< alpha_flat_class[16] alpha flat for each class - SAP*/
    int32_t alpha_flat_class[16];
    /*!< alpha_slope_class[16] alpha slope for each class - SAP*/
    int32_t alpha_slope_class[16];
    /*!< alpha_edge_class[16] alpha edge for each class - SAP*/
    int32_t alpha_edge_class[16];
    /*!< alpha_texture_class[16] alpha texture for each class - SAP*/
    int32_t alpha_texture_class[16];
    /*!< lin_slope_measure_slope_a_class[16] slope measure based on linear eq - slope for each class - SAP*/
    int32_t lin_slope_measure_slope_a_class[16];
    /*!< lin_slope_measure_x0_class[16] slope measure based on linear eq - x0 for each class - SAP*/
    int32_t lin_slope_measure_x0_class[16];
    /*!< lin_slope_edge_measure_slope_a_class[16] edge measure based on linear eq - slope for each class - SAP*/
    int32_t lin_slope_edge_measure_slope_a_class[16];
    /*!< lin_slope_edge_measure_x0_class[16] edge measure based on linear eq - x0 for each class - SAP*/
    int32_t lin_slope_edge_measure_x0_class[16];
    /*!< var_measure_slope_a_class[16] variance measure based on linear eq - slope for each class - SAP*/
    int32_t var_measure_slope_a_class[16];
    /*!< var_measure_x0_class[16] variance measure based on linear eq - x0 for each class - SAP*/
    int32_t var_measure_x0_class[16];
    /*!< var_edge_measure_slope_a_class[16] variance edge measure based on linear eq - slope for each class - SAP*/
    int32_t var_edge_measure_slope_a_class[16];
    /*!< var_edge_measure_x0_class[16] variance edge  measure based on linear eq - x0 for each class - SAP*/
    int32_t var_edge_measure_x0_class[16];

} ia_pal_isp_bnlm_3_4_t;

/*! \isp struct bxt_blc

*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< bypass bypass for the filter*/
    int32_t bypass;
    /*!< dummy_bypass dumy bypass for the filter. Required to allign block API to RTL registers*/
    int32_t dummy_bypass;
    /*!< fixobc00 black level value*/
    int32_t fixobc00;
    /*!< fixobc01 black level value*/
    int32_t fixobc01;
    /*!< fixobc02 black level value*/
    int32_t fixobc02;
    /*!< fixobc03 black level value*/
    int32_t fixobc03;
    /*!< fixobc10 black level value*/
    int32_t fixobc10;
    /*!< fixobc11 black level value*/
    int32_t fixobc11;
    /*!< fixobc12 black level value*/
    int32_t fixobc12;
    /*!< fixobc13 black level value*/
    int32_t fixobc13;
    /*!< fixobc20 black level value*/
    int32_t fixobc20;
    /*!< fixobc21 black level value*/
    int32_t fixobc21;
    /*!< fixobc22 black level value*/
    int32_t fixobc22;
    /*!< fixobc23 black level value*/
    int32_t fixobc23;
    /*!< fixobc30 black level value*/
    int32_t fixobc30;
    /*!< fixobc31 black level value*/
    int32_t fixobc31;
    /*!< fixobc32 black level value*/
    int32_t fixobc32;
    /*!< fixobc33 black level value*/
    int32_t fixobc33;

} ia_pal_isp_bxt_blc_t;

/*! \isp struct bxt_demosaic

*/
typedef struct
{
    /*!< bypass Block bypass for HW use*/
    int32_t bypass;
    /*!< frame_width Frame width*/
    int32_t frame_width;
    /*!< gammasg Sharpening coefficient*/
    int32_t gammasg;
    /*!< lcctrl Checkers removal control*/
    int32_t lcctrl;
    /*!< crparam1 High frequency denoise param1*/
    int32_t crparam1;
    /*!< crparam2 High frequency denoise param2*/
    int32_t crparam2;
    /*!< coringparam False color correction gain*/
    int32_t coringparam;
    /*!< char_en Checkers removal enable*/
    int32_t char_en;
    /*!< fcc_en False color correction enable*/
    int32_t fcc_en;
    /*!< car_en Chroam artifacts removal enable*/
    int32_t car_en;
    /*!< hfar_en High frequency aliasing reduction correction enable*/
    int32_t hfar_en;
    /*!< es_enable Edge smoothing enable*/
    int32_t es_enable;
    /*!< es_pow Edge smoohing enable.*/
    int32_t es_pow;
    /*!< diag_car_trade_off_th Diagonal regions protection param1*/
    int32_t diag_car_trade_off_th;
    /*!< diag_car_trade_off_slope Diagonal regions protection param2*/
    int32_t diag_car_trade_off_slope;
    /*!< stream_ylp_c Coefficient for the YLP for central element of 3x3 neighborhood*/
    int32_t stream_ylp_c;
    /*!< stream_ylp_p Coefficient for the YLP for peripheral element of 3x3 neighborhood*/
    int32_t stream_ylp_p;
    /*!< stream_ylp_d Coefficient for the YLP for diagonal element of 3x3 neighborhood*/
    int32_t stream_ylp_d;
    /*!< stream_ylp_mul_norm Coefficient for multiplier in YLP stream*/
    int32_t stream_ylp_mul_norm;
    /*!< stream_ylp_norm_shift Coefficient for YLP stream*/
    int32_t stream_ylp_norm_shift;
    /*!< configunitdiag1_x[2] CU_DIAG1 - x input*/
    int32_t configunitdiag1_x[2];
    /*!< configunitdiag2_x[2] CU_DIAG2 - x input*/
    int32_t configunitdiag2_x[2];
    /*!< configunitdiag3_x[2] CU_DIAG3 - x input*/
    int32_t configunitdiag3_x[2];
    /*!< configunitcar_sat_x[2] CU_CAR_SAT - x input*/
    int32_t configunitcar_sat_x[2];
    /*!< configunitdiag1_y[1] CU_DIAG1 - y input*/
    int32_t configunitdiag1_y[1];
    /*!< configunitdiag1_slope[1] CU_DIAG1 - slope input*/
    int32_t configunitdiag1_slope[1];
    /*!< configunitdiag2_y[1] CU_DIAG2 - y input*/
    int32_t configunitdiag2_y[1];
    /*!< configunitdiag2_slope[1] CU_DIAG2 - slope input*/
    int32_t configunitdiag2_slope[1];
    /*!< configunitdiag3_y[1] CU_DIAG3 - y input*/
    int32_t configunitdiag3_y[1];
    /*!< configunitdiag3_slope[1] CU_DIAG3 - slope input*/
    int32_t configunitdiag3_slope[1];
    /*!< configunitcar_sat_y[1] CU_CAR_SAT - y input*/
    int32_t configunitcar_sat_y[1];
    /*!< configunitcar_sat_slope[1] CU_CAR_SAT - slope input*/
    int32_t configunitcar_sat_slope[1];

} ia_pal_isp_bxt_demosaic_t;

/*! \isp struct cas_1_1

*/
typedef struct
{
    /*!< enable block enable*/
    int32_t enable;
    /*!< is_segmentation_aware SAP (Segmentation Aware Processing) enable*/
    int32_t is_segmentation_aware;
    /*!< x_center Optical center x*/
    int32_t x_center;
    /*!< y_center Optical center y*/
    int32_t y_center;
    /*!< x_start Starting column of the fragment.*/
    int32_t x_start;
    /*!< y_start Starting row of the fragment (Usualy will be 0)*/
    int32_t y_start;
    /*!< stats_collection_boundaries[2] columns where statitcis collection takes place*/
    int32_t stats_collection_boundaries[2];
    /*!< is_first_stripe is first stripe in frame*/
    int32_t is_first_stripe;
    /*!< is_last_stripe is last stripe in frame*/
    int32_t is_last_stripe;
    /*!< inv_spatial_model[16] Describes the inverse spatial noise*/
    int32_t inv_spatial_model[16];
    /*!< spatial_step_log2 log2 of spatial lut step size (value is derived from x_center and y_center. See spec for more details)*/
    int32_t spatial_step_log2;
    /*!< nm_lut[16] noise model for luma. Save&restore register (will be ovveride in video mode)*/
    int32_t nm_lut[16];
    /*!< apu_alpha_limit update mechanism in apu - as limit increases, we need more measurements for the histogram bins to be considered as reliable.*/
    int32_t apu_alpha_limit;
    /*!< apu_alpha_power update mechanism in apu - as power increase, we count more on the new val calculated then the one from previous frame.*/
    int32_t apu_alpha_power;
    /*!< hist_vals[256] histogram valuse of APU to flow between fragments. save and restore. 2D array of size 16*(2^(4))( HWP_APU_N_VALUES*(1<<HWP_APU_HIST_N_BINS_EXP)). precision is 20 (HWP_APU_HIST_BIN_BITTAGE)*/
    int32_t hist_vals[256];
    /*!< skin_sharp_suppression_power Suppress sharpening in human skin areas*/
    int32_t skin_sharp_suppression_power;
    /*!< signal_metric_low_th low threshold for normalizing signal metric map*/
    int32_t signal_metric_low_th;
    /*!< signal_metric_low_th_per_segment[16] low threshold for normalizing signal metric map per segment*/
    int32_t signal_metric_low_th_per_segment[16];
    /*!< signal_metric_slope slope for normalizing signal metric map*/
    int32_t signal_metric_slope;
    /*!< texture_noise_regulator detects less textures for higher values [0,0.2]*/
    int32_t texture_noise_regulator;
    /*!< texture_low_th low threshold for normalizing texture map. Values below this threshold will be consider as none texture.*/
    int32_t texture_low_th;
    /*!< texture_low_th_per_segment[16] low threshold for normalizing texture map. Values below this threshold will be consider as none texture. per segment*/
    int32_t texture_low_th_per_segment[16];
    /*!< texture_slope slope for normalizing texture map. This will be used to calculate the high threshold*/
    int32_t texture_slope;
    /*!< unsharpfilter[15] Unsharp-mask filter coefficients*/
    int32_t unsharpfilter[15];
    /*!< power_luma_control_enable enables the luma control mechanism*/
    int32_t power_luma_control_enable;
    /*!< cu_power_luma_control_x[4] x axis values for luma sharpening config-unit*/
    int32_t cu_power_luma_control_x[4];
    /*!< cu_power_luma_control_y[3] y axis values for luma sharpening config-unit*/
    int32_t cu_power_luma_control_y[3];
    /*!< cu_power_luma_control_slope[3] slope values for luma sharpening config-unit*/
    int32_t cu_power_luma_control_slope[3];
    /*!< power_spatial_control_th adapts the power sharpening to spatial location - this threshold is the distance from which the adaptation begins*/
    int32_t power_spatial_control_th;
    /*!< power_spatial_control_multiply_factor adapts the power sharpening to spatial location - this it the factor for the power sharpening in the periphrial regions.*/
    int32_t power_spatial_control_multiply_factor;
    /*!< power_spatial_control_slope adapts the power sharpening to spatial location - this slope is how fast the adaptation with respect to the distance from the center. In order to bypass spatial control mechanism assign this variable to 0*/
    int32_t power_spatial_control_slope;
    /*!< sharpening_power_texture Power of unsharp-mask sharpening for texture regions*/
    int32_t sharpening_power_texture;
    /*!< sharpening_power_texture_per_segment[16] Power of unsharp-mask sharpening for texture regions per segment*/
    int32_t sharpening_power_texture_per_segment[16];
    /*!< sharpening_power_edges Power of unsharp-mask sharpening for edges regions*/
    int32_t sharpening_power_edges;
    /*!< sharpening_power_edges_per_segment[16] Power of unsharp-mask sharpening for edges regions per segment*/
    int32_t sharpening_power_edges_per_segment[16];
    /*!< skin_uv_center[2] center of the UV ellipse in UV space*/
    int32_t skin_uv_center[2];
    /*!< skin_uv_ellipse[3] minor and major axis UV ellipse. Symetric matrix therfore reducing values to 3 instead of 4*/
    int32_t skin_uv_ellipse[3];
    /*!< skin_uv_low_th low threshold for normalizing non-skin area map. Values below this threshold will be consider as skin.*/
    int32_t skin_uv_low_th;
    /*!< skin_uv_slope slope for normalizing non-skin map. This will be used to calculate the high threshold*/
    int32_t skin_uv_slope;
    /*!< skin_smoothing blending factor for smooting human skin using the bilateral*/
    int32_t skin_smoothing;
    /*!< inv_denoise_power 0 - strong denoiser, 63 - weak denoiser*/
    int32_t inv_denoise_power;
    /*!< sort_low_undershoots Sorting low undershoots*/
    int32_t sort_low_undershoots;
    /*!< alfa_os controls edged overshoot. 0 - no overshoot allowed, 63 - max overshoot allowed*/
    int32_t alfa_os;
    /*!< alfa_os_per_segment[16] controls edged overshoot. 0 - no overshoot allowed, 63 - max overshoot allowed per segment*/
    int32_t alfa_os_per_segment[16];
    /*!< alfa_us controls edged undershoot. 0 - no undershoot allowed, 63 - max undershoot allowed*/
    int32_t alfa_us;
    /*!< alfa_us_per_segment[16] controls edged undershoot. 0 - no undershoot allowed, 63 - max undershoot allowed per segment*/
    int32_t alfa_us_per_segment[16];
    /*!< os_us_delta_compression_threshold overshood/undershood delta which exceed threshold will be compressed. 0-no OS/US allowed. 511-no OS/US clipping.*/
    int32_t os_us_delta_compression_threshold;
    /*!< saturated_color_shrap_suppression_th the sharpening for max(u,v) above this threshold wll be suppressed*/
    int32_t saturated_color_shrap_suppression_th;
    /*!< saturated_color_shrap_suppression_factor the sharpening for max(u,v) above threshold wll be suppressed by this factor*/
    int32_t saturated_color_shrap_suppression_factor;
    /*!< os_us_delta_compression_factor overshoot / undershoot compression factor*/
    int32_t os_us_delta_compression_factor;
    /*!< conf_low_th the minimum number of samples consider reliable for APU estimation*/
    int32_t conf_low_th;
    /*!< conf_slope slope for normalizing confidence map. This will be used to calculate the high threshold*/
    int32_t conf_slope;

} ia_pal_isp_cas_1_1_t;

/*! \isp struct ccm_3a_2_0
AE color correction
*/
typedef struct
{
    /*!< gain_cx[8] WB coefficients*/
    int32_t gain_cx[8];
    /*!< m_1x[4] CCM matrix coefficients M11 - M14 (-4..4)*/
    int32_t m_1x[4];
    /*!< m_2x[4] CCM matrix coefficients M21 - M24 (-4..4)*/
    int32_t m_2x[4];
    /*!< m_3x[4] CCM matrix coefficients M21 - M24 (-4..4)*/
    int32_t m_3x[4];
    /*!< c_x[4] Y-calc matrix coefficients C01 - C04*/
    int32_t c_x[4];
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;
    /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_00;
    /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_01;
    /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_02;
    /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_03;
    /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_10;
    /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_11;
    /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_12;
    /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_13;
    /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_20;
    /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_21;
    /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_22;
    /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_23;
    /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_30;
    /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_31;
    /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_32;
    /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_33;

} ia_pal_isp_ccm_3a_2_0_t;

/*! \isp struct crop_bpp_adjust_1_0

*/
typedef struct
{
    /*!< enable enables the filter, if disabled the input is replicated to output*/
    int32_t enable;
    /*!< crop_left Number of pixel to crop on the left of the image*/
    int32_t crop_left;
    /*!< crop_right Number of pixel to crop on the right of the image*/
    int32_t crop_right;
    /*!< crop_top Number of pixel to crop on the top of the image*/
    int32_t crop_top;
    /*!< crop_bottom Number of pixel to crop on the bottom of the image*/
    int32_t crop_bottom;
    /*!< bpp_input Input bpp: 1 - 8 bit, 2 - 10 bit, 3 - 12 bit*/
    int32_t bpp_input;

} ia_pal_isp_crop_bpp_adjust_1_0_t;

/*! \isp struct csc_1_1

*/
typedef struct
{
    /*!< m_csc_c_matrix_arr[9] CSC Matrix components (S0.14)*/
    int32_t m_csc_c_matrix_arr[9];
    /*!< m_csc_b_vec_arr[3] CSC Vector components (S0.13)*/
    int32_t m_csc_b_vec_arr[3];
    /*!< m_chroma_ds_coeff_arr[8] Chroma downsample 4x2 filter coefficients (U2.0)*/
    int32_t m_chroma_ds_coeff_arr[8];
    /*!< m_chroma_ds_nf Chroma downsample 4x2 filter normalization factor*/
    int32_t m_chroma_ds_nf;
    /*!< m_bypass Bypassing CSC. Outputting RGB to the Chroma downscale*/
    int32_t m_bypass;
    /*!< m_uv_bin_output 0 = YUV4:2:0 output, 1 = YUV4:2:2 output*/
    int32_t m_uv_bin_output;

} ia_pal_isp_csc_1_1_t;

/*! \isp struct dol_lite_1_2

*/
typedef struct
{
    /*!< smthnrm_slope[4] estimated short-smoothed normalization coefficient*/
    int32_t smthnrm_slope[4];
    /*!< smthnrm_slope_user[4] estimated short-smoothed normalization coefficient - user override*/
    int32_t smthnrm_slope_user[4];
    /*!< etr_slope[4] estimated ETR coefficient*/
    int32_t etr_slope[4];
    /*!< etr_slope_user[4] estimated ETR coefficient - user override*/
    int32_t etr_slope_user[4];
    /*!< smthnrm_bias[4] estimated short-smoothed normalization bias*/
    int32_t smthnrm_bias[4];
    /*!< smthnrm_bias_user[4] estimated short-smoothed normalization bias - user override*/
    int32_t smthnrm_bias_user[4];
    /*!< etr_bias[4] estimated ETR bias*/
    int32_t etr_bias[4];
    /*!< etr_bias_user[4] estimated ETR bias - user override*/
    int32_t etr_bias_user[4];
    /*!< deghost_bias deghost indicator constant*/
    int32_t deghost_bias;
    /*!< deghost_coeff deghost indicator coefficient*/
    int32_t deghost_coeff;
    /*!< short_is_invalid If on, the blend is 100% long exposure (back door)*/
    int32_t short_is_invalid;
    /*!< max_use_long Max use of long exposure in the output blend*/
    int32_t max_use_long;
    /*!< update_limit Limit of S&R parameter update mechanism*/
    int32_t update_limit;
    /*!< update_coeff S&R parameter update coefficient*/
    int32_t update_coeff;
    /*!< d_ml[32] Maximum-likelihood of distance distribution*/
    int32_t d_ml[32];
    /*!< outofbounds[32] is ML value out of histogram bounds?*/
    int32_t outofbounds[32];
    /*!< is_first_stripe If first stripe in frame*/
    int32_t is_first_stripe;
    /*!< is_last_stripe Iflast stripe in frame*/
    int32_t is_last_stripe;
    /*!< is_first_frame If first frame*/
    int32_t is_first_frame;
    /*!< is_steady_state if change in S&R values is small, apply strong temporal smoothing*/
    int32_t is_steady_state;
    /*!< long_saturation_bias saturation indicator constant*/
    int32_t long_saturation_bias;
    /*!< long_saturation_full saturation indicator full value*/
    int32_t long_saturation_full;
    /*!< long_saturation_coeff saturation indicator coefficient*/
    int32_t long_saturation_coeff;
    /*!< long_saturation_transition relative width of transition between fully saturated and unsaturated*/
    int32_t long_saturation_transition;
    /*!< long_saturation_tracking enable tracking of long-exposure saturation based on noise model*/
    int32_t long_saturation_tracking;
    /*!< etr_estim_enable enable online ETR estimation*/
    int32_t etr_estim_enable;
    /*!< etr_load_user read ETR info from user instead of S&R*/
    int32_t etr_load_user;
    /*!< wb_gains[4] white-balance gains for curr frame*/
    int32_t wb_gains[4];
    /*!< wb_gains_prev[4] white-balance gains from prev frame*/
    int32_t wb_gains_prev[4];
    /*!< pedestal_out output pedestal level*/
    int32_t pedestal_out;
    /*!< shrt_smth_padding_top shrt-smth padding on top*/
    int32_t shrt_smth_padding_top;
    /*!< shrt_smth_padding_lft shrt-smth padding on left*/
    int32_t shrt_smth_padding_lft;
    /*!< black_level[4] black level*/
    int32_t black_level[4];
    /*!< short_denoise_power use of denoised short-exposure in blend*/
    int32_t short_denoise_power;
    /*!< short_denoise_sensitivity denoise bilateral sensitivity*/
    int32_t short_denoise_sensitivity;
    /*!< three_input_mode enable third input (pre-processed short)*/
    int32_t three_input_mode;
    /*!< psve_gains_short[4] PSVE output - gains for short exposure*/
    int32_t psve_gains_short[4];
    /*!< psve_bias_short[4] PSVE output - black level for short exposure*/
    int32_t psve_bias_short[4];
    /*!< psve_gains_long[4] PSVE output - gains for long exposure*/
    int32_t psve_gains_long[4];
    /*!< psve_bias_long[4] PSVE output - black level for long exposure*/
    int32_t psve_bias_long[4];
    /*!< psve_long_max_val PSVE output - max-val for long exposure*/
    int32_t psve_long_max_val;
    /*!< enable block enable*/
    int32_t enable;
    /*!< stats_collection_boundaries[2] columns where statitcis collection takes place (half res)*/
    int32_t stats_collection_boundaries[2];
    /*!< acc_histogram[512] accumulator for APU*/
    int32_t acc_histogram[512];
    /*!< acc_etr_in[8] accumulator for ETR estimation - in*/
    int32_t acc_etr_in[8];
    /*!< acc_etr_out[8] accumulator for ETR estimation - out*/
    int32_t acc_etr_out[8];
    /*!< acc_etr_in_sq[8] accumulator for ETR estimation - in x in*/
    int32_t acc_etr_in_sq[8];
    /*!< acc_etr_inout[8] accumulator for ETR estimation - in x out*/
    int32_t acc_etr_inout[8];
    /*!< acc_etr_sow[8] accumulator for ETR estimation - sum of weights*/
    int32_t acc_etr_sow[8];
    /*!< acc_smthnrm_in[8] accumulator for SmthNrm estimation - in*/
    int32_t acc_smthnrm_in[8];
    /*!< acc_smthnrm_out[8] accumulator for SmthNrm estimation - out*/
    int32_t acc_smthnrm_out[8];
    /*!< acc_smthnrm_in_sq[8] accumulator for SmthNrm estimation - in x in*/
    int32_t acc_smthnrm_in_sq[8];
    /*!< acc_smthnrm_inout[8] accumulator for SmthNrm estimation - in x out*/
    int32_t acc_smthnrm_inout[8];
    /*!< acc_smthnrm_sow[8] accumulator for SmthNrm estimation - sum of weights*/
    int32_t acc_smthnrm_sow[8];

} ia_pal_isp_dol_lite_1_2_t;

/*! \isp struct dpc_2_2

*/
typedef struct
{
    /*!< afxoffset[32] 8 Autofocus pixels X axis offset U14.0, should be smaller than afxperiod*/
    int32_t afxoffset[32];
    /*!< afxperiod[32] 8 Autofocus pixels X axis period*/
    int32_t afxperiod[32];
    /*!< afyoffset[32] 8 Autofocus pixels Y axis offset U14.0, should be smaller than afyperiod*/
    int32_t afyoffset[32];
    /*!< afyperiod[32] 8 Autofocus pixels Y axis period*/
    int32_t afyperiod[32];
    /*!< hdrfactors[16] 4x4 HDR exposure factor U6.8*/
    int32_t hdrfactors[16];
    /*!< hdrfactorsinverse[16] 4x4 HDR exposure inverse factor U6.8 - should be inverse of hdrfactors*/
    int32_t hdrfactorsinverse[16];
    /*!< configunitcolddistvsmedian_slope[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_slope[7];
    /*!< configunitcolddistvsmedian_x[8] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_x[8];
    /*!< configunitcolddistvsmedian_y[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_y[7];
    /*!< configunitcolddistvsneighb_slope[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_slope[7];
    /*!< configunitcolddistvsneighb_x[8] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_x[8];
    /*!< configunitcolddistvsneighb_y[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_y[7];
    /*!< configunitfix_slope[3] fix config unit*/
    int32_t configunitfix_slope[3];
    /*!< configunitfix_x[4] fix config unit*/
    int32_t configunitfix_x[4];
    /*!< configunitfix_y[3] fix config unit*/
    int32_t configunitfix_y[3];
    /*!< configunithotdistvsmedian_slope[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_slope[7];
    /*!< configunithotdistvsmedian_x[8] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_x[8];
    /*!< configunithotdistvsmedian_y[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_y[7];
    /*!< configunithotdistvsneighb_slope[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_slope[7];
    /*!< configunithotdistvsneighb_x[8] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_x[8];
    /*!< configunithotdistvsneighb_y[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_y[7];
    /*!< pelesttype[16] 0-P1, 1-P2, 2-P3, 3-P4, 4-P5, 5-P6*/
    int32_t pelesttype[16];
    /*!< dtype[16] 0-D1 1-D2  2-D3*/
    int32_t dtype[16];
    /*!< pmasks[384] configurations related to the bayer pattern*/
    int32_t pmasks[384];
    /*!< dmasks[48] configurations related to the bayer pattern*/
    int32_t dmasks[48];
    /*!< bitreduceshift Shift value for bit reduce block*/
    int32_t bitreduceshift;
    /*!< afenable enable for the AF unit block*/
    int32_t afenable;
    /*!< dynamicenable enable for the dynamic detection block*/
    int32_t dynamicenable;
    /*!< frame_width frame width*/
    int32_t frame_width;
    /*!< paf_grid_en[32] paf grid enables*/
    int32_t paf_grid_en[32];
    /*!< paf_pattern_rearrangement_en Enable pattern rearrangement unit after AF Pels detection*/
    int32_t paf_pattern_rearrangement_en;
    /*!< afsXStart AF pixel detection crop - start X position*/
    int32_t afsXStart;
    /*!< afsYStart AF pixel detection crop - start Y position*/
    int32_t afsYStart;
    /*!< afsXEnd AF pixel detection crop - end X position*/
    int32_t afsXEnd;
    /*!< afsYEnd AF pixel detection crop - end Y position*/
    int32_t afsYEnd;
    /*!< afsXStartCropEn AF pixel crop enable - start X position*/
    int32_t afsXStartCropEn;
    /*!< afsYStartCropEn AF pixel crop enable - start Y position*/
    int32_t afsYStartCropEn;
    /*!< afsXEndCropEn AF pixel crop enable - end X position*/
    int32_t afsXEndCropEn;
    /*!< afsYEndCropEn AF pixel crop enable - end Y position*/
    int32_t afsYEndCropEn;
    /*!< use_nlm[16] use non local means mechanism*/
    int32_t use_nlm[16];
    /*!< sad1_thr threshold on the first sad*/
    int32_t sad1_thr;
    /*!< sad2_thr threshold on the second sad*/
    int32_t sad2_thr;
    /*!< pixel_diff_thr threshold on the pixel difference*/
    int32_t pixel_diff_thr;
    /*!< min_direction_sad_thr threshold on the min direction*/
    int32_t min_direction_sad_thr;
    /*!< max_direction_sad_thr threshold on the max direction*/
    int32_t max_direction_sad_thr;
    /*!< saturation_thr protect pixels in saturated areas*/
    int32_t saturation_thr;
    /*!< ignore_ver_direction[16] ignore vertical direction for certain types of pdaf sensors*/
    int32_t ignore_ver_direction[16];
    /*!< configunit_med_protection_slope[3] nlm fix config unit*/
    int32_t configunit_med_protection_slope[3];
    /*!< configunit_med_protection_x[4] nlm fix config unit*/
    int32_t configunit_med_protection_x[4];
    /*!< configunit_med_protection_y[3] nlm fix config unit*/
    int32_t configunit_med_protection_y[3];
    /*!< clamping_disable disable clamping to support previous version of dpc*/
    int32_t clamping_disable;
    /*!< sensor_type 0=simple_bayer 1=2pd 2=sve_2pd 3=sve_zigzag1 4=sve_zigzag2*/
    int32_t sensor_type;
    /*!< fix_dist when 0 - opposite sign distances around the pixel are ignored*/
    int32_t fix_dist;
    /*!< flip_neigb_axis flip neigb vs dist axis*/
    int32_t flip_neigb_axis;
    /*!< g_locations_for_sve[16] g on 4x4 grid*/
    int32_t g_locations_for_sve[16];
    /*!< config_median_blend_slope[3] blend coef cfg*/
    int32_t config_median_blend_slope[3];
    /*!< config_median_blend_x[4] blend coef cfg*/
    int32_t config_median_blend_x[4];
    /*!< config_median_blend_y[3] blend coef cfg*/
    int32_t config_median_blend_y[3];
    /*!< config_ridges_slope[3] ridge coef cfg*/
    int32_t config_ridges_slope[3];
    /*!< config_ridges_x[4] ridge coef cfg*/
    int32_t config_ridges_x[4];
    /*!< config_ridges_y[3] ridge coef cfg*/
    int32_t config_ridges_y[3];
    /*!< dpc_enable dpc enable*/
    int32_t dpc_enable;

} ia_pal_isp_dpc_2_2_t;

/*! \isp struct fr_grid_1_0
FR Statistics
*/
typedef struct
{
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128,256)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128,256)*/
    int32_t block_height;
    /*!< y_fr_en 0: FF will not write to the Y  array; 1: FF will write  to the Y  array*/
    int32_t y_fr_en;
    /*!< x_start X top left corner of the grid*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid*/
    int32_t y_end;
    /*!< shftr_val_x[4] Log2(num pixels of estimated colour component in a block). The binding as follows: m_ShftR_val_Y00 = shftr_val_x[0]; m_ShftR_val_Y01 = shftr_val_x[1];m_ShftR_val_Y10 = shftr_val_x[2];m_ShftR_val_Y11 = shftr_val_x[3];*/
    int32_t shftr_val_x[4];
    /*!< gx_0[4] gx0 Y_calc contribution ratio for Pat_ij*/
    int32_t gx_0[4];
    /*!< gx_1[4] gx1 Y_calc contribution ratio for Pat_ij*/
    int32_t gx_1[4];
    /*!< gx_2[4] gx2 Y_calc contribution ratio for Pat_ij*/
    int32_t gx_2[4];
    /*!< gx_3[4] gx3 Y_calc contribution ratio for Pat_ij*/
    int32_t gx_3[4];
    /*!< mask_y0 selecting the relevant pixels for Y0; bit k = row * 4 + column*/
    int32_t mask_y0;
    /*!< mask_y1 selecting the relevant pixels for Y1; bit k = row * 4 + column*/
    int32_t mask_y1;
    /*!< oe_y0 output enable for Y0; bit k corresponds to row * 2 + column*/
    int32_t oe_y0;
    /*!< oe_y1 output enable for Y1; bit k corresponds to row * 2 + column*/
    int32_t oe_y1;
    /*!< on_x_y0[4] Y0 estimation normalization (00, 01, 10, 11)*/
    int32_t on_x_y0[4];
    /*!< on_x_y1[4] Y1 estimation normalization (00, 01, 10, 11)*/
    int32_t on_x_y1[4];
    /*!< y00_filter_coeff[6] filter coefficients for Y00 (A1, A2, A3, A4, A5, A6)*/
    int32_t y00_filter_coeff[6];
    /*!< y00_filter_sign_vec sign vector for Y00*/
    int32_t y00_filter_sign_vec;
    /*!< y01_filter_coeff[6] filter coefficients for Y01 (A1, A2, A3, A4, A5, A6)*/
    int32_t y01_filter_coeff[6];
    /*!< y01_filter_sign_vec sign vector for Y01*/
    int32_t y01_filter_sign_vec;
    /*!< y10_filter_coeff[6] filter coefficients for Y10 (A1, A2, A3, A4, A5, A6)*/
    int32_t y10_filter_coeff[6];
    /*!< y10_filter_sign_vec sign vector for Y10*/
    int32_t y10_filter_sign_vec;
    /*!< y11_filter_coeff[6] filter coefficients for Y11 (A1, A2, A3, A4, A5, A6)*/
    int32_t y11_filter_coeff[6];
    /*!< y11_filter_sign_vec sign vector for Y11*/
    int32_t y11_filter_sign_vec;
    /*!< nf_x[4] Filter response normalization factors for Y00, Y01, Y10, Y11*/
    int32_t nf_x[4];
    /*!< sensor_mode Sensor mode 0: 1x1,  1: 2x2, 2: 4x4*/
    int32_t sensor_mode;
    /*!< downscaling_factor Downscaling factor 0: 1x, 1: 2x, 2: 4x*/
    int32_t downscaling_factor;
    /*!< y00_blending_weight Median filter weight for Y00*/
    int32_t y00_blending_weight;
    /*!< y01_blending_weight Median filter weight for Y01*/
    int32_t y01_blending_weight;
    /*!< y10_blending_weight Median filter weight for Y10*/
    int32_t y10_blending_weight;
    /*!< y11_blending_weight Median filter weight for Y11*/
    int32_t y11_blending_weight;

} ia_pal_isp_fr_grid_1_0_t;

/*! \isp struct gammatm_v4

*/
typedef struct
{
    /*!< enable enable for the filter*/
    int32_t enable;
    /*!< a1 shift amount at stage 1*/
    int32_t a1;
    /*!< a2 shift amount at stage 2*/
    int32_t a2;
    /*!< a3 shift amount at stage 3 (output bpp adaptation)*/
    int32_t a3;
    /*!< gamma_lut_enable enable for gamma lut*/
    int32_t gamma_lut_enable;
    /*!< gamma_lut_base_level[8] base level for gamma lut*/
    int32_t gamma_lut_base_level[8];
    /*!< gamma_lut_step[8] step for gamma lut*/
    int32_t gamma_lut_step[8];
    /*!< gamma_lut_start_bin[8] start bin for gamma lut*/
    int32_t gamma_lut_start_bin[8];
    /*!< gamma_lut_size gamma lut size*/
    int32_t gamma_lut_size;
    /*!< gamma_lut_gen_lut[1537] generalized lut for gamma lut*/
    int32_t gamma_lut_gen_lut[1537];
    /*!< tm_lut_enable enable for tone mapping lut*/
    int32_t tm_lut_enable;
    /*!< tm_lut_base_level[3] base level for  tone mapping lut*/
    int32_t tm_lut_base_level[3];
    /*!< tm_lut_step[3] step for  tone mapping lut*/
    int32_t tm_lut_step[3];
    /*!< tm_lut_start_bin[3] start bin for  tone mapping lut*/
    int32_t tm_lut_start_bin[3];
    /*!< tm_lut_size tone mapping lut size*/
    int32_t tm_lut_size;
    /*!< tm_lut_gen_lut[2049] generalized lut for tone mapping lut*/
    int32_t tm_lut_gen_lut[2049];
    /*!< a polynomial chromaticity model degree*/
    int32_t a;
    /*!< b color saturation in highlights*/
    int32_t b;
    /*!< c overall color desaturation*/
    int32_t c;

} ia_pal_isp_gammatm_v4_t;

/*! \isp struct gd_2_2

*/
typedef struct
{
    /*!< green_pos gb position*/
    int32_t green_pos;
    /*!< lc_cu_x[4] local contrast config unit x*/
    int32_t lc_cu_x[4];
    /*!< lc_cu_y[3] local contrast config unit y*/
    int32_t lc_cu_y[3];
    /*!< lc_cu_slope[3] local contrast config unit slope*/
    int32_t lc_cu_slope[3];
    /*!< delta_cu_x[4] delta config unit x*/
    int32_t delta_cu_x[4];
    /*!< delta_cu_y[3] delta config unit y*/
    int32_t delta_cu_y[3];
    /*!< delta_cu_slope[3] delta config unit slope*/
    int32_t delta_cu_slope[3];
    /*!< inv_lc_cu_x[8] inverse local contarst config unit x*/
    int32_t inv_lc_cu_x[8];
    /*!< inv_lc_cu_y[7] inverse local contarst config unit y*/
    int32_t inv_lc_cu_y[7];
    /*!< inv_lc_cu_slope[7] inverse local contarst config unit slope*/
    int32_t inv_lc_cu_slope[7];
    /*!< inv_delta_cu_x[8] inverse delta config unit x*/
    int32_t inv_delta_cu_x[8];
    /*!< inv_delta_cu_y[7] inverse delta config unit y*/
    int32_t inv_delta_cu_y[7];
    /*!< inv_delta_cu_slope[7] inverse delta config unit slope*/
    int32_t inv_delta_cu_slope[7];
    /*!< detail_pres detail preservation factor*/
    int32_t detail_pres;
    /*!< invscale scale factor after normalizing by inverse*/
    int32_t invscale;
    /*!< gdc_enable gdc enable*/
    int32_t gdc_enable;

} ia_pal_isp_gd_2_2_t;

/*! \isp struct gd_dpc_2_1

*/
typedef struct
{
    /*!< green_pos gb position*/
    int32_t green_pos;
    /*!< lc_cu_x[4] local contrast config unit x*/
    int32_t lc_cu_x[4];
    /*!< lc_cu_y[3] local contrast config unit y*/
    int32_t lc_cu_y[3];
    /*!< lc_cu_slope[3] local contrast config unit slope*/
    int32_t lc_cu_slope[3];
    /*!< delta_cu_x[4] delta config unit x*/
    int32_t delta_cu_x[4];
    /*!< delta_cu_y[3] delta config unit y*/
    int32_t delta_cu_y[3];
    /*!< delta_cu_slope[3] delta config unit slope*/
    int32_t delta_cu_slope[3];
    /*!< inv_lc_cu_x[8] inverse local contarst config unit x*/
    int32_t inv_lc_cu_x[8];
    /*!< inv_lc_cu_y[7] inverse local contarst config unit y*/
    int32_t inv_lc_cu_y[7];
    /*!< inv_lc_cu_slope[7] inverse local contarst config unit slope*/
    int32_t inv_lc_cu_slope[7];
    /*!< inv_delta_cu_x[8] inverse delta config unit x*/
    int32_t inv_delta_cu_x[8];
    /*!< inv_delta_cu_y[7] inverse delta config unit y*/
    int32_t inv_delta_cu_y[7];
    /*!< inv_delta_cu_slope[7] inverse delta config unit slope*/
    int32_t inv_delta_cu_slope[7];
    /*!< detail_pres detail preservation factor*/
    int32_t detail_pres;
    /*!< invscale scale factor after normalizing by inverse*/
    int32_t invscale;
    /*!< afxoffset[32] 8 Autofocus pixels X axis offset U14.0, should be smaller than afxperiod*/
    int32_t afxoffset[32];
    /*!< afxperiod[32] 8 Autofocus pixels X axis period*/
    int32_t afxperiod[32];
    /*!< afyoffset[32] 8 Autofocus pixels Y axis offset U14.0, should be smaller than afyperiod*/
    int32_t afyoffset[32];
    /*!< afyperiod[32] 8 Autofocus pixels Y axis period*/
    int32_t afyperiod[32];
    /*!< hdrfactors[16] 4x4 HDR exposure factor U6.8*/
    int32_t hdrfactors[16];
    /*!< hdrfactorsinverse[16] 4x4 HDR exposure inverse factor U6.8 - should be inverse of hdrfactors*/
    int32_t hdrfactorsinverse[16];
    /*!< configunitcolddistvsmedian_slope[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_slope[7];
    /*!< configunitcolddistvsmedian_x[8] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_x[8];
    /*!< configunitcolddistvsmedian_y[7] cold dist vs median config unit classifier*/
    int32_t configunitcolddistvsmedian_y[7];
    /*!< configunitcolddistvsneighb_slope[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_slope[7];
    /*!< configunitcolddistvsneighb_x[8] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_x[8];
    /*!< configunitcolddistvsneighb_y[7] cold dist vs neigb config unit classifier*/
    int32_t configunitcolddistvsneighb_y[7];
    /*!< configunitfix_slope[3] fix config unit*/
    int32_t configunitfix_slope[3];
    /*!< configunitfix_x[4] fix config unit*/
    int32_t configunitfix_x[4];
    /*!< configunitfix_y[3] fix config unit*/
    int32_t configunitfix_y[3];
    /*!< configunithotdistvsmedian_slope[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_slope[7];
    /*!< configunithotdistvsmedian_x[8] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_x[8];
    /*!< configunithotdistvsmedian_y[7] hot dist vs median classifier*/
    int32_t configunithotdistvsmedian_y[7];
    /*!< configunithotdistvsneighb_slope[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_slope[7];
    /*!< configunithotdistvsneighb_x[8] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_x[8];
    /*!< configunithotdistvsneighb_y[7] hot dist vs neigb config unit classifier*/
    int32_t configunithotdistvsneighb_y[7];
    /*!< pelesttype[16] 0-P1, 1-P2, 2-P3, 3-P4, 4-P5, 5-P6*/
    int32_t pelesttype[16];
    /*!< dtype[16] 0-D1 1-D2  2-D3*/
    int32_t dtype[16];
    /*!< pmasks[384] configurations related to the bayer pattern*/
    int32_t pmasks[384];
    /*!< dmasks[48] configurations related to the bayer pattern*/
    int32_t dmasks[48];
    /*!< bitreduceshift Shift value for bit reduce block*/
    int32_t bitreduceshift;
    /*!< afenable enable for the AF unit block*/
    int32_t afenable;
    /*!< dynamicenable enable for the dynamic detection block*/
    int32_t dynamicenable;
    /*!< frame_width frame width*/
    int32_t frame_width;
    /*!< paf_grid_en[32] paf grid enables*/
    int32_t paf_grid_en[32];
    /*!< paf_pattern_rearrangement_en Enable pattern rearrangement unit after AF Pels detection*/
    int32_t paf_pattern_rearrangement_en;
    /*!< afsXStart AF pixel detection crop - start X position*/
    int32_t afsXStart;
    /*!< afsYStart AF pixel detection crop - start Y position*/
    int32_t afsYStart;
    /*!< afsXEnd AF pixel detection crop - end X position*/
    int32_t afsXEnd;
    /*!< afsYEnd AF pixel detection crop - end Y position*/
    int32_t afsYEnd;
    /*!< afsXStartCropEn AF pixel crop enable - start X position*/
    int32_t afsXStartCropEn;
    /*!< afsYStartCropEn AF pixel crop enable - start Y position*/
    int32_t afsYStartCropEn;
    /*!< afsXEndCropEn AF pixel crop enable - end X position*/
    int32_t afsXEndCropEn;
    /*!< afsYEndCropEn AF pixel crop enable - end Y position*/
    int32_t afsYEndCropEn;
    /*!< use_nlm[16] use non local means mechanism*/
    int32_t use_nlm[16];
    /*!< sad1_thr threshold on the first sad*/
    int32_t sad1_thr;
    /*!< sad2_thr threshold on the second sad*/
    int32_t sad2_thr;
    /*!< pixel_diff_thr threshold on the pixel difference*/
    int32_t pixel_diff_thr;
    /*!< min_direction_sad_thr threshold on the min direction*/
    int32_t min_direction_sad_thr;
    /*!< max_direction_sad_thr threshold on the max direction*/
    int32_t max_direction_sad_thr;
    /*!< saturation_thr protect pixels in saturated areas*/
    int32_t saturation_thr;
    /*!< ignore_ver_direction[16] ignore vertical direction for certain types of pdaf sensors*/
    int32_t ignore_ver_direction[16];
    /*!< configunit_med_protection_slope[3] nlm fix config unit*/
    int32_t configunit_med_protection_slope[3];
    /*!< configunit_med_protection_x[4] nlm fix config unit*/
    int32_t configunit_med_protection_x[4];
    /*!< configunit_med_protection_y[3] nlm fix config unit*/
    int32_t configunit_med_protection_y[3];
    /*!< clamping_disable disable clamping to support previous version of dpc*/
    int32_t clamping_disable;
    /*!< sensor_type 0=simple_bayer 1=2pd 2=sve_2pd 3=sve_zigzag1 4=sve_zigzag2*/
    int32_t sensor_type;
    /*!< fix_dist when 0 - opposite sign distances around the pixel are ignored*/
    int32_t fix_dist;
    /*!< flip_neigb_axis flip neigb vs dist axis*/
    int32_t flip_neigb_axis;
    /*!< g_locations_for_sve[16] g on 4x4 grid*/
    int32_t g_locations_for_sve[16];
    /*!< config_median_blend_slope[3] blend coef cfg*/
    int32_t config_median_blend_slope[3];
    /*!< config_median_blend_x[4] blend coef cfg*/
    int32_t config_median_blend_x[4];
    /*!< config_median_blend_y[3] blend coef cfg*/
    int32_t config_median_blend_y[3];
    /*!< config_ridges_slope[3] ridge coef cfg*/
    int32_t config_ridges_slope[3];
    /*!< config_ridges_x[4] ridge coef cfg*/
    int32_t config_ridges_x[4];
    /*!< config_ridges_y[3] ridge coef cfg*/
    int32_t config_ridges_y[3];
    /*!< global_enable global enable*/
    int32_t global_enable;
    /*!< gdc_enable gdc enable*/
    int32_t gdc_enable;
    /*!< dpc_enable dpc enable*/
    int32_t dpc_enable;

} ia_pal_isp_gd_dpc_2_1_t;

/*! \isp struct gdc7

*/
typedef struct
{
    /*!< gdc_coord_enable coord calculation bypass*/
    int32_t gdc_coord_enable;
    /*!< crop_top Top border for cropping*/
    int32_t crop_top;
    /*!< crop_left Left border for cropping*/
    int32_t crop_left;
    /*!< crop_bottom Bottom border for cropping*/
    int32_t crop_bottom;
    /*!< crop_right Right border for cropping*/
    int32_t crop_right;
    /*!< homography_transformation_luma_0[64] homography transformation matrices for luma channel,  1, 2, 4, 5. elements S4.18,*/
    int32_t homography_transformation_luma_0[64];
    /*!< homography_transformation_luma_1[32] homography transformation matrices for luma channel,  7. and 8. S0.31 but only 25 lower bits used*/
    int32_t homography_transformation_luma_1[32];
    /*!< homography_transformation_luma_2[48] homography transformation matrices for luma channel, 3, 6, 9. S18.13*/
    int32_t homography_transformation_luma_2[48];
    /*!< homography_matrices_offset[16] Offsets from the top for homography matrices*/
    int32_t homography_matrices_offset[16];
    /*!< homography_matrices_count number of homography matrices*/
    int32_t homography_matrices_count;
    /*!< ldc_r_lut[256] LDC (R) LUT table, format Q14.16*/
    int32_t ldc_r_lut[256];
    /*!< gdc_modep 0:Homography/Projections/LDC/PostAffine, 1:Homography/Projections/Rotation/LDC/PostAffine, 2:Homography/Projections/Rotation/PostAffine*/
    int32_t gdc_modep;
    /*!< rotationmatrix[9] Rotational Matrix for applying rotation (S1.20)*/
    int32_t rotationmatrix[9];
    /*!< projectionsf_1[2] Scaling factor for Projections. (Elements 1 and 2 of scaling factor: S4.20)*/
    int32_t projectionsf_1[2];
    /*!< projectionsf_2[2] Scaling factor for Projections. (Elements 3 and 4 of scaling factor: S14.8)*/
    int32_t projectionsf_2[2];
    /*!< projection_type 0: Rectilinear, 1: Conic, 2: Equirectangular, 3: 2D Bowl*/
    int32_t projection_type;
    /*!< projections_inv_f_pi Inv_f_pi = (1/f*pi) where f corresponds to View_Width/HFOV (Q0.31)*/
    int32_t projections_inv_f_pi;
    /*!< ldc_max_a Maximum distance from the radial center from the full sensor resolution. Q3.16*/
    int32_t ldc_max_a;
    /*!< ldc_inv_max_a Inv of ldc_max_a, Q0.26*/
    int32_t ldc_inv_max_a;
    /*!< ldc_lut_shift_bits LDC LUT Shift bits*/
    int32_t ldc_lut_shift_bits;
    /*!< postaffine_matrix_scale[4] PostAffine Matrix for scale S4.15*/
    int32_t postaffine_matrix_scale[4];
    /*!< postaffine_matrix_translation[2] PostAffine Matrix for translation integer value S18.8*/
    int32_t postaffine_matrix_translation[2];
    /*!< invalid_coord_mask[3] Invalid Coordinate Mask to be set. Default value set is for 8 bits.*/
    int32_t invalid_coord_mask[3];
    /*!< translation3d[3] 3D translation for bowl projection (S14.8)*/
    int32_t translation3d[3];
    /*!< bowl_radius_sqr_2d 2D Bowl Radius Square (Q28.0)*/
    int32_t bowl_radius_sqr_2d;
    /*!< bowl_scale_2d 2D Bowl Scale Value (Q0.31)*/
    int32_t bowl_scale_2d;
    /*!< IRS_interpolation_enable Use NN for interpolation*/
    int32_t IRS_interpolation_enable;
    /*!< input_height input image height*/
    int32_t input_height;
    /*!< input_width input image width*/
    int32_t input_width;
    /*!< GDC_SP_coord_conv_enable GDC SP 1:4 coord conversion mechanism*/
    int32_t GDC_SP_coord_conv_enable;
    /*!< max_distortion_reporting_enable Report position within input image of last processed row for internal rolling buffer support 0-off, 1-on*/
    int32_t max_distortion_reporting_enable;
    /*!< max_distortion Maximum lens distortion in input image domain, which defines stagger of last processed input row relative to output row*/
    int32_t max_distortion;

} ia_pal_isp_gdc7_t;

/*! \isp struct gdc7_1

*/
typedef struct
{
    /*!< grid_x[16384] grid x coordinate*/
    int32_t grid_x[16384];
    /*!< grid_y[16384] grid y coordinate*/
    int32_t grid_y[16384];
    /*!< grid_height grid height*/
    int32_t grid_height;
    /*!< grid_width grid width*/
    int32_t grid_width;
    /*!< input_height input image height*/
    int32_t input_height;
    /*!< input_width input image width*/
    int32_t input_width;
    /*!< grid_scale scale to convert from int value to floating point*/
    int32_t grid_scale;
    /*!< output_bpp output image bit per pixel*/
    int32_t output_bpp;
    /*!< output_height output image height*/
    int32_t output_height;
    /*!< output_width output image width*/
    int32_t output_width;
    /*!< mask_val_y Masking value for out of picture reference*/
    int32_t mask_val_y;
    /*!< mask_val_u Masking value for out of picture reference*/
    int32_t mask_val_u;
    /*!< mask_val_v Masking value for out of picture reference*/
    int32_t mask_val_v;
    /*!< interpolation_type 0 - BiLinear interpolation, 1 - BiCubic interpolation*/
    int32_t interpolation_type;

} ia_pal_isp_gdc7_1_t;

/*! \isp struct glim_2_0
Global inverse tone mapping
*/
typedef struct
{
    /*!< glim_enable Enable GLIM*/
    int32_t glim_enable;
    /*!< glu_base_level[8] GLU base level offset*/
    int32_t glu_base_level[8];
    /*!< glu_step[8] GLU step amount per stage*/
    int32_t glu_step[8];
    /*!< glu_start_bin[8] GLU stage start offset in LUT*/
    int32_t glu_start_bin[8];
    /*!< glu_gen_lut_size Utilized LUT size*/
    int32_t glu_gen_lut_size;
    /*!< glu_gen_lut[385] LUT samples*/
    int32_t glu_gen_lut[385];
    /*!< gain_prec Gain precision bits*/
    int32_t gain_prec;

} ia_pal_isp_glim_2_0_t;

/*! \isp struct gltm_2_0
Global tone mapping
*/
typedef struct
{
    /*!< gltm_enable Enable GLTM*/
    int32_t gltm_enable;
    /*!< fc_m[9] YUV2RGB format conversion matrix (coeffs S2.13)*/
    int32_t fc_m[9];
    /*!< glu_base_level[8] GLU base level offset*/
    int32_t glu_base_level[8];
    /*!< glu_step[8] GLU step amount per stage*/
    int32_t glu_step[8];
    /*!< glu_start_bin[8] GLU stage start offset in LUT*/
    int32_t glu_start_bin[8];
    /*!< glu_gen_lut_size Utilized LUT size*/
    int32_t glu_gen_lut_size;
    /*!< glu_gen_lut[385] LUT samples*/
    int32_t glu_gen_lut[385];
    /*!< gain_prec Gain precision bits*/
    int32_t gain_prec;

} ia_pal_isp_gltm_2_0_t;

/*! \isp struct gmv_statistics_1_1

*/
typedef struct
{
    /*!< gmv_en ff enable/disable flag*/
    int32_t gmv_en;
    /*!< is_first_frame Set to 1 on first frame. If 1, the input features are ignored, fixed (fake) matches are produced*/
    int32_t is_first_frame;
    /*!< kappa kappa for Harris grade calculation*/
    int32_t kappa;
    /*!< counter_shifter Shifter for the good feature point and good match point counter*/
    int32_t counter_shifter;
    /*!< good_corner_threshold Threshold for the good corner counter.*/
    int32_t good_corner_threshold;
    /*!< good_match_threshold Threshold for the good match counter.*/
    int32_t good_match_threshold;
    /*!< additional_bin_input set to 1 if 4x binning is required before processing, otherwise image is binned 2x*/
    int32_t additional_bin_input;
    /*!< block_width Block width*/
    int32_t block_width;
    /*!< block_height Block height*/
    int32_t block_height;
    /*!< y_start y start for best feature search*/
    int32_t y_start;
    /*!< y_end y end for best feature search*/
    int32_t y_end;
    /*!< x_start x start for best feature search*/
    int32_t x_start;
    /*!< x_end x end for best feature search*/
    int32_t x_end;
    /*!< grid_width width of the output grid, overall size is gw X 16*/
    int32_t grid_width;

} ia_pal_isp_gmv_statistics_1_1_t;

/*! \isp struct input_system_drainer

*/
typedef struct
{
    /*!< binning_bayer_enable Bayer binning enable*/
    int32_t binning_bayer_enable;
    /*!< binning_4cell_enable 4cell binning enable*/
    int32_t binning_4cell_enable;
    /*!< crop_enable 0 - Line cropping enabled, 1 - Line cropping enabled*/
    int32_t crop_enable;
    /*!< crop_line_top When cropping is enabled, all lines before this line will be cropped*/
    int32_t crop_line_top;
    /*!< crop_line_bot When cropping is enabled, all lines after this line will be cropped*/
    int32_t crop_line_bot;

} ia_pal_isp_input_system_drainer_t;

/*! \isp struct io_buffer_1_4

*/
typedef struct
{
    /*!< input_width Input width counted in number of pixels components per line*/
    int32_t input_width;
    /*!< input_height Input height counted in number of lines*/
    int32_t input_height;
    /*!< output_width Output width counted in number of pixels components per line*/
    int32_t output_width;
    /*!< output_height Output height counted in number of lines*/
    int32_t output_height;
    /*!< x_output_offset Output horizontal offset from the input, counted in number of pixels components per line, 16b signed (if negative padding is required)*/
    int32_t x_output_offset;
    /*!< y_output_offset Output vertical offset from the input counted in number of lines, 16b signed*/
    int32_t y_output_offset;
    /*!< use_attributes This capability impact the ODR. When set, ODR should use the EOL/EOF attributes to detect frame dimensions. In general, this capability is used when the height or width or both are not known or cannot be expressed. Using this capability disable the option using crop/pad mechanism and force SW to provide the same dimension in input/output region (if known) and zero the offset values.*/
    int32_t use_attributes;
    /*!< espa_luma_shift_left 1-perform shift left on the luma/bayer componenets, 0-perfrom shift right on the luma/bayer components*/
    int32_t espa_luma_shift_left;
    /*!< espa_luma_shift_count shift amount to the luma/bayer component where sign is kept and shift right done with rounding*/
    int32_t espa_luma_shift_count;
    /*!< espa_chroma_shift_left 1-perform shift left on the chroma componenets, 0-perfrom shift right on the chroma components*/
    int32_t espa_chroma_shift_left;
    /*!< espa_chroma_shift_count shift amount to the chroma component where sign is kept and shift right done with rounding*/
    int32_t espa_chroma_shift_count;
    /*!< espa_range_reduction_output_resolution Set the output resolution to be used at the range reduction calculation*/
    int32_t espa_range_reduction_output_resolution;
    /*!< espa_range_reduction_enable enable range reduction calculation for all components*/
    int32_t espa_range_reduction_enable;
    /*!< espa_luma_clipping_min_enable clipping the luma components to clipping_min value*/
    int32_t espa_luma_clipping_min_enable;
    /*!< espa_luma_clipping_max_enable clipping the luma components to clipping_max value*/
    int32_t espa_luma_clipping_max_enable;
    /*!< espa_chroma_clipping_min_enable clipping the chroma components to clipping_min value*/
    int32_t espa_chroma_clipping_min_enable;
    /*!< espa_chroma_clipping_max_enable clipping the chroma components to clipping_max value*/
    int32_t espa_chroma_clipping_max_enable;
    /*!< espa_luma_clipping_min_value Min value (S15) to clip the component after the shift using sign arithmetic*/
    int32_t espa_luma_clipping_min_value;
    /*!< espa_luma_clipping_max_value Max value (S15) to clip the component after the shift using sign arithmetic*/
    int32_t espa_luma_clipping_max_value;
    /*!< espa_luma_offset_value Offset value (S15) to be added to the component using sign arithmetic*/
    int32_t espa_luma_offset_value;
    /*!< espa_chroma_clipping_min_value Min value (S15) to clip the component after the shift using sign arithmetic*/
    int32_t espa_chroma_clipping_min_value;
    /*!< espa_chroma_clipping_max_value Max value (S15) to clip the component after the shift using sign arithmetic*/
    int32_t espa_chroma_clipping_max_value;
    /*!< espa_chroma_offset_value Offset value (S15) to be added to the component using sign arithmetic*/
    int32_t espa_chroma_offset_value;
    /*!< espa_enable Enable espa*/
    int32_t espa_enable;
    /*!< component_precision Pixel element precision in bits: 0=>8b, 1=>10b, 2=>12b, 3=>16, 4=>32, 5=>2, 6=>4, 7..15=>reserved*/
    int32_t component_precision;
    /*!< unpack_alignment Valid for unpacked vectors: 0-element located at LSB and MSB is zero; 1-element located at MSB and LSB is zero*/
    int32_t unpack_alignment;
    /*!< vertical_ordering_enable If set, the walking order should be vertical using the sub_line value to indicate how many CL generate vertical movement*/
    int32_t vertical_ordering_enable;
    /*!< vertical_ordering_sub_line valid when vertical_ordering is set, indicates the size of the sub line to generate vertical step in CL granularity*/
    int32_t vertical_ordering_sub_line;
    /*!< num_of_queues Amount of total active queues (YUV FP - 4, YUV SP - 3 YUV SP Tile - 2. RGB - 1,1,1. Bayer -2). Must be up to amount of maximum queue supported. Can be changed per frame. At LBFF used dynamicly for PDAF*/
    int32_t num_of_queues;
    /*!< vector_format Vector CL format: 0-unpacked using 2B container; 1-packed*/
    int32_t vector_format;
    /*!< tile_mode Valid for IO that can provide tile format: 0-no tiling; 1-the IO should use tiling with the configured height, width, and tiling type (internal tiling or external Tile-4)*/
    int32_t tile_mode;
    /*!< tiling_type Tiling Type: 0 - internal tiling; 1 - external tiling (Tile-4)*/
    int32_t tiling_type;
    /*!< compression_mode Valid for streaming that are tiled: 1-the stream is written/fetched to/from DDR through compression engine; 0-not going through compression*/
    int32_t compression_mode;
    /*!< buffer_1d_enable Valid only for 1 plane and 1 queue streams. 0-the buffer is described as 2D; 1-the buffer is described as 1D (continues from start to end w/o stride ignoring lines)*/
    int32_t buffer_1d_enable;
    /*!< num_of_planes Amount of valid planes (supported 1, 2, 3, 4 - depends also on HW parameter of max planes and data type)*/
    int32_t num_of_planes;
    /*!< plane_stride[3] Per plane: provides the difference between two horizontal pixels, in bytes, CL aligned, unsigned.  At tile mode - provide the difference between two lines of tiles in bytes*/
    uint32_t plane_stride[3];
    /*!< plane_offset_start_address[3] Per plane: Start offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_start_address[3];
    /*!< plane_offset_end_address[3] Per plane: End offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_end_address[3];
    /*!< plane_tile_width[3] Per plane: buffer tile width configuration in bytes*/
    int32_t plane_tile_width[3];
    /*!< plane_tile_height[3] Per plane: buffer tile height configuration in lines*/
    int32_t plane_tile_height[3];
    /*!< chroma_planes_order Chroma planes ordering: 0 - U before V; 1 - V before U (valid for half planer configuration)*/
    int32_t chroma_planes_order;
    /*!< chroma_duplication Valid when format 420 is configured to provide 422 (2P2Q with SIF count of 4 or 2). when reset - duplicate the chroma and provide the same value each two Y lines, when set - send the chroma components only with the even Y (at odd Y lines doesn’t send any chroma)*/
    int32_t chroma_duplication;
    /*!< onep_pixel_order Set the ordering of the first plane (lines-N, pixels-M) 4PPC: 0-(N, M), (N, M+1), (N+1, M), (N+1, M+1), horizontal raster; 1-(N, M), (N+1, M), (N, M+1), (N+1, M+1), vertical raster 2PPC: 0-first cyc: (N, M), (N+1, M), second cyc: (N, M+1), (N+1, M+1); 1-first cyc: (N, M), (N, M+1),*/
    int32_t onep_pixel_order;
    /*!< zlr_transaction_enable when set enable sending zlr request for prefetch address translation and compression status*/
    int32_t zlr_transaction_enable;
    /*!< streaming_mode The streaming unified buffer protocol:  0-static offline (producer/consumer write/read from DDR after kick);  1-dynamic offline (producer/consumer send wr/rd EOF/SOF, producer write after kick, consumer read after full frame at DDR);  2-buffer chasing large memory (producer/consumer send wr/rd EOF/SOF, producer send wr update, consumer read according to wr update);  3-buffer chasing on small memory (producer/consumer send wr/rd EOF/SOF, producer write released buffers and sends wr pointers, consumer read valid buffer and sends rd pointer);  4-S&R like 3 with option to change the link (supporting modes 2 and 3 with dynamic change) 5-buffer chasing small memory - fix starting point, single buffer 6-buffer chasing small memory - float starting point 7-buffer chasing small memory - fix starting point, double buffer*/
    int32_t streaming_mode;
    /*!< streaming_sw_managed When set - the SW verify the shared buffer is fully consumed by  the producer and can be written immediately*/
    int32_t streaming_sw_managed;
    /*!< local_link_id indicates the stream used at the current connectlon*/
    int32_t local_link_id;
    /*!< stride_ratio provides the BCSM max_stride/stride ratio with possible values of 1-8, 16, 32, 64, 128*/
    int32_t stride_ratio;
    /*!< granularity_pointer_update Valid according the streaming mode: number of lines (LB)/lines of blocks (BB) to be written/release before sending a pointer update (reporting always done with producer view)*/
    int32_t granularity_pointer_update;
    /*!< max_stride provides the maximum stride value to be used at the connection*/
    uint32_t max_stride;
    /*!< block_width buffer block width configuration in pixels*/
    int32_t block_width;
    /*!< block_height buffer block height configuration in lines*/
    int32_t block_height;
    /*!< first_row_blocks_height buffer block height configuration in lines of all the blocks in the first row of blocks. If zero - use streaming_buffer_blocks_height*/
    int32_t first_row_blocks_height;
    /*!< last_row_blocks_height buffer block height configuration in lines of all the blocks in the last row of blocks. If zero - use streaming_buffer_blocks_height*/
    int32_t last_row_blocks_height;
    /*!< plane_max_burst_size[3] Plane maximum burst size: used to specify the transfer size in CL granularity (Max limited to 16, possible values - 1, 2, 4, 8, 16)*/
    int32_t plane_max_burst_size[3];
    /*!< plane_horiz_subsample_config[3] Plane Horiz subsample (width>>N).  Affect tile width and width resolution=>Bayer - 0, Y/UV at YUV SP - 0, Y at YUV FP -0, UV U/V at YUV FP-1)*/
    int32_t plane_horiz_subsample_config[3];
    /*!< plane_vert_subsample_config[3] Plane Vertical subsample (height>>N). Affect tile highet and highet resolution=>Bayer - 0, Y atYUV SP - 0, UV at YUV SP - 1, Y at YUV FP -0, U/V at YUV FP-1)*/
    int32_t plane_vert_subsample_config[3];
    /*!< plane_zlr_granularity[3] Plane ZLR page granularity: if 0 - 4KB, if 1 - 2KB. Valid only if ZLR is enalbe*/
    int32_t plane_zlr_granularity[3];
    /*!< progress_message_line Provides the line number that when is done generate progress message (IFD - last byte of the line arrive, ODR - last byte of the line acked by nbuf)*/
    int32_t progress_message_line;
    /*!< pace_message_ref_line Provides the line number that when start indicating start measuring the pace and active  (ODR - send first WR of the line, IFD send first RD of line)*/
    int32_t pace_message_ref_line;
    /*!< pace_message_pace_line Provides the line number indicating to stop measuring the activity and pace and sending pace meesage (at IFD - get the last data of the line, at ODR - getnon-buf ack on last data of the line)*/
    int32_t pace_message_pace_line;
    /*!< component_in_valid_pixel Provides amount of valid component per valid pixel*/
    int32_t component_in_valid_pixel;
    /*!< pixels_in_valid_cycle Provides amount of valid pixels per valid cycle*/
    int32_t pixels_in_valid_cycle;
    /*!< subsample_YUV444_to_YUV422 Used by ODR to convert YUV444 to YUV422: 0-use amount of element as written at components_in_valid_cycle, 1-drop the chroma components any odd cycle*/
    int32_t subsample_YUV444_to_YUV422;
    /*!< middle_ack_line_number Valid if ack enable  If enabled, the device should generate middle ack when delivers the EOL of the configured line (global number) assuming the first line delievered at SOF is zero.  In case of multiple planes the counting is done using plane1 but only when all the planes are synced*/
    int32_t middle_ack_line_number;
    /*!< middle_ack_enable If set, enable the mechansim to generate middle ack when consumed amount of configured lines*/
    int32_t middle_ack_enable;
    /*!< middle_ack_mode_stall Valid only when ack_enable is set When set, the device should stall once sending the middle ack*/
    int32_t middle_ack_mode_stall;
    /*!< stream_dt stream data type as need to be used by the MIPI*/
    int32_t stream_dt;
    /*!< stream_vc stream virtual channel number as need to be used in MIPI*/
    int32_t stream_vc;
    /*!< proc_ff_bypass when set indicates the FF in the pipe (FCVT & ESPA) need to be bypass*/
    int32_t proc_ff_bypass;
    /*!< dpa_bypass When set indicate the end of MIPI frame (used for MIPI CSI sub frames)*/
    int32_t dpa_bypass;
    /*!< stream_dt_for_mipi_packet stream data type as need to be used in the header of mipi packet - not affect the proc*/
    int32_t stream_dt_for_mipi_packet;
    /*!< arbiter_pin MIPI CSI arbiter pin location of the stream*/
    int32_t arbiter_pin;
    /*!< user_reserved user_reserved*/
    int32_t user_reserved;
    /*!< aligner_data_size amount of valid bits per valid cycle to be accumulate and use the aligner (valid when dpa_bypass is set). LSB represent 2b resolution (meaning value can be 2, 4, 6, 8, … up to 72 which is the size bus)*/
    int32_t aligner_data_size;
    /*!< mipi_csi_eof When set indicate the end of MIPI frame (used for MIPI CSI sub frames)*/
    int32_t mipi_csi_eof;
    /*!< ppc provides the amount of pixel per cycle*/
    int32_t ppc;
    /*!< stream_wc stream word count as need to be used by the MIPI*/
    int32_t stream_wc;
    /*!< max_credits provides the maximum amount of credits for eliminating the need to calculate it in HW according the next formula: (end_address-start_address)/Max_Stride*/
    uint32_t max_credits;
    /*!< reserved_0_0 Reserved for future use*/
    int32_t reserved_0_0;
    /*!< reserved_0_1 Reserved for future use*/
    int32_t reserved_0_1;
    /*!< reserved_0_2 Reserved for future use*/
    int32_t reserved_0_2;
    /*!< reserved_0_3 Reserved for future use*/
    int32_t reserved_0_3;
    /*!< reserved_1_0 Reserved for future use*/
    int32_t reserved_1_0;
    /*!< reserved_1_1 Reserved for future use*/
    int32_t reserved_1_1;
    /*!< reserved_1_2 Reserved for future use*/
    int32_t reserved_1_2;
    /*!< reserved_1_3 Reserved for future use*/
    int32_t reserved_1_3;
    /*!< chroma_non_duplication_location Valid when format 420 is configured to provide 422 (2P2Q with SIF count of 4 or 2) and chroma_duplication is disabled. when reset - add the chroma lines w/ the even luma lines, when set - add the chroma lines w/ the odd luma lines*/
    int32_t chroma_non_duplication_location;
    /*!< input_width_msb provides bits [19:16] to the input width resolution*/
    int32_t input_width_msb;
    /*!< output_width_msb provides bits [19:16] to the output width resolution*/
    int32_t output_width_msb;
    /*!< snoop 0 - non-snoopable, 1 - snoopable*/
    int32_t snoop;
    /*!< traffic_class Traffic class the request belongs to and be stored at the XFER queue ccordingly*/
    int32_t traffic_class;
    /*!< allocate used for streaming cache: 0-don’t cache, 1-reserved, 2-cache only to non-reserved ways, 3-cache use reserved space for this device*/
    int32_t allocate;
    /*!< wraparound_enable wraparound enable bit: 0 - disabled. 1 - enabled.*/
    uint32_t wraparound_enable;
    /*!< horizontal_stride_enable horizontal stride enable bit: 0 - horizontal stride is disabled. 1 - horizontal stride is enabled.*/
    uint32_t horizontal_stride_enable;
    /*!< variable_length_buffer_enable variable length buffer enable bit: 0 - disabled. 1 - enabled.*/
    uint32_t variable_length_buffer_enable;
    /*!< variable_length_buffer_mode 0 - FW/SW manage. 1 - HW manage (relevant only to ODR)*/
    uint32_t variable_length_buffer_mode;
    /*!< horizontal_sub_line valid when horizontal_stride_enable is set, indicates the size of the sub line to generate horizontal step in CL granularity .The horizontal stride occurs every number of horizontal_sub_line CLs.*/
    uint32_t horizontal_sub_line;
    /*!< wraparound_offset_start_address[3] when wraparound_enable is 1, Start offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t wraparound_offset_start_address[3];
    /*!< wraparound_offset_end_address[3] when wraparound_enable is 1, End offset address of plane in bytes, CL aligned, unsigned, Valid for streaming mode of small memory*/
    uint32_t wraparound_offset_end_address[3];
    /*!< horizontal_stride[3] provides the difference between two sub-lines, in CL granularity, unsigned.*/
    uint32_t horizontal_stride[3];
    /*!< mipi_unpacking_en mipi unpacking enable bit: 0 - disabled. 1 - enabled.*/
    uint32_t mipi_unpacking_en;
    /*!< buffer_user_info_reserved_0 Reserved for future use*/
    int32_t buffer_user_info_reserved_0;
    /*!< buffer_user_info_reserved_1 Reserved for future use*/
    int32_t buffer_user_info_reserved_1;

} ia_pal_isp_io_buffer_1_4_t;

/*! \isp struct isys_drainer_1_0

*/
typedef struct
{
    /*!< output_format 0-7 - RGB formats (with A=0); 8-15 - YUV formats; 0 - Output is in 3-plane RGB format; 3 - Output is in ARGB format; 4 - Output is in RGBA format; 5 - Output is in BGRA format; 6 - Output is in ABGR format; 8 - Output is in 2-plane YUV420 (NV12) format; 9 - Output Y only and discard UV;*/
    int32_t output_format;
    /*!< plane_offset_start_address[3] Per plane: Start offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_start_address[3];

} ia_pal_isp_isys_drainer_1_0_t;

/*! \isp struct linearization2_0
Linearization
*/
typedef struct
{
    /*!< Linearization2_0_enable Enable Linearization2_0*/
    int32_t Linearization2_0_enable;
    /*!< glu_base_level0[5] GLU base level offset*/
    int32_t glu_base_level0[5];
    /*!< glu_base_level1[5] GLU1 base level offset*/
    int32_t glu_base_level1[5];
    /*!< glu_base_level2[5] GLU2 base level offset*/
    int32_t glu_base_level2[5];
    /*!< glu_base_level3[5] GLU3 base level offset*/
    int32_t glu_base_level3[5];
    /*!< glu_base_level4[5] GLU4 base level offset*/
    int32_t glu_base_level4[5];
    /*!< glu_base_level5[5] GLU5 base level offset*/
    int32_t glu_base_level5[5];
    /*!< glu_base_level6[5] GLU6 base level offset*/
    int32_t glu_base_level6[5];
    /*!< glu_base_level7[5] GLU7 base level offset*/
    int32_t glu_base_level7[5];
    /*!< glu_step0[5] GLU step amount per stage*/
    int32_t glu_step0[5];
    /*!< glu_step1[5] GLU1 step amount per stage*/
    int32_t glu_step1[5];
    /*!< glu_step2[5] GLU2 step amount per stage*/
    int32_t glu_step2[5];
    /*!< glu_step3[5] GLU3 step amount per stage*/
    int32_t glu_step3[5];
    /*!< glu_step4[5] GLU4 step amount per stage*/
    int32_t glu_step4[5];
    /*!< glu_step5[5] GLU5 step amount per stage*/
    int32_t glu_step5[5];
    /*!< glu_step6[5] GLU6 step amount per stage*/
    int32_t glu_step6[5];
    /*!< glu_step7[5] GLU7 step amount per stage*/
    int32_t glu_step7[5];
    /*!< glu_start_bin0[5] GLU stage start offset in LUT*/
    int32_t glu_start_bin0[5];
    /*!< glu_start_bin1[5] GLU stage start offset in LUT1*/
    int32_t glu_start_bin1[5];
    /*!< glu_start_bin2[5] GLU stage start offset in LUT2*/
    int32_t glu_start_bin2[5];
    /*!< glu_start_bin3[5] GLU stage start offset in LUT3*/
    int32_t glu_start_bin3[5];
    /*!< glu_start_bin4[5] GLU stage start offset in LUT4*/
    int32_t glu_start_bin4[5];
    /*!< glu_start_bin5[5] GLU stage start offset in LUT5*/
    int32_t glu_start_bin5[5];
    /*!< glu_start_bin6[5] GLU stage start offset in LUT6*/
    int32_t glu_start_bin6[5];
    /*!< glu_start_bin7[5] GLU stage start offset in LUT7*/
    int32_t glu_start_bin7[5];
    /*!< glu_gen_lut_size0 Utilized LUT size*/
    int32_t glu_gen_lut_size0;
    /*!< glu_gen_lut_size1 Utilized LUT1 size*/
    int32_t glu_gen_lut_size1;
    /*!< glu_gen_lut_size2 Utilized LUT2 size*/
    int32_t glu_gen_lut_size2;
    /*!< glu_gen_lut_size3 Utilized LUT3 size*/
    int32_t glu_gen_lut_size3;
    /*!< glu_gen_lut_size4 Utilized LUT4 size*/
    int32_t glu_gen_lut_size4;
    /*!< glu_gen_lut_size5 Utilized LUT5 size*/
    int32_t glu_gen_lut_size5;
    /*!< glu_gen_lut_size6 Utilized LUT6 size*/
    int32_t glu_gen_lut_size6;
    /*!< glu_gen_lut_size7 Utilized LUT7 size*/
    int32_t glu_gen_lut_size7;
    /*!< glu_gen_lut0[512] LUT samples*/
    int32_t glu_gen_lut0[512];
    /*!< glu_gen_lut1[512] LUT1 samples*/
    int32_t glu_gen_lut1[512];
    /*!< glu_gen_lut2[512] LUT2 samples*/
    int32_t glu_gen_lut2[512];
    /*!< glu_gen_lut3[512] LUT3 samples*/
    int32_t glu_gen_lut3[512];
    /*!< glu_gen_lut4[512] LUT4 samples*/
    int32_t glu_gen_lut4[512];
    /*!< glu_gen_lut5[512] LUT5 samples*/
    int32_t glu_gen_lut5[512];
    /*!< glu_gen_lut6[512] LUT6 samples*/
    int32_t glu_gen_lut6[512];
    /*!< glu_gen_lut7[512] LUT7 samples*/
    int32_t glu_gen_lut7[512];
    /*!< mask0[4] Mask of quad 0*/
    int32_t mask0[4];
    /*!< mask1[4] Mask of quad 1*/
    int32_t mask1[4];
    /*!< mask2[4] Mask of quad 2*/
    int32_t mask2[4];
    /*!< mask3[4] Mask of quad 3*/
    int32_t mask3[4];

} ia_pal_isp_linearization2_0_t;

/*! \isp struct lsc_1_2
Lens shading correction up to 24 bit
*/
typedef struct
{
    /*!< cfa_type cfa type 0=1x1 1=2x2 2=4x4*/
    int32_t cfa_type;
    /*!< lsclog2gridwidth log2 width of each subplane*/
    int32_t lsclog2gridwidth;
    /*!< lsclog2gridheight log2 height of each subplane*/
    int32_t lsclog2gridheight;
    /*!< lsc_col_start X value of top left corner of sensor relative to ROI*/
    int32_t lsc_col_start;
    /*!< lsc_row_start Y value of top left corner of sensor relative to ROI*/
    int32_t lsc_row_start;
    /*!< lsc_exp resolution modifier of the lsc tables*/
    int32_t lsc_exp;
    /*!< lsc_grid_tablec00[4096] lsc grid table*/
    int32_t lsc_grid_tablec00[4096];
    /*!< lsc_grid_tablec01[4096] lsc grid table*/
    int32_t lsc_grid_tablec01[4096];
    /*!< lsc_grid_tablec02[4096] lsc grid table*/
    int32_t lsc_grid_tablec02[4096];
    /*!< lsc_grid_tablec03[4096] lsc grid table*/
    int32_t lsc_grid_tablec03[4096];
    /*!< lsc_grid_tablec10[4096] lsc grid table*/
    int32_t lsc_grid_tablec10[4096];
    /*!< lsc_grid_tablec11[4096] lsc grid table*/
    int32_t lsc_grid_tablec11[4096];
    /*!< lsc_grid_tablec12[4096] lsc grid table*/
    int32_t lsc_grid_tablec12[4096];
    /*!< lsc_grid_tablec13[4096] lsc grid table*/
    int32_t lsc_grid_tablec13[4096];
    /*!< lsc_grid_tablec20[4096] lsc grid table*/
    int32_t lsc_grid_tablec20[4096];
    /*!< lsc_grid_tablec21[4096] lsc grid table*/
    int32_t lsc_grid_tablec21[4096];
    /*!< lsc_grid_tablec22[4096] lsc grid table*/
    int32_t lsc_grid_tablec22[4096];
    /*!< lsc_grid_tablec23[4096] lsc grid table*/
    int32_t lsc_grid_tablec23[4096];
    /*!< lsc_grid_tablec30[4096] lsc grid table*/
    int32_t lsc_grid_tablec30[4096];
    /*!< lsc_grid_tablec31[4096] lsc grid table*/
    int32_t lsc_grid_tablec31[4096];
    /*!< lsc_grid_tablec32[4096] lsc grid table*/
    int32_t lsc_grid_tablec32[4096];
    /*!< lsc_grid_tablec33[4096] lsc grid table*/
    int32_t lsc_grid_tablec33[4096];
    /*!< lsc_table_width table width*/
    int32_t lsc_table_width;
    /*!< lsc_table_height table height*/
    int32_t lsc_table_height;
    /*!< bypass bypass for the filter*/
    int32_t bypass;
    /*!< enable_compand enable for the (de)companding*/
    int32_t enable_compand;
    /*!< cu_compression_x[13] U.24 linear, default log-limited*/
    int32_t cu_compression_x[13];
    /*!< cu_compression_y[12] U.15 companded output*/
    int32_t cu_compression_y[12];
    /*!< cu_compression_slope[12] U1.14 15bit slopes for companding*/
    int32_t cu_compression_slope[12];
    /*!< cu_decompression_x[13] U.15 companded input, default log-limited*/
    int32_t cu_decompression_x[13];
    /*!< cu_decompression_y[12] U.24 linear*/
    int32_t cu_decompression_y[12];
    /*!< cu_decompression_slope[12] U20.6 26bit slopes for decompanding*/
    int32_t cu_decompression_slope[12];
    /*!< linear_pedestal Pedestal subtracted (and added later) in linear domain, U.24*/
    int32_t linear_pedestal;
    /*!< use_pedestal If true, pedestal is used and the companded signal should be U15. If false, linear_pedestal should be 0*/
    int32_t use_pedestal;

} ia_pal_isp_lsc_1_2_t;

/*! \isp struct nntm_1_0

*/
typedef struct
{
    /*!< bypass bypass for the filter*/
    int32_t bypass;
    /*!< mode NNTM modes [0,1]*/
    int32_t mode;
    /*!< offset_yuv2rgb[3] yuv2rgb offset*/
    int32_t offset_yuv2rgb[3];
    /*!< yuv2rgb[9] yuv2rgb calibration*/
    int32_t yuv2rgb[9];
    /*!< rgb2yuv[9] rgb2yuv calibration*/
    int32_t rgb2yuv[9];
    /*!< input_range_restricted input range is restricted flag*/
    int32_t input_range_restricted;
    /*!< output_range_restricted output range is restricted flag*/
    int32_t output_range_restricted;
    /*!< blending_map[16384] blending map*/
    int32_t blending_map[16384];
    /*!< blending_width blending map width*/
    int32_t blending_width;
    /*!< blending_height blending map height*/
    int32_t blending_height;
    /*!< guidence_weight_bias[2] guidence conv weight & bias*/
    int32_t guidence_weight_bias[2];
    /*!< gtm_a polynomial chromaticity model degree*/
    int32_t gtm_a;
    /*!< gtm_b color saturation in highlights*/
    int32_t gtm_b;
    /*!< gtm_c overall color desaturation*/
    int32_t gtm_c;
    /*!< tm_lut[2049] generalized lut for tone mapping lut*/
    int32_t tm_lut[2049];

} ia_pal_isp_nntm_1_0_t;

/*! \isp struct pafstatistics_1_2
PAF Statistics
*/
typedef struct
{
    /*!< paf_en 0: FF will not write to the PAF  array; 1: FF will write*/
    int32_t paf_en;
    /*!< paf_frame_width width of PAF frame (in PAF pixels)*/
    int32_t paf_frame_width;
    /*!< paf_frame_height height of PAF frame (in PAF lines)*/
    int32_t paf_frame_height;
    /*!< skip_horizontal_start number of skipped PAF pixel pairs at the start of each line pair*/
    int32_t skip_horizontal_start;
    /*!< skip_vertical_start number of skipped PAF line pairs at the start of the frame*/
    int32_t skip_vertical_start;
    /*!< block_width number of PAF pixel pairs per block in horizontal direction*/
    int32_t block_width;
    /*!< block_height number of PAF pixel pairs per block in vertical direction*/
    int32_t block_height;
    /*!< accum_horizontal number of consecutive PAF pixel pairs accumulated in horizontal direction*/
    int32_t accum_horizontal;
    /*!< skip_horizontal number of PAF pixel pairs skipped between accumulated pixel pairs in horizontal direction*/
    int32_t skip_horizontal;
    /*!< accum_vertical number of consecutive PAF pixel pairs accumulated in vertical direction*/
    int32_t accum_vertical;
    /*!< skip_vertical number of PAF line pairs skipped between accumulated pixel pairs in vertical direction*/
    int32_t skip_vertical;
    /*!< min_shift minimum evaluation shift in steps*/
    int32_t min_shift;
    /*!< shift_steps number of evaluation points, starting from m_paf_min_shift*/
    int32_t shift_steps;
    /*!< paf_shift_step_size phase evaluation step size in pixels*/
    int32_t paf_shift_step_size;
    /*!< paf_shifter configured so that the accumulated phase difference fits in the output register*/
    int32_t paf_shifter;
    /*!< split_accross_multiple_lines 0: SOP = SOL, EOP = EOL; 1: SOF determined by the reset, EOL determined by pixels per line*/
    int32_t split_accross_multiple_lines;
    /*!< pixels_per_line number of pixels per line; pixels_per_line <= paf_frame_width*/
    int32_t pixels_per_line;
    /*!< input_modes 0: RRRR+LLLL; 1: LLLL+RRRR; 2: RLRL; 3: LRLR; 4: RRRR+LLLL_ALT; 5: LLLL+RRRR_ALT; 6: RLRL_ALT; 7: LRLR_ALT*/
    int32_t input_modes;
    /*!< input_bpp 0: 8 bits; 1: 10 bits; 2: 12 bits; 3: 14 bits; 4: 16 bits; 5: 15 bits (for PDAF3type)*/
    int32_t input_bpp;
    /*!< int_prec internal precision of PAF pixels*/
    int32_t int_prec;
    /*!< paf_blacklevel Black level to be subtracted from raw PDAF pixel values*/
    int32_t paf_blacklevel;
    /*!< shading_coeff_l[192] Shading correction coefficients for L PDAF values (arrangement is the same as PDAF grid: 16x12)*/
    int32_t shading_coeff_l[192];
    /*!< shading_coeff_r[192] Shading correction coefficients for R PDAF values (arrangement is the same as PDAF grid: 16x12)*/
    int32_t shading_coeff_r[192];
    /*!< paf_abs_shifter Bit right shift after abs-operation, to compensate for the shading gains*/
    int32_t paf_abs_shifter;

} ia_pal_isp_pafstatistics_1_2_t;

/*! \isp struct pext_1_0

*/
typedef struct
{
    /*!< paf_output_mode 0)disables, do not pass anything\n 1) first line sent to memset0 second\n line sent to memset1\n 2)first line sent to memset0 second to memset 1 and afterward alternate every two lines 3) passthrough –send to memset0 everything*/
    int32_t paf_output_mode;
    /*!< swapping1stbc Apply swapping of BC inputs for 1st/3rd/etc.\n0: no swapping\n1: swap B/C inputs*/
    int32_t swapping1stbc;
    /*!< swapping1stcd Apply swapping of CD inputs for 1st/3rd/etc.\n0: no swapping\n1: swap C/D inputs*/
    int32_t swapping1stcd;
    /*!< swapping2ndbc Apply swapping of BC inputs for 2nd/4th/etc. lines\n0: no swapping\n1: swap A/B inputs*/
    int32_t swapping2ndbc;
    /*!< swapping2ndcd Apply swapping of CD inputs for 2nd/4th/etc. lines\n0: no swapping\n1: swap C/D inputs*/
    int32_t swapping2ndcd;
    /*!< pdaf_width Width in units of PDAF pixels. After Width pixels – Pext knows there is a new line coming in. In Modes1..3 – max line length is as in the internal buffer size which is 1024 pixels.*/
    int32_t pdaf_width;
    /*!< pdaf_height Height in units of pdaf lines*/
    int32_t pdaf_height;
    /*!< drop_pattern[32] Drop pattern for AF pixels. 1=drop the lines\n0=use the line*/
    int32_t drop_pattern[32];
    /*!< drop_period Period of the drop pattern*/
    int32_t drop_period;

} ia_pal_isp_pext_1_0_t;

/*! \isp struct rgb_ir_2_0
RGB-IR
*/
typedef struct
{
    /*!< Bypass Bypass (0,1)*/
    int32_t Bypass;
    /*!< CFArgbir[16] RGB-IR CFA descriptor for 4x4 repetitive pattern (0: R, 1: G, 2: B, 3: IR)*/
    int32_t CFArgbir[16];
    /*!< CFAbayer[4] Bayer CFA descriptor for 2x2 repetitive pattern (0: R, 1: G, 2: B)*/
    int32_t CFAbayer[4];
    /*!< SensorDim[2] Sensor dimensions (height,width) for IR contamination correction (optical center calculation)*/
    int32_t SensorDim[2];
    /*!< ImageDim[2] Image dimensions (height,width)*/
    int32_t ImageDim[2];
    /*!< IRimageDim[2] IR image dimensions (height,width)*/
    int32_t IRimageDim[2];
    /*!< IRtype Type of IR pixel layout (2: IRtype2, 1: IRtype1, 0: any other supported, -1: unsupported)*/
    int32_t IRtype;
    /*!< IRrefloc Pixel location corresponding to the reference (first) IR pixel within a 4x4 repetitive pattern*/
    int32_t IRrefloc;
    /*!< LumaWeights11[25] Filter mask for luminance calculations in CFA locations 11; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights11[25];
    /*!< LumaWeights12[25] Filter mask for luminance calculations in CFA locations 12; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights12[25];
    /*!< LumaWeights13[25] Filter mask for luminance calculations in CFA locations 13; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights13[25];
    /*!< LumaWeights14[25] Filter mask for luminance calculations in CFA locations 14; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights14[25];
    /*!< LumaWeights21[25] Filter mask for luminance calculations in CFA locations 21; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights21[25];
    /*!< LumaWeights22[25] Filter mask for luminance calculations in CFA locations 22; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights22[25];
    /*!< LumaWeights23[25] Filter mask for luminance calculations in CFA locations 23; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights23[25];
    /*!< LumaWeights24[25] Filter mask for luminance calculations in CFA locations 24; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights24[25];
    /*!< LumaWeights31[25] Filter mask for luminance calculations in CFA locations 31; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights31[25];
    /*!< LumaWeights32[25] Filter mask for luminance calculations in CFA locations 32; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights32[25];
    /*!< LumaWeights33[25] Filter mask for luminance calculations in CFA locations 33; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights33[25];
    /*!< LumaWeights34[25] Filter mask for luminance calculations in CFA locations 34; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights34[25];
    /*!< LumaWeights41[25] Filter mask for luminance calculations in CFA locations 41; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights41[25];
    /*!< LumaWeights42[25] Filter mask for luminance calculations in CFA locations 42; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights42[25];
    /*!< LumaWeights43[25] Filter mask for luminance calculations in CFA locations 43; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights43[25];
    /*!< LumaWeights44[25] Filter mask for luminance calculations in CFA locations 44; both the mask coefficients and their sum should be power of two values. A negative value excludes the corresponding sample from consideration.*/
    int32_t LumaWeights44[25];
    /*!< LumaWeightSums[16] Right bit shifts equivalent to the sum of the luminance filter mask coefficients for all 16 channels (11,12,44) within 4x4 repetitive pattern.*/
    int32_t LumaWeightSums[16];
    /*!< BayerRestNeighbors11[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 11; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors11[8];
    /*!< BayerRestNeighbors12[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 12; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors12[8];
    /*!< BayerRestNeighbors13[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations ; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors13[8];
    /*!< BayerRestNeighbors14[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 14; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors14[8];
    /*!< BayerRestNeighbors21[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 21; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors21[8];
    /*!< BayerRestNeighbors22[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 22; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors22[8];
    /*!< BayerRestNeighbors23[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 23; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors23[8];
    /*!< BayerRestNeighbors24[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 24; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors24[8];
    /*!< BayerRestNeighbors31[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 31; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors31[8];
    /*!< BayerRestNeighbors32[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 32; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors32[8];
    /*!< BayerRestNeighbors33[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 33; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors33[8];
    /*!< BayerRestNeighbors34[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 34; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors34[8];
    /*!< BayerRestNeighbors41[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 41; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors41[8];
    /*!< BayerRestNeighbors42[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 42; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors42[8];
    /*!< BayerRestNeighbors43[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 43; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors43[8];
    /*!< BayerRestNeighbors44[8] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) of up-to-four neighboring pixels chosen for restoration in CFA locations 44; (y=0,x=0) excludes the corresponding sample from consideration by setting its weight to 0*/
    int32_t BayerRestNeighbors44[8];
    /*!< BayerRestLuma Disable the use of the luminance in Bayer CFA restoration (0: disable, 1: enable)*/
    int32_t BayerRestLuma;
    /*!< BayerRestWeights Disable the use of the weights in Bayer CFA restoration (0: disable, 1: enable)*/
    int32_t BayerRestWeights;
    /*!< IRspatialOffset[2] Spatial shift (y,x) of pixel locations for IR contamination correction*/
    int32_t IRspatialOffset[2];
    /*!< IRbinningFactor[2] Binning factors (y,x) for IR contamination correction*/
    int32_t IRbinningFactor[2];
    /*!< IRcormode IR contamination correction mode (0: disable, 1: enable)*/
    int32_t IRcormode;
    /*!< IRmodelSigma[3] IR contamination model sigma (R,G,B)*/
    int32_t IRmodelSigma[3];
    /*!< IRmodelOffset[3] IR contamination model offset (R,G,B)*/
    int32_t IRmodelOffset[3];
    /*!< IRmodelHeight[3] IR contamination model height (R,G,B)*/
    int32_t IRmodelHeight[3];
    /*!< IRmodelWidth[3] IR contamination model width (R,G,B)*/
    int32_t IRmodelWidth[3];
    /*!< IRmodelMax[3] IR contamination model maximum (R,G,B)*/
    int32_t IRmodelMax[3];
    /*!< IRmodelCUxR[12] IR contamination model configuration unit parameter set X for R channel*/
    int32_t IRmodelCUxR[12];
    /*!< IRmodelCUaR[11] IR contamination model configuration unit parameter set A for R channel*/
    int32_t IRmodelCUaR[11];
    /*!< IRmodelCUbR[11] IR contamination model configuration unit parameter set B for R channel*/
    int32_t IRmodelCUbR[11];
    /*!< IRmodelCUxG[12] IR contamination model configuration unit parameter set X for G channel*/
    int32_t IRmodelCUxG[12];
    /*!< IRmodelCUaG[11] IR contamination model configuration unit parameter set A for G channel*/
    int32_t IRmodelCUaG[11];
    /*!< IRmodelCUbG[11] IR contamination model configuration unit parameter set B for G channel*/
    int32_t IRmodelCUbG[11];
    /*!< IRmodelCUxB[12] IR contamination model configuration unit parameter set X for B channel*/
    int32_t IRmodelCUxB[12];
    /*!< IRmodelCUaB[11] IR contamination model configuration unit parameter set A for B channel*/
    int32_t IRmodelCUaB[11];
    /*!< IRmodelCUbB[11] IR contamination model configuration unit parameter set B for B channel*/
    int32_t IRmodelCUbB[11];
    /*!< IRinterpNeighbors11[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 11*/
    int32_t IRinterpNeighbors11[12];
    /*!< IRinterpNeighbors12[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 12*/
    int32_t IRinterpNeighbors12[12];
    /*!< IRinterpNeighbors13[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 13*/
    int32_t IRinterpNeighbors13[12];
    /*!< IRinterpNeighbors14[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 14*/
    int32_t IRinterpNeighbors14[12];
    /*!< IRinterpNeighbors21[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 21*/
    int32_t IRinterpNeighbors21[12];
    /*!< IRinterpNeighbors22[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 22*/
    int32_t IRinterpNeighbors22[12];
    /*!< IRinterpNeighbors23[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 23*/
    int32_t IRinterpNeighbors23[12];
    /*!< IRinterpNeighbors24[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 24*/
    int32_t IRinterpNeighbors24[12];
    /*!< IRinterpNeighbors31[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 31*/
    int32_t IRinterpNeighbors31[12];
    /*!< IRinterpNeighbors32[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 32*/
    int32_t IRinterpNeighbors32[12];
    /*!< IRinterpNeighbors33[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 33*/
    int32_t IRinterpNeighbors33[12];
    /*!< IRinterpNeighbors34[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 34*/
    int32_t IRinterpNeighbors34[12];
    /*!< IRinterpNeighbors41[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 41*/
    int32_t IRinterpNeighbors41[12];
    /*!< IRinterpNeighbors42[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 42*/
    int32_t IRinterpNeighbors42[12];
    /*!< IRinterpNeighbors43[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 43*/
    int32_t IRinterpNeighbors43[12];
    /*!< IRinterpNeighbors44[12] Spatial offsets (y1,x1,y2,x2,y3,x3,y4,x4) and corresponding weights (w1,w2,w3,w4) of four neighboring pixels for IR interpolation in CFA locations 44*/
    int32_t IRinterpNeighbors44[12];
    /*!< IRscaledSensorDim[2] Scaled sensor dimensions (height,width) for IR contamination correction (optical center calculation); (1 << SHVAL)/SensorDim, for SHVAL = 24. Maximum value assumes that sensor dimensions are larger than 256*/
    int32_t IRscaledSensorDim[2];
    /*!< IRscaledModelSigma[3] Scaled IR contamination model sigma (R,G,B); (1 << SMVAL)/IRmodelSigma, for SMVAL = 16*/
    int32_t IRscaledModelSigma[3];

} ia_pal_isp_rgb_ir_2_0_t;

/*! \isp struct rgbs_grid_1_1

*/
typedef struct
{
    /*!< grid_height represents number of vertical grid cells*/
    int32_t grid_height;
    /*!< grid_width represents number of horizontal grid cells*/
    int32_t grid_width;
    /*!< block_width Log2 the width of each grid cell (8,16,32,64,128)*/
    int32_t block_width;
    /*!< block_height Log2 the height of each grid cell (8,16,32,64,128)*/
    int32_t block_height;
    /*!< min_out_bytes_per_cell Minimum bytes per grid cell in output buffer (pad with '0's in MSB side if not met otherwise)*/
    int32_t min_out_bytes_per_cell;
    /*!< rgbs_en 0: FF will not write to the RGBS array; 1: FF will write*/
    int32_t rgbs_en;
    /*!< rgbs_incl_sat 0: do not include saturated quads in the average; 1: include saturated quads in the average*/
    int32_t rgbs_incl_sat;
    /*!< x_start X top left corner of the grid. 0 <= x_start <= (frame_width - 1)*/
    int32_t x_start;
    /*!< y_start Y top left corner of the grid. 0 <= y_start <= (frame_height - 1)*/
    int32_t y_start;
    /*!< x_end X bottom right corner of the grid. x_end = x_start + (grid_width << block_width) - 1*/
    int32_t x_end;
    /*!< y_end Y bottom right corner of the grid. y_end = y_start + (grid_height << block_height) - 1*/
    int32_t y_end;
    /*!< sensor_mode 0: 1x1 CFA (array sensor); 1: 2 x 2 CFA; 2: 4 x 4 CFA*/
    int32_t sensor_mode;
    /*!< pat_00 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_00;
    /*!< pat_01 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_01;
    /*!< pat_02 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_02;
    /*!< pat_03 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_03;
    /*!< pat_10 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_10;
    /*!< pat_11 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_11;
    /*!< pat_12 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_12;
    /*!< pat_13 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_13;
    /*!< pat_20 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_20;
    /*!< pat_21 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_21;
    /*!< pat_22 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_22;
    /*!< pat_23 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_23;
    /*!< pat_30 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_30;
    /*!< pat_31 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_31;
    /*!< pat_32 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_32;
    /*!< pat_33 defines the color ID of the pixel in the CFA pattern; Pat_ij: i - row, j - column*/
    int32_t pat_33;
    /*!< rgbs_thr_cx[8] RGBS threshold value (C0, C1, C2, C3, C4, C5, C6, C7)*/
    int32_t rgbs_thr_cx[8];
    /*!< shftr_val_cx[8] ShiftVal is derived from log2(number of pixels from C0-C7 color channel in a cell)*/
    int32_t shftr_val_cx[8];
    /*!< shftr_sat represents log2(num of pixels in cell)*/
    int32_t shftr_sat;
    /*!< output_packed Enabling Output packing. Use 0 if ColorID [0 3] are used, Use 1 if all ColorIDs i.e. [0 7] are used (i.e. multi-exposure (e.g. SVE) use-cases)*/
    int32_t output_packed;
    /*!< copy_out_components bit0: copy_enable_colorid0, bit1..3: copy_src_colorid, bit4: copy_enable_colorid1, bit5..7: copy_src_colorid, ... , bit28: copy_enable_colorid7, bit29..31: copy_src_colorid*/
    uint32_t copy_out_components;

} ia_pal_isp_rgbs_grid_1_1_t;

/*! \isp struct smurf_1_0

*/
typedef struct
{
    /*!< enable enables the filter, if disabled the input is copied to the output*/
    int32_t enable;
    /*!< downscale_factor U1.15, ws / wt, reciprocal of upscaling ratio*/
    int32_t downscale_factor;
    /*!< x_start U13.15 location of the center of the top-left pixel*/
    int32_t x_start;
    /*!< y_start U13.15 location of the center of the top-left pixel*/
    int32_t y_start;
    /*!< in_width input image width*/
    int32_t in_width;
    /*!< in_height input image height*/
    int32_t in_height;
    /*!< out_width output image width*/
    int32_t out_width;
    /*!< out_height output image height*/
    int32_t out_height;

} ia_pal_isp_smurf_1_0_t;

/*! \isp struct tnr_scaler_1_1

*/
typedef struct
{
    /*!< enable enable TNR_SCALE_1_0 filter*/
    int32_t enable;
    /*!< inWidth Number of pixels per row at output*/
    int32_t inWidth;
    /*!< inHeight Number of rows at output*/
    int32_t inHeight;
    /*!< bitReductionBypass bypass of bit reduction of input pixels*/
    int32_t bitReductionBypass;
    /*!< inputShift shift on input pixels*/
    int32_t inputShift;
    /*!< cu_bit_reduce_x[6] input bit reduction config unit - x values*/
    int32_t cu_bit_reduce_x[6];
    /*!< cu_bit_reduce_y[5] input bit reduction config unit - y values*/
    int32_t cu_bit_reduce_y[5];
    /*!< cu_bit_reduce_slope[5] input bit reduction config unit - slope values*/
    int32_t cu_bit_reduce_slope[5];

} ia_pal_isp_tnr_scaler_1_1_t;

/*! \isp struct tnr7_bc_1_2

*/
typedef struct
{
    /*!< enable block enable*/
    int32_t enable;
    /*!< is_first_frame If first frame, ignore input rec-sim*/
    int32_t is_first_frame;
    /*!< is_segmentation_aware SAP enable*/
    int32_t is_segmentation_aware;
    /*!< do_update Limit of S&R parameter update mechanism*/
    int32_t do_update;
    /*!< coeffs[3] Per-region mult-and-clamp coefficients*/
    int32_t coeffs[3];
    /*!< coeffs_user[3] Per-region mult-and-clamp coefficients (specified by user during offline calibration)*/
    int32_t coeffs_user[3];
    /*!< tune_sensitivity user tuning - alignment-conf sensitivity*/
    int32_t tune_sensitivity;
    /*!< tune_sensitivity_class[16] user tuning - alignment-conf sensitivity*/
    int32_t tune_sensitivity_class[16];
    /*!< global_protection global protection enable*/
    int32_t global_protection;
    /*!< global_protection_sensitivity_lut_values[3] global protection - LUT values*/
    int32_t global_protection_sensitivity_lut_values[3];
    /*!< global_protection_sensitivity_lut_slopes[2] global protection - LUT slopes*/
    int32_t global_protection_sensitivity_lut_slopes[2];
    /*!< global_protection_motion_level average alignment conf of previous frame*/
    int32_t global_protection_motion_level;
    /*!< global_protection_motion_level_user average alignment conf of previous frame (specified by user during offline calibration)*/
    int32_t global_protection_motion_level_user;
    /*!< global_protection_inv_num_pixels inverse of number of pixels in frame - prec is U0.20*/
    int32_t global_protection_inv_num_pixels;
    /*!< stats_collection_boundaries[2] columns where statitcis collection takes place*/
    int32_t stats_collection_boundaries[2];
    /*!< acc_AC accumulator for sum of alignment confidence*/
    int32_t acc_AC;
    /*!< acc_num_safe_pixels accumulator for num of safe pixels*/
    int32_t acc_num_safe_pixels;
    /*!< acc_histogram[189] APU histogram*/
    int32_t acc_histogram[189];
    /*!< is_first_stripe is first stripe in frame*/
    int32_t is_first_stripe;
    /*!< is_last_stripe is last stripe in frame*/
    int32_t is_last_stripe;
    /*!< bgm_is_overlap[16] defines which segment is an overlap segment*/
    int32_t bgm_is_overlap[16];
    /*!< bgm_global_protection_th defines which segment is an overlap segment*/
    int32_t bgm_global_protection_th;

} ia_pal_isp_tnr7_bc_1_2_t;

/*! \isp struct tnr7_blend_1_1

*/
typedef struct
{
    /*!< enable Enable TNR7 blend*/
    int32_t enable;
    /*!< is_segmentation_aware SAP enable*/
    int32_t is_segmentation_aware;
    /*!< denoise_power_class[16] Segmentation-aware denoise power*/
    int32_t denoise_power_class[16];
    /*!< single_output_mode Both outputs use the same blend*/
    int32_t single_output_mode;
    /*!< spatial_weight_coeff Spatial weight coeff to be used in single_output_mode*/
    int32_t spatial_weight_coeff;
    /*!< max_recursive_similarity Maximum value of recursive similarity*/
    int32_t max_recursive_similarity;
    /*!< max_recursive_similarity_class[16] Maximum value of recursive similarity*/
    int32_t max_recursive_similarity_class[16];
    /*!< spatial_alpha Use of spatial filtering in the feedback output*/
    int32_t spatial_alpha;
    /*!< w_out_prev_LUT[32] Weight of reference in the main output*/
    int32_t w_out_prev_LUT[32];
    /*!< w_out_spl_LUT[32] Weight of spatial in the main output*/
    int32_t w_out_spl_LUT[32];
    /*!< bgm_is_overlap[16] defines which segment is an overlap segment*/
    int32_t bgm_is_overlap[16];
    /*!< bgm_alpha_output[16] alpha value for blending the output image*/
    int32_t bgm_alpha_output[16];
    /*!< bgm_alpha_fb[16] alpha value for blending the feedback image*/
    int32_t bgm_alpha_fb[16];

} ia_pal_isp_tnr7_blend_1_1_t;

/*! \isp struct tnr7_ims_1_2

*/
typedef struct
{
    /*!< enable block enable*/
    int32_t enable;
    /*!< update_limit Limit of S&R parameter update mechanism*/
    int32_t update_limit;
    /*!< update_coeff S&R parameter update coefficient*/
    int32_t update_coeff;
    /*!< do_update Enables S&R update mechanism for distance log-likelihood distribution*/
    int32_t do_update;
    /*!< d_ml[16] Maximum-likelihood of distance distribution*/
    int32_t d_ml[16];
    /*!< d_slopes[16] Distance log-likelihood slopes*/
    int32_t d_slopes[16];
    /*!< d_top[16] Distance log-likelihood constants*/
    int32_t d_top[16];
    /*!< outofbounds[16] Is ml value out-of-hostogram-bounds?*/
    int32_t outofbounds[16];
    /*!< d_ml_user[16] Maximum-likelihood of distance distribution (specified by user during offline calibration)*/
    int32_t d_ml_user[16];
    /*!< d_slopes_user[16] Distance log-likelihood slopes (specified by user during offline calibration)*/
    int32_t d_slopes_user[16];
    /*!< d_top_user[16] Distance log-likelihood constants (specified by user during offline calibration)*/
    int32_t d_top_user[16];
    /*!< gpu_mode meta parameter for controlling convolution implementation: 0 - HW implementation  1 - GPU implementation*/
    int32_t gpu_mode;
    /*!< stats_collection_boundaries[2] columns where statitcis collection takes place*/
    int32_t stats_collection_boundaries[2];
    /*!< acc_histogram[512] APU histogram*/
    int32_t acc_histogram[512];
    /*!< is_first_stripe is first stripe in frame*/
    int32_t is_first_stripe;
    /*!< is_last_stripe is last stripe in frame*/
    int32_t is_last_stripe;
    /*!< radial_start radial correction start (relative to frame size)*/
    int32_t radial_start;
    /*!< radial_coeff radial correction power*/
    int32_t radial_coeff;
    /*!< frame_center_y frame center vertical*/
    int32_t frame_center_y;
    /*!< frame_center_x frame center horizontal*/
    int32_t frame_center_x;
    /*!< r_coeff radius relative to frame size*/
    int32_t r_coeff;

} ia_pal_isp_tnr7_ims_1_2_t;

/*! \isp struct tnr7_mc_1_0

*/
typedef struct
{
    /*!< passThrough Passthrough (set the motion vectors to zero when enabled)*/
    int32_t passThrough;
    /*!< imageHeightFR Height (pixels) of the full-resolution image*/
    int32_t imageHeightFR;
    /*!< imageWidthFR Width (pixels) of the full-resolution image*/
    int32_t imageWidthFR;
    /*!< imageHeightDS Height (pixels) of the small-resoltion image*/
    int32_t imageHeightDS;
    /*!< imageWidthDS Width (pixels) of the small-resoltion image*/
    int32_t imageWidthDS;

} ia_pal_isp_tnr7_mc_1_0_t;

/*! \isp struct tnr7_spatial_1_1

*/
typedef struct
{
    /*!< enable Enable TNR7 spatial fallback filter*/
    int32_t enable;
    /*!< noise_model_radius Controls noise model radius*/
    int32_t noise_model_radius;
    /*!< iir_luma_power iir luma filtering strength (0-only fir, 64-only iir)*/
    int32_t iir_luma_power;
    /*!< iir_chroma_power iir chroma filtering strength (0-only fir, 64-only iir)*/
    int32_t iir_chroma_power;
    /*!< luma_strength blending coef for luma channel (blend with input)*/
    int32_t luma_strength;
    /*!< chroma_strength blending coef for chroma channel (blend with input)*/
    int32_t chroma_strength;
    /*!< lumaLUT_v[16] self calibrating noise model (NM) state variables, luma*/
    int32_t lumaLUT_v[16];
    /*!< lumaLUT_v_bins[16] self calibrating noise model (NM) state variables, luma*/
    int32_t lumaLUT_v_bins[16];
    /*!< lumaLUT_v_limits[2] vertical luma NM limnits*/
    int32_t lumaLUT_v_limits[2];
    /*!< nmGain_h_limits[2] horizontal luma NM limnits*/
    int32_t nmGain_h_limits[2];
    /*!< nmGain_iir_limits[2] iir luma NM limnits*/
    int32_t nmGain_iir_limits[2];
    /*!< nmGain_h horizontal NM gain*/
    int32_t nmGain_h;
    /*!< nmGain_iir iir NM gain*/
    int32_t nmGain_iir;
    /*!< update_limit update rate of N lut (0-no update, 256-current frame only)*/
    int32_t update_limit;
    /*!< update_coeff slope of the update rate as a function of #samples*/
    int32_t update_coeff;
    /*!< stats_collection_boundaries[2] columns where statitcis collection takes place*/
    int32_t stats_collection_boundaries[2];
    /*!< acc_histogram_v[256] APU histogram - vertical*/
    int32_t acc_histogram_v[256];
    /*!< acc_histogram_h[16] APU histogram - horizontal*/
    int32_t acc_histogram_h[16];
    /*!< acc_histogram_iir[16] APU histogram - IIR*/
    int32_t acc_histogram_iir[16];
    /*!< is_first_stripe is first stripe in frame*/
    int32_t is_first_stripe;
    /*!< is_last_stripe is last stripe in frame*/
    int32_t is_last_stripe;

} ia_pal_isp_tnr7_spatial_1_1_t;

/*! \isp struct upipe_1_0

*/
typedef struct
{
    /*!< enable enables the filter, if disabled the input is replicated to all three output channels*/
    int32_t enable;
    /*!< input_pattern_0[3] 4x4 pattern to RGB, channels in R,G,B order; default- GRBG*/
    int32_t input_pattern_0[3];
    /*!< demosaic_mode_0 Demosaic mode, 0- 2x2, 1- 4x4. Note that binning interpretation depends on this*/
    int32_t demosaic_mode_0;
    /*!< black_level_0[3] Sensor/ tuned black level, per channel. U10 value*/
    int32_t black_level_0[3];
    /*!< binning_factor_0 Log2 of the downscale to use. This is on top of x4 downscale is demosaic*/
    int32_t binning_factor_0;
    /*!< color_adjust_matrix_0[9] Color correction matrix, S4.11; default- unity*/
    int32_t color_adjust_matrix_0[9];
    /*!< tone_adjust_lut_0[11] Exponential U10 to U8 gamma LUT; default- linear*/
    int32_t tone_adjust_lut_0[11];
    /*!< rgb_to_yuv_matrix_0[9] RGB to YUV matrix, S4.11; default- BT709*/
    int32_t rgb_to_yuv_matrix_0[9];
    /*!< rgb_to_yuv_en_0 0 - Output is in RGB format; 1 - Output is in YUV format*/
    int32_t rgb_to_yuv_en_0;
    /*!< input_pattern_1[3] 4x4 pattern to RGB, channels in R,G,B order; default- GRBG*/
    int32_t input_pattern_1[3];
    /*!< demosaic_mode_1 Demosaic mode, 0- 2x2, 1- 4x4. Note that binning interpretation depends on this*/
    int32_t demosaic_mode_1;
    /*!< black_level_1[3] Sensor/ tuned black level, per channel. U10 value*/
    int32_t black_level_1[3];
    /*!< binning_factor_1 Log2 of the downscale to use. This is on top of x4 downscale is demosaic*/
    int32_t binning_factor_1;
    /*!< color_adjust_matrix_1[9] Color correction matrix, S4.11; default- unity*/
    int32_t color_adjust_matrix_1[9];
    /*!< tone_adjust_lut_1[11] Exponential U10 to U8 gamma LUT; default- linear*/
    int32_t tone_adjust_lut_1[11];
    /*!< rgb_to_yuv_matrix_1[9] RGB to YUV matrix, S4.11; default- BT709*/
    int32_t rgb_to_yuv_matrix_1[9];
    /*!< rgb_to_yuv_en_1 0 - Output is in RGB format; 1 - Output is in YUV format*/
    int32_t rgb_to_yuv_en_1;

} ia_pal_isp_upipe_1_0_t;

/*! \isp struct upscaler_1_1

*/
typedef struct
{
    /*!< upscale_enable enable scaling filter*/
    int32_t upscale_enable;
    /*!< scaling_ratio U1.16 , upscale - less than 1, equals to 1/uspcale_factor*/
    int32_t scaling_ratio;
    /*!< output_height Output height counted in number of lines*/
    int32_t output_height;
    /*!< output_width Output width counted in number of pixels components per line*/
    int32_t output_width;
    /*!< upscale_x_offset S0.16 location of the center of the top-left pixel*/
    int32_t upscale_x_offset;
    /*!< upscale_y_offset S0.16 location of the center of the top-left pixel*/
    int32_t upscale_y_offset;
    /*!< kernel_LUT[129] S1.10 Y+UV channels Interpolation vertical kernel coefficients for scaler*/
    int32_t kernel_LUT[129];
    /*!< chroma_kernel_LUT[129] S1.10 Y+UV channels Interpolation vertical kernel coefficients for scaler*/
    int32_t chroma_kernel_LUT[129];
    /*!< cropper_input_width cropper Input width counted in number of pixels components per line*/
    int32_t cropper_input_width;
    /*!< cropper_input_height cropper Input height counted in number of lines*/
    int32_t cropper_input_height;
    /*!< cropper_x_output_offset Output horizontal offset from the input, counted in number of pixels components per line, 16b signed (if negative padding is required)*/
    int32_t cropper_x_output_offset;
    /*!< cropper_y_output_offset cropper Output vertical offset from the input counted in number of lines, 16b signed*/
    int32_t cropper_y_output_offset;
    /*!< cropper_output_width cropper output width, equals upscaler input height*/
    int32_t cropper_output_width;
    /*!< cropper_output_height cropper output height, equals upscaler input height*/
    int32_t cropper_output_height;
    /*!< upscale_input_height upscaler input height, equals to cropper_output_height*/
    int32_t upscale_input_height;
    /*!< upscale_input_width upscaler input width, equals to cropper_output_width*/
    int32_t upscale_input_width;

} ia_pal_isp_upscaler_1_1_t;

/*! \isp struct vcr_3_1

*/
typedef struct
{
    /*!< enable enables the filter (YUV420 --> RGB444)*/
    int32_t enable;
    /*!< nb1 offset 1 yuv2rgb conversion, rgb = m * yuv + nb*/
    int32_t nb1;
    /*!< nb2 offset 2 yuv2rgb conversion, rgb = m * yuv + nb*/
    int32_t nb2;
    /*!< nb3 offset 3 yuv2rgb conversion, rgb = m * yuv + nb*/
    int32_t nb3;
    /*!< yuv2rgb_matrix[9] yuv to rgb conversion matrix, S4.11*/
    int32_t yuv2rgb_matrix[9];

} ia_pal_isp_vcr_3_1_t;

/*! \isp struct vcsc_2_0

*/
typedef struct
{
    /*!< csc_c_matrix_arr[9] CSC Matrix components (S0.15)*/
    int32_t csc_c_matrix_arr[9];
    /*!< csc_b_vec_arr[3] CSC Vector components (S0.15)*/
    int32_t csc_b_vec_arr[3];
    /*!< chroma_ds_coeff_arr[8] Chroma downsample 4x2 filter coefficients (U2.0)*/
    int32_t chroma_ds_coeff_arr[8];
    /*!< chroma_ds_nf Chroma downsample 4x2 filter normalization factor*/
    int32_t chroma_ds_nf;
    /*!< enable Bypassing CSC. Outputting RGB to the Chroma downscale*/
    int32_t enable;
    /*!< uv_bin_output 0 = YUV4:2:0 output, 1 = YUV4:2:2 output*/
    int32_t uv_bin_output;

} ia_pal_isp_vcsc_2_0_t;

/*! \isp struct wb_1_1

*/
typedef struct
{
    /*!< bypass Bypass            {0,1}*/
    int32_t bypass;
    /*!< gainch0 Gain Channel0 (Gr) (U8.12)*/
    int32_t gainch0;
    /*!< gainch1 Gain Channel1 (Gb) (U8.12)*/
    int32_t gainch1;
    /*!< gainch2 Gain Channel2 (G)  (U8.12)*/
    int32_t gainch2;
    /*!< gainch3 Gain Channel3 (B)  (U8.12)*/
    int32_t gainch3;
    /*!< gainch4 Gain Channel4 (R)  (U8.12)*/
    int32_t gainch4;
    /*!< gainch5 Gain Channel5 (W)  (U8.12)*/
    int32_t gainch5;
    /*!< gainch6 Gain Channel6 (U8.12)*/
    int32_t gainch6;
    /*!< gainch7 Gain Channel7 (U8.12)*/
    int32_t gainch7;
    /*!< sensormode Sensor CFA size: 1x1 (0), 2x2 (1), 4x4 (2)*/
    int32_t sensormode;
    /*!< wbindmat[16] Vector WB matrix*/
    int32_t wbindmat[16];

} ia_pal_isp_wb_1_1_t;

/*! \isp struct xnr_5_4
Low Frequency Chroma Denoiser
*/
typedef struct
{
    /*!< top_frame_width XNR5 input frame width*/
    int32_t top_frame_width;
    /*!< top_frame_height XNR5 input frame height*/
    int32_t top_frame_height;
    /*!< top_xnr_bypass Bypass entire xnr*/
    int32_t top_xnr_bypass;
    /*!< vhf_frame_width XNR5 input frame width*/
    int32_t vhf_frame_width;
    /*!< vhf_frame_height XNR5 input frame height*/
    int32_t vhf_frame_height;
    /*!< vhf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t vhf_low_band_disable;
    /*!< vhf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t vhf_low_band_only;
    /*!< hf_frame_width XNR5 input frame width*/
    int32_t hf_frame_width;
    /*!< hf_frame_height XNR5 input frame height*/
    int32_t hf_frame_height;
    /*!< hf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t hf_low_band_disable;
    /*!< hf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t hf_low_band_only;
    /*!< hf_nr_bypass Input YUV goes directly to output after vertical delay*/
    int32_t hf_nr_bypass;
    /*!< hf_se_bypass Replace all SE outputs with se_bypass_val*/
    int32_t hf_se_bypass;
    /*!< hf_se_bypass_val SE bypass value*/
    int32_t hf_se_bypass_val;
    /*!< mf_frame_width XNR5 input frame width*/
    int32_t mf_frame_width;
    /*!< mf_frame_height XNR5 input frame height*/
    int32_t mf_frame_height;
    /*!< mf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t mf_low_band_disable;
    /*!< mf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t mf_low_band_only;
    /*!< mf_nr_bypass Input YUV goes directly to output after vertical delay*/
    int32_t mf_nr_bypass;
    /*!< mf_se_bypass Replace all SE outputs with se_bypass_val*/
    int32_t mf_se_bypass;
    /*!< mf_se_bypass_val SE bypass value*/
    int32_t mf_se_bypass_val;
    /*!< lf_frame_width XNR5 input frame width*/
    int32_t lf_frame_width;
    /*!< lf_frame_height XNR5 input frame height*/
    int32_t lf_frame_height;
    /*!< lf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t lf_low_band_disable;
    /*!< lf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t lf_low_band_only;
    /*!< lf_nr_bypass Input YUV goes directly to output after vertical delay*/
    int32_t lf_nr_bypass;
    /*!< lf_se_bypass Replace all SE outputs with se_bypass_val*/
    int32_t lf_se_bypass;
    /*!< lf_se_bypass_val SE bypass value*/
    int32_t lf_se_bypass_val;
    /*!< vlf_frame_width XNR5 input frame width*/
    int32_t vlf_frame_width;
    /*!< vlf_frame_height XNR5 input frame height*/
    int32_t vlf_frame_height;
    /*!< vlf_low_band_disable Lower band is disabled and zero on inputs*/
    int32_t vlf_low_band_disable;
    /*!< vlf_low_band_only Lower band directly goes to output and other inputs are zeroes*/
    int32_t vlf_low_band_only;
    /*!< vlf_nr_bypass Input YUV goes directly to output after vertical delay*/
    int32_t vlf_nr_bypass;
    /*!< vlf_se_bypass Replace all SE outputs with se_bypass_val*/
    int32_t vlf_se_bypass;
    /*!< vlf_se_bypass_val SE bypass value*/
    int32_t vlf_se_bypass_val;
    /*!< Bypass Deprecated bypass parameter - to be removed!*/
    int32_t Bypass;
    /*!< top_viir_coefs_b[3] Param_Top_VIIR_b*/
    int32_t top_viir_coefs_b[3];
    /*!< top_viir_coefs_a[2] Param_Top_VIIR_a*/
    int32_t top_viir_coefs_a[2];
    /*!< top_viir_offset Param_Top_VIIR_offset*/
    int32_t top_viir_offset;
    /*!< top_viir_alpha Param_Top_VIIR_alpha*/
    int32_t top_viir_alpha;
    /*!< top_hus_vlf_image_coefs[9] Param_Top_HUS_VLF_Image_func*/
    int32_t top_hus_vlf_image_coefs[9];
    /*!< top_hus_vlf_delta_coefs[9] Param_Top_HUS_VLF_Delta_func*/
    int32_t top_hus_vlf_delta_coefs[9];
    /*!< top_hus_lf_image_coefs[5] Param_Top_HUS_LF_Image_func*/
    int32_t top_hus_lf_image_coefs[5];
    /*!< top_hus_lf_delta_coefs[5] Param_Top_HUS_LF_Delta_func*/
    int32_t top_hus_lf_delta_coefs[5];
    /*!< top_hus_mf_image_coefs[5] Param_Top_HUS_MF_Image_func*/
    int32_t top_hus_mf_image_coefs[5];
    /*!< top_hus_mf_delta_coefs[5] Param_Top_HUS_MF_Delta_func*/
    int32_t top_hus_mf_delta_coefs[5];
    /*!< hf_blf_2dfir_filter_length Param_HFC_BLF_FIR_BfLen*/
    int32_t hf_blf_2dfir_filter_length;
    /*!< hf_blf_2dfir_dcdc_bypass_y Param_HFC_BLF_FIR_bypassDCDifferentialCompensationY*/
    int32_t hf_blf_2dfir_dcdc_bypass_y;
    /*!< hf_blf_2dfir_dcdc_thresh_y_y Param_HFC_BLF_FIR_DCDiffThYy*/
    uint32_t hf_blf_2dfir_dcdc_thresh_y_y;
    /*!< hf_blf_2dfir_dcdc_thresh_y_u Param_HFC_BLF_FIR_DCDiffThYu*/
    uint32_t hf_blf_2dfir_dcdc_thresh_y_u;
    /*!< hf_blf_2dfir_dcdc_thresh_y_v Param_HFC_BLF_FIR_DCDiffThYv*/
    uint32_t hf_blf_2dfir_dcdc_thresh_y_v;
    /*!< hf_blf_2dfir_dcdc_bypass_uv Param_HFC_BLF_FIR_bypassDCDifferentialCompensationUV*/
    int32_t hf_blf_2dfir_dcdc_bypass_uv;
    /*!< hf_blf_2dfir_dcdc_thresh_uv_y Param_HFC_BLF_FIR_DCDiffThUVy*/
    uint32_t hf_blf_2dfir_dcdc_thresh_uv_y;
    /*!< hf_blf_2dfir_dcdc_thresh_uv_u Param_HFC_BLF_FIR_DCDiffThUVu*/
    uint32_t hf_blf_2dfir_dcdc_thresh_uv_u;
    /*!< hf_blf_2dfir_dcdc_thresh_uv_v Param_HFC_BLF_FIR_DCDiffThUVv*/
    uint32_t hf_blf_2dfir_dcdc_thresh_uv_v;
    /*!< hf_blf_colorspace Param_HFC_BLF_colorspaceYRB*/
    int32_t hf_blf_colorspace;
    /*!< hf_blf_noisemodel_basefunc_y_a_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t hf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< hf_blf_noisemodel_basefunc_y_a_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacY_A_Y*/
    int32_t hf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< hf_blf_noisemodel_basefunc_y_a_slope[4] Param_HFC_BLF_NoiseModel_sigmaParafacY_A_Slope*/
    int32_t hf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< hf_blf_noisemodel_basefunc_y_b_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacY_B_X*/
    int32_t hf_blf_noisemodel_basefunc_y_b_x[5];
    /*!< hf_blf_noisemodel_basefunc_y_b_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacY_B Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_y_b_y[4];
    /*!< hf_blf_noisemodel_basefunc_y_b_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_y_b_slope[4];
    /*!< hf_blf_noisemodel_basefunc_y_c_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacY_C_X*/
    int32_t hf_blf_noisemodel_basefunc_y_c_x[5];
    /*!< hf_blf_noisemodel_basefunc_y_c_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacY_C Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_y_c_y[4];
    /*!< hf_blf_noisemodel_basefunc_y_c_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_y_c_slope[4];
    /*!< hf_blf_noisemodel_basefunc_y_wbg Param_HFC_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t hf_blf_noisemodel_basefunc_y_wbg;
    /*!< hf_blf_noisemodel_basefunc_u_a_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacU_A_X*/
    int32_t hf_blf_noisemodel_basefunc_u_a_x[5];
    /*!< hf_blf_noisemodel_basefunc_u_a_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacU_A Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_u_a_y[4];
    /*!< hf_blf_noisemodel_basefunc_u_a_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_u_a_slope[4];
    /*!< hf_blf_noisemodel_basefunc_u_b_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacU_B_X*/
    int32_t hf_blf_noisemodel_basefunc_u_b_x[5];
    /*!< hf_blf_noisemodel_basefunc_u_b_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacU_B Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_u_b_y[4];
    /*!< hf_blf_noisemodel_basefunc_u_b_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_u_b_slope[4];
    /*!< hf_blf_noisemodel_basefunc_u_c_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacU_C_X*/
    int32_t hf_blf_noisemodel_basefunc_u_c_x[5];
    /*!< hf_blf_noisemodel_basefunc_u_c_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacU_C Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_u_c_y[4];
    /*!< hf_blf_noisemodel_basefunc_u_c_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_u_c_slope[4];
    /*!< hf_blf_noisemodel_basefunc_u_wbg Param_HFC_BLF_NoiseModel_sigmaParafacU_DEF*/
    int32_t hf_blf_noisemodel_basefunc_u_wbg;
    /*!< hf_blf_noisemodel_basefunc_v_a_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacV_A_X*/
    int32_t hf_blf_noisemodel_basefunc_v_a_x[5];
    /*!< hf_blf_noisemodel_basefunc_v_a_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacV_A Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_v_a_y[4];
    /*!< hf_blf_noisemodel_basefunc_v_a_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_v_a_slope[4];
    /*!< hf_blf_noisemodel_basefunc_v_b_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacV_B_X*/
    int32_t hf_blf_noisemodel_basefunc_v_b_x[5];
    /*!< hf_blf_noisemodel_basefunc_v_b_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacV_B Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_v_b_y[4];
    /*!< hf_blf_noisemodel_basefunc_v_b_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_v_b_slope[4];
    /*!< hf_blf_noisemodel_basefunc_v_c_x[5] Param_HFC_BLF_NoiseModel_sigmaParafacV_C_X*/
    int32_t hf_blf_noisemodel_basefunc_v_c_x[5];
    /*!< hf_blf_noisemodel_basefunc_v_c_y[4] Param_HFC_BLF_NoiseModel_sigmaParafacV_C Config Unit Value*/
    int32_t hf_blf_noisemodel_basefunc_v_c_y[4];
    /*!< hf_blf_noisemodel_basefunc_v_c_slope[4] Slope*/
    int32_t hf_blf_noisemodel_basefunc_v_c_slope[4];
    /*!< hf_blf_noisemodel_basefunc_v_wbg Param_HFC_BLF_NoiseModel_sigmaParafacV_DEF*/
    int32_t hf_blf_noisemodel_basefunc_v_wbg;
    /*!< hf_blf_noisemodel_weight_uv_y Param_HFC_BLF_NoiseModel_sigmaWgtUVy*/
    int32_t hf_blf_noisemodel_weight_uv_y;
    /*!< hf_blf_noisemodel_weight_uv_u Param_HFC_BLF_NoiseModel_sigmaWgtUVu*/
    int32_t hf_blf_noisemodel_weight_uv_u;
    /*!< hf_blf_noisemodel_weight_uv_v Param_HFC_BLF_NoiseModel_sigmaWgtUVv*/
    int32_t hf_blf_noisemodel_weight_uv_v;
    /*!< hf_blf_noisemodel_radialdependent_bypass Param_HFC_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t hf_blf_noisemodel_radialdependent_bypass;
    /*!< hf_blf_noisemodel_colordependent_bypass Param_HFC_BLF_NoiseModel_bypassColorDependent*/
    int32_t hf_blf_noisemodel_colordependent_bypass;
    /*!< hf_blf_noisemodel_graydependent_bypass Param_HFC_BLF_NoiseModel_bypassGrayDependent*/
    int32_t hf_blf_noisemodel_graydependent_bypass;
    /*!< hf_blf_noisemodel_radialdependent_x0 Param_HFC_BLF_NoiseModel_radialDependent_x0*/
    int32_t hf_blf_noisemodel_radialdependent_x0;
    /*!< hf_blf_noisemodel_radialdependent_x0_square Param_HFC_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t hf_blf_noisemodel_radialdependent_x0_square;
    /*!< hf_blf_noisemodel_radialdependent_y0 Param_HFC_BLF_NoiseModel_radialDependent_y0*/
    int32_t hf_blf_noisemodel_radialdependent_y0;
    /*!< hf_blf_noisemodel_radialdependent_y0_square Param_HFC_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t hf_blf_noisemodel_radialdependent_y0_square;
    /*!< hf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_HFC_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t hf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< hf_blf_noisemodel_radialdependent_gain_x[4] Param_HFC_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t hf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< hf_blf_noisemodel_radialdependent_gain_y[3] Param_HFC_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t hf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< hf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t hf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< hf_blf_noisemodel_colordependent_a[32] Param_HFC_BLF_NoiseModel_colorDependent_A*/
    int32_t hf_blf_noisemodel_colordependent_a[32];
    /*!< hf_blf_noisemodel_colordependent_b[32] Param_HFC_BLF_NoiseModel_colorDependent_B*/
    int32_t hf_blf_noisemodel_colordependent_b[32];
    /*!< hf_blf_noisemodel_colordependent_c[32] Param_HFC_BLF_NoiseModel_colorDependent_C*/
    int32_t hf_blf_noisemodel_colordependent_c[32];
    /*!< hf_blf_noisemodel_colordependent_norm_offset Param_HFC_BLF_NoiseModel_colorDependent_normalization_offset*/
    int32_t hf_blf_noisemodel_colordependent_norm_offset;
    /*!< hf_blf_noisemodel_colordependent_gain_x[6] Param_HFC_BLF_NoiseModel_colorDependent_Lut_X*/
    int32_t hf_blf_noisemodel_colordependent_gain_x[6];
    /*!< hf_blf_noisemodel_colordependent_gain_y[5] Param_HFC_BLF_NoiseModel_colorDependent_Lut Config Unit Value*/
    int32_t hf_blf_noisemodel_colordependent_gain_y[5];
    /*!< hf_blf_noisemodel_colordependent_gain_slope[5] Slope*/
    int32_t hf_blf_noisemodel_colordependent_gain_slope[5];
    /*!< hf_blf_noisemodel_graydependent_graylevel_thresh Param_HFC_BLF_NoiseModel_grayDependent_grayThrsh*/
    int32_t hf_blf_noisemodel_graydependent_graylevel_thresh;
    /*!< hf_blf_noisemodel_graydependent_graylevel_slope Param_HFC_BLF_NoiseModel_grayDependent_graySlope*/
    int32_t hf_blf_noisemodel_graydependent_graylevel_slope;
    /*!< hf_blf_noisemodel_graydependent_gain_x[6] Param_HFC_BLF_NoiseModel_grayDependent_transLut_X*/
    int32_t hf_blf_noisemodel_graydependent_gain_x[6];
    /*!< hf_blf_noisemodel_graydependent_gain_y[5] Param_HFC_BLF_NoiseModel_grayDependent_transLut Config Unit Value*/
    int32_t hf_blf_noisemodel_graydependent_gain_y[5];
    /*!< hf_blf_noisemodel_graydependent_gain_slope[5] Slope*/
    int32_t hf_blf_noisemodel_graydependent_gain_slope[5];
    /*!< hf_blf_noisemodel_normfactor_uv_y Param_HFC_BLF_NoiseModel_invSigmaUVy*/
    int32_t hf_blf_noisemodel_normfactor_uv_y;
    /*!< hf_blf_noisemodel_normfactor_uv_u Param_HFC_BLF_NoiseModel_invSigmaUVu*/
    int32_t hf_blf_noisemodel_normfactor_uv_u;
    /*!< hf_blf_noisemodel_normfactor_uv_v Param_HFC_BLF_NoiseModel_invSigmaUVv*/
    int32_t hf_blf_noisemodel_normfactor_uv_v;
    /*!< hf_blf_snrm_bypass Param_HFC_BLF_SNRM_bypassSNRManagement*/
    int32_t hf_blf_snrm_bypass;
    /*!< hf_blf_snrm_slope_uv Param_HFC_BLF_SNRM_slopeUV*/
    int32_t hf_blf_snrm_slope_uv;
    /*!< hf_blf_snrm_xoffset_uv Param_HFC_BLF_SNRM_xoffsetUV*/
    int32_t hf_blf_snrm_xoffset_uv;
    /*!< hf_blf_snrm_maxval_uv Param_HFC_BLF_SNRM_maxValUV*/
    int32_t hf_blf_snrm_maxval_uv;
    /*!< hf_blf_snrm_minval_uv Param_HFC_BLF_SNRM_minValUV*/
    int32_t hf_blf_snrm_minval_uv;
    /*!< hf_afc_bypass Param_HFC_AFC_bypassAntiFalseColor*/
    int32_t hf_afc_bypass;
    /*!< hf_afc_weight_snr Param_HFC_AFC_wgtSnr*/
    int32_t hf_afc_weight_snr;
    /*!< hf_afc_weight_chroma Param_HFC_AFC_wgtC*/
    int32_t hf_afc_weight_chroma;
    /*!< hf_min_distance_clamp Param_HFC_min_distance_clamp*/
    int32_t hf_min_distance_clamp;
    /*!< mf_blf_2dfir_filter_length Param_MF_BLF_FIR_BfLen*/
    int32_t mf_blf_2dfir_filter_length;
    /*!< mf_blf_2dfir_luma_coefs[10] Param_MF_BLF_FIR_Kn_coef*/
    int32_t mf_blf_2dfir_luma_coefs[10];
    /*!< mf_blf_2dfir_luma_denom_bits Param_MF_BLF_FIR_Kn_denom_bits*/
    int32_t mf_blf_2dfir_luma_denom_bits;
    /*!< mf_blf_2dfir_dcdc_bypass_y Param_MF_BLF_FIR_bypassDCDifferentialCompensationY*/
    int32_t mf_blf_2dfir_dcdc_bypass_y;
    /*!< mf_blf_2dfir_dcdc_thresh_y_y Param_MF_BLF_FIR_DCDiffThYy*/
    uint32_t mf_blf_2dfir_dcdc_thresh_y_y;
    /*!< mf_blf_2dfir_dcdc_thresh_y_u Param_MF_BLF_FIR_DCDiffThYu*/
    uint32_t mf_blf_2dfir_dcdc_thresh_y_u;
    /*!< mf_blf_2dfir_dcdc_thresh_y_v Param_MF_BLF_FIR_DCDiffThYv*/
    uint32_t mf_blf_2dfir_dcdc_thresh_y_v;
    /*!< mf_blf_2dfir_dcdc_bypass_uv Param_MF_BLF_FIR_bypassDCDifferentialCompensationUV*/
    int32_t mf_blf_2dfir_dcdc_bypass_uv;
    /*!< mf_blf_2dfir_dcdc_thresh_uv_y Param_MF_BLF_FIR_DCDiffThUVy*/
    uint32_t mf_blf_2dfir_dcdc_thresh_uv_y;
    /*!< mf_blf_2dfir_dcdc_thresh_uv_u Param_MF_BLF_FIR_DCDiffThUVu*/
    uint32_t mf_blf_2dfir_dcdc_thresh_uv_u;
    /*!< mf_blf_2dfir_dcdc_thresh_uv_v Param_MF_BLF_FIR_DCDiffThUVv*/
    uint32_t mf_blf_2dfir_dcdc_thresh_uv_v;
    /*!< mf_blf_2dfir_bypass_snr_y Param_MF_BLF_FIR_bypasssSnrY*/
    int32_t mf_blf_2dfir_bypass_snr_y;
    /*!< mf_blf_colorspace Param_MF_BLF_colorspaceYRB*/
    int32_t mf_blf_colorspace;
    /*!< mf_blf_noisemodel_basefunc_y_a_x[5] Param_MF_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t mf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< mf_blf_noisemodel_basefunc_y_a_y[4] Param_MF_BLF_NoiseModel_sigmaParafacY_A Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< mf_blf_noisemodel_basefunc_y_a_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< mf_blf_noisemodel_basefunc_y_b_x[5] Param_MF_BLF_NoiseModel_sigmaParafacY_B_X*/
    int32_t mf_blf_noisemodel_basefunc_y_b_x[5];
    /*!< mf_blf_noisemodel_basefunc_y_b_y[4] Param_MF_BLF_NoiseModel_sigmaParafacY_B Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_y_b_y[4];
    /*!< mf_blf_noisemodel_basefunc_y_b_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_y_b_slope[4];
    /*!< mf_blf_noisemodel_basefunc_y_c_x[5] Param_MF_BLF_NoiseModel_sigmaParafacY_C_X*/
    int32_t mf_blf_noisemodel_basefunc_y_c_x[5];
    /*!< mf_blf_noisemodel_basefunc_y_c_y[4] Param_MF_BLF_NoiseModel_sigmaParafacY_C Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_y_c_y[4];
    /*!< mf_blf_noisemodel_basefunc_y_c_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_y_c_slope[4];
    /*!< mf_blf_noisemodel_basefunc_y_wbg Param_MF_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t mf_blf_noisemodel_basefunc_y_wbg;
    /*!< mf_blf_noisemodel_basefunc_u_a_x[5] Param_MF_BLF_NoiseModel_sigmaParafacU_A_X*/
    int32_t mf_blf_noisemodel_basefunc_u_a_x[5];
    /*!< mf_blf_noisemodel_basefunc_u_a_y[4] Param_MF_BLF_NoiseModel_sigmaParafacU_A Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_u_a_y[4];
    /*!< mf_blf_noisemodel_basefunc_u_a_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_u_a_slope[4];
    /*!< mf_blf_noisemodel_basefunc_u_b_x[5] Param_MF_BLF_NoiseModel_sigmaParafacU_B_X*/
    int32_t mf_blf_noisemodel_basefunc_u_b_x[5];
    /*!< mf_blf_noisemodel_basefunc_u_b_y[4] Param_MF_BLF_NoiseModel_sigmaParafacU_B Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_u_b_y[4];
    /*!< mf_blf_noisemodel_basefunc_u_b_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_u_b_slope[4];
    /*!< mf_blf_noisemodel_basefunc_u_c_x[5] Param_MF_BLF_NoiseModel_sigmaParafacU_C_X*/
    int32_t mf_blf_noisemodel_basefunc_u_c_x[5];
    /*!< mf_blf_noisemodel_basefunc_u_c_y[4] Param_MF_BLF_NoiseModel_sigmaParafacU_C Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_u_c_y[4];
    /*!< mf_blf_noisemodel_basefunc_u_c_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_u_c_slope[4];
    /*!< mf_blf_noisemodel_basefunc_u_wbg Param_MF_BLF_NoiseModel_sigmaParafacU_DEF*/
    int32_t mf_blf_noisemodel_basefunc_u_wbg;
    /*!< mf_blf_noisemodel_basefunc_v_a_x[5] Param_MF_BLF_NoiseModel_sigmaParafacV_A_X*/
    int32_t mf_blf_noisemodel_basefunc_v_a_x[5];
    /*!< mf_blf_noisemodel_basefunc_v_a_y[4] Param_MF_BLF_NoiseModel_sigmaParafacV_A Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_v_a_y[4];
    /*!< mf_blf_noisemodel_basefunc_v_a_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_v_a_slope[4];
    /*!< mf_blf_noisemodel_basefunc_v_b_x[5] Param_MF_BLF_NoiseModel_sigmaParafacV_B_X*/
    int32_t mf_blf_noisemodel_basefunc_v_b_x[5];
    /*!< mf_blf_noisemodel_basefunc_v_b_y[4] Param_MF_BLF_NoiseModel_sigmaParafacV_B Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_v_b_y[4];
    /*!< mf_blf_noisemodel_basefunc_v_b_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_v_b_slope[4];
    /*!< mf_blf_noisemodel_basefunc_v_c_x[5] Param_MF_BLF_NoiseModel_sigmaParafacV_C_X*/
    int32_t mf_blf_noisemodel_basefunc_v_c_x[5];
    /*!< mf_blf_noisemodel_basefunc_v_c_y[4] Param_MF_BLF_NoiseModel_sigmaParafacV_C Config Unit Value*/
    int32_t mf_blf_noisemodel_basefunc_v_c_y[4];
    /*!< mf_blf_noisemodel_basefunc_v_c_slope[4] Slope*/
    int32_t mf_blf_noisemodel_basefunc_v_c_slope[4];
    /*!< mf_blf_noisemodel_basefunc_v_wbg Param_MF_BLF_NoiseModel_sigmaParafacV_DEF*/
    int32_t mf_blf_noisemodel_basefunc_v_wbg;
    /*!< mf_blf_noisemodel_weight_y_y Param_MF_BLF_NoiseModel_sigmaWgtYy*/
    int32_t mf_blf_noisemodel_weight_y_y;
    /*!< mf_blf_noisemodel_weight_y_u Param_MF_BLF_NoiseModel_sigmaWgtYu*/
    int32_t mf_blf_noisemodel_weight_y_u;
    /*!< mf_blf_noisemodel_weight_y_v Param_MF_BLF_NoiseModel_sigmaWgtYv*/
    int32_t mf_blf_noisemodel_weight_y_v;
    /*!< mf_blf_noisemodel_weight_uv_y Param_MF_BLF_NoiseModel_sigmaWgtUVy*/
    int32_t mf_blf_noisemodel_weight_uv_y;
    /*!< mf_blf_noisemodel_weight_uv_u Param_MF_BLF_NoiseModel_sigmaWgtUVu*/
    int32_t mf_blf_noisemodel_weight_uv_u;
    /*!< mf_blf_noisemodel_weight_uv_v Param_MF_BLF_NoiseModel_sigmaWgtUVv*/
    int32_t mf_blf_noisemodel_weight_uv_v;
    /*!< mf_blf_noisemodel_radialdependent_bypass Param_MF_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t mf_blf_noisemodel_radialdependent_bypass;
    /*!< mf_blf_noisemodel_colordependent_bypass Param_MF_BLF_NoiseModel_bypassColorDependent*/
    int32_t mf_blf_noisemodel_colordependent_bypass;
    /*!< mf_blf_noisemodel_graydependent_bypass Param_MF_BLF_NoiseModel_bypassGrayDependent*/
    int32_t mf_blf_noisemodel_graydependent_bypass;
    /*!< lf_blf_noisemodel_radialdependent_x0 Param_LF_BLF_NoiseModel_radialDependent_x0*/
    int32_t lf_blf_noisemodel_radialdependent_x0;
    /*!< lf_blf_noisemodel_radialdependent_x0_square Param_LF_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t lf_blf_noisemodel_radialdependent_x0_square;
    /*!< lf_blf_noisemodel_radialdependent_y0 Param_LF_BLF_NoiseModel_radialDependent_y0*/
    int32_t lf_blf_noisemodel_radialdependent_y0;
    /*!< lf_blf_noisemodel_radialdependent_y0_square Param_LF_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t lf_blf_noisemodel_radialdependent_y0_square;
    /*!< mf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_MF_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t mf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< mf_blf_noisemodel_radialdependent_gain_x[4] Param_MF_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t mf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< mf_blf_noisemodel_radialdependent_gain_y[3] Param_MF_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t mf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< mf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t mf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< mf_blf_noisemodel_colordependent_a[32] Param_MF_BLF_NoiseModel_colorDependent_A*/
    int32_t mf_blf_noisemodel_colordependent_a[32];
    /*!< mf_blf_noisemodel_colordependent_b[32] Param_MF_BLF_NoiseModel_colorDependent_B*/
    int32_t mf_blf_noisemodel_colordependent_b[32];
    /*!< mf_blf_noisemodel_colordependent_c[32] Param_MF_BLF_NoiseModel_colorDependent_C*/
    int32_t mf_blf_noisemodel_colordependent_c[32];
    /*!< mf_blf_noisemodel_colordependent_norm_offset Param_MF_BLF_NoiseModel_colorDependent_normalization_offset*/
    int32_t mf_blf_noisemodel_colordependent_norm_offset;
    /*!< mf_blf_noisemodel_colordependent_gain_x[6] Param_MF_BLF_NoiseModel_colorDependent_Lut_X*/
    int32_t mf_blf_noisemodel_colordependent_gain_x[6];
    /*!< mf_blf_noisemodel_colordependent_gain_y[5] Param_MF_BLF_NoiseModel_colorDependent_Lut Config Unit Value*/
    int32_t mf_blf_noisemodel_colordependent_gain_y[5];
    /*!< mf_blf_noisemodel_colordependent_gain_slope[5] Slope*/
    int32_t mf_blf_noisemodel_colordependent_gain_slope[5];
    /*!< mf_blf_noisemodel_graydependent_graylevel_thresh Param_MF_BLF_NoiseModel_grayDependent_grayThrsh*/
    int32_t mf_blf_noisemodel_graydependent_graylevel_thresh;
    /*!< mf_blf_noisemodel_graydependent_graylevel_slope Param_MF_BLF_NoiseModel_grayDependent_graySlope*/
    int32_t mf_blf_noisemodel_graydependent_graylevel_slope;
    /*!< mf_blf_noisemodel_graydependent_gain_x[6] Param_MF_BLF_NoiseModel_grayDependent_transLut_X*/
    int32_t mf_blf_noisemodel_graydependent_gain_x[6];
    /*!< mf_blf_noisemodel_graydependent_gain_y[5] Param_MF_BLF_NoiseModel_grayDependent_transLut Config Unit Value*/
    int32_t mf_blf_noisemodel_graydependent_gain_y[5];
    /*!< mf_blf_noisemodel_graydependent_gain_slope[5] Slope*/
    int32_t mf_blf_noisemodel_graydependent_gain_slope[5];
    /*!< mf_blf_noisemodel_normfactor_y_y Param_MF_BLF_NoiseModel_invSigmaYy*/
    int32_t mf_blf_noisemodel_normfactor_y_y;
    /*!< mf_blf_noisemodel_normfactor_y_u Param_MF_BLF_NoiseModel_invSigmaYu*/
    int32_t mf_blf_noisemodel_normfactor_y_u;
    /*!< mf_blf_noisemodel_normfactor_y_v Param_MF_BLF_NoiseModel_invSigmaYv*/
    int32_t mf_blf_noisemodel_normfactor_y_v;
    /*!< mf_blf_noisemodel_normfactor_uv_y Param_MF_BLF_NoiseModel_invSigmaUVy*/
    int32_t mf_blf_noisemodel_normfactor_uv_y;
    /*!< mf_blf_noisemodel_normfactor_uv_u Param_MF_BLF_NoiseModel_invSigmaUVu*/
    int32_t mf_blf_noisemodel_normfactor_uv_u;
    /*!< mf_blf_noisemodel_normfactor_uv_v Param_MF_BLF_NoiseModel_invSigmaUVv*/
    int32_t mf_blf_noisemodel_normfactor_uv_v;
    /*!< mf_blf_snrm_bypass Param_MF_BLF_SNRM_bypassSNRManagement*/
    int32_t mf_blf_snrm_bypass;
    /*!< mf_blf_snrm_bypass_y Param_MF_BLF_SNRM_bypassY*/
    int32_t mf_blf_snrm_bypass_y;
    /*!< mf_blf_snrm_slope_y Param_MF_BLF_SNRM_slopeY*/
    int32_t mf_blf_snrm_slope_y;
    /*!< mf_blf_snrm_xoffset_y Param_MF_BLF_SNRM_xoffsetY*/
    int32_t mf_blf_snrm_xoffset_y;
    /*!< mf_blf_snrm_maxval_y Param_MF_BLF_SNRM_maxValY*/
    int32_t mf_blf_snrm_maxval_y;
    /*!< mf_blf_snrm_minval_y Param_MF_BLF_SNRM_minValY*/
    int32_t mf_blf_snrm_minval_y;
    /*!< mf_blf_snrm_slope_uv Param_MF_BLF_SNRM_slopeUV*/
    int32_t mf_blf_snrm_slope_uv;
    /*!< mf_blf_snrm_xoffset_uv Param_MF_BLF_SNRM_xoffsetUV*/
    int32_t mf_blf_snrm_xoffset_uv;
    /*!< mf_blf_snrm_maxval_uv Param_MF_BLF_SNRM_maxValUV*/
    int32_t mf_blf_snrm_maxval_uv;
    /*!< mf_blf_snrm_minval_uv Param_MF_BLF_SNRM_minValUV*/
    int32_t mf_blf_snrm_minval_uv;
    /*!< mf_afc_bypass Param_MF_AFC_bypassAntiFalseColor*/
    int32_t mf_afc_bypass;
    /*!< mf_afc_weight_snr Param_MF_AFC_wgtSnr*/
    int32_t mf_afc_weight_snr;
    /*!< mf_afc_weight_chroma Param_MF_AFC_wgtC*/
    int32_t mf_afc_weight_chroma;
    /*!< mf_min_distance_clamp Param_MF_min_distance_clamp*/
    int32_t mf_min_distance_clamp;
    /*!< lf_blf_fir_filter_length Param_LF_BLF_FIR_BfLen*/
    int32_t lf_blf_fir_filter_length;
    /*!< lf_blf_fir_luma_coefs[6] Param_LF_BLF_FIR_Kn_coef*/
    int32_t lf_blf_fir_luma_coefs[6];
    /*!< lf_blf_fir_luma_denom_bits Param_LF_BLF_FIR_Kn_denom_bits*/
    int32_t lf_blf_fir_luma_denom_bits;
    /*!< lf_blf_fir_bypass_snr_y Param_LF_BLF_FIR_bypasssSnrY*/
    int32_t lf_blf_fir_bypass_snr_y;
    /*!< lf_blf_colorspace Param_LF_BLF_colorspaceYRB*/
    int32_t lf_blf_colorspace;
    /*!< lf_blf_noisemodel_basefunc_y_a_x[5] Param_LF_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t lf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< lf_blf_noisemodel_basefunc_y_a_y[4] Param_LF_BLF_NoiseModel_sigmaParafacY_A Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< lf_blf_noisemodel_basefunc_y_a_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< lf_blf_noisemodel_basefunc_y_b_x[5] Param_LF_BLF_NoiseModel_sigmaParafacY_B_X*/
    int32_t lf_blf_noisemodel_basefunc_y_b_x[5];
    /*!< lf_blf_noisemodel_basefunc_y_b_y[4] Param_LF_BLF_NoiseModel_sigmaParafacY_B Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_y_b_y[4];
    /*!< lf_blf_noisemodel_basefunc_y_b_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_y_b_slope[4];
    /*!< lf_blf_noisemodel_basefunc_y_c_x[5] Param_LF_BLF_NoiseModel_sigmaParafacY_C_X*/
    int32_t lf_blf_noisemodel_basefunc_y_c_x[5];
    /*!< lf_blf_noisemodel_basefunc_y_c_y[4] Param_LF_BLF_NoiseModel_sigmaParafacY_C Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_y_c_y[4];
    /*!< lf_blf_noisemodel_basefunc_y_c_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_y_c_slope[4];
    /*!< lf_blf_noisemodel_basefunc_y_wbg Param_LF_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t lf_blf_noisemodel_basefunc_y_wbg;
    /*!< lf_blf_noisemodel_basefunc_u_a_x[5] Param_LF_BLF_NoiseModel_sigmaParafacU_A_X*/
    int32_t lf_blf_noisemodel_basefunc_u_a_x[5];
    /*!< lf_blf_noisemodel_basefunc_u_a_y[4] Param_LF_BLF_NoiseModel_sigmaParafacU_A Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_u_a_y[4];
    /*!< lf_blf_noisemodel_basefunc_u_a_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_u_a_slope[4];
    /*!< lf_blf_noisemodel_basefunc_u_b_x[5] Param_LF_BLF_NoiseModel_sigmaParafacU_B_X*/
    int32_t lf_blf_noisemodel_basefunc_u_b_x[5];
    /*!< lf_blf_noisemodel_basefunc_u_b_y[4] Param_LF_BLF_NoiseModel_sigmaParafacU_B Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_u_b_y[4];
    /*!< lf_blf_noisemodel_basefunc_u_b_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_u_b_slope[4];
    /*!< lf_blf_noisemodel_basefunc_u_c_x[5] Param_LF_BLF_NoiseModel_sigmaParafacU_C_X*/
    int32_t lf_blf_noisemodel_basefunc_u_c_x[5];
    /*!< lf_blf_noisemodel_basefunc_u_c_y[4] Param_LF_BLF_NoiseModel_sigmaParafacU_C Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_u_c_y[4];
    /*!< lf_blf_noisemodel_basefunc_u_c_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_u_c_slope[4];
    /*!< lf_blf_noisemodel_basefunc_u_wbg Param_LF_BLF_NoiseModel_sigmaParafacU_DEF*/
    int32_t lf_blf_noisemodel_basefunc_u_wbg;
    /*!< lf_blf_noisemodel_basefunc_v_a_x[5] Param_LF_BLF_NoiseModel_sigmaParafacV_A_X*/
    int32_t lf_blf_noisemodel_basefunc_v_a_x[5];
    /*!< lf_blf_noisemodel_basefunc_v_a_y[4] Param_LF_BLF_NoiseModel_sigmaParafacV_A Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_v_a_y[4];
    /*!< lf_blf_noisemodel_basefunc_v_a_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_v_a_slope[4];
    /*!< lf_blf_noisemodel_basefunc_v_b_x[5] Param_LF_BLF_NoiseModel_sigmaParafacV_B_X*/
    int32_t lf_blf_noisemodel_basefunc_v_b_x[5];
    /*!< lf_blf_noisemodel_basefunc_v_b_y[4] Param_LF_BLF_NoiseModel_sigmaParafacV_B Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_v_b_y[4];
    /*!< lf_blf_noisemodel_basefunc_v_b_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_v_b_slope[4];
    /*!< lf_blf_noisemodel_basefunc_v_c_x[5] Param_LF_BLF_NoiseModel_sigmaParafacV_C_X*/
    int32_t lf_blf_noisemodel_basefunc_v_c_x[5];
    /*!< lf_blf_noisemodel_basefunc_v_c_y[4] Param_LF_BLF_NoiseModel_sigmaParafacV_C Config Unit Value*/
    int32_t lf_blf_noisemodel_basefunc_v_c_y[4];
    /*!< lf_blf_noisemodel_basefunc_v_c_slope[4] Slope*/
    int32_t lf_blf_noisemodel_basefunc_v_c_slope[4];
    /*!< lf_blf_noisemodel_basefunc_v_wbg Param_LF_BLF_NoiseModel_sigmaParafacV_DEF*/
    int32_t lf_blf_noisemodel_basefunc_v_wbg;
    /*!< lf_blf_noisemodel_weight_y_y Param_LF_BLF_NoiseModel_sigmaWgtYy*/
    int32_t lf_blf_noisemodel_weight_y_y;
    /*!< lf_blf_noisemodel_weight_y_u Param_LF_BLF_NoiseModel_sigmaWgtYu*/
    int32_t lf_blf_noisemodel_weight_y_u;
    /*!< lf_blf_noisemodel_weight_y_v Param_LF_BLF_NoiseModel_sigmaWgtYv*/
    int32_t lf_blf_noisemodel_weight_y_v;
    /*!< lf_blf_noisemodel_weight_uv_y Param_LF_BLF_NoiseModel_sigmaWgtUVy*/
    int32_t lf_blf_noisemodel_weight_uv_y;
    /*!< lf_blf_noisemodel_weight_uv_u Param_LF_BLF_NoiseModel_sigmaWgtUVu*/
    int32_t lf_blf_noisemodel_weight_uv_u;
    /*!< lf_blf_noisemodel_weight_uv_v Param_LF_BLF_NoiseModel_sigmaWgtUVv*/
    int32_t lf_blf_noisemodel_weight_uv_v;
    /*!< lf_blf_noisemodel_radialdependent_bypass Param_LF_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t lf_blf_noisemodel_radialdependent_bypass;
    /*!< lf_blf_noisemodel_colordependent_bypass Param_LF_BLF_NoiseModel_bypassColorDependent*/
    int32_t lf_blf_noisemodel_colordependent_bypass;
    /*!< lf_blf_noisemodel_graydependent_bypass Param_LF_BLF_NoiseModel_bypassGrayDependent*/
    int32_t lf_blf_noisemodel_graydependent_bypass;
    /*!< mf_blf_noisemodel_radialdependent_x0 Param_MF_BLF_NoiseModel_radialDependent_x0*/
    int32_t mf_blf_noisemodel_radialdependent_x0;
    /*!< mf_blf_noisemodel_radialdependent_x0_square Param_MF_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t mf_blf_noisemodel_radialdependent_x0_square;
    /*!< mf_blf_noisemodel_radialdependent_y0 Param_MF_BLF_NoiseModel_radialDependent_y0*/
    int32_t mf_blf_noisemodel_radialdependent_y0;
    /*!< mf_blf_noisemodel_radialdependent_y0_square Param_MF_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t mf_blf_noisemodel_radialdependent_y0_square;
    /*!< lf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_LF_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t lf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< lf_blf_noisemodel_radialdependent_gain_x[4] Param_LF_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t lf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< lf_blf_noisemodel_radialdependent_gain_y[3] Param_LF_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t lf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< lf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t lf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< lf_blf_noisemodel_colordependent_a[32] Param_LF_BLF_NoiseModel_colorDependent_A*/
    int32_t lf_blf_noisemodel_colordependent_a[32];
    /*!< lf_blf_noisemodel_colordependent_b[32] Param_LF_BLF_NoiseModel_colorDependent_B*/
    int32_t lf_blf_noisemodel_colordependent_b[32];
    /*!< lf_blf_noisemodel_colordependent_c[32] Param_LF_BLF_NoiseModel_colorDependent_C*/
    int32_t lf_blf_noisemodel_colordependent_c[32];
    /*!< lf_blf_noisemodel_colordependent_norm_offset Param_LF_BLF_NoiseModel_colorDependent_normalization_offset*/
    int32_t lf_blf_noisemodel_colordependent_norm_offset;
    /*!< lf_blf_noisemodel_colordependent_gain_x[6] Param_LF_BLF_NoiseModel_colorDependent_Lut_X*/
    int32_t lf_blf_noisemodel_colordependent_gain_x[6];
    /*!< lf_blf_noisemodel_colordependent_gain_y[5] Param_LF_BLF_NoiseModel_colorDependent_Lut Config Unit Value*/
    int32_t lf_blf_noisemodel_colordependent_gain_y[5];
    /*!< lf_blf_noisemodel_colordependent_gain_slope[5] Slope*/
    int32_t lf_blf_noisemodel_colordependent_gain_slope[5];
    /*!< lf_blf_noisemodel_graydependent_graylevel_thresh Param_LF_BLF_NoiseModel_grayDependent_grayThrsh*/
    int32_t lf_blf_noisemodel_graydependent_graylevel_thresh;
    /*!< lf_blf_noisemodel_graydependent_graylevel_slope Param_LF_BLF_NoiseModel_grayDependent_graySlope*/
    int32_t lf_blf_noisemodel_graydependent_graylevel_slope;
    /*!< lf_blf_noisemodel_graydependent_gain_x[6] Param_LF_BLF_NoiseModel_grayDependent_transLut_X*/
    int32_t lf_blf_noisemodel_graydependent_gain_x[6];
    /*!< lf_blf_noisemodel_graydependent_gain_y[5] Param_LF_BLF_NoiseModel_grayDependent_transLut Config Unit Value*/
    int32_t lf_blf_noisemodel_graydependent_gain_y[5];
    /*!< lf_blf_noisemodel_graydependent_gain_slope[5] Slope*/
    int32_t lf_blf_noisemodel_graydependent_gain_slope[5];
    /*!< lf_blf_noisemodel_normfactor_y_y Param_LF_BLF_NoiseModel_invSigmaYy*/
    int32_t lf_blf_noisemodel_normfactor_y_y;
    /*!< lf_blf_noisemodel_normfactor_y_u Param_LF_BLF_NoiseModel_invSigmaYu*/
    int32_t lf_blf_noisemodel_normfactor_y_u;
    /*!< lf_blf_noisemodel_normfactor_y_v Param_LF_BLF_NoiseModel_invSigmaYv*/
    int32_t lf_blf_noisemodel_normfactor_y_v;
    /*!< lf_blf_noisemodel_normfactor_uv_y Param_LF_BLF_NoiseModel_invSigmaUVy*/
    int32_t lf_blf_noisemodel_normfactor_uv_y;
    /*!< lf_blf_noisemodel_normfactor_uv_u Param_LF_BLF_NoiseModel_invSigmaUVu*/
    int32_t lf_blf_noisemodel_normfactor_uv_u;
    /*!< lf_blf_noisemodel_normfactor_uv_v Param_LF_BLF_NoiseModel_invSigmaUVv*/
    int32_t lf_blf_noisemodel_normfactor_uv_v;
    /*!< lf_blf_snrm_bypass Param_LF_BLF_SNRM_bypassSNRManagement*/
    int32_t lf_blf_snrm_bypass;
    /*!< lf_blf_snrm_bypass_y Param_LF_BLF_SNRM_bypassY*/
    int32_t lf_blf_snrm_bypass_y;
    /*!< lf_blf_snrm_slope_y Param_LF_BLF_SNRM_slopeY*/
    int32_t lf_blf_snrm_slope_y;
    /*!< lf_blf_snrm_xoffset_y Param_LF_BLF_SNRM_xoffsetY*/
    int32_t lf_blf_snrm_xoffset_y;
    /*!< lf_blf_snrm_maxval_y Param_LF_BLF_SNRM_maxValY*/
    int32_t lf_blf_snrm_maxval_y;
    /*!< lf_blf_snrm_minval_y Param_LF_BLF_SNRM_minValY*/
    int32_t lf_blf_snrm_minval_y;
    /*!< lf_blf_snrm_slope_uv Param_LF_BLF_SNRM_slopeUV*/
    int32_t lf_blf_snrm_slope_uv;
    /*!< lf_blf_snrm_xoffset_uv Param_LF_BLF_SNRM_xoffsetUV*/
    int32_t lf_blf_snrm_xoffset_uv;
    /*!< lf_blf_snrm_maxval_uv Param_LF_BLF_SNRM_maxValUV*/
    int32_t lf_blf_snrm_maxval_uv;
    /*!< lf_blf_snrm_minval_uv Param_LF_BLF_SNRM_minValUV*/
    int32_t lf_blf_snrm_minval_uv;
    /*!< lf_blf_iir_alpha_y Param_LF_BLF_IIR_alphaY*/
    int32_t lf_blf_iir_alpha_y;
    /*!< lf_blf_iir_alpha_uv Param_LF_BLF_IIR_alphaUV*/
    int32_t lf_blf_iir_alpha_uv;
    /*!< lf_cs_bypass Param_LF_CS_bypassChromaSuppression*/
    int32_t lf_cs_bypass;
    /*!< lf_cs_coef Param_LF_CS_coef*/
    int32_t lf_cs_coef;
    /*!< lf_min_distance_clamp Param_LF_min_distance_clamp*/
    int32_t lf_min_distance_clamp;
    /*!< vlf_blf_fir_filter_length Param_VLF_BLF_FIR_BfLen*/
    int32_t vlf_blf_fir_filter_length;
    /*!< vlf_blf_fir_luma_coefs[6] Param_VLF_BLF_FIR_Kn_coef*/
    int32_t vlf_blf_fir_luma_coefs[6];
    /*!< vlf_blf_fir_luma_denom_bits Param_VLF_BLF_FIR_Kn_denom_bits*/
    int32_t vlf_blf_fir_luma_denom_bits;
    /*!< vlf_blf_fir_bypass_snr_y Param_VLF_BLF_FIR_bypasssSnrY*/
    int32_t vlf_blf_fir_bypass_snr_y;
    /*!< vlf_blf_colorspace Param_VLF_BLF_colorspaceYRB*/
    int32_t vlf_blf_colorspace;
    /*!< vlf_blf_noisemodel_basefunc_y_a_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t vlf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< vlf_blf_noisemodel_basefunc_y_a_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacY_A Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< vlf_blf_noisemodel_basefunc_y_a_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_y_b_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacY_B_X*/
    int32_t vlf_blf_noisemodel_basefunc_y_b_x[5];
    /*!< vlf_blf_noisemodel_basefunc_y_b_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacY_B Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_y_b_y[4];
    /*!< vlf_blf_noisemodel_basefunc_y_b_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_y_b_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_y_c_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacY_C_X*/
    int32_t vlf_blf_noisemodel_basefunc_y_c_x[5];
    /*!< vlf_blf_noisemodel_basefunc_y_c_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacY_C Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_y_c_y[4];
    /*!< vlf_blf_noisemodel_basefunc_y_c_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_y_c_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_y_wbg Param_VLF_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t vlf_blf_noisemodel_basefunc_y_wbg;
    /*!< vlf_blf_noisemodel_basefunc_u_a_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacU_A_X*/
    int32_t vlf_blf_noisemodel_basefunc_u_a_x[5];
    /*!< vlf_blf_noisemodel_basefunc_u_a_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacU_A Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_u_a_y[4];
    /*!< vlf_blf_noisemodel_basefunc_u_a_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_u_a_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_u_b_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacU_B_X*/
    int32_t vlf_blf_noisemodel_basefunc_u_b_x[5];
    /*!< vlf_blf_noisemodel_basefunc_u_b_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacU_B Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_u_b_y[4];
    /*!< vlf_blf_noisemodel_basefunc_u_b_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_u_b_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_u_c_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacU_C_X*/
    int32_t vlf_blf_noisemodel_basefunc_u_c_x[5];
    /*!< vlf_blf_noisemodel_basefunc_u_c_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacU_C Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_u_c_y[4];
    /*!< vlf_blf_noisemodel_basefunc_u_c_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_u_c_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_u_wbg Param_VLF_BLF_NoiseModel_sigmaParafacU_DEF*/
    int32_t vlf_blf_noisemodel_basefunc_u_wbg;
    /*!< vlf_blf_noisemodel_basefunc_v_a_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacV_A_X*/
    int32_t vlf_blf_noisemodel_basefunc_v_a_x[5];
    /*!< vlf_blf_noisemodel_basefunc_v_a_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacV_A Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_v_a_y[4];
    /*!< vlf_blf_noisemodel_basefunc_v_a_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_v_a_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_v_b_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacV_B_X*/
    int32_t vlf_blf_noisemodel_basefunc_v_b_x[5];
    /*!< vlf_blf_noisemodel_basefunc_v_b_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacV_B Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_v_b_y[4];
    /*!< vlf_blf_noisemodel_basefunc_v_b_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_v_b_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_v_c_x[5] Param_VLF_BLF_NoiseModel_sigmaParafacV_C_X*/
    int32_t vlf_blf_noisemodel_basefunc_v_c_x[5];
    /*!< vlf_blf_noisemodel_basefunc_v_c_y[4] Param_VLF_BLF_NoiseModel_sigmaParafacV_C Config Unit Value*/
    int32_t vlf_blf_noisemodel_basefunc_v_c_y[4];
    /*!< vlf_blf_noisemodel_basefunc_v_c_slope[4] Slope*/
    int32_t vlf_blf_noisemodel_basefunc_v_c_slope[4];
    /*!< vlf_blf_noisemodel_basefunc_v_wbg Param_VLF_BLF_NoiseModel_sigmaParafacV_DEF*/
    int32_t vlf_blf_noisemodel_basefunc_v_wbg;
    /*!< vlf_blf_noisemodel_weight_y_y Param_VLF_BLF_NoiseModel_sigmaWgtYy*/
    int32_t vlf_blf_noisemodel_weight_y_y;
    /*!< vlf_blf_noisemodel_weight_y_u Param_VLF_BLF_NoiseModel_sigmaWgtYu*/
    int32_t vlf_blf_noisemodel_weight_y_u;
    /*!< vlf_blf_noisemodel_weight_y_v Param_VLF_BLF_NoiseModel_sigmaWgtYv*/
    int32_t vlf_blf_noisemodel_weight_y_v;
    /*!< vlf_blf_noisemodel_weight_uv_y Param_VLF_BLF_NoiseModel_sigmaWgtUVy*/
    int32_t vlf_blf_noisemodel_weight_uv_y;
    /*!< vlf_blf_noisemodel_weight_uv_u Param_VLF_BLF_NoiseModel_sigmaWgtUVu*/
    int32_t vlf_blf_noisemodel_weight_uv_u;
    /*!< vlf_blf_noisemodel_weight_uv_v Param_VLF_BLF_NoiseModel_sigmaWgtUVv*/
    int32_t vlf_blf_noisemodel_weight_uv_v;
    /*!< vlf_blf_noisemodel_radialdependent_bypass Param_VLF_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t vlf_blf_noisemodel_radialdependent_bypass;
    /*!< vlf_blf_noisemodel_colordependent_bypass Param_VLF_BLF_NoiseModel_bypassColorDependent*/
    int32_t vlf_blf_noisemodel_colordependent_bypass;
    /*!< vhf_blf_noisemodel_radialdependent_x0 Param_VHF_BLF_NoiseModel_radialDependent_x0*/
    int32_t vhf_blf_noisemodel_radialdependent_x0;
    /*!< vhf_blf_noisemodel_radialdependent_x0_square Param_VHF_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t vhf_blf_noisemodel_radialdependent_x0_square;
    /*!< vhf_blf_noisemodel_radialdependent_y0 Param_VHF_BLF_NoiseModel_radialDependent_y0*/
    int32_t vhf_blf_noisemodel_radialdependent_y0;
    /*!< vhf_blf_noisemodel_radialdependent_y0_square Param_VHF_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t vhf_blf_noisemodel_radialdependent_y0_square;
    /*!< vlf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_VLF_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t vlf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< vlf_blf_noisemodel_radialdependent_gain_x[4] Param_VLF_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t vlf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< vlf_blf_noisemodel_radialdependent_gain_y[3] Param_VLF_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t vlf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< vlf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t vlf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< vlf_blf_noisemodel_colordependent_a[32] Param_VLF_BLF_NoiseModel_colorDependent_A*/
    int32_t vlf_blf_noisemodel_colordependent_a[32];
    /*!< vlf_blf_noisemodel_colordependent_b[32] Param_VLF_BLF_NoiseModel_colorDependent_B*/
    int32_t vlf_blf_noisemodel_colordependent_b[32];
    /*!< vlf_blf_noisemodel_colordependent_c[32] Param_VLF_BLF_NoiseModel_colorDependent_C*/
    int32_t vlf_blf_noisemodel_colordependent_c[32];
    /*!< vlf_blf_noisemodel_colordependent_norm_offset Param_VLF_BLF_NoiseModel_colorDependent_normalization_offset*/
    int32_t vlf_blf_noisemodel_colordependent_norm_offset;
    /*!< vlf_blf_noisemodel_colordependent_gain_x[6] Param_VLF_BLF_NoiseModel_colorDependent_Lut_X*/
    int32_t vlf_blf_noisemodel_colordependent_gain_x[6];
    /*!< vlf_blf_noisemodel_colordependent_gain_y[5] Param_VLF_BLF_NoiseModel_colorDependent_Lut Config Unit Value*/
    int32_t vlf_blf_noisemodel_colordependent_gain_y[5];
    /*!< vlf_blf_noisemodel_colordependent_gain_slope[5] Slope*/
    int32_t vlf_blf_noisemodel_colordependent_gain_slope[5];
    /*!< vlf_blf_noisemodel_graydependent_gain_x[6] Param_VLF_BLF_NoiseModel_grayDependent_transLut_X*/
    int32_t vlf_blf_noisemodel_graydependent_gain_x[6];
    /*!< vlf_blf_noisemodel_graydependent_gain_y[5] Param_VLF_BLF_NoiseModel_grayDependent_transLut Config Unit Value*/
    int32_t vlf_blf_noisemodel_graydependent_gain_y[5];
    /*!< vlf_blf_noisemodel_graydependent_gain_slope[5] Slope*/
    int32_t vlf_blf_noisemodel_graydependent_gain_slope[5];
    /*!< vlf_blf_noisemodel_normfactor_y_y Param_VLF_BLF_NoiseModel_invSigmaYy*/
    int32_t vlf_blf_noisemodel_normfactor_y_y;
    /*!< vlf_blf_noisemodel_normfactor_y_u Param_VLF_BLF_NoiseModel_invSigmaYu*/
    int32_t vlf_blf_noisemodel_normfactor_y_u;
    /*!< vlf_blf_noisemodel_normfactor_y_v Param_VLF_BLF_NoiseModel_invSigmaYv*/
    int32_t vlf_blf_noisemodel_normfactor_y_v;
    /*!< vlf_blf_noisemodel_normfactor_uv_y Param_VLF_BLF_NoiseModel_invSigmaUVy*/
    int32_t vlf_blf_noisemodel_normfactor_uv_y;
    /*!< vlf_blf_noisemodel_normfactor_uv_u Param_VLF_BLF_NoiseModel_invSigmaUVu*/
    int32_t vlf_blf_noisemodel_normfactor_uv_u;
    /*!< vlf_blf_noisemodel_normfactor_uv_v Param_VLF_BLF_NoiseModel_invSigmaUVv*/
    int32_t vlf_blf_noisemodel_normfactor_uv_v;
    /*!< vlf_blf_iir_alpha_y Param_VLF_BLF_IIR_alphaY*/
    int32_t vlf_blf_iir_alpha_y;
    /*!< vlf_blf_iir_alpha_uv Param_VLF_BLF_IIR_alphaUV*/
    int32_t vlf_blf_iir_alpha_uv;
    /*!< vlf_cs_bypass Param_VLF_CS_bypassChromaSuppression*/
    int32_t vlf_cs_bypass;
    /*!< vlf_cs_coef Param_VLF_CS_coef*/
    int32_t vlf_cs_coef;
    /*!< vlf_min_distance_clamp Param_VLF_min_distance_clamp*/
    int32_t vlf_min_distance_clamp;
    /*!< vhf_blf_noisemodel_basefunc_y_a_x[5] Param_VHF_BLF_NoiseModel_sigmaParafacY_A_X*/
    int32_t vhf_blf_noisemodel_basefunc_y_a_x[5];
    /*!< vhf_blf_noisemodel_basefunc_y_a_y[4] Param_VHF_BLF_NoiseModel_sigmaParafacY_A Config Unit Value*/
    int32_t vhf_blf_noisemodel_basefunc_y_a_y[4];
    /*!< vhf_blf_noisemodel_basefunc_y_a_slope[4] Slope*/
    int32_t vhf_blf_noisemodel_basefunc_y_a_slope[4];
    /*!< vhf_blf_noisemodel_basefunc_y_wbg Param_VHF_BLF_NoiseModel_sigmaParafacY_DEF*/
    int32_t vhf_blf_noisemodel_basefunc_y_wbg;
    /*!< vhf_blf_noisemodel_weight_y_y Param_VHF_BLF_NoiseModel_sigmaWgtYy*/
    int32_t vhf_blf_noisemodel_weight_y_y;
    /*!< vhf_blf_noisemodel_radialdependent_bypass Param_VHF_BLF_NoiseModel_bypassRadialCorrection*/
    int32_t vhf_blf_noisemodel_radialdependent_bypass;
    /*!< vlf_blf_noisemodel_radialdependent_x0 Param_VLF_BLF_NoiseModel_radialDependent_x0*/
    int32_t vlf_blf_noisemodel_radialdependent_x0;
    /*!< vlf_blf_noisemodel_radialdependent_x0_square Param_VLF_BLF_NoiseModel_radialDependent_x0_square*/
    int32_t vlf_blf_noisemodel_radialdependent_x0_square;
    /*!< vlf_blf_noisemodel_radialdependent_y0 Param_VLF_BLF_NoiseModel_radialDependent_y0*/
    int32_t vlf_blf_noisemodel_radialdependent_y0;
    /*!< vlf_blf_noisemodel_radialdependent_y0_square Param_VLF_BLF_NoiseModel_radialDependent_y0_square*/
    int32_t vlf_blf_noisemodel_radialdependent_y0_square;
    /*!< vhf_blf_noisemodel_radialdependent_rshift_norm_square_distance Param_VHF_BLF_NoiseModel_radialDependent_rshiftNormSquareDist*/
    int32_t vhf_blf_noisemodel_radialdependent_rshift_norm_square_distance;
    /*!< vhf_blf_noisemodel_radialdependent_gain_x[4] Param_VHF_BLF_NoiseModel_radialDependent_radialLut_X*/
    int32_t vhf_blf_noisemodel_radialdependent_gain_x[4];
    /*!< vhf_blf_noisemodel_radialdependent_gain_y[3] Param_VHF_BLF_NoiseModel_radialDependent_radialLut Config Unit Value*/
    int32_t vhf_blf_noisemodel_radialdependent_gain_y[3];
    /*!< vhf_blf_noisemodel_radialdependent_gain_slope[3] Slope*/
    int32_t vhf_blf_noisemodel_radialdependent_gain_slope[3];
    /*!< vhf_blf_noisemodel_normfactor_y_y Param_VHF_BLF_NoiseModel_invSigmaYy*/
    int32_t vhf_blf_noisemodel_normfactor_y_y;
    /*!< vhf_blf_bypass Param_VHF_BLF_bypass*/
    int32_t vhf_blf_bypass;
    /*!< vhf_min_distance_clamp Param_VHF_min_distance_clamp*/
    int32_t vhf_min_distance_clamp;
    /*!< hf_lcs_cu_slope[5] PARAM_HFC_LCS_CU_SLOPE*/
    int32_t hf_lcs_cu_slope[5];
    /*!< hf_lcs_cu_x[6] PARAM_HFC_LCS_CU_X*/
    int32_t hf_lcs_cu_x[6];
    /*!< hf_lcs_cu_y[5] PARAM_HFC_LCS_CU_Y*/
    int32_t hf_lcs_cu_y[5];
    /*!< hf_lcs_bypass Param_HFC_LCS_bypass*/
    int32_t hf_lcs_bypass;
    /*!< hf_lcs_thresh_high HFC_LCS_THRESHOLD_HIGH*/
    uint32_t hf_lcs_thresh_high;
    /*!< hf_lcs_thresh_low PARAM_HFC_LCS_THRESH_LOW*/
    uint32_t hf_lcs_thresh_low;
    /*!< hf_lcs_chm_gain PARAM_HFC_LCS_CHM_GAIN*/
    uint32_t hf_lcs_chm_gain;
    /*!< hf_lcs_ylocal_size ylocal filter size 0 - 5x5, 1 - 7x7*/
    uint32_t hf_lcs_ylocal_size;
    /*!< hf_lcs_chm_size chroma metric filter size 0 - 5x5, 1 - 7x7*/
    uint32_t hf_lcs_chm_size;
    /*!< vlf_power_uv VLF denoise power chroma*/
    int32_t vlf_power_uv;
    /*!< vlf_power_y VLF denoise power luma*/
    int32_t vlf_power_y;
    /*!< lf_power_uv LF denoise power chroma*/
    int32_t lf_power_uv;
    /*!< lf_power_y VLF denoise power luma*/
    int32_t lf_power_y;
    /*!< mf_power_uv MF denoise power chroma*/
    int32_t mf_power_uv;
    /*!< mf_power_y MF denoise power luma*/
    int32_t mf_power_y;
    /*!< hf_power_uv HF denoise power chroma*/
    int32_t hf_power_uv;
    /*!< vhf_power_y VHF denoise power luma*/
    int32_t vhf_power_y;
    /*!< top_ds_2x_coefs[5] 1:2 downscaling filter coefficients*/
    int32_t top_ds_2x_coefs[5];
    /*!< top_ds_4x_coefs[7] 1:4 downscaling filter coefficients*/
    int32_t top_ds_4x_coefs[7];
    /*!< is_segmentation_aware enable for the segment aware processing*/
    int32_t is_segmentation_aware;
    /*!< vhf_blf_noisemodel_modifier_y_class[16] VHF Y-filter noise model class threshold modifier*/
    int32_t vhf_blf_noisemodel_modifier_y_class[16];
    /*!< hf_blf_noisemodel_modifier_uv_class[16] HFC UV-filter noise model class threshold modifier*/
    int32_t hf_blf_noisemodel_modifier_uv_class[16];
    /*!< mf_blf_noisemodel_modifier_y_class[16] MF Y-filter noise model class threshold modifier*/
    int32_t mf_blf_noisemodel_modifier_y_class[16];
    /*!< mf_blf_noisemodel_modifier_uv_class[16] MF UV-filter noise model class threshold modifier*/
    int32_t mf_blf_noisemodel_modifier_uv_class[16];
    /*!< lf_blf_noisemodel_modifier_y_class[16] LF Y-filter noise model class threshold modifier*/
    int32_t lf_blf_noisemodel_modifier_y_class[16];
    /*!< lf_blf_noisemodel_modifier_uv_class[16] LF UV-filter noise model class threshold modifier*/
    int32_t lf_blf_noisemodel_modifier_uv_class[16];
    /*!< vlf_blf_noisemodel_modifier_y_class[16] VLF Y-filter noise model class threshold modifier*/
    int32_t vlf_blf_noisemodel_modifier_y_class[16];
    /*!< vlf_blf_noisemodel_modifier_uv_class[16] VLF UV-filter noise model class threshold modifier*/
    int32_t vlf_blf_noisemodel_modifier_uv_class[16];

} ia_pal_isp_xnr_5_4_t;



/* System API Structs */

#pragma pack(push, 4)

typedef struct
{
    uint16_t system_api_uuid;
} ia_pal_system_api_record_header_t;

/*! \system api struct acm_1_2

*/
typedef struct
{
    /*!< is_segmentation_aware SAP enable*/
    uint8_t is_segmentation_aware;

} ia_pal_system_api_acm_1_2_t;

/*! \system api struct aestatistics_2_1
AE Statistics (histogram)
*/
typedef struct
{
    /*!< is_dol_psve_processing 0- regular processing. 1 - ae input is a pseudo sve image from dol*/
    uint8_t is_dol_psve_processing;
    /*!< stripe_blocks[4] Blocks per stripe*/
    uint32_t stripe_blocks[4];

} ia_pal_system_api_aestatistics_2_1_t;

/*! \system api struct b2i_ds_1_1

*/
typedef struct
{
    /*!< is_striping indicate if it is ipu8 and above*/
    uint8_t is_striping;

} ia_pal_system_api_b2i_ds_1_1_t;

/*! \system api struct bnlm_3_4
noise reduction
*/
typedef struct
{
    /*!< is_segmentation_aware SAP enable*/
    uint8_t is_segmentation_aware;
    /*!< YUV_processing indicates if input is YUV, otherwise Bayer*/
    uint8_t YUV_processing;

} ia_pal_system_api_bnlm_3_4_t;

/*! \system api struct bxt_blc

*/
typedef struct
{
    /*!< dol_processing 0 - regular processing. 1 - dol processing*/
    uint8_t dol_processing;

} ia_pal_system_api_bxt_blc_t;

/*! \system api struct cas_1_1

*/
typedef struct
{
    /*!< is_segmentation_aware SAP enable*/
    uint8_t is_segmentation_aware;

} ia_pal_system_api_cas_1_1_t;

/*! \system api struct ccm_3a_2_0
AE color correction
*/
typedef struct
{
    /*!< is_dol_psve_processing 0- regular processing. 1 - input is a pseudo sve image from dol*/
    uint8_t is_dol_psve_processing;

} ia_pal_system_api_ccm_3a_2_0_t;

/*! \system api struct dol_lite_1_2

*/
typedef struct
{
    /*!< is_three_input_mode Indicates whether dol filter should work in 3 inputs mode or 2 inputs mode(1 - 3 inputs mode, 0 - 2 inputs mode)*/
    uint8_t is_three_input_mode;

} ia_pal_system_api_dol_lite_1_2_t;

/*! \system api struct dpc_2_2

*/
typedef struct
{
    /*!< stripe_blocks[4] Blocks per stripe*/
    uint32_t stripe_blocks[4];

} ia_pal_system_api_dpc_2_2_t;

/*! \system api struct fr_grid_1_0
FR Statistics
*/
typedef struct
{
    /*!< stripe_blocks[4] Blocks per stripe*/
    uint32_t stripe_blocks[4];

} ia_pal_system_api_fr_grid_1_0_t;

/*! \system api struct gdc7

*/
typedef struct
{
    /*!< gdc_sp_standalone indicated if gdc_sp is used in standalone mode ( 0: used with gdc_FP, 1: used in standalone)*/
    uint8_t gdc_sp_standalone;
    /*!< max_distortion max_dostortion parameter. Valid only in case  small_memory is set.*/
    uint32_t max_distortion;
    /*!< small_memory Indicates whether we work with small memory or not, to enable/disable max_distortion mechanism (enabled only when working with small memory)*/
    uint8_t small_memory;

} ia_pal_system_api_gdc7_t;

/*! \system api struct gmv_statistics_1_1

*/
typedef struct
{
    /*!< binning_factor binning factor*/
    int32_t binning_factor;
    /*!< block_height block height*/
    int32_t block_height;
    /*!< block_width block width*/
    int32_t block_width;
    /*!< stripe_blocks[4] Blocks per stripe*/
    uint32_t stripe_blocks[4];

} ia_pal_system_api_gmv_statistics_1_1_t;

/*! \system api struct io_buffer_1_4

*/
typedef struct
{
    /*!< aligner_data_size amount of valid bits per valid cycle to be accumulate and use the aligner (valid when dpa_bypass is set). LSB represent 2b resolution (meaning value can be 2, 4, 6, 8, … up to 72 which is the size bus)*/
    int32_t aligner_data_size;
    /*!< allocate used for streaming cache: 0-don’t cache, 1-reserved, 2-cache only to non-reserved ways, 3-cache use reserved space for this device*/
    uint8_t allocate;
    /*!< arbiter_pin MIPI CSI arbiter pin location of the stream*/
    int32_t arbiter_pin;
    /*!< block_height buffer block height configuration in lines*/
    uint16_t block_height;
    /*!< block_width buffer block width configuration in pixels*/
    uint16_t block_width;
    /*!< buffer_1d_enable Valid only for 1 plane and 1 queue streams. 0-the buffer is described as 2D; 1-the buffer is described as 1D (continues from start to end w/o stride ignoring lines)*/
    uint8_t buffer_1d_enable;
    /*!< buffer_user_info_reserved_0 Reserved for future use*/
    uint8_t buffer_user_info_reserved_0;
    /*!< buffer_user_info_reserved_1 Reserved for future use*/
    uint8_t buffer_user_info_reserved_1;
    /*!< chip_location Indicate io_buffer location in the pipe. 0- not set (default), 1-BB_ODR_OFA*/
    uint8_t chip_location;
    /*!< chroma_base_conversion chroma converted from zero-based to half-based or vice versa*/
    uint8_t chroma_base_conversion;
    /*!< chroma_duplication Valid when format 420 is configured to provide 422 (2P2Q with SIF count of 4 or 2). when reset - duplicate the chroma and provide the same value each two Y lines, when set - send the chroma components only with the even Y (at odd Y lines doesn’t send any chroma)*/
    uint8_t chroma_duplication;
    /*!< chroma_non_duplication_location Valid when format 420 is configured to provide 422 (2P2Q with SIF count of 4 or 2) and chroma_duplication is disabled. when reset - add the chroma lines w/ the even luma lines, when set - add the chroma lines w/ the odd luma lines*/
    uint8_t chroma_non_duplication_location;
    /*!< chroma_planes_order Chroma planes ordering: 0 - U before V; 1 - V before U (valid for half planer configuration)*/
    uint8_t chroma_planes_order;
    /*!< component_in_valid_pixel Provides amount of valid component per valid pixel*/
    uint8_t component_in_valid_pixel;
    /*!< component_precision Pixel element precision in bits: 0=>8b, 1=>10b, 2=>12b, 3=>16, 4=>32, 5=>2, 6=>4, 7..15=>reserved*/
    uint8_t component_precision;
    /*!< compression_mode Valid for streaming that are tiled: 1-the stream is written/fetched to/from DDR through compression engine; 0-not going through compression*/
    uint8_t compression_mode;
    /*!< dpa_bypass When set indicate the end of MIPI frame (used for MIPI CSI sub frames)*/
    uint8_t dpa_bypass;
    /*!< first_row_blocks_height buffer block height configuration in lines of all the blocks in the first row of blocks. If zero - use streaming_buffer_blocks_height*/
    uint16_t first_row_blocks_height;
    /*!< granularity_pointer_update Valid according the streaming mode: number of lines (LB)/lines of blocks (BB) to be written/release before sending a pointer update (reporting always done with producer view)*/
    uint16_t granularity_pointer_update;
    /*!< in_chroma_signed chroma in input is signed (1) or unsigned (0)*/
    uint8_t in_chroma_signed;
    /*!< in_luma_signed luma in input is signed (1) or unsigned (0)*/
    uint8_t in_luma_signed;
    /*!< last_row_blocks_height buffer block height configuration in lines of all the blocks in the last row of blocks. If zero - use streaming_buffer_blocks_height*/
    uint16_t last_row_blocks_height;
    /*!< local_link_id indicates the stream used at the current connectlon*/
    uint8_t local_link_id;
    /*!< luma_base_conversion luma converted from zero-based to half-based or vice versa*/
    uint8_t luma_base_conversion;
    /*!< max_credits provides the maximum amount of credits for eliminating the need to calculate it in HW according the next formula: (end_address-start_address)/Max_Stride*/
    uint32_t max_credits;
    /*!< max_stride provides the maximum stride value to be used at the connection*/
    uint32_t max_stride;
    /*!< middle_ack_enable If set, enable the mechansim to generate middle ack when consumed amount of configured lines*/
    uint8_t middle_ack_enable;
    /*!< middle_ack_line_number Valid if ack enable  If enabled, the device should generate middle ack when delivers the EOL of the configured line (global number) assuming the first line delievered at SOF is zero.  In case of multiple planes the counting is done using plane1 but only when all the planes are synced*/
    uint16_t middle_ack_line_number;
    /*!< middle_ack_mode_stall Valid only when ack_enable is set When set, the device should stall once sending the middle ack*/
    uint8_t middle_ack_mode_stall;
    /*!< mipi_csi_eof When set indicate the end of MIPI frame (used for MIPI CSI sub frames)*/
    uint8_t mipi_csi_eof;
    /*!< mipi_enable when set indicates MIPI format is enabled*/
    uint8_t mipi_enable;
    /*!< num_of_planes Amount of valid planes (supported 1, 2, 3, 4 - depends also on HW parameter of max planes and data type)*/
    uint8_t num_of_planes;
    /*!< num_of_queues Amount of total active queues (YUV FP - 4, YUV SP - 3 YUV SP Tile - 2. RGB - 1,1,1. Bayer -2). Must be up to amount of maximum queue supported. Can be changed per frame. At LBFF used dynamicly for PDAF*/
    uint8_t num_of_queues;
    /*!< onep_pixel_order Set the ordering of the first plane (lines-N, pixels-M) 4PPC: 0-(N, M), (N, M+1), (N+1, M), (N+1, M+1), horizontal raster; 1-(N, M), (N+1, M), (N, M+1), (N+1, M+1), vertical raster 2PPC: 0-first cyc: (N, M), (N+1, M), second cyc: (N, M+1), (N+1, M+1); 1-first cyc: (N, M), (N, M+1),*/
    uint8_t onep_pixel_order;
    /*!< out_chroma_signed chroma in output is signed (1) or unsigned (0)*/
    uint8_t out_chroma_signed;
    /*!< out_luma_signed luma in output is signed (1) or unsigned (0)*/
    uint8_t out_luma_signed;
    /*!< pace_message_pace_line Provides the line number indicating to stop measuring the activity and pace and sending pace meesage (at IFD - get the last data of the line, at ODR - getnon-buf ack on last data of the line)*/
    uint16_t pace_message_pace_line;
    /*!< pace_message_ref_line Provides the line number that when start indicating start measuring the pace and active  (ODR - send first WR of the line, IFD send first RD of line)*/
    uint16_t pace_message_ref_line;
    /*!< pixels_in_valid_cycle Provides amount of valid pixels per valid cycle*/
    uint8_t pixels_in_valid_cycle;
    /*!< plane_horiz_subsample_config[3] Plane Horiz subsample (width>>N).  Affect tile width and width resolution=>Bayer - 0, Y/UV at YUV SP - 0, Y at YUV FP -0, UV U/V at YUV FP-1)*/
    uint8_t plane_horiz_subsample_config[3];
    /*!< plane_max_burst_size[3] Plane maximum burst size: used to specify the transfer size in CL granularity (Max limited to 16, possible values - 1, 2, 4, 8, 16)*/
    uint8_t plane_max_burst_size[3];
    /*!< plane_offset_end_address[3] Per plane: End offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_end_address[3];
    /*!< plane_offset_start_address[3] Per plane: Start offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_start_address[3];
    /*!< plane_start_address_per_stripe[12] Per plane, per stripe: Start offset address of each plane per stripe with regarding to the full frame base_offset, in bytes, unsigned.*/
    uint32_t plane_start_address_per_stripe[12];
    /*!< plane_stride[3] Per plane: provides the difference between two horizontal pixels, in bytes, CL aligned, unsigned.  At tile mode - provide the difference between two lines of tiles in bytes*/
    uint32_t plane_stride[3];
    /*!< plane_tile_height[3] Per plane: buffer tile height configuration in lines*/
    uint8_t plane_tile_height[3];
    /*!< plane_tile_width[3] Per plane: buffer tile width configuration in bytes*/
    uint8_t plane_tile_width[3];
    /*!< plane_vert_subsample_config[3] Plane Vertical subsample (height>>N). Affect tile highet and highet resolution=>Bayer - 0, Y atYUV SP - 0, UV at YUV SP - 1, Y at YUV FP -0, U/V at YUV FP-1)*/
    uint8_t plane_vert_subsample_config[3];
    /*!< plane_zlr_granularity[3] Plane ZLR page granularity: if 0 - 4KB, if 1 - 2KB. Valid only if ZLR is enalbe*/
    uint8_t plane_zlr_granularity[3];
    /*!< ppc provides the amount of pixel per cycle*/
    uint8_t ppc;
    /*!< proc_ff_bypass when set indicates the FF in the pipe (FCVT & ESPA) need to be bypass*/
    uint8_t proc_ff_bypass;
    /*!< progress_message_line Provides the line number that when is done generate progress message (IFD - last byte of the line arrive, ODR - last byte of the line acked by nbuf)*/
    uint16_t progress_message_line;
    /*!< snoop 0 - non-snoopable, 1 - snoopable*/
    uint8_t snoop;
    /*!< stream_dt stream data type as need to be used by the MIPI*/
    uint8_t stream_dt;
    /*!< stream_dt_for_mipi_packet stream data type as need to be used in the header of mipi packet - not affect the proc*/
    int32_t stream_dt_for_mipi_packet;
    /*!< stream_vc stream virtual channel number as need to be used in MIPI*/
    uint8_t stream_vc;
    /*!< stream_wc stream word count as need to be used by the MIPI*/
    uint16_t stream_wc;
    /*!< streaming_mode The streaming unified buffer protocol:  0-static offline (producer/consumer write/read from DDR after kick);  1-dynamic offline (producer/consumer send wr/rd EOF/SOF, producer write after kick, consumer read after full frame at DDR);  2-buffer chasing large memory (producer/consumer send wr/rd EOF/SOF, producer send wr update, consumer read according to wr update);  3-buffer chasing on small memory (producer/consumer send wr/rd EOF/SOF, producer write released buffers and sends wr pointers, consumer read valid buffer and sends rd pointer);  4-S&R like 3 with option to change the link (supporting modes 2 and 3 with dynamic change) 5-buffer chasing small memory - fix starting point, single buffer 6-buffer chasing small memory - float starting point 7-buffer chasing small memory - fix starting point, double buffer*/
    uint8_t streaming_mode;
    /*!< streaming_sw_managed When set - the SW verify the shared buffer is fully consumed by  the producer and can be written immediately*/
    uint8_t streaming_sw_managed;
    /*!< stride_ratio provides the BCSM max_stride/stride ratio with possible values of 1-8, 16, 32, 64, 128*/
    uint8_t stride_ratio;
    /*!< subsample_YUV444_to_YUV422 Used by ODR to convert YUV444 to YUV422: 0-use amount of element as written at components_in_valid_cycle, 1-drop the chroma components any odd cycle*/
    uint8_t subsample_YUV444_to_YUV422;
    /*!< tile_mode Valid for IO that can provide tile format: 0-no tiling; 1-the IO should use tiling with the configured height, width, and tiling type (internal tiling or external Tile-4)*/
    uint8_t tile_mode;
    /*!< tiling_type Tiling Type: 0 - internal tiling; 1 - external tiling (Tile-4)*/
    uint8_t tiling_type;
    /*!< traffic_class Traffic class the request belongs to and be stored at the XFER queue ccordingly*/
    uint8_t traffic_class;
    /*!< unpack_alignment Valid for unpacked vectors: 0-element located at LSB and MSB is zero; 1-element located at MSB and LSB is zero*/
    uint8_t unpack_alignment;
    /*!< use_attributes This capability impact the ODR. When set, ODR should use the EOL/EOF attributes to detect frame dimensions. In general, this capability is used when the height or width or both are not known or cannot be expressed. Using this capability disable the option using crop/pad mechanism and force SW to provide the same dimension in input/output region (if known) and zero the offset values.*/
    uint8_t use_attributes;
    /*!< vector_format Vector CL format: 0-unpacked using 2B container; 1-packed*/
    uint8_t vector_format;
    /*!< vertical_ordering_enable If set, the walking order should be vertical using the sub_line value to indicate how many CL generate vertical movement*/
    uint8_t vertical_ordering_enable;
    /*!< vertical_ordering_sub_line valid when vertical_ordering is set, indicates the size of the sub line to generate vertical step in CL granularity*/
    uint8_t vertical_ordering_sub_line;
    /*!< x_output_offset_per_stripe[4] Per stripe: Output offset of each  stripe with regarding to the base_offset, in pixels, unsigned.*/
    uint32_t x_output_offset_per_stripe[4];
    /*!< zlr_transaction_enable when set enable sending zlr request for prefetch address translation and compression status*/
    uint8_t zlr_transaction_enable;

} ia_pal_system_api_io_buffer_1_4_t;

/*! \system api struct isys_drainer_1_0

*/
typedef struct
{
    /*!< output_format 0-7 - RGB formats (with A=0); 8-15 - YUV formats; 0 - Output is in 3-plane RGB format; 3 - Output is in ARGB format; 4 - Output is in RGBA format; 5 - Output is in BGRA format; 6 - Output is in ABGR format; 8 - Output is in 2-plane YUV420 (NV12) format; 9 - Output Y only and discard UV;*/
    uint32_t output_format;
    /*!< plane_offset_start_address[3] Per plane: Start offset address of plane with regarding to the base_offset, in bytes, CL aligned, unsigned.*/
    uint32_t plane_offset_start_address[3];

} ia_pal_system_api_isys_drainer_1_0_t;

/*! \system api struct linearization2_0
Linearization
*/
typedef struct
{
    /*!< dol_processing 0 - regular processing. 1 - dol processing*/
    uint8_t dol_processing;

} ia_pal_system_api_linearization2_0_t;

/*! \system api struct lsc_1_2
Lens shading correction up to 24 bit
*/
typedef struct
{
    /*!< ir_processing 0 - RGB processing or 1 - IR processing*/
    uint8_t ir_processing;
    /*!< stripe_blocks[4] Blocks per stripe*/
    uint32_t stripe_blocks[4];
    /*!< stripe_start_block[4] Blocks per stripe*/
    uint32_t stripe_start_block[4];

} ia_pal_system_api_lsc_1_2_t;

/*! \system api struct nntm_1_0

*/
typedef struct
{
    /*!< dol_processing 0 - regular processing. 1 - dol processing*/
    uint8_t dol_processing;

} ia_pal_system_api_nntm_1_0_t;

/*! \system api struct pafstatistics_1_2
PAF Statistics
*/
typedef struct
{
    /*!< input_modes 0: RRRR+LLLL; 1: LLLL+RRRR; 2: RLRL; 3: LRLR; 4: RRRR+LLLL_ALT; 5: LLLL+RRRR_ALT; 6: RLRL_ALT; 7: LRLR_ALT*/
    int32_t input_modes;

} ia_pal_system_api_pafstatistics_1_2_t;

/*! \system api struct pext_1_0

*/
typedef struct
{
    /*!< swapping1stbc Apply swapping of BC inputs for 1st/3rd/etc.\n0: no swapping\n1: swap B/C inputs*/
    int32_t swapping1stbc;
    /*!< swapping1stcd Apply swapping of CD inputs for 1st/3rd/etc.\n0: no swapping\n1: swap C/D inputs*/
    int32_t swapping1stcd;
    /*!< swapping2ndbc Apply swapping of BC inputs for 2nd/4th/etc. lines\n0: no swapping\n1: swap A/B inputs*/
    int32_t swapping2ndbc;
    /*!< swapping2ndcd Apply swapping of CD inputs for 2nd/4th/etc. lines\n0: no swapping\n1: swap C/D inputs*/
    int32_t swapping2ndcd;
    /*!< united_rows Define number of queues for pdaf for type 2 0-one queue 1 -two queues*/
    int32_t united_rows;

} ia_pal_system_api_pext_1_0_t;

/*! \system api struct rgbs_grid_1_1

*/
typedef struct
{
    /*!< ir_processing 0 - RGB processing or 1 - IR processing*/
    uint8_t ir_processing;
    /*!< is_dol_psve_processing 0- regular processing. 1 - rgbs input is a pseudo sve image from dol*/
    uint8_t is_dol_psve_processing;
    /*!< is_fragmentation If no - min_out_bytes=0. Otherwise - calculate to fit grid to CL.*/
    uint8_t is_fragmentation;
    /*!< stripe_blocks[4] Blocks per stripe*/
    uint32_t stripe_blocks[4];

} ia_pal_system_api_rgbs_grid_1_1_t;

/*! \system api struct tnr7_bc_1_2

*/
typedef struct
{
    /*!< is_segmentation_aware SAP enable*/
    uint8_t is_segmentation_aware;

} ia_pal_system_api_tnr7_bc_1_2_t;

/*! \system api struct tnr7_blend_1_1

*/
typedef struct
{
    /*!< is_segmentation_aware SAP enable*/
    uint8_t is_segmentation_aware;

} ia_pal_system_api_tnr7_blend_1_1_t;

/*! \system api struct upipe_1_0

*/
typedef struct
{
    /*!< binning_factor Log2 of the downscale to use. This is on top of x4 downscale is demosaic*/
    uint8_t binning_factor;
    /*!< demosaic_mode Demosaic mode, 0- 2x2, 1- 4x4. Note that binning interpretation depends on this*/
    uint8_t demosaic_mode;
    /*!< enable enables the filter, if disabled the input is replicated to all three output channels*/
    uint8_t enable;
    /*!< input_pattern[3] 4x4 pattern to RGB, channels in R,G,B order; default- GRBG*/
    uint16_t input_pattern[3];
    /*!< rgb_to_yuv_en 0 - Output is in RGB format; 1 - Output is in YUV format*/
    uint8_t rgb_to_yuv_en;
    /*!< rgb_to_yuv_matrix[9] RGB to YUV matrix, S4.11; default- BT709*/
    int16_t rgb_to_yuv_matrix[9];

} ia_pal_system_api_upipe_1_0_t;

/*! \system api struct xnr_5_4
Low Frequency Chroma Denoiser
*/
typedef struct
{
    /*!< is_segmentation_aware SAP enable*/
    uint8_t is_segmentation_aware;

} ia_pal_system_api_xnr_5_4_t;



#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif // IA_PAL_TYPES_ISP_PARAMETERS_AUTOGEN_H
