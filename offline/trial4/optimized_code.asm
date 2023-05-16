.MODEL small
.STACK 100h
.DATA
	print_var dw ?
	ret_temp dw ?
	i_1_1 dw ?
	j_1_1 dw ?
	k_1_1 dw ?
	ll_1_1 dw ?
	m_1_1 dw ?
	n_1_1 dw ?
	o_1_1 dw ?
	p_1_1 dw ?
	t0 dw ?
	t1 dw ?
	t2 dw ?
	t3 dw ?
	t4 dw ?
	t5 dw ?
	t6 dw ?
	t7 dw ?
	t8 dw ?
.CODE
print PROC
	push ax
	push bx
	push cx
	push dx
	mov ax, print_var
	mov bx, 10
	mov cx, 0
printLabel1:
	mov dx, 0
	div bx
	push dx
	inc cx
	cmp ax, 0
	jne printLabel1
printLabel2:
	mov ah, 2
	pop dx
	add dl, '0'
	int 21h
	dec cx
	cmp cx, 0
	jne printLabel2
	mov dl, 0Ah
	int 21h
	mov dl, 0Dh
	int 21h
	pop dx
	pop cx
	pop bx
	pop ax
	ret
print endp
main PROC
	mov ax, @data
	mov ds, ax
	mov ax, 1
	mov i_1_1, ax
	mov ax, i_1_1
	mov print_var, ax
	call print
	mov ax, 5
	add ax, 8
	mov t0, ax
	mov j_1_1, ax
	mov print_var, ax
	call print
	mov ax, 2
	mov bx, j_1_1
	mul bx
	mov t1, ax
	mov ax, i_1_1
	add ax, t1
	mov t2, ax
	mov k_1_1, ax
	mov print_var, ax
	call print
	mov ax, k_1_1
	mov bx, 9
	xor dx, dx
	div bx
	mov t3, dx
	mov ax, t3
	mov m_1_1, ax
	mov print_var, ax
	call print
	mov ax, m_1_1
	cmp ax, ll_1_1
	jle l0
	mov t4, 0
	jmp l1
l0:
	mov t4, 1
l1:
	mov ax, t4
	mov n_1_1, ax
	mov ax, n_1_1
	mov print_var, ax
	call print
	mov ax, i_1_1
	cmp ax, j_1_1
	jne l2
	mov t5, 0
	jmp l3
l2:
	mov t5, 1
l3:
	mov ax, t5
	mov o_1_1, ax
	mov ax, o_1_1
	mov print_var, ax
	call print
	cmp n_1_1, 0
	jne l4
	cmp o_1_1, 0
	jne l4
	mov t6, 0
	jmp l5
l4:
	mov t6, 1
l5:
	mov ax, t6
	mov p_1_1, ax
	mov ax, p_1_1
	mov print_var, ax
	call print
	cmp n_1_1, 0
	je l6
	cmp o_1_1, 0
	je l6
	mov t7, 1
	jmp l7
l6:
	mov t7, 0
l7:
	mov ax, t7
	mov p_1_1, ax
	mov ax, p_1_1
	mov print_var, ax
	call print
	mov ax, p_1_1
	mov t8, ax
	inc p_1_1
	mov ax, p_1_1
	mov print_var, ax
	call print
	neg p_1_1
	mov ax, p_1_1
	mov k_1_1, ax
	mov ax, k_1_1
	mov print_var, ax
	call print
	mov ax, 0
	mov ret_temp, ax
main ENDP
END main
