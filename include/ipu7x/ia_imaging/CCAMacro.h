/*
 * Copyright (C) 2021-2024 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file CCAMacro.h
 * @brief This file contains macro definitions and constants used in the CCA module for IPU7.
 *
 * The constants defined in this file are used throughout the CCA module to configure
 * various parameters such as maximum lengths, sizes, and default values.
 * These definitions should ideally be generated automatically to support different
 * platforms or products, as they depend on sensor, IPU, etc.
 */

#ifndef CCAMACRO_H_
#define CCAMACRO_H_

#include <stdint.h>

namespace cca {

/*
 * TODO:
 * This config file should be generated automatically to support different
 * platforms or products, because the below defintions should depend on
 * sensor, IPU, etc.
 */
/**
 * @brief Maximum number of cameras.
 */
const uint32_t MAX_CAM_NUM = 4U;

/**
 * @brief Maximum length of CPF (Camera Parameter File).
 */
const uint32_t MAX_CPF_LEN = 1024 * 1024 * 4;

/**
 * @brief Maximum length of NVM (Non-Volatile Memory).
 */
const uint32_t MAX_NVM_LEN = 1024 * 16;

/**
 * @brief Maximum length of AIQD (AIQ Data).
 */
const uint32_t MAX_AIQD_LEN = 1024 * 1024;

/**
 * @brief Maximum length of MKN (Makernote).
 */
const uint32_t MAX_MKN_LEN = 80 * 1024;

/**
 * @brief Maximum section size of MKN.
 */
const uint32_t MAX_MKN_SECTION_SIZE = 100000;

/**
 * @brief Maximum length of CMC (Camera Module Calibration).
 */
const uint32_t MAX_CMC_LEN = 1024 * 1024;

/**
 * @brief Maximum length of tag list.
 */
const uint32_t MAX_TAG_LIST_LEN = 8;

/**
 * @brief Default frames per second.
 */
const uint32_t DEFAULT_FPS = 30;

/**
 * @brief Maximum number of exposures.
 */
const uint32_t MAX_NUM_EXPOSURE = 4;

/**
 * @brief Maximum number of statistics.
 */
const uint32_t MAX_NUM_STATS = 5;

/**
 * @brief Maximum number of AF (Auto Focus) statistics.
 */
const uint32_t MAX_NUM_AF_STATS = 1;

/**
 * @brief Maximum number of sensors.
 */
const uint32_t MAX_SENSOR = 2;

/**
 * @brief Maximum exposure plan.
 */
const uint32_t MAX_EXPO_PLAN = 4;

/**
 * @brief Maximum number of flash LEDs.
 */
const uint32_t MAX_NUM_FLASH_LEDS = 1;

/**
 * @brief Maximum Bayer order number.
 */
const uint32_t MAX_BAYER_ORDER_NUM = 4;

/**
 * @brief Maximum DVS (Digital Video Stabilization) vector count.
 */
const uint32_t MAX_DVS_VECTOR_COUNT = 100 * 100;

/**
 * @brief Maximum SIS (Super Image Stabilization) frame size.
 */
const uint32_t MAX_SIS_FRAME_SIZE = 500 * 500 * 4;

/**
 * @brief Maximum PAL (Platform Abstraction Layer) tuning size.
 */
const uint32_t MAX_PAL_TUNING_SIZE = 1024 * 1024;

/**
 * @brief Maximum custom controls parameter size.
 */
const uint32_t MAX_CUSTOM_CONTROLS_PARAM_SIZE = 128;

/**
 * @brief Maximum number of kernels in a pipeline.
 */
const uint32_t MAX_KERNEL_NUMBERS_IN_PIPE = 128;

/**
 * @brief Maximum AF grid width.
 */
const uint32_t MAX_AF_GRID_WIDTH = 128;

/**
 * @brief Maximum AF grid height.
 */
const uint32_t MAX_AF_GRID_HEIGHT = 128;

/**
 * @brief Maximum weight grid size.
 */
const uint32_t MAX_WEIGHT_GRID_SIZE = 64 * 64;

/**
 * @brief Maximum AF statistics grid size.
 */
const uint32_t MAX_AF_STATS_GRID_SIZE = (MAX_AF_GRID_WIDTH * MAX_AF_GRID_HEIGHT);

/**
 * @brief Maximum GRBS grid width.
 */
const uint32_t MAX_GRBS_GRID_WIDTH = 150;

/**
 * @brief Maximum GRBS grid height.
 */
const uint32_t MAX_GRBS_GRID_HEIGHT = 150;

/**
 * @brief Maximum RGBS statistics grid size.
 */
const uint32_t MAX_RGBS_STATS_GRID_SIZE = (MAX_GRBS_GRID_WIDTH * MAX_GRBS_GRID_HEIGHT);

/**
 * @brief Maximum statistics length.
 */
const uint32_t MAX_STATS_LEN = 1024 * 1024;

/**
 * @brief Maximum number of faces.
 */
const uint32_t MAX_FACE_NUM = 32;

/**
 * @brief Maximum LSC (Lens Shading Correction) dimension.
 */
const uint32_t MAX_LSC_DIM = 4;

/**
 * @brief Maximum LSC dimension size.
 */
const uint32_t MAX_LSC_DIM_SIZE = 4;

/**
 * @brief Maximum LSC grid size.
 */
const uint32_t MAX_LSC_GRID_SIZE = 128 * 128;

/**
 * @brief Maximum gamma LUT (Look-Up Table) size.
 */
const uint32_t MAX_GAMMA_LUT_SIZE = 2048;

/**
 * @brief Maximum tone map LUT size.
 */
const uint32_t MAX_TONE_MAP_LUT_SIZE = 2048;

/**
 * @brief Maximum number of sectors.
 */
const uint32_t MAX_NUM_SECTORS = 36;

/**
 * @brief Maximum IR (Infrared) weight grid size.
 */
const uint32_t MAX_IR_WEIGHT_GRID_SIZE = 480;

/**
 * @brief GDC (Geometric Distortion Correction) Y block width.
 */
const uint32_t GDC_Y_BLOCK_WIDTH = 32;

/**
 * @brief GDC UV block width.
 */
const uint32_t GDC_UV_BLOCK_WIDTH = 16;

/**
 * @brief GDC Y block height.
 */
const uint32_t GDC_Y_BLOCK_HEIGHT = 32;

/**
 * @brief GDC UV block height.
 */
const uint32_t GDC_UV_BLOCK_HEIGHT = 16;

/**
 * @brief GDC split metadata length.
 */
const uint32_t GDC_SPLIT_METADATA_LEN = 4;

/**
 * @brief GDC clip maximum angle.
 */
const float GDC_CLIP_MAX_ANGLE = 3.5f;

/**
 * @brief Maximum number of kernels in a processing group.
 */
const uint32_t MAX_KERNEL_NUM_IN_PG = 128;

/**
 * @brief Maximum number of processing groups.
 */
const uint32_t MAX_PG_NUM = 5;

/**
 * @brief Maximum number of terminals in a processing group.
 */
const uint32_t MAX_PG_TERMINAL_NUM = 38;

/**
 * @brief Minimum manual gamma value.
 */
const float MIN_MANUAL_GAMMA = 0.1f;

/**
 * @brief Maximum manual gamma value.
 */
const float MAX_MANUAL_GAMMA = 5.0f;

/**
 * @brief PDAF (Phase Detection Auto Focus) statistics grid width.
 */
const uint32_t PDAF_STATS_GRID_WIDTH = 16;

/**
 * @brief PDAF statistics grid height.
 */
const uint32_t PDAF_STATS_GRID_HEIGHT = 12;

/**
 * @brief Number of non-SVE (Super Video Engine) PDAF statistics.
 */
const uint32_t PDAF_STATS_NUM_NONSVE = 1;

/**
 * @brief Maximum number of streams.
 */
const uint32_t MAX_STREAM_NUM = 5;

/**
 * @brief Maximum number of RGBIR models.
 */
const uint32_t MAX_RGBIR_MODELS = 3;

/**
 * @brief Invalid frame ID.
 */
const uint64_t INVALID_FRAME_ID = static_cast<uint64_t>(-1);

/**
 * @brief Number of ACM (Advanced Color Management) segments.
 */
const uint32_t NUM_OF_ACM_SEGMENTS = 6U;

/**
 * @brief Number of sectors per ACM segment.
 */
const uint32_t NUM_OF_SECTORS_PER_SEGMENT = 6U;

/**
 * @brief Maximum number of fragments.
 */
const uint32_t MAX_NUMBER_OF_FRAGMENTS = 1U;
}//cca
#endif //CCAMACRO_H_
