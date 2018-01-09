define i32 @foo() { ret i32 1 }

define i32 @test() {
  call i32 @test()
  ret i32 %1
}
define i32 @bar() { ret i32 2 }
