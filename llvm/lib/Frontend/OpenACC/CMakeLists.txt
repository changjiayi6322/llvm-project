set(LLVM_TARGET_DEFINITIONS ${LLVM_MAIN_INCLUDE_DIR}/llvm/Frontend/OpenACC/ACC.td)
tablegen(LLVM ACC.cpp --gen-directive-impl)
add_public_tablegen_target(acc_cpp)

add_llvm_component_library(LLVMFrontendOpenACC
  ACC.cpp # Generated by tablegen above

  ADDITIONAL_HEADER_DIRS
  ${LLVM_MAIN_INCLUDE_DIR}/llvm/Frontend
  ${LLVM_MAIN_INCLUDE_DIR}/llvm/Frontend/OpenACC

  DEPENDS
  acc_gen
  acc_cpp

  LINK_COMPONENTS
  Support
)
