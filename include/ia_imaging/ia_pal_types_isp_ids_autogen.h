
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
    ia_pal_uuid_isp_aestatistics_2_1 = 55073,
    ia_pal_uuid_isp_b2i_ds_1_0_1 = 20739,
    ia_pal_uuid_isp_b2i_ds_1_1 = 40299,
    ia_pal_uuid_isp_sw_scaler = 19706,
    ia_pal_uuid_isp_bnlm_3_3 = 21777,
    ia_pal_uuid_isp_bxt_blc = 11700,
    ia_pal_uuid_isp_bxt_csc = 31704,
    ia_pal_uuid_isp_bxt_demosaic = 48695,
    ia_pal_uuid_isp_cas_1_0 = 22660,
    ia_pal_uuid_isp_ccm_3a_2_0 = 62344,
    ia_pal_uuid_isp_dol_lite_1_0 = 3700,
    ia_pal_uuid_isp_fr_grid_1_0 = 26958,
    ia_pal_uuid_isp_gammatm_v3 = 57496,
    ia_pal_uuid_isp_gd_dpc_2_1 = 22642,
    ia_pal_uuid_isp_gd_dpc_2_2 = 33714,
    ia_pal_uuid_isp_gdc7 = 21644,
    ia_pal_uuid_isp_gdc_sp = 59334,
    ia_pal_uuid_isp_gdc7_1 = 2565,
    ia_pal_uuid_isp_glim_2_0 = 36029,
    ia_pal_uuid_isp_gltm_2_0 = 54721,
    ia_pal_uuid_isp_gmv_statistics_1_0 = 61146,
    ia_pal_uuid_isp_ifd_pipe_1_1 = 52164,
    ia_pal_uuid_isp_ifd_pdaf_1_1 = 3971,
    ia_pal_uuid_isp_ifd_lsc_1_1 = 6070,
    ia_pal_uuid_isp_odr_pdaf_1_1 = 31724,
    ia_pal_uuid_isp_odr_awb_sat_1_1 = 54176,
    ia_pal_uuid_isp_odr_awb_sve_1_1 = 2452,
    ia_pal_uuid_isp_odr_awb_std_1_1 = 20731,
    ia_pal_uuid_isp_odr_ae_1_1 = 50677,
    ia_pal_uuid_isp_odr_af_std_1_1 = 6500,
    ia_pal_uuid_isp_odr_af_sve_1_1 = 36307,
    ia_pal_uuid_isp_odr_ir_1_1 = 3371,
    ia_pal_uuid_isp_odr_burst_isp_1_1 = 57981,
    ia_pal_uuid_isp_ifd_gmv_1_1 = 41864,
    ia_pal_uuid_isp_odr_gmv_feature_1_1 = 8985,
    ia_pal_uuid_isp_odr_gmv_match_1_1 = 13820,
    ia_pal_uuid_isp_lbff_crop_espa_1_1 = 36213,
    ia_pal_uuid_isp_odr_output_ps_1_1 = 40915,
    ia_pal_uuid_isp_odr_output_me_1_1 = 55391,
    ia_pal_uuid_isp_slim_tnr_spatial_bifd_yuvn_regs_1_1 = 44984,
    ia_pal_uuid_isp_slim_tnr_sp_bc_bifd_rs4nm1_regs_1_1 = 33179,
    ia_pal_uuid_isp_slim_tnr_sp_bc_bifd_yuv4nm1_regs_1_1 = 11500,
    ia_pal_uuid_isp_tnr_sp_bc_bifd_yuv4n_regs_1_1 = 6326,
    ia_pal_uuid_isp_slim_tnr_fp_blend_bifd_yuvnm1_regs_1_1 = 27830,
    ia_pal_uuid_isp_tnr_fp_bodr_yuvn_regs_1_1 = 39844,
    ia_pal_uuid_isp_tnr_sp_bc_bodr_rs4n_regs_1_1 = 48743,
    ia_pal_uuid_isp_tnr_fp_blend_bifd_rs4n_regs_1_1 = 44199,
    ia_pal_uuid_isp_tnr_scale_fp_bodr_yuv4n_regs_1_1 = 57148,
    ia_pal_uuid_isp_ofs_mp_bodr_regs_1_1 = 7175,
    ia_pal_uuid_isp_ofs_dp_bodr_regs_1_1 = 30277,
    ia_pal_uuid_isp_ofs_pp_bodr_regs_1_1 = 31882,
    ia_pal_uuid_isp_linearization2_0 = 10326,
    ia_pal_uuid_isp_lsc_1_2 = 2144,
    ia_pal_uuid_isp_nntm_1_0 = 28761,
    ia_pal_uuid_isp_outputscaler_2_0_a = 6800,
    ia_pal_uuid_isp_outputscaler_2_0_b = 51856,
    ia_pal_uuid_isp_pafstatistics_1_2 = 44308,
    ia_pal_uuid_isp_pext_1_0 = 43213,
    ia_pal_uuid_isp_rgb_ir_2_0 = 14488,
    ia_pal_uuid_isp_rgbs_grid_1_1 = 15021,
    ia_pal_uuid_isp_tm_app = 40423,
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
    ia_pal_uuid_system_api_aestatistics_2_1 = 39342,
    ia_pal_uuid_system_api_bnlm_3_3 = 5901,
    ia_pal_uuid_system_api_bxt_blc = 12306,
    ia_pal_uuid_system_api_ccm_3a_2_0 = 37617,
    ia_pal_uuid_system_api_gammatm_v3 = 54040,
    ia_pal_uuid_system_api_gdc7 = 26430,
    ia_pal_uuid_system_api_io_buffer_1_1 = 50058,
    ia_pal_uuid_system_api_linearization2_0 = 47321,
    ia_pal_uuid_system_api_lsc_1_2 = 19967,
    ia_pal_uuid_system_api_nntm_1_0 = 10286,
    ia_pal_uuid_system_api_pafstatistics_1_2 = 53308,
    ia_pal_uuid_system_api_pext_1_0 = 29899,
    ia_pal_uuid_system_api_rgbs_grid_1_1 = 30239,
    ia_pal_uuid_system_api_tnr7_blend_1_0 = 53161,

} ia_system_api_uuid;

#ifdef __cplusplus
}
#endif

#endif // IA_PAL_TYPES_ISP_IDS_AUTOGEN_H
