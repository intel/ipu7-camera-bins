
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

#ifndef IA_PAL_TYPES_ISP_IDS_AUTOGEN_H
#define IA_PAL_TYPES_ISP_IDS_AUTOGEN_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef enum
{
    ia_pal_uuid_isp_acm_1_2 = 17531,
    ia_pal_uuid_isp_aestatistics_2_1 = 55073,
    ia_pal_uuid_isp_b2i_ds_1_1 = 40299,
    ia_pal_uuid_isp_b2i_ds_output_1_1 = 50136,
    ia_pal_uuid_isp_sw_scaler = 19706,
    ia_pal_uuid_isp_bgb_1_0 = 45585,
    ia_pal_uuid_isp_bnlm_3_4 = 45146,
    ia_pal_uuid_isp_bxt_blc = 11700,
    ia_pal_uuid_isp_bxt_demosaic = 48695,
    ia_pal_uuid_isp_cas_1_1 = 9385,
    ia_pal_uuid_isp_ccm_3a_2_0 = 62344,
    ia_pal_uuid_isp_crop_bpp_adjust_1_0 = 36280,
    ia_pal_uuid_isp_csc_1_1 = 62703,
    ia_pal_uuid_isp_dol_lite_1_2 = 54871,
    ia_pal_uuid_isp_dpc_2_2 = 33184,
    ia_pal_uuid_isp_fr_grid_1_0 = 26958,
    ia_pal_uuid_isp_gammatm_v4 = 5394,
    ia_pal_uuid_isp_gd_2_2 = 13882,
    ia_pal_uuid_isp_gd_dpc_2_1 = 22642,
    ia_pal_uuid_isp_gdc7 = 21644,
    ia_pal_uuid_isp_gdc_sp = 59334,
    ia_pal_uuid_isp_gdc7_1 = 5637,
    ia_pal_uuid_isp_glim_2_0 = 36029,
    ia_pal_uuid_isp_gltm_2_0 = 54721,
    ia_pal_uuid_isp_gmv_statistics_1_1 = 40280,
    ia_pal_uuid_isp_is_odr_a = 11470,
    ia_pal_uuid_isp_is_odr_b = 55449,
    ia_pal_uuid_isp_is_odr_c = 50407,
    ia_pal_uuid_isp_ifd_pipe_1_4 = 52446,
    ia_pal_uuid_isp_ifd_pipe_long_1_4 = 24678,
    ia_pal_uuid_isp_ifd_pipe_short_smth_1_4 = 4386,
    ia_pal_uuid_isp_ifd_pdaf_1_4 = 22427,
    ia_pal_uuid_isp_ifd_lsc_1_4 = 29313,
    ia_pal_uuid_isp_odr_bnlm_1_4 = 53535,
    ia_pal_uuid_isp_odr_pdaf_1_4 = 26892,
    ia_pal_uuid_isp_odr_awb_sat_1_4 = 1248,
    ia_pal_uuid_isp_odr_awb_sve_1_4 = 53430,
    ia_pal_uuid_isp_odr_awb_std_1_4 = 38544,
    ia_pal_uuid_isp_odr_ae_1_4 = 62556,
    ia_pal_uuid_isp_odr_af_std_1_4 = 59136,
    ia_pal_uuid_isp_odr_ir_1_4 = 60297,
    ia_pal_uuid_isp_odr_burst_isp_1_4 = 28230,
    ia_pal_uuid_isp_ifd_gmv_1_4 = 51073,
    ia_pal_uuid_isp_odr_gmv_feature_1_4 = 7416,
    ia_pal_uuid_isp_odr_gmv_match_1_4 = 41148,
    ia_pal_uuid_isp_lbff_crop_espa_1_4 = 65466,
    ia_pal_uuid_isp_ifd_segmap_bnlm_1_4 = 35263,
    ia_pal_uuid_isp_ifd_segmap_xnr_1_4 = 9241,
    ia_pal_uuid_isp_ifd_segmap_acm_1_4 = 51914,
    ia_pal_uuid_isp_ifd_segmap_tnr_bc_1_4 = 47873,
    ia_pal_uuid_isp_ifd_segmap_tnr_blend_1_4 = 14619,
    ia_pal_uuid_isp_ifd_segmap_cas_1_4 = 20893,
    ia_pal_uuid_isp_ifd_tnr_sp_bc_yuv4nm1_1_4 = 7357,
    ia_pal_uuid_isp_ifd_tnr_sp_bc_rs4nm1_1_4 = 62054,
    ia_pal_uuid_isp_odr_tnr_sp_bc_rs4n_1_4 = 63731,
    ia_pal_uuid_isp_ifd_tnr_fp_blend_yuvnm1_1_4 = 16295,
    ia_pal_uuid_isp_odr_tnr_fp_yuvn_1_4 = 5215,
    ia_pal_uuid_isp_odr_tnr_scale_fp_yuv4n_1_4 = 65437,
    ia_pal_uuid_isp_odr_ofs_mp_1_4 = 16460,
    ia_pal_uuid_isp_odr_ofs_dp_1_4 = 37951,
    ia_pal_uuid_isp_ifd_bgmap_1_4 = 40067,
    ia_pal_uuid_isp_ifd_bg_yuv_1_4 = 15064,
    ia_pal_uuid_isp_odr_dpc_pdaf_1_4 = 54812,
    ia_pal_uuid_isp_isys_drainer_1_0 = 26150,
    ia_pal_uuid_isp_linearization2_0 = 10326,
    ia_pal_uuid_isp_lsc_1_2 = 2144,
    ia_pal_uuid_isp_nntm_1_0 = 46539,
    ia_pal_uuid_isp_pafstatistics_1_2 = 44308,
    ia_pal_uuid_isp_pext_1_0 = 43213,
    ia_pal_uuid_isp_rgb_ir_2_0 = 14488,
    ia_pal_uuid_isp_rgbs_grid_1_1 = 15021,
    ia_pal_uuid_isp_smurf_bnlm_1_0 = 54924,
    ia_pal_uuid_isp_smurf_xnr_1_0 = 42329,
    ia_pal_uuid_isp_smurf_acm_1_0 = 28366,
    ia_pal_uuid_isp_smurf_tnr_bc_1_0 = 13101,
    ia_pal_uuid_isp_smurf_tnr_blend_1_0 = 42749,
    ia_pal_uuid_isp_smurf_cas_1_0 = 37468,
    ia_pal_uuid_isp_tnr_scaler_lb_1_1 = 29996,
    ia_pal_uuid_isp_tnr_scaler_fp_1_1 = 20623,
    ia_pal_uuid_isp_tnr7_bc_1_2 = 1502,
    ia_pal_uuid_isp_tnr7_blend_1_1 = 20119,
    ia_pal_uuid_isp_tnr7_ims_1_2 = 23639,
    ia_pal_uuid_isp_tnr7_mc_1_0 = 1886,
    ia_pal_uuid_isp_tnr_sp_mc2 = 43550,
    ia_pal_uuid_isp_tnr7_spatial_1_1 = 2495,
    ia_pal_uuid_isp_upipe_1_0 = 5420,
    ia_pal_uuid_isp_image_upscaler_1_1 = 28787,
    ia_pal_uuid_isp_bgmap_upscaler_1_1 = 13074,
    ia_pal_uuid_isp_vcr_3_1 = 36035,
    ia_pal_uuid_isp_vcsc_2_0_b = 13708,
    ia_pal_uuid_isp_wb_1_1 = 5144,
    ia_pal_uuid_isp_xnr_5_4 = 30019,

} ia_pal_uuid;

typedef enum
{
    ia_pal_uuid_system_api_acm_1_2 = 36320,
    ia_pal_uuid_system_api_aestatistics_2_1 = 6191,
    ia_pal_uuid_system_api_b2i_ds_1_1 = 2102,
    ia_pal_uuid_system_api_bnlm_3_4 = 10944,
    ia_pal_uuid_system_api_bxt_blc = 12306,
    ia_pal_uuid_system_api_cas_1_1 = 3917,
    ia_pal_uuid_system_api_ccm_3a_2_0 = 37617,
    ia_pal_uuid_system_api_dol_lite_1_2 = 8785,
    ia_pal_uuid_system_api_dpc_2_2 = 40171,
    ia_pal_uuid_system_api_fr_grid_1_0 = 11825,
    ia_pal_uuid_system_api_gdc7 = 26430,
    ia_pal_uuid_system_api_gmv_statistics_1_1 = 31661,
    ia_pal_uuid_system_api_io_buffer_1_4 = 47417,
    ia_pal_uuid_system_api_isys_drainer_1_0 = 3396,
    ia_pal_uuid_system_api_linearization2_0 = 47321,
    ia_pal_uuid_system_api_lsc_1_2 = 53704,
    ia_pal_uuid_system_api_nntm_1_0 = 10286,
    ia_pal_uuid_system_api_pafstatistics_1_2 = 53308,
    ia_pal_uuid_system_api_pext_1_0 = 29899,
    ia_pal_uuid_system_api_rgbs_grid_1_1 = 41868,
    ia_pal_uuid_system_api_tnr7_bc_1_2 = 27934,
    ia_pal_uuid_system_api_tnr7_blend_1_1 = 26244,
    ia_pal_uuid_system_api_upipe_1_0 = 61460,
    ia_pal_uuid_system_api_xnr_5_4 = 4645,

} ia_system_api_uuid;

#ifdef __cplusplus
}
#endif

#endif // IA_PAL_TYPES_ISP_IDS_AUTOGEN_H
