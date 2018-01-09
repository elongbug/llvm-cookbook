; ModuleID = 'interval.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nounwind
define void @donothing(i32 %a) #0 {
  %1 = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  ret void
}

; Function Attrs: nounwind
define i32 @func(i32 %i) #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  %m = alloca i32, align 4
  %b = alloca i32, align 4
  %z = alloca i32, align 4
  %k = alloca i32, align 4
  store i32 %i, i32* %1, align 4
  store i32 5, i32* %a, align 4
  %2 = load i32, i32* %a, align 4
  call void @donothing(i32 %2)
  %3 = load i32, i32* %a, align 4
  store i32 %3, i32* %m, align 4
  %4 = load i32, i32* %m, align 4
  call void @donothing(i32 %4)
  store i32 9, i32* %a, align 4
  %5 = load i32, i32* %1, align 4
  %6 = icmp slt i32 %5, 5
  br i1 %6, label %7, label %11

; <label>:7                                       ; preds = %0
  store i32 3, i32* %b, align 4
  %8 = load i32, i32* %b, align 4
  call void @donothing(i32 %8)
  %9 = load i32, i32* %b, align 4
  store i32 %9, i32* %z, align 4
  %10 = load i32, i32* %z, align 4
  call void @donothing(i32 %10)
  br label %14

; <label>:11                                      ; preds = %0
  %12 = load i32, i32* %a, align 4
  store i32 %12, i32* %k, align 4
  %13 = load i32, i32* %k, align 4
  call void @donothing(i32 %13)
  br label %14

; <label>:14                                      ; preds = %11, %7
  %15 = load i32, i32* %m, align 4
  ret i32 %15
}

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-realign-stack" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.7.0 (trunk 234045)"}
