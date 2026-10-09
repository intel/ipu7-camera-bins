/*
 * Copyright 2012-2026 Intel Corporation
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

#ifndef IA_NNTM_TYPES_H_
#define IA_NNTM_TYPES_H_

#include "ia_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief NNTM global weight GAIC payload and related flags for GTM / GBCE input.
 *
 * On zero-initialization (\c memset(0), \c {0}, etc.), \c nntm_enable and \c is_update_tuning_required are false.
 */
typedef struct ia_nntm_global_weight_input
{
    ia_gaic_record_t raw_gaic_record;    /*!< Raw (not interpolated) Generic AIC record information. */
    bool nntm_enable;                    /*!< Determines if NNTM is enabled in the pipe. */
} ia_nntm_global_weight_input_t;

#ifdef __cplusplus
}
#endif

#endif /* IA_NNTM_TYPES_H_ */
