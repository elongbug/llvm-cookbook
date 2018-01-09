	.text
	.file	"bc_to_target_assembly.bc"
	.globl	mult
	.align	16, 0x90
	.type	mult,@function
mult:                                   # @mult
	.cfi_startproc
# BB#0:
	imull	%esi, %edi
	movl	%edi, %eax
	retq
.Lfunc_end0:
	.size	mult, .Lfunc_end0-mult
	.cfi_endproc


	.section	".note.GNU-stack","",@progbits
