; ModuleID = 'test1.ll'

define i32 @test1(i32 %A) {
  %B = add i32 %A, 0
  ret i32 %B
}

define internal i32 @test(i32 %X) {
  ret i32 %X
}

define i32 @caller() {
  %A = call i32 @test(i32 123)
  ret i32 %A
}
