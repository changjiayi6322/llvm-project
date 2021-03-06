; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc -verify-machineinstrs -mcpu=ppc64 < %s | FileCheck %s
target datalayout = "E-m:e-i64:64-n32:64"
target triple = "powerpc64-unknown-linux-gnu"

; Function Attrs: nounwind readnone
define i64 @cn1() #0 {
; CHECK-LABEL: cn1:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    lis 3, -1
; CHECK-NEXT:    rldicr 3, 3, 48, 63
; CHECK-NEXT:    blr
entry:
  ret i64 281474976710655

}

; Function Attrs: nounwind readnone
define i64 @cnb() #0 {
; CHECK-LABEL: cnb:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    lis 3, -81
; CHECK-NEXT:    rldicr 3, 3, 48, 63
; CHECK-NEXT:    blr
entry:
  ret i64 281474976710575

}

; Function Attrs: nounwind readnone
define i64 @f2(i64 %x) #0 {
; CHECK-LABEL: f2:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    li 3, -1
; CHECK-NEXT:    sldi 3, 3, 36
; CHECK-NEXT:    blr
entry:
  ret i64 -68719476736

}

; Function Attrs: nounwind readnone
define i64 @f2a(i64 %x) #0 {
; CHECK-LABEL: f2a:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    li 3, -337
; CHECK-NEXT:    sldi 3, 3, 30
; CHECK-NEXT:    blr
entry:
  ret i64 -361850994688

}

; Function Attrs: nounwind readnone
define i64 @f2n(i64 %x) #0 {
; CHECK-LABEL: f2n:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    lis 3, -4096
; CHECK-NEXT:    rldicr 3, 3, 36, 63
; CHECK-NEXT:    blr
entry:
  ret i64 68719476735

}

; Function Attrs: nounwind readnone
define i64 @f3(i64 %x) #0 {
; CHECK-LABEL: f3:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    lis 3, -32768
; CHECK-NEXT:    rldicr 3, 3, 33, 63
; CHECK-NEXT:    blr
entry:
  ret i64 8589934591

}

; Function Attrs: nounwind readnone
define i64 @cn2n() #0 {
; CHECK-LABEL: cn2n:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    lis 3, -5121
; CHECK-NEXT:    ori 3, 3, 65534
; CHECK-NEXT:    rldicr 3, 3, 22, 63
; CHECK-NEXT:    blr
entry:
  ret i64 -1407374887747585

}

define i64 @uint32_1() #0 {
; CHECK-LABEL: uint32_1:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    lis 3, 232
; CHECK-NEXT:    ori 3, 3, 30023
; CHECK-NEXT:    sldi 3, 3, 8
; CHECK-NEXT:    blr
entry:
  ret i64 3900000000

}

define i32 @uint32_1_i32() #0 {
; CHECK-LABEL: uint32_1_i32:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    lis 3, 232
; CHECK-NEXT:    ori 3, 3, 30023
; CHECK-NEXT:    sldi 3, 3, 8
; CHECK-NEXT:    blr
entry:
  ret i32 -394967296

}

define i64 @uint32_2() #0 {
; CHECK-LABEL: uint32_2:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    li 3, 0
; CHECK-NEXT:    oris 3, 3, 65535
; CHECK-NEXT:    ori 3, 3, 65535
; CHECK-NEXT:    blr
entry:
  ret i64 4294967295

}

define i32 @uint32_2_i32() #0 {
; CHECK-LABEL: uint32_2_i32:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    li 3, 0
; CHECK-NEXT:    oris 3, 3, 65535
; CHECK-NEXT:    ori 3, 3, 65535
; CHECK-NEXT:    blr
entry:
  ret i32 -1

}

define i64 @uint32_3() #0 {
; CHECK-LABEL: uint32_3:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    li 3, 1
; CHECK-NEXT:    sldi 3, 3, 31
; CHECK-NEXT:    blr
entry:
  ret i64 2147483648

}

define i64 @uint32_4() #0 {
; CHECK-LABEL: uint32_4:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    li 3, 29
; CHECK-NEXT:    sldi 3, 3, 32
; CHECK-NEXT:    oris 3, 3, 3752
; CHECK-NEXT:    ori 3, 3, 57376
; CHECK-NEXT:    blr
entry:
  ret i64 124800000032

}

define i64 @cn_ones_1() #0 {
; CHECK-LABEL: cn_ones_1:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    li 3, 2
; CHECK-NEXT:    sldi 3, 3, 32
; CHECK-NEXT:    oris 3, 3, 28543
; CHECK-NEXT:    ori 3, 3, 65535
; CHECK-NEXT:    blr
entry:
  ret i64 10460594175

}

define i64 @cn_ones_2() #0 {
; CHECK-LABEL: cn_ones_2:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    li 3, 2
; CHECK-NEXT:    sldi 3, 3, 32
; CHECK-NEXT:    oris 3, 3, 28521
; CHECK-NEXT:    ori 3, 3, 32767
; CHECK-NEXT:    blr
entry:
  ret i64 10459119615

}

attributes #0 = { nounwind readnone }
