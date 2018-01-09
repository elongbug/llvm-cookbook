declare i32 @strlen(i8*) readonly nounwind
define void @test() {
	call i32 @strlen( i8* null )
	ret void
}
