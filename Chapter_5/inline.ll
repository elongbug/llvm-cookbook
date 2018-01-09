define i32 @inner1() alwaysinline {
  ret i32 1
}
define i32 @outer1() {
  %r = call i32 @inner1()
  ret i32 %r
}
