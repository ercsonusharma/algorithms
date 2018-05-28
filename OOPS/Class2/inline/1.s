	.file	"1.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	"Constructor"
	.text
	.align 2
	.globl	_ZN1AC2Ev
	.type	_ZN1AC2Ev, @function
_ZN1AC2Ev:
.LFB972:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC0, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE972:
	.size	_ZN1AC2Ev, .-_ZN1AC2Ev
	.globl	_ZN1AC1Ev
	.set	_ZN1AC1Ev,_ZN1AC2Ev
	.align 2
	.globl	_ZN1A1fEv
	.type	_ZN1A1fEv, @function
_ZN1A1fEv:
.LFB974:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$20, -12(%ebp)
	movl	$10, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZNSolsEi
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE974:
	.size	_ZN1A1fEv, .-_ZN1A1fEv
	.globl	main
	.type	main, @function
main:
.LFB975:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN1AC1Ev
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN1A1fEv
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN1A1fEv
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN1A1fEv
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE975:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB984:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	.L5
	cmpl	$65535, 12(%ebp)
	jne	.L5
	movl	$_ZStL8__ioinit, (%esp)
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, 8(%esp)
	movl	$_ZStL8__ioinit, 4(%esp)
	movl	$_ZNSt8ios_base4InitD1Ev, (%esp)
	call	__cxa_atexit
.L5:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE984:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__ZN1AC2Ev, @function
_GLOBAL__sub_I__ZN1AC2Ev:
.LFB985:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	_Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE985:
	.size	_GLOBAL__sub_I__ZN1AC2Ev, .-_GLOBAL__sub_I__ZN1AC2Ev
	.section	.init_array,"aw"
	.align 4
	.long	_GLOBAL__sub_I__ZN1AC2Ev
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
