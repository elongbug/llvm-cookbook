	.text
	.file	"interval.ll"
	.globl	donothing
	.align	16, 0x90
	.type	donothing,@function
donothing:                              # @donothing
# BB#0:
	movl	%edi, -4(%rsp)
	retq
.Lfunc_end0:
	.size	donothing, .Lfunc_end0-donothing

	.globl	func
	.align	16, 0x90
	.type	func,@function
func:                                   # @func
# BB#0:
	subq	$24, %rsp
	movl	%edi, 20(%rsp)
	movl	$5, 16(%rsp)
	movl	$5, %edi
	callq	donothing
	movl	16(%rsp), %edi
	movl	%edi, 12(%rsp)
	callq	donothing
	movl	$9, 16(%rsp)
	cmpl	$4, 20(%rsp)
	jg	.LBB1_2
# BB#1:
	movl	$3, 8(%rsp)
	movl	$3, %edi
	callq	donothing
	movl	8(%rsp), %edi
	movl	%edi, 4(%rsp)
	jmp	.LBB1_3
.LBB1_2:
	movl	16(%rsp), %edi
	movl	%edi, (%rsp)
.LBB1_3:
	callq	donothing
	movl	12(%rsp), %eax
	addq	$24, %rsp
	retq
.Lfunc_end1:
	.size	func, .Lfunc_end1-func


	.ident	"clang version 3.7.0 (trunk 234045)"
	.section	".note.GNU-stack","",@progbits
