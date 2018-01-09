define i32 @test(i32 %b, i32 %a) {
        %tmp.1 = add i32 %a, 1234
        %tmp.2 = add i32 %b, %tmp.1
        %tmp.4 = xor i32 %a, -1
        ; (b+(a+1234))+~a -> b+1233
        %tmp.5 = add i32 %tmp.2, %tmp.4
        ret i32 %tmp.5
}
