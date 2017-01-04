/*===---------------------------Vectorize.h --------------------- -*- C -*-===*\
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Vectorize.h                                                               //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
// This header declares the C interface to libLLVMVectorize.a, which         //
// implements various vectorization transformations of the LLVM IR.          //
// Many exotic languages can interoperate with C code but have a harder time //
// with C++ due to name mangling. So in addition to C, this interface enables//
// tools written in such languages.                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef LLVM_C_TRANSFORMS_VECTORIZE_H
#define LLVM_C_TRANSFORMS_VECTORIZE_H

#include "llvm-c/Core.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup LLVMCTransformsVectorize Vectorization transformations
 * @ingroup LLVMCTransforms
 *
 * @{
 */

/** See llvm::createBBVectorizePass function. */
void LLVMAddBBVectorizePass(LLVMPassManagerRef PM);

/** See llvm::createLoopVectorizePass function. */
void LLVMAddLoopVectorizePass(LLVMPassManagerRef PM);

/** See llvm::createSLPVectorizerPass function. */
void LLVMAddSLPVectorizePass(LLVMPassManagerRef PM);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */

#endif
