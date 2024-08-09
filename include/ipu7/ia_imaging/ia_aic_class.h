/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2018-2024 Intel Corporation
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
 * \file ia_aic_class.h
 * \brief AIC specific implementation.
*/

#ifndef IA_AIC_CLASS_H
#define IA_AIC_CLASS_H

#include "ia_aic_types.h"
#if defined INPUTS_IN_FILE
#include "ia_aic_class_file_debug.h"
#endif

namespace aic {
class LIBEXPORT IaAic
{
  public:
    IaAic();
    virtual ~IaAic();

    /*! Create AIC context and initialize AIC
     *
     * Create new AIC context for the pipeline. Performs basic initialization of the context
     *
     * \param [in] aiqb_data         Tuning data information
     *
     * \return                       Pointer to new context, Null if failed
     */
    ia_err Init(
        const ia_binary_data *aiqb_data);

    /*! Configure statistics
     *
     * Configure statistics for the context. This API changes
     * while the implementation of the statistics part progress
     *
     * \param [in] ia_cmc            Sensor characterization information
     * \param [in] max_stats_width   Maximum statistics width
     * \param [in] max_stats_height  Maximum statistics height
     * \param [in] max_num_stats_in  Maximum number of statistics
     *
     * \return ia_error_none / error code on failure
     */
    ia_err StatisticsInit(
        ia_cmc_t *ia_cmc,
        uint32_t max_stats_width,
        uint32_t max_stats_height,
        uint32_t max_num_stats_in);

    /*! Run AIC common for the pipeline
     *
     * Run common part of the AIC. Call processes input parameters from
     * the 3A+ algoritms and performs tuning interpolation
     * for the all the kernels which are registered to this context.
     *
     * This call is not thread safe. Only one instance may be running at the same time.
     *
     * Caller must guarantee following:
     * Input data buffers pointed by pointers in input_params retains unmodified until
     * ia_aic_run_kernels calls for all registered CB/PG's have been run. ia_aic_run_aic doesn't
     * make internal copies of the large tables pointed by input_params.
     *
     * \param [in] sequenceId       Sequence number of frame this AicRun should producer to
     * \param [in] input_params     Pointer to AIC input parameter structure
     *
     * \return ia_error_none / error code on failure
     *
     */
    ia_err RunAic(
        int64_t sequenceId,
        const IaAicInputParams *inputParams);

    /*! Process all kernels from group registered as group_id
     *
     *  Run all kernels from group known as group_id in this context.
     *
     * \param [in] group_id     PG / CB ID given at registration time
     * \param [in] sequenceId   Frame sequence id
     * \param [out] output_data Provide a way to have read-only access to ISP API simulation format data
     * \param [in] fragment_index in case of striping, indicates the current stripe index that we calculate parameters for. In case striping is not supported 0 should be used.
     *
     * return ia_err_none in success. Errorcode on failure
     */
    ia_err RunKernels(
        int32_t group_id,
        int64_t sequenceId,
        ia_binary_data *output_data,
        uint32_t fragment_index = 0U);

    /*! Register kernel offsets for a kernel with uuid in CB/PG group_id and terminal
     *
     * Register kernel offsets for a kernel with uuid in CB/PG group_id and terminal.
     *
     * \param [in] uuid                 Kernel identifier (PAL UUID)
     * \param [in] group_id             CB/PG id given at registration phase
     * \param [in] terminal_type        CB/PG id given at registration phase
     * \param [in] terminal_index       The index of the terminal to register the offsets to
     * \param [in] offsets              List of offsets for all the sections for this kernel in the given terminal
     * \param [in] sizes                List of sizes for all the sections for this kernel in the given terminal
     * \param [in] num_offsets          Number of sections for this kernel in the given terminal
     * \param [in] fragment             Fragment index **Deprecated**
     *
     * return ia_err_none in success. Error code on failure
     *
     */
    ia_err RegisterKernelOffset(
        int32_t uuid,
        int32_t group_id,
        IaAicBufferTypes terminal_type,
        uint32_t terminal_index,
        uint32_t *offsets,
        const uint32_t *sizes,
        uint32_t num_offsets,
        uint32_t fragment);

    /*! Configure CB/PG to AIC context
     *
     * Configure a CB/PG using kernel run list. This function creates internal
     * context for a CB/PG in this context. CB/PG is known as group_id from now on.
     *
     * Note: Kernel list is fixed after this call. Kernel must cover all kernels in
     * CB/PG and it may not contain any extra kernel.
     *
     * \param [in] pg_id            unique identifier for this group of kernels in this context
     * \param [in] fragmentCount    Number of fragments in this group
     * \param [in] kernelGroup      List of kernels in this group with per kernel configuration data
     * \param [in] statsBufToTermId Mapping from statistics buffer type to terminal ID (Optional)
     *
     * return ia_err_none in success. Errorcode on failure
     */
    ia_err Configure(
        int32_t pg_id,
        int32_t fragmentCount,
        const ImagingKernelGroup *kernelGroup,
        const int32_t* statsBufToTermId = nullptr);

    /*! Update tuning including isp
     *  It provides the functionality that update tuning data in run time after initialization.
     *
     * \param [in] aiqb_data     ISP tuning data
     *
     * return ia_err_none in success. Errorcode on failure
     */
    ia_err updateTuning(
        const ia_binary_data *aiqb_data,
        const ia_cmc_t *ia_cmc_ptr = nullptr);

    /*! Update resolutions info/history configuration for CB/PG to AIC context
     *
     *
     *
     * \param [in] pg_id            unique identifier for this group of kernels in this context
     * \param [in] fragmentCount    Number of fragments in this group
     * \param [in] pg               List of kernels in this group with per kernel configuration data
     *
     * return ia_err_none in success. Errorcode on failure
     */
    ia_err UpdateConfigurationResolutions(int32_t pg_id,
        int32_t fragmentCount,
        const ImagingKernelGroup* kernelGroup, bool isKeyResolutionChanged);

    /*! Register HW register format output buffer
     *
     * Register a buffer to AIC context. All but pixel buffers must be registered to the context
     * before the streaming starts.
     *
     * \param [in] group_id         unique identifier for this group of kernels in this context
     * \param [in] terminal_index   index to terminal.
     * \param [in] buffer           Buffer descriptor
     * \param [in] fragment_index in case of striping, indicates the current stripe index that we register buffer for. In case striping is not supported for this specific buffer or at all, 0 should be used
     *
     * return ia_err_none in success. Errorcode on failure
     *
     */
    ia_err RegisterBuffer(
        int32_t group_id,
        uint32_t terminal_index,
        const IaAicBuffer *buffer,
        uint32_t fragment_index = 0U);

    /*! Get current buffer
     *
     * Get current output buffer for terminal. Same buffer can be returned several times
     * if the content hasn't been updated.
     *
     * \param [in] group_id         unique identifier for this group of kernels in this context
     * \param [in] terminal_index   index to terminal
     * \param [in] target           Pointer to buffer desciptor where this function stores the buffer information
     * \param [in] fragment_index in case of striping, indicates the current stripe index that we get buffer for. In case striping is not supported for this specific buffer or at all, 0 should be used
     *
     * return ia_err_none in success. Errorcode on failure
     *
     */
    ia_err GetBuffer(
        int32_t group_id,
        uint32_t terminal_index,
        IaAicBuffer *target,
        uint32_t fragment_index = 0U);

    /*! Get buffer size for particular terminal
     *
     * \param [in] group_id         unique identifier for this group of kernels in this context
     * \param [in] terminal_index   index to terminal
     * \param [in] fragment_index in case of striping, indicates the current stripe index that we get buffer for. In case striping is not supported for this specific buffer or at all, 0 should be used
     *
     * return size when success. Zero on failure.
     */
    size_t GetBufferSize(
        int32_t group_id,
        uint32_t terminal_index,
        uint32_t fragment_index = 0U) const;

    /*! Decode statistics
     *
     * Decodes statistics produced by kernels within the group
     *
     * \param [in] group_id    unique identifier for this group of kernels in this context
     * \param [in] sequenceId  sequence id of the frame to decode from
     * \param [out] stats      pointer to statistics store where to decode to
     * \param [out] dvs_stat   pointer to statistics store where to decode to for dvs only
     *
     * return ia_err_none in success. Error code on failure
     */
    ia_err DecodeStatistics(
        int32_t group_id,
        int64_t sequenceId,
        IaCcatStatistics *stats,
        ia_dvs_statistics *dvs_stat = nullptr);

    static  uint32_t getPacOutputSize(const ImagingKernelGroup* kernelGroup);

  private:
    IaAic(const IaAic &);
    IaAic &operator=(const IaAic &);

    int32_t PgIndex(int32_t group_id) const;

    ia_err IaAicInitPrivate(const ia_binary_data *aiqb_data);

    void IaAicDeinitPrivate();
    ia_err IaAicUpdateGAic(const ia_binary_data *aiqb_data);

    ia_err RunAicPrivate(const IaAicInputParams *inputParams);
    size_t MapConversionBuffers(void *buffer);
    /* file debug */
#if defined INPUTS_IN_FILE
    aic_debug_t *mDebug;
#endif
    /* Pipe level AIC */
    ia_aic_handle *mAic;

    /* Max number of CBs / program groups which one context can handle */
    static const int32_t AIC_MAX_PGS = 5;
    /* Num CB/PG in this pipe */
    int32_t mNumPgs;
    /* PAC engines in this pipe */
    void* mPgs[AIC_MAX_PGS];
};
} /* namespace aic */

#endif  /* IA_AIC_CLASS_H */
