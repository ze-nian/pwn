	.file	"demo1.c"
	.intel_syntax noprefix
	.text
	.globl	function
	.type	function, @function
function:
	push	ebp
	mov	ebp, esp
	sub	esp, 40
	mov	DWORD PTR [ebp-23], 0
	mov	DWORD PTR [ebp-19], 0
	mov	DWORD PTR [ebp-15], 0
	mov	WORD PTR [ebp-11], 0
	mov	BYTE PTR [ebp-9], 0
	lea	eax, [ebp-23]
	mov	DWORD PTR [esp], eax
	call	gets
	mov	eax, DWORD PTR [ebp+12]
	mov	edx, DWORD PTR [ebp+8]
	add	eax, edx
	leave
	ret
	.size	function, .-function
	.globl	main
	.type	main, @function
main:
	push	ebp
	mov	ebp, esp
	and	esp, -16
	sub	esp, 16
	mov	DWORD PTR [esp+4], 3
	mov	DWORD PTR [esp], 2
	call	function
	mov	eax, 1
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
