/*
* Copyright 2018-2024 Intel Corporation
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
 * \file ia_aic_types.h
 * \brief AIC data types for external use
 */

#ifndef IA_AIC_TYPES_H
#define IA_AIC_TYPES_H

#include <ia_isp_types.h>
#include <ia_ob.h>
#include <ia_ltm.h>
#include <ia_view.h>
#include <ia_bcomp.h>
#include <ia_dvs.h>
#include <ia_ccat_types.h>
#include <ia_isp_bxt_types.h>
#include <ia_camera_types.h>

namespace aic {
/*
 * All that external parties needs to know about the AIC internals
 */
struct ia_aic_handle;
typedef struct ia_aic_handle ia_aic_handle_t;

class IaAic;
typedef ia_rectangle IaRectangle;

enum IaAicBufferTypes
{
    iaAicParamInBuffer = 0,
    iaAicParamOutBuffer,
    iaAicProgramBuffer,
    iaAicSpatialInBuffer,
    iaAicSpatialOutBuffer,
    iaAicFrameInBuffer,
    iaAicFrameOutBuffer,
    iaAicSystemBuffer,
    iaAicSRFrameInBuffer,
    iaAicSRFragInBuffer,
    iaAicBufferTypeNotSet
};

struct IaAicFragmentDesc //must be aligned with: ia_pac_fragment_desc in ia_pac_frag_types
{
    uint16_t fragmentInputWidth;   /*!< The input width of the fragment. */
    uint16_t fragmentOutputWidth;  /*!< The output width of the fragment. */
    uint16_t fragmentStartX;       /*!< The x offset from the top-left corner of the full image. */
};


/*! AIC buffer descriptor
*
* A structure which descripes buffers between caller and AIC
*
*/
struct IaAicBuffer
{
    uint32_t id;         /*! Buffer type identifier */
    size_t size;             /*! Size of the payload data */
    int64_t sequence;           /*! Frame sequence the buffer has been previously associated with
                                 NOTE: coherent only for buffer returned from IaAicGetBuffer() */
    void *payloadPtr;        /*! Pointer to payload data */
};

struct IaBinaryData
{
    void *data;
    uint32_t size;
};

/*!
* \brief Defines how ISP kernel should modify bit depth of image passing through it.
*/

struct ImagingKernelFormatInfo
 {
    uint32_t inputFormat;  /*!< FourCC of format in input edge of the kernel
                                (can be used to retrieve full format descrition from ISP format bridge */
    uint32_t outputFormat; /*!< FourCC of format in output edge of the kernel */
 };

struct ImagingKernelBppInfo
{
    uint8_t inBpp;
    uint8_t outBpp;
};

/*!
* \brief Describes options for run-time kernel control.
*/
enum ImagingKernelEnableControl
{
    kernelPassthrough = 0,
    kernelEnable,
    kernelDisable
};


struct ia_pac_kernel_info {
    ia_isp_bxt_run_kernels_t run_kernel;
    IaAicFragmentDesc* fragment_descs;
    bool fragments_defined;
};

struct ImagingKernelGroup
{
    uint32_t kernelCount;                       /*!< Number of kernels in the kernelList .*/
    ia_pac_kernel_info *kernelList;                 /*!< Array of kernels in the group. */
    uint32_t operationMode;                     /*!< Operation mode for selecting proper tunings. Is usually associated to different resolutions. */
    uint32_t streamId;                          /*!< Indicate predefined tuning id to use with this group */
};

struct IaAicInputParams
{
    /* Mandatory parameters */
    ia_aiq_frame_params *sensorFrameParams;         /*!< Mandatory. Sensor frame parameters. Describe frame scaling/cropping done in sensor. */
    ia_aiq_awb_results *awbResults;                 /*!< Mandatory. WB results which are to be used to calculate next ISP parameters (WB gains, color matrix,etc). */
    ia_aiq_gbce_results *gbceResults;               /*!< Mandatory. GBCE Gamma tables which are to be used to calculate next ISP parameters.*/
    ia_aiq_ae_results *aeResults;                   /*!< Mandatory. Exposure results which are to be used to calculate next ISP parameters.
                                                                     Currently only exposure times, analog and digital gains are used. For convenience reasons AIC takes
                                                                     ae results and not only needed parameters. */
    ia_aiq_pa_results_v1 *paResults;                /*!< Mandatory. Parameter adaptor results from AIQ. */
    ia_aiq_sa_results_v1 *saResults;                /*!< Mandatory. Shading adaptor results from AIQ. */
    ia_aiq_hist_weight_grid *weightGrid;            /*!< Mandatory. Weight map to be used in the next frame histogram calculation. */
    ia_isp_feature_setting nrSetting;               /*!< Mandatory. Feature setting for noise reduction algorithms. */
    ia_isp_feature_setting eeSetting;               /*!< Mandatory. Feature setting for edge enhancement algorithms. */
    ia_ltm_results *ltmResults;                     /*!< Mandatory. Local tone mapping results from LTM. */
    ia_ltm_drc_params *ltmDrcParams;                /*!< Mandatory. DRC parameters from LTM. */
    uint64_t timestamp;                   /*!< Mandatory. Current timestamp (is microseconds) when ia_isp_bxt_run function is called. AIC uses timestamp to decide what
                                                                     calculations are done based on tunable run rate for each ISP configuration algorithm. */
    ia_dvs_image_transformation *gdcTransformation; /*!< Mandatory. Image transformation parameters for GDC5 ISP FW. This feature replaces the need for morph_table usage.*/
    ia_media_format mediaFormat;                    /*!< Mandatory. Selected Digital television output format.(e.g. BT709) */

    /* Optional parameters */
    char manualBrightness;                          /*!< Optional. Manual brightness value range [-128,127]. Value 0 means no change. */
    char manualContrast;                            /*!< Optional. Manual contrast value range [-128,127]. Value 0 means no change. */
    char manualHue;                                 /*!< Optional. Manual hue value range [-128,127]. Value 0 means no change.
                                                                    Value -96 means red become blue, green become red, blue become green */
    char manualSaturation;                          /*!< Optional. Manual saturation value range [-128,127]. Value 0 means no change. */
    ia_isp_effect effects;                          /*!< Optional. Manual setting for special effects. Combination of ia_isp_effect enums.*/
    ia_isp_custom_controls *customControls;         /*!< Optional. Custom control parameter for interpolating between different tunings.
                                                                    If custom controls are not used, pointer can be set as null.*/
    float32_t manualDigitalGain;                        /*!< Optional. Additional digital gain that is applied to all color channels of the image before ISP statistics collection.
                                                                    Values less than 1.0 means no additional gain. */
    ia_ob_output obBlackLevel;                      /*!< Optional. Black level values calculated on-the-fly when the sensor supports. */
    ia_view_config_t const *viewParams;             /*!< Optional. View parameters for running in GDC5 mode.*/
    ia_camera_parameters_t const *cameraParams;     /*!< Optional. Camera parameters running in GDC7 for auto calib.*/
    ia_rectify_parameters_t const *rectifyParams;   /*!< Optional. Rectification running in GDC7 for UV mapping */
    ia_bcomp_results const *bcompResults;           /*!< Optional.  bit-compression curves. */
    ia_nntm_parameters_t *nntmParams;               /*!< Optional.  Neural network tone mapping parameters. */
    ia_faces_roi_results* face_roi;                     /*!< Optional. Face detection ROI parameters.*/
#ifdef USE_SCD
    ia_aiq_scd_results* scd_results;                 /*!< Mandatory. SCD results which are to be used to calculate scene change magnitude. */
#endif
};

typedef ia_ccat_frame_statistics IaCcatStatistics;

typedef uint32_t IaAicStructuralParameter;

// ==========================================================================
// Depricated interface
// ==========================================================================

typedef class IaAic ia_aic_ctx_t;
}  // namespace aic

#endif  // IA_AIC_TYPES_H
