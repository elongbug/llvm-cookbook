; ModuleID = 'test4.c'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i686-pc-linux-gnu"

; Function Attrs: nounwind
define i32 @main(i32 %argc, i8** %argv) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i8**, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %t = alloca i32, align 4
  store i32 0, i32* %1
  store i32 %argc, i32* %2, align 4
  store i8** %argv, i8*** %3, align 4
  store i32 0, i32* %t, align 4
  store i32 0, i32* %i, align 4
  br label %4

; <label>:4                                       ; preds = %36, %0
  %5 = load i32, i32* %i, align 4
  %6 = icmp slt i32 %5, 10
  br i1 %6, label %7, label %39

; <label>:7                                       ; preds = %4
  store i32 0, i32* %j, align 4
  br label %8

; <label>:8                                       ; preds = %22, %7
  %9 = load i32, i32* %j, align 4
  %10 = icmp slt i32 %9, 10
  br i1 %10, label %11, label %25

; <label>:11                                      ; preds = %8
  store i32 0, i32* %k, align 4
  br label %12

; <label>:12                                      ; preds = %18, %11
  %13 = load i32, i32* %k, align 4
  %14 = icmp slt i32 %13, 10
  br i1 %14, label %15, label %21

; <label>:15                                      ; preds = %12
  %16 = load i32, i32* %t, align 4
  %17 = add nsw i32 %16, 1
  store i32 %17, i32* %t, align 4
  br label %18

; <label>:18                                      ; preds = %15
  %19 = load i32, i32* %k, align 4
  %20 = add nsw i32 %19, 1
  store i32 %20, i32* %k, align 4
  br label %12

; <label>:21                                      ; preds = %12
  br label %22

; <label>:22                                      ; preds = %21
  %23 = load i32, i32* %j, align 4
  %24 = add nsw i32 %23, 1
  store i32 %24, i32* %j, align 4
  br label %8

; <label>:25                                      ; preds = %8
  store i32 0, i32* %j, align 4
  br label %26

; <label>:26                                      ; preds = %32, %25
  %27 = load i32, i32* %j, align 4
  %28 = icmp slt i32 %27, 10
  br i1 %28, label %29, label %35

; <label>:29                                      ; preds = %26
  %30 = load i32, i32* %t, align 4
  %31 = add nsw i32 %30, 1
  store i32 %31, i32* %t, align 4
  br label %32

; <label>:32                                      ; preds = %29
  %33 = load i32, i32* %j, align 4
  %34 = add nsw i32 %33, 1
  store i32 %34, i32* %j, align 4
  br label %26

; <label>:35                                      ; preds = %26
  br label %36

; <label>:36                                      ; preds = %35
  %37 = load i32, i32* %i, align 4
  %38 = add nsw i32 %37, 1
  store i32 %38, i32* %i, align 4
  br label %4

; <label>:39                                      ; preds = %4
  store i32 0, i32* %i, align 4
  br label %40

; <label>:40                                      ; preds = %64, %39
  %41 = load i32, i32* %i, align 4
  %42 = icmp slt i32 %41, 20
  br i1 %42, label %43, label %67

; <label>:43                                      ; preds = %40
  store i32 0, i32* %j, align 4
  br label %44

; <label>:44                                      ; preds = %50, %43
  %45 = load i32, i32* %j, align 4
  %46 = icmp slt i32 %45, 20
  br i1 %46, label %47, label %53

; <label>:47                                      ; preds = %44
  %48 = load i32, i32* %t, align 4
  %49 = add nsw i32 %48, 1
  store i32 %49, i32* %t, align 4
  br label %50

; <label>:50                                      ; preds = %47
  %51 = load i32, i32* %j, align 4
  %52 = add nsw i32 %51, 1
  store i32 %52, i32* %j, align 4
  br label %44

; <label>:53                                      ; preds = %44
  store i32 0, i32* %j, align 4
  br label %54

; <label>:54                                      ; preds = %60, %53
  %55 = load i32, i32* %j, align 4
  %56 = icmp slt i32 %55, 20
  br i1 %56, label %57, label %63

; <label>:57                                      ; preds = %54
  %58 = load i32, i32* %t, align 4
  %59 = add nsw i32 %58, 1
  store i32 %59, i32* %t, align 4
  br label %60

; <label>:60                                      ; preds = %57
  %61 = load i32, i32* %j, align 4
  %62 = add nsw i32 %61, 1
  store i32 %62, i32* %j, align 4
  br label %54

; <label>:63                                      ; preds = %54
  br label %64

; <label>:64                                      ; preds = %63
  %65 = load i32, i32* %i, align 4
  %66 = add nsw i32 %65, 1
  store i32 %66, i32* %i, align 4
  br label %40

; <label>:67                                      ; preds = %40
  %68 = load i32, i32* %t, align 4
  ret i32 %68
}

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.7.0 (trunk 234702)"}
