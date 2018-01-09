define i32 @test19(i32 %x, i32 %y, i32 %z) {
 %xor1 = xor i32 %y, %z
 %or = or i32 %x, %xor1
 %xor2 = xor i32 %x, %z
 %xor3 = xor i32 %xor2, %y
 %res = xor i32 %or, %xor3
 ret i32 %res
}
