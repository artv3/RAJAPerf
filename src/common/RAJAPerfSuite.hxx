/*!
 ******************************************************************************
 *
 * \file
 *
 * \brief   Header file containing enums, names, and interfaces for defining 
 *          performance suite kernels and variants.
 *
 ******************************************************************************
 */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2017, Lawrence Livermore National Security, LLC.
//
// Produced at the Lawrence Livermore National Laboratory
//
// LLNL-CODE-xxxxxx
//
// All rights reserved.
//
// This file is part of the RAJA Performance Suite.
//
// For additional details, please read the file LICENSE.
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

// Std C++ includes
#include <string>
#include <vector>

#ifdef _OPENMP
  #include <omp.h>
#else
  #define omp_get_thread_num() 0
  #define omp_get_num_threads() 1
#endif

#ifndef RAJAPerfSuite_HXX
#define RAJAPerfSuite_HXX

namespace rajaperf
{

class KernelBase;

/*!
 *******************************************************************************
 *
 * \brief Enumeration defining unique id for each KERNEL in suite.
 *
 * IMPORTANT: This is only modified when a new kernel is added to the suite.
 *
 *            IT MUST BE KEPT CONSISTENT (CORRESPONDING ONE-TO-ONE) WITH
 *            ARRAY OF KERNEL NAMES IN IMPLEMENTATION FILE!!! 
 *
 *******************************************************************************
 */
enum KernelID {

//
// Basic kernels...
//
#if 0
  Basic_INIT3 = 0,
#endif
  Basic_MULADDSUB = 0,
#if 0
  Basic_IF_QUAD,
  Basic_TRAP_INT,
#endif

//
// LLoops kernels...
//
#if 0
  LLoops_HYDRO_1D,
  LLoops_ICCG,
  LLoops_INNER_PROD,
  LLoops_BAND_LIN_EQ,
  LLoops_TRIDIAG_ELIM,
  LLoops_EOS,
  LLoops_ADI,
  LLoops_INT_PREDICT,
  LLoops_DIFF_PREDICT,
  LLoops_FIRST_SUM,
  LLoops_FIRST_DIFF,
  LLoops_PIC_2D,
  LLoops_PIC_1D,
  LLoops_HYDRO_2D,
  LLoops_GEN_LIN_RECUR,
  LLoops_DISC_ORD,
  LLoops_MAT_X_MAT,
  LLoops_PLANCKIAN,
  LLoops_IMP_HYDRO_2D,
  LLoops_FIND_FIRST_MIN,
#endif

//
// Polybench kernels...
//
#if 0
  Polybench_***
#endif

//
// Stream kernels...
//
#if 0
  Stream_***
#endif

//
// Apps kernels...
//
#if 0
  Apps_PRESSURE_CALC,
  Apps_ENERGY_CALC,
  Apps_VOL3D_CALC,
  Apps_DEL_DOT_VEC_2D,
  Apps_COUPLE,
  Apps_FIR,
#endif

  NUM_KERNELS // Keep this one last and NEVER comment out (!!)

};


/*!
 *******************************************************************************
 *
 * \brief Enumeration defining unique id for each VARIANT in suite.
 *
 * IMPORTANT: This is only modified when a new kernel is added to the suite.
 *
 *            IT MUST BE KEPT CONSISTENT (CORRESPONDING ONE-TO-ONE) WITH
 *            ARRAY OF VARIANT NAMES IN IMPLEMENTATION FILE!!! 
 *
 *******************************************************************************
 */
enum VariantID {

  BASELINE = 0,
  RAJA_SERIAL,
  BASELINE_OPENMP,
  RAJA_OPENMP,
  BASELINE_CUDA,
  RAJA_CUDA,

  NUM_VARIANTS // Keep this one last and NEVER comment out (!!)

};


/*!
 *******************************************************************************
 *
 * \brief Return kernel name associated with KernelID enum value.
 *
 *******************************************************************************
 */
const std::string& getKernelName(KernelID kid);

/*!
 *******************************************************************************
 *
 * \brief Return variant name associated with VariantID enum value.
 *
 *******************************************************************************
 */
const std::string& getVariantName(VariantID vid); 

/*!
 *******************************************************************************
 *
 * \brief Construct and return kernel object for given KernelID enum value.
 *
 *        IMPORTANT: Caller assumes ownerhip of returned object.
 *
 *******************************************************************************
 */
KernelBase* getKernelObject(KernelID kid);

}  // closing brace for rajaperf namespace

#endif  // closing endif for header file include guard
