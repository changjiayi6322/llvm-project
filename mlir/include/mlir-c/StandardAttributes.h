//===-- mlir-c/StandardAttributes.h - C API for Std Attributes-----*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM
// Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This header declares the C interface to MLIR Standard attributes.
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_C_STANDARDATTRIBUTES_H
#define MLIR_C_STANDARDATTRIBUTES_H

#include "mlir-c/AffineMap.h"
#include "mlir-c/IR.h"
#include "mlir-c/Support.h"

#ifdef __cplusplus
extern "C" {
#endif

//===----------------------------------------------------------------------===//
// Affine map attribute.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is an affine map attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsAAffineMap(MlirAttribute attr);

/** Creates an affine map attribute wrapping the given map. The attribute
 * belongs to the same context as the affine map. */
MLIR_CAPI_EXPORTED MlirAttribute mlirAffineMapAttrGet(MlirAffineMap map);

/// Returns the affine map wrapped in the given affine map attribute.
MLIR_CAPI_EXPORTED MlirAffineMap mlirAffineMapAttrGetValue(MlirAttribute attr);

//===----------------------------------------------------------------------===//
// Array attribute.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is an array attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsAArray(MlirAttribute attr);

/** Creates an array element containing the given list of elements in the given
 * context. */
MLIR_CAPI_EXPORTED MlirAttribute mlirArrayAttrGet(MlirContext ctx,
                                                  intptr_t numElements,
                                                  MlirAttribute *elements);

/// Returns the number of elements stored in the given array attribute.
MLIR_CAPI_EXPORTED intptr_t mlirArrayAttrGetNumElements(MlirAttribute attr);

/// Returns pos-th element stored in the given array attribute.
MLIR_CAPI_EXPORTED MlirAttribute mlirArrayAttrGetElement(MlirAttribute attr,
                                                         intptr_t pos);

//===----------------------------------------------------------------------===//
// Dictionary attribute.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is a dictionary attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsADictionary(MlirAttribute attr);

/** Creates a dictionary attribute containing the given list of elements in the
 * provided context. */
MLIR_CAPI_EXPORTED MlirAttribute mlirDictionaryAttrGet(
    MlirContext ctx, intptr_t numElements, MlirNamedAttribute *elements);

/// Returns the number of attributes contained in a dictionary attribute.
MLIR_CAPI_EXPORTED intptr_t
mlirDictionaryAttrGetNumElements(MlirAttribute attr);

/// Returns pos-th element of the given dictionary attribute.
MLIR_CAPI_EXPORTED MlirNamedAttribute
mlirDictionaryAttrGetElement(MlirAttribute attr, intptr_t pos);

/** Returns the dictionary attribute element with the given name or NULL if the
 * given name does not exist in the dictionary. */
MLIR_CAPI_EXPORTED MlirAttribute
mlirDictionaryAttrGetElementByName(MlirAttribute attr, const char *name);

//===----------------------------------------------------------------------===//
// Floating point attribute.
//===----------------------------------------------------------------------===//

/* TODO: add support for APFloat and APInt to LLVM IR C API, then expose the
 * relevant functions here. */

/// Checks whether the given attribute is a floating point attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsAFloat(MlirAttribute attr);

/** Creates a floating point attribute in the given context with the given
 * double value and double-precision FP semantics. */
MLIR_CAPI_EXPORTED MlirAttribute mlirFloatAttrDoubleGet(MlirContext ctx,
                                                        MlirType type,
                                                        double value);

/** Same as "mlirFloatAttrDoubleGet", but if the type is not valid for a
 * construction of a FloatAttr, returns a null MlirAttribute. */
MLIR_CAPI_EXPORTED MlirAttribute
mlirFloatAttrDoubleGetChecked(MlirType type, double value, MlirLocation loc);

/** Returns the value stored in the given floating point attribute, interpreting
 * the value as double. */
MLIR_CAPI_EXPORTED double mlirFloatAttrGetValueDouble(MlirAttribute attr);

//===----------------------------------------------------------------------===//
// Integer attribute.
//===----------------------------------------------------------------------===//

/* TODO: add support for APFloat and APInt to LLVM IR C API, then expose the
 * relevant functions here. */

/// Checks whether the given attribute is an integer attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsAInteger(MlirAttribute attr);

/** Creates an integer attribute of the given type with the given integer
 * value. */
MLIR_CAPI_EXPORTED MlirAttribute mlirIntegerAttrGet(MlirType type,
                                                    int64_t value);

/** Returns the value stored in the given integer attribute, assuming the value
 * fits into a 64-bit integer. */
MLIR_CAPI_EXPORTED int64_t mlirIntegerAttrGetValueInt(MlirAttribute attr);

//===----------------------------------------------------------------------===//
// Bool attribute.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is a bool attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsABool(MlirAttribute attr);

/// Creates a bool attribute in the given context with the given value.
MLIR_CAPI_EXPORTED MlirAttribute mlirBoolAttrGet(MlirContext ctx, int value);

/// Returns the value stored in the given bool attribute.
MLIR_CAPI_EXPORTED int mlirBoolAttrGetValue(MlirAttribute attr);

//===----------------------------------------------------------------------===//
// Integer set attribute.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is an integer set attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsAIntegerSet(MlirAttribute attr);

//===----------------------------------------------------------------------===//
// Opaque attribute.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is an opaque attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsAOpaque(MlirAttribute attr);

/** Creates an opaque attribute in the given context associated with the dialect
 * identified by its namespace. The attribute contains opaque byte data of the
 * specified length (data need not be null-terminated). */
MLIR_CAPI_EXPORTED MlirAttribute mlirOpaqueAttrGet(MlirContext ctx,
                                                   const char *dialectNamespace,
                                                   intptr_t dataLength,
                                                   const char *data,
                                                   MlirType type);

/** Returns the namespace of the dialect with which the given opaque attribute
 * is associated. The namespace string is owned by the context. */
MLIR_CAPI_EXPORTED const char *
mlirOpaqueAttrGetDialectNamespace(MlirAttribute attr);

/** Returns the raw data as a string reference. The data remains live as long as
 * the context in which the attribute lives. */
MLIR_CAPI_EXPORTED MlirStringRef mlirOpaqueAttrGetData(MlirAttribute attr);

//===----------------------------------------------------------------------===//
// String attribute.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is a string attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsAString(MlirAttribute attr);

/** Creates a string attribute in the given context containing the given string.
 * The string need not be null-terminated and its length must be specified. */
MLIR_CAPI_EXPORTED MlirAttribute mlirStringAttrGet(MlirContext ctx,
                                                   intptr_t length,
                                                   const char *data);

/** Creates a string attribute in the given context containing the given string.
 * The string need not be null-terminated and its length must be specified.
 * Additionally, the attribute has the given type. */
MLIR_CAPI_EXPORTED MlirAttribute mlirStringAttrTypedGet(MlirType type,
                                                        intptr_t length,
                                                        const char *data);

/** Returns the attribute values as a string reference. The data remains live as
 * long as the context in which the attribute lives. */
MLIR_CAPI_EXPORTED MlirStringRef mlirStringAttrGetValue(MlirAttribute attr);

//===----------------------------------------------------------------------===//
// SymbolRef attribute.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is a symbol reference attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsASymbolRef(MlirAttribute attr);

/** Creates a symbol reference attribute in the given context referencing a
 * symbol identified by the given string inside a list of nested references.
 * Each of the references in the list must not be nested. The string need not be
 * null-terminated and its length must be specified. */
MLIR_CAPI_EXPORTED MlirAttribute
mlirSymbolRefAttrGet(MlirContext ctx, intptr_t length, const char *symbol,
                     intptr_t numReferences, MlirAttribute *references);

/** Returns the string reference to the root referenced symbol. The data remains
 * live as long as the context in which the attribute lives. */
MLIR_CAPI_EXPORTED MlirStringRef
mlirSymbolRefAttrGetRootReference(MlirAttribute attr);

/** Returns the string reference to the leaf referenced symbol. The data remains
 * live as long as the context in which the attribute lives. */
MLIR_CAPI_EXPORTED MlirStringRef
mlirSymbolRefAttrGetLeafReference(MlirAttribute attr);

/** Returns the number of references nested in the given symbol reference
 * attribute. */
MLIR_CAPI_EXPORTED intptr_t
mlirSymbolRefAttrGetNumNestedReferences(MlirAttribute attr);

/// Returns pos-th reference nested in the given symbol reference attribute.
MLIR_CAPI_EXPORTED MlirAttribute
mlirSymbolRefAttrGetNestedReference(MlirAttribute attr, intptr_t pos);

//===----------------------------------------------------------------------===//
// Flat SymbolRef attribute.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is a flat symbol reference attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsAFlatSymbolRef(MlirAttribute attr);

/** Creates a flat symbol reference attribute in the given context referencing a
 * symbol identified by the given string. The string need not be null-terminated
 * and its length must be specified. */
MLIR_CAPI_EXPORTED MlirAttribute mlirFlatSymbolRefAttrGet(MlirContext ctx,
                                                          intptr_t length,
                                                          const char *symbol);

/** Returns the referenced symbol as a string reference. The data remains live
 * as long as the context in which the attribute lives. */
MLIR_CAPI_EXPORTED MlirStringRef
mlirFlatSymbolRefAttrGetValue(MlirAttribute attr);

//===----------------------------------------------------------------------===//
// Type attribute.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is a type attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsAType(MlirAttribute attr);

/** Creates a type attribute wrapping the given type in the same context as the
 * type. */
MLIR_CAPI_EXPORTED MlirAttribute mlirTypeAttrGet(MlirType type);

/// Returns the type stored in the given type attribute.
MLIR_CAPI_EXPORTED MlirType mlirTypeAttrGetValue(MlirAttribute attr);

//===----------------------------------------------------------------------===//
// Unit attribute.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is a unit attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsAUnit(MlirAttribute attr);

/// Creates a unit attribute in the given context.
MLIR_CAPI_EXPORTED MlirAttribute mlirUnitAttrGet(MlirContext ctx);

//===----------------------------------------------------------------------===//
// Elements attributes.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is an elements attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsAElements(MlirAttribute attr);

/// Returns the element at the given rank-dimensional index.
MLIR_CAPI_EXPORTED MlirAttribute mlirElementsAttrGetValue(MlirAttribute attr,
                                                          intptr_t rank,
                                                          uint64_t *idxs);

/** Checks whether the given rank-dimensional index is valid in the given
 * elements attribute. */
MLIR_CAPI_EXPORTED int
mlirElementsAttrIsValidIndex(MlirAttribute attr, intptr_t rank, uint64_t *idxs);

/** Gets the total number of elements in the given elements attribute. In order
 * to iterate over the attribute, obtain its type, which must be a statically
 * shaped type and use its sizes to build a multi-dimensional index. */
MLIR_CAPI_EXPORTED int64_t mlirElementsAttrGetNumElements(MlirAttribute attr);

//===----------------------------------------------------------------------===//
// Dense elements attribute.
//===----------------------------------------------------------------------===//

// TODO: decide on the interface and add support for complex elements.
/* TODO: add support for APFloat and APInt to LLVM IR C API, then expose the
 * relevant functions here. */

/// Checks whether the given attribute is a dense elements attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsADenseElements(MlirAttribute attr);
MLIR_CAPI_EXPORTED int mlirAttributeIsADenseIntElements(MlirAttribute attr);
MLIR_CAPI_EXPORTED int mlirAttributeIsADenseFPElements(MlirAttribute attr);

/** Creates a dense elements attribute with the given Shaped type and elements
 * in the same context as the type. */
MLIR_CAPI_EXPORTED MlirAttribute mlirDenseElementsAttrGet(
    MlirType shapedType, intptr_t numElements, MlirAttribute *elements);

/** Creates a dense elements attribute with the given Shaped type containing a
 * single replicated element (splat). */
MLIR_CAPI_EXPORTED MlirAttribute
mlirDenseElementsAttrSplatGet(MlirType shapedType, MlirAttribute element);
MLIR_CAPI_EXPORTED MlirAttribute
mlirDenseElementsAttrBoolSplatGet(MlirType shapedType, int element);
MLIR_CAPI_EXPORTED MlirAttribute
mlirDenseElementsAttrUInt32SplatGet(MlirType shapedType, uint32_t element);
MLIR_CAPI_EXPORTED MlirAttribute
mlirDenseElementsAttrInt32SplatGet(MlirType shapedType, int32_t element);
MLIR_CAPI_EXPORTED MlirAttribute
mlirDenseElementsAttrUInt64SplatGet(MlirType shapedType, uint64_t element);
MLIR_CAPI_EXPORTED MlirAttribute
mlirDenseElementsAttrInt64SplatGet(MlirType shapedType, int64_t element);
MLIR_CAPI_EXPORTED MlirAttribute
mlirDenseElementsAttrFloatSplatGet(MlirType shapedType, float element);
MLIR_CAPI_EXPORTED MlirAttribute
mlirDenseElementsAttrDoubleSplatGet(MlirType shapedType, double element);

/** Creates a dense elements attribute with the given shaped type from elements
 * of a specific type. Expects the element type of the shaped type to match the
 * data element type. */
MLIR_CAPI_EXPORTED MlirAttribute mlirDenseElementsAttrBoolGet(
    MlirType shapedType, intptr_t numElements, const int *elements);
MLIR_CAPI_EXPORTED MlirAttribute mlirDenseElementsAttrUInt32Get(
    MlirType shapedType, intptr_t numElements, const uint32_t *elements);
MLIR_CAPI_EXPORTED MlirAttribute mlirDenseElementsAttrInt32Get(
    MlirType shapedType, intptr_t numElements, const int32_t *elements);
MLIR_CAPI_EXPORTED MlirAttribute mlirDenseElementsAttrUInt64Get(
    MlirType shapedType, intptr_t numElements, const uint64_t *elements);
MLIR_CAPI_EXPORTED MlirAttribute mlirDenseElementsAttrInt64Get(
    MlirType shapedType, intptr_t numElements, const int64_t *elements);
MLIR_CAPI_EXPORTED MlirAttribute mlirDenseElementsAttrFloatGet(
    MlirType shapedType, intptr_t numElements, const float *elements);
MLIR_CAPI_EXPORTED MlirAttribute mlirDenseElementsAttrDoubleGet(
    MlirType shapedType, intptr_t numElements, const double *elements);

/** Creates a dense elements attribute with the given shaped type from string
 * elements. The strings need not be null-terminated and their lengths are
 * provided as a separate argument co-indexed with the strs argument. */
MLIR_CAPI_EXPORTED MlirAttribute
mlirDenseElementsAttrStringGet(MlirType shapedType, intptr_t numElements,
                               intptr_t *strLengths, const char **strs);
/** Creates a dense elements attribute that has the same data as the given dense
 * elements attribute and a different shaped type. The new type must have the
 * same total number of elements. */
MLIR_CAPI_EXPORTED MlirAttribute
mlirDenseElementsAttrReshapeGet(MlirAttribute attr, MlirType shapedType);

/** Checks whether the given dense elements attribute contains a single
 * replicated value (splat). */
MLIR_CAPI_EXPORTED int mlirDenseElementsAttrIsSplat(MlirAttribute attr);

/** Returns the single replicated value (splat) of a specific type contained by
 * the given dense elements attribute. */
MLIR_CAPI_EXPORTED MlirAttribute
mlirDenseElementsAttrGetSplatValue(MlirAttribute attr);
MLIR_CAPI_EXPORTED int
mlirDenseElementsAttrGetBoolSplatValue(MlirAttribute attr);
MLIR_CAPI_EXPORTED int32_t
mlirDenseElementsAttrGetInt32SplatValue(MlirAttribute attr);
MLIR_CAPI_EXPORTED uint32_t
mlirDenseElementsAttrGetUInt32SplatValue(MlirAttribute attr);
MLIR_CAPI_EXPORTED int64_t
mlirDenseElementsAttrGetInt64SplatValue(MlirAttribute attr);
MLIR_CAPI_EXPORTED uint64_t
mlirDenseElementsAttrGetUInt64SplatValue(MlirAttribute attr);
MLIR_CAPI_EXPORTED float
mlirDenseElementsAttrGetFloatSplatValue(MlirAttribute attr);
MLIR_CAPI_EXPORTED double
mlirDenseElementsAttrGetDoubleSplatValue(MlirAttribute attr);
MLIR_CAPI_EXPORTED MlirStringRef
mlirDenseElementsAttrGetStringSplatValue(MlirAttribute attr);

/** Returns the pos-th value (flat contiguous indexing) of a specific type
 * contained by the given dense elements attribute. */
MLIR_CAPI_EXPORTED int mlirDenseElementsAttrGetBoolValue(MlirAttribute attr,
                                                         intptr_t pos);
MLIR_CAPI_EXPORTED int32_t
mlirDenseElementsAttrGetInt32Value(MlirAttribute attr, intptr_t pos);
MLIR_CAPI_EXPORTED uint32_t
mlirDenseElementsAttrGetUInt32Value(MlirAttribute attr, intptr_t pos);
MLIR_CAPI_EXPORTED int64_t
mlirDenseElementsAttrGetInt64Value(MlirAttribute attr, intptr_t pos);
MLIR_CAPI_EXPORTED uint64_t
mlirDenseElementsAttrGetUInt64Value(MlirAttribute attr, intptr_t pos);
MLIR_CAPI_EXPORTED float mlirDenseElementsAttrGetFloatValue(MlirAttribute attr,
                                                            intptr_t pos);
MLIR_CAPI_EXPORTED double
mlirDenseElementsAttrGetDoubleValue(MlirAttribute attr, intptr_t pos);
MLIR_CAPI_EXPORTED MlirStringRef
mlirDenseElementsAttrGetStringValue(MlirAttribute attr, intptr_t pos);

/** Returns the raw data of the given dense elements attribute. */
MLIR_CAPI_EXPORTED const void *
mlirDenseElementsAttrGetRawData(MlirAttribute attr);

//===----------------------------------------------------------------------===//
// Opaque elements attribute.
//===----------------------------------------------------------------------===//

// TODO: expose Dialect to the bindings and implement accessors here.

/// Checks whether the given attribute is an opaque elements attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsAOpaqueElements(MlirAttribute attr);

//===----------------------------------------------------------------------===//
// Sparse elements attribute.
//===----------------------------------------------------------------------===//

/// Checks whether the given attribute is a sparse elements attribute.
MLIR_CAPI_EXPORTED int mlirAttributeIsASparseElements(MlirAttribute attr);

/** Creates a sparse elements attribute of the given shape from a list of
 * indices and a list of associated values. Both lists are expected to be dense
 * elements attributes with the same number of elements. The list of indices is
 * expected to contain 64-bit integers. The attribute is created in the same
 * context as the type. */
MLIR_CAPI_EXPORTED MlirAttribute mlirSparseElementsAttribute(
    MlirType shapedType, MlirAttribute denseIndices, MlirAttribute denseValues);

/** Returns the dense elements attribute containing 64-bit integer indices of
 * non-null elements in the given sparse elements attribute. */
MLIR_CAPI_EXPORTED MlirAttribute
mlirSparseElementsAttrGetIndices(MlirAttribute attr);

/** Returns the dense elements attribute containing the non-null elements in the
 * given sparse elements attribute. */
MLIR_CAPI_EXPORTED MlirAttribute
mlirSparseElementsAttrGetValues(MlirAttribute attr);

#ifdef __cplusplus
}
#endif

#endif // MLIR_C_STANDARDATTRIBUTES_H
