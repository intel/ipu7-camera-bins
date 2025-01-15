
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
    ia_pal_uuid_isp_acm_1_1 = 13026,
    ia_pal_uuid_isp_acm_1_2 = 17531,
    ia_pal_uuid_isp_aestatistics_2_1 = 55073,
    ia_pal_uuid_isp_b2i_ds_1_1 = 40299,
    ia_pal_uuid_isp_bnlm_3_3 = 21777,
    ia_pal_uuid_isp_bxt_blc = 11700,
    ia_pal_uuid_isp_bxt_demosaic = 48695,
    ia_pal_uuid_isp_cas_1_0 = 22660,
    ia_pal_uuid_isp_ccm_3a_2_0 = 62344,
    ia_pal_uuid_isp_csc_1_1 = 62703,
    ia_pal_uuid_isp_dol_lite_1_1 = 22000,
    ia_pal_uuid_isp_fr_grid_1_0 = 26958,
    ia_pal_uuid_isp_gammatm_v4 = 5394,
    ia_pal_uuid_isp_gd_dpc_2_1 = 22642,
    ia_pal_uuid_isp_gd_dpc_2_2 = 33714,
    ia_pal_uuid_isp_gdc7 = 21644,
    ia_pal_uuid_isp_gdc_sp = 59334,
    ia_pal_uuid_isp_gdc7_1 = 5637,
    ia_pal_uuid_isp_glim_2_0 = 36029,
    ia_pal_uuid_isp_gltm_2_0 = 54721,
    ia_pal_uuid_isp_gmv_statistics_1_0 = 61146,
    ia_pal_uuid_isp_ifd_pipe_1_3 = 55223,
    ia_pal_uuid_isp_ifd_pipe_long_1_3 = 52982,
    ia_pal_uuid_isp_ifd_pipe_short_smth_1_3 = 49695,
    ia_pal_uuid_isp_ifd_pdaf_1_3 = 6874,
    ia_pal_uuid_isp_ifd_lsc_1_3 = 27730,
    ia_pal_uuid_isp_odr_bnlm_1_3 = 56904,
    ia_pal_uuid_isp_odr_pdaf_1_3 = 24208,
    ia_pal_uuid_isp_odr_awb_sat_1_3 = 45123,
    ia_pal_uuid_isp_odr_awb_sve_1_3 = 8720,
    ia_pal_uuid_isp_odr_awb_std_1_3 = 1338,
    ia_pal_uuid_isp_odr_ae_1_3 = 53496,
    ia_pal_uuid_isp_odr_af_std_1_3 = 23958,
    ia_pal_uuid_isp_odr_af_sve_1_3 = 19238,
    ia_pal_uuid_isp_odr_ir_1_3 = 28176,
    ia_pal_uuid_isp_odr_burst_isp_1_3 = 32658,
    ia_pal_uuid_isp_ifd_gmv_1_3 = 62409,
    ia_pal_uuid_isp_odr_gmv_feature_1_3 = 55924,
    ia_pal_uuid_isp_odr_gmv_match_1_3 = 32160,
    ia_pal_uuid_isp_lbff_crop_espa_1_3 = 42330,
    ia_pal_uuid_isp_odr_output_ps_1_3 = 38648,
    ia_pal_uuid_isp_odr_output_me_1_3 = 59680,
    ia_pal_uuid_isp_slim_tnr_spatial_bifd_yuvn_regs_1_3 = 6907,
    ia_pal_uuid_isp_slim_tnr_sp_bc_bifd_rs4nm1_regs_1_3 = 48078,
    ia_pal_uuid_isp_slim_tnr_sp_bc_bifd_yuv4nm1_regs_1_3 = 25579,
    ia_pal_uuid_isp_tnr_sp_bc_bifd_yuv4n_regs_1_3 = 57803,
    ia_pal_uuid_isp_slim_tnr_fp_blend_bifd_yuvnm1_regs_1_3 = 26536,
    ia_pal_uuid_isp_tnr_fp_bodr_yuvn_regs_1_3 = 38465,
    ia_pal_uuid_isp_tnr_sp_bc_bodr_rs4n_regs_1_3 = 39096,
    ia_pal_uuid_isp_tnr_fp_blend_bifd_rs4n_regs_1_3 = 42936,
    ia_pal_uuid_isp_tnr_scale_fp_bodr_yuv4n_regs_1_3 = 20865,
    ia_pal_uuid_isp_ofs_mp_bodr_regs_1_3 = 18789,
    ia_pal_uuid_isp_ofs_dp_bodr_regs_1_3 = 27847,
    ia_pal_uuid_isp_linearization2_0 = 10326,
    ia_pal_uuid_isp_lsc_1_2 = 2144,
    ia_pal_uuid_isp_nntm_1_0 = 46539,
    ia_pal_uuid_isp_outputscaler_2_0_a = 6800,
    ia_pal_uuid_isp_pafstatistics_1_2 = 44308,
    ia_pal_uuid_isp_pext_1_0 = 43213,
    ia_pal_uuid_isp_rgb_ir_2_0 = 14488,
    ia_pal_uuid_isp_rgbs_grid_1_1 = 15021,
    ia_pal_uuid_isp_tnr_scale_lb = 33723,
    ia_pal_uuid_isp_tnr_scale_fp = 60056,
    ia_pal_uuid_isp_tnr7_bc_1_1 = 54840,
    ia_pal_uuid_isp_tnr7_blend_1_0 = 32696,
    ia_pal_uuid_isp_tnr7_ims_1_1 = 48987,
    ia_pal_uuid_isp_tnr7_mc_1_0 = 1886,
    ia_pal_uuid_isp_tnr_sp_mc2 = 43550,
    ia_pal_uuid_isp_tnr7_spatial_1_0 = 3133,
    ia_pal_uuid_isp_upscaler_1_0 = 25569,
    ia_pal_uuid_isp_vcr_3_1 = 36035,
    ia_pal_uuid_isp_vcsc_2_0_b = 13708,
    ia_pal_uuid_isp_wb_1_1 = 5144,
    ia_pal_uuid_isp_xnr_5_2 = 58858,

} ia_pal_uuid;

typedef enum
{
    ia_pal_uuid_system_api_acm_1_2 = 36320,
    ia_pal_uuid_system_api_aestatistics_2_1 = 6191,
    ia_pal_uuid_system_api_bnlm_3_3 = 5901,
    ia_pal_uuid_system_api_bxt_blc = 12306,
    ia_pal_uuid_system_api_ccm_3a_2_0 = 37617,
    ia_pal_uuid_system_api_dol_lite_1_1 = 2870,
    ia_pal_uuid_system_api_fr_grid_1_0 = 11825,
    ia_pal_uuid_system_api_gdc7 = 26430,
    ia_pal_uuid_system_api_io_buffer_1_3 = 47358,
    ia_pal_uuid_system_api_linearization2_0 = 47321,
    ia_pal_uuid_system_api_lsc_1_2 = 53704,
    ia_pal_uuid_system_api_nntm_1_0 = 10286,
    ia_pal_uuid_system_api_pafstatistics_1_2 = 53308,
    ia_pal_uuid_system_api_pext_1_0 = 29899,
    ia_pal_uuid_system_api_rgbs_grid_1_1 = 41868,
    ia_pal_uuid_system_api_tnr7_blend_1_0 = 53161,

} ia_system_api_uuid;

#ifdef __cplusplus
}
#endif

#endif // IA_PAL_TYPES_ISP_IDS_AUTOGEN_H
