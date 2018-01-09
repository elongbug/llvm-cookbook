; ModuleID = 'bc_to_target_assembly.bc'

define i32 @mult(i32 %a, i32 %b) {
  %1 = mul nsw i32 %a, %b
  ret i32 %1
}
