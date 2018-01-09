	.text
	.file	"testgc.ll"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 3, __gcc_personality_v0
	.cfi_lsda 3, .Lexception0
# BB#0:                                 # %entry
	pushq	%rbx
.Ltmp9:
	.cfi_def_cfa_offset 16
	subq	$32, %rsp
.Ltmp10:
	.cfi_def_cfa_offset 48
.Ltmp11:
	.cfi_offset %rbx, -16
	movq	llvm_gc_root_chain(%rip), %rax
	movq	$__gc_main, 8(%rsp)
	movq	$0, 16(%rsp)
	movq	%rax, (%rsp)
	leaq	(%rsp), %rax
	movq	%rax, llvm_gc_root_chain(%rip)
	movq	$0, 24(%rsp)
.Ltmp0:
	movl	$1048576, %edi          # imm = 0x100000
	callq	llvm_gc_initialize
.Ltmp1:
# BB#1:                                 # %entry.cont3
.Ltmp2:
	movl	$10, %edi
	callq	llvm_gc_allocate
.Ltmp3:
# BB#2:                                 # %entry.cont2
	movq	%rax, 16(%rsp)
.Ltmp4:
	movl	$8, %edi
	callq	llvm_gc_allocate
.Ltmp5:
# BB#3:                                 # %entry.cont
	movq	%rax, 24(%rsp)
	movq	16(%rsp), %rcx
	movq	%rcx, (%rax)
	movl	$10000000, %ebx         # imm = 0x989680
	.align	16, 0x90
.LBB0_4:                                # %AllocLoop
                                        # =>This Inner Loop Header: Depth=1
.Ltmp6:
	movl	$100, %edi
	callq	llvm_gc_allocate
.Ltmp7:
# BB#5:                                 # %AllocLoop.cont
                                        #   in Loop: Header=BB0_4 Depth=1
	decl	%ebx
	jne	.LBB0_4
# BB#6:                                 # %Exit
	movq	(%rsp), %rax
	movq	%rax, llvm_gc_root_chain(%rip)
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbx
	retq
.LBB0_7:                                # %gc_cleanup
.Ltmp8:
	movq	(%rsp), %rcx
	movq	%rcx, llvm_gc_root_chain(%rip)
	movq	%rax, %rdi
	callq	_Unwind_Resume
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.align	4
GCC_except_table0:
.Lexception0:
	.byte	255                     # @LPStart Encoding = omit
	.byte	3                       # @TType Encoding = udata4
	.asciz	"\234"                  # @TType base offset
	.byte	3                       # Call site Encoding = udata4
	.byte	26                      # Call site table length
	.long	.Ltmp0-.Lfunc_begin0    # >> Call Site 1 <<
	.long	.Ltmp7-.Ltmp0           #   Call between .Ltmp0 and .Ltmp7
	.long	.Ltmp8-.Lfunc_begin0    #     jumps to .Ltmp8
	.byte	0                       #   On action: cleanup
	.long	.Ltmp7-.Lfunc_begin0    # >> Call Site 2 <<
	.long	.Lfunc_end0-.Ltmp7      #   Call between .Ltmp7 and .Lfunc_end0
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.align	4

	.type	llvm_gc_root_chain,@object # @llvm_gc_root_chain
	.bss
	.weak	llvm_gc_root_chain
	.align	8
llvm_gc_root_chain:
	.quad	0
	.size	llvm_gc_root_chain, 8

	.type	__gc_main,@object       # @__gc_main
	.section	.rodata,"a",@progbits
	.align	8
__gc_main:
	.long	2                       # 0x2
	.long	0                       # 0x0
	.size	__gc_main, 8


	.section	".note.GNU-stack","",@progbits
