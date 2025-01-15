/*
 * Copyright (C) 2020-2024 Intel Corporation.
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
 * @file CCAStorage.h
 * @brief This file contains the declaration of the CCAStorage class and related structures for AIQ result storage.
 *
 * The CCAStorage class provides an interface for storing and querying AIQ algorithm results.
 * It supports both standard and customized standard libraries for map and list data structures.
 */

#ifndef CCASTORAGE_H_
#define CCASTORAGE_H_

#include "ia_abstraction.h"
#include "IntelCCATypes.h"
#include "CCAMacro.h"

#ifndef ENABLE_CUSTOMIZED_STD_LIB
#include <map>
#include <list>
#else
#include "FixedMap.h"
#include "FixedList.h"
#endif

namespace cca {

/**
 * @brief AIQ results structure used in CCAStorage.
 */
typedef struct {
    //aec results
    ia_aiq_ae_exposure_result exposure_results[MAX_NUM_EXPOSURE]; /**< AEC results */
    ia_aiq_aperture_control   aperture_control; /**< Aperture control */
    ia_aiq_hist_weight_grid   weight_grid; /**< Histogram weight grid */
    uint8_t weights[MAX_WEIGHT_GRID_SIZE]; /**< Weights for the histogram grid */
    ia_aiq_flash_parameters   flashes[MAX_NUM_FLASH_LEDS]; /**< Flash parameters */
    ia_aiq_exposure_parameters        generic_exposure[MAX_NUM_EXPOSURE * MAX_EXPO_PLAN]; /**< Generic exposure parameters */
    ia_aiq_exposure_sensor_parameters sensor_exposure[MAX_NUM_EXPOSURE * MAX_EXPO_PLAN]; /**< Sensor exposure parameters */

    //gbce results
    float32_t r_gamma_lut[MAX_GAMMA_LUT_SIZE]; /**< Red gamma LUT */
    float32_t g_gamma_lut[MAX_GAMMA_LUT_SIZE]; /**< Green gamma LUT */
    float32_t b_gamma_lut[MAX_GAMMA_LUT_SIZE]; /**< Blue gamma LUT */
    float32_t tone_map_lut[MAX_TONE_MAP_LUT_SIZE]; /**< Tone map LUT */

    //pa results
    ia_aiq_advanced_ccm_t preferred_acm; /**< Preferred ACM */
    uint32_t hue_sectors[MAX_NUM_SECTORS]; /**< Hue sectors */
    float32_t ACM[MAX_NUM_SECTORS][3][3]; /**< Advanced color conversion matrices */
    ia_aiq_ir_weight_t ir_weight; /**< IR weight */
    uint16_t ir_weight_r[MAX_IR_WEIGHT_GRID_SIZE]; /**< IR weight for red channel */
    uint16_t ir_weight_g[MAX_IR_WEIGHT_GRID_SIZE]; /**< IR weight for green channel */
    uint16_t ir_weight_b[MAX_IR_WEIGHT_GRID_SIZE]; /**< IR weight for blue channel */
    ia_aiq_rgbir_t rgbir; /**< RGBIR data */
    ia_aiq_rgbir_model_t models[MAX_RGBIR_MODELS]; /**< RGBIR models */
    ia_aiq_advanced_ccm_SAP_t preferred_acm_SAP; /**< Preferred ACM SAP */
    int32_t sector_index_array[NUM_OF_ACM_SEGMENTS][NUM_OF_SECTORS_PER_SEGMENT]; /**< Sector index array */
    float32_t advanced_color_conversion_matrices[NUM_OF_ACM_SEGMENTS][NUM_OF_SECTORS_PER_SEGMENT][3][3]; /**< Advanced color conversion matrices */

    /*LDRA_INSPECTED 67 X */
    ia_aiq_pa_results_v1 pa_results; /**< PA results */
    ia_aiq_awb_results awb_results; /**< AWB results */
    ia_aiq_ae_results aec_results; /**< AEC results */
    ia_aiq_af_results af_results; /**< AF results */
    /*LDRA_INSPECTED 67 X */
    ia_aiq_gbce_results gbce_results; /**< GBCE results */
    /*LDRA_INSPECTED 67 X */
    ia_aiq_sa_results_v1 sa_results; /**< SA results */
    uint32_t result_bitmap; /**< Result bitmap */
} aiq_results;

/**
 * @brief Storage for AIQ results.
 */
struct cca_aiq_results_storage {
    aiq_results* aiq_results_ptr; /**< Pointer to AIQ results */
    ia_aiq_pa_results_v1* pa_results; /**< Pointer to PA results */
    ia_aiq_awb_results* awb_results; /**< Pointer to AWB results */
    ia_aiq_ae_results* aec_results; /**< Pointer to AEC results */
    ia_aiq_af_results* af_results; /**< Pointer to AF results */
    ia_aiq_gbce_results* gbce_results; /**< Pointer to GBCE results */
    ia_aiq_sa_results_v1 *sa_results; /**< Pointer to SA results */
    uint32_t *aiq_results_bitmap; /**< Pointer to AIQ results bitmap */

    /**
     * @brief Constructor for cca_aiq_results_storage.
     */
    cca_aiq_results_storage() :
        aiq_results_ptr(nullptr),
        pa_results(nullptr),
        awb_results(nullptr),
        aec_results(nullptr),
        af_results(nullptr),
        gbce_results(nullptr),
        sa_results(nullptr),
        aiq_results_bitmap(nullptr)
        {}
};

/**
 * @brief Interface exposed to IntelCCA for AIQ algorithm result storage.
 */
class CCAStorage {
public:
    /**
     * @brief Constructor for CCAStorage.
     * @param len Length of the storage.
     */
    explicit CCAStorage(uint8_t len);

    /**
     * @brief Save AIQ results.
     * @param frameId Frame ID.
     * @param results AIQ results to save.
     * @return Error code.
     */
    ia_err saveAiqResults(uint64_t frameId, const cca_aiq_results_storage& results);

    /**
     * @brief Query AIQ results.
     * @param frameId Frame ID.
     * @param results Pointer to store the queried results.
     * @return Error code.
     */
    ia_err queryAiqResults(uint64_t frameId, cca_aiq_results_storage* results);

    /**
     * @brief Destructor for CCAStorage.
     */
    virtual ~CCAStorage();

private:
    /**
     * @brief Create AIQ result.
     * @return Error code.
     */
    ia_err createAiqResult();

    /**
     * @brief Delete AIQ result.
     */
    void deleteAiqResult();

    /**
     * @brief Reset AIQ result.
     * @param results Pointer to AIQ results.
     * @param bitmap Bitmap for the results.
     * @return Error code.
     */
    ia_err resetAiqResult(aiq_results* results, CCAModuleBitMap bitmap) const;

    /**
     * @brief Initialize AIQ result element.
     * @param aiqResults Pointer to AIQ results.
     * @return Error code.
     */
    ia_err initAiqResultEle(aiq_results *aiqResults) const;

    /**
     * @brief Query cold start results.
     * @param results Pointer to store the queried results.
     * @return Error code.
     */
    ia_err queryColdStartResults(cca_aiq_results_storage *results);

#ifndef ENABLE_CUSTOMIZED_STD_LIB
    std::map<uint64_t, cca_aiq_results_storage> mAiqResultsMap; /**< Map to store AIQ results */
    std::list<uint64_t> mFrameIdList; /**< List of frame IDs */
#else
    static const uint8_t kAiqResultsMapCap = 5U; /**< Capacity of the AIQ results map */
    FixedMap<uint64_t, cca_aiq_results_storage, kAiqResultsMapCap> mAiqResultsMap; /**< Fixed map to store AIQ results */
    FixedList<uint64_t, kAiqResultsMapCap> mFrameIdList; /**< Fixed list of frame IDs */
#endif

    uint8_t mStorageLen; /**< Length of the storage */
    mutex_t mStorageMutex; /**< Mutex for storage synchronization */
    aiq_results *mAiqResults; /**< Pointer to AIQ results */
    aiq_results mColdStartAiqResults; /**< Cold start AIQ results */
};

}//cca
#endif //CCASTORAGE_H_
