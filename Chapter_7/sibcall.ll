declare i32 @bar(i32, i32)

define i32 @foo(i32 %a, i32 %b, i32 %c) {
entry:
  %0 = tail call i32 @bar(i32 %a, i32 %b)
  ret i32 %0
}
