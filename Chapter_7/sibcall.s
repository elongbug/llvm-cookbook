	.text
	.file	"sibcall.ll"
	.globl	foo
	.align	16, 0x90
	.type	foo,@function
foo:                                    # @foo
	.cfi_startproc
# BB#0:                                 # %entry
	jmp	bar                     # TAILCALL
.Lfunc_end0:
	.size	foo, .Lfunc_end0-foo
	.cfi_endproc


	.section	".note.GNU-stack","",@progbits
