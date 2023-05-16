.MODEL small
.STACK 100h
.DATA
	print_var dw ?
	ret_temp dw ?
	a_1 dw ?
	b_1 dw ?
	c_1 dw ?
	a_1_2 dw ?
	t0 dw ?
	a_1_3 dw ?
	b_1_3 dw ?
	c_1_3 dw ?
	t1 dw ?
	t2 dw ?
	t3 dw ?
	i_1_4 dw ?
	j_1_4 dw ?
	k_1_4 dw ?
	l_1_4 dw ?
	t4 dw ?
	t5 dw ?
	t6 dw ?
	t7 dw ?
	t8 dw ?
	t9 dw ?
	t10 dw ?
	t11 dw ?
	t12 dw ?
	t13 dw ?
.CODE
print PROC
	push ax
	push bx
	push cx
	push dx
	mov bx,print_var
	cmp bx,0
	jge nonneg_num
	mov dl,'-'
	mov ah,2
	int 21h
	neg bx
	nonneg_num:
	mov ax,bx
	mov bx, 10D
	xor cx, cx
	cloop:
	xor dx, dx
	div bx
	push dx
	inc cx
	cmp ax, 0
	jne cloop
	print_loop:
	pop dx
	add dx, '0'
	mov ah, 2
	int 21h
	loop print_loop
	mov dl,0Ah
	mov ah,2
	int 21h
	mov dl,0Dh
	mov ah,2
	int 21h
	pop dx
	pop cx
	pop bx
	pop ax
	ret
print endp

func_a PROC
	push ax
	push bx
	push cx
	push dx
	mov ax, 7
	mov a_1, ax
	pop dx
	pop cx
	pop bx
	pop ax
	ret
func_a ENDP
foo PROC
	push ax
	push bx
	push cx
	push dx
	mov ax, a_1_2
	add ax, 3
	mov t0, ax
	mov a_1_2, ax
	mov ret_temp, ax
	pop dx
	pop cx
	pop bx
	pop ax
	ret
foo ENDP
bar PROC
	push ax
	push bx
	push cx
	push dx
	mov ax, 4
	mov bx, a_1_3
	mul bx
	mov t1, ax
	mov ax, 2
	mov bx, b_1_3
	mul bx
	mov t2, ax
	mov ax, t1
	add ax, t2
	mov t3, ax
	mov c_1_3, ax
	mov ret_temp, ax
	pop dx
	pop cx
	pop bx
	pop ax
	ret
bar ENDP
main PROC
	mov ax, @data
	mov ds, ax
	mov ax, 5
	mov i_1_4, ax
	mov ax, 6
	mov j_1_4, ax
	call func_a
	mov ax, ret_temp
	mov t4, ax
	mov ax, a_1
	mov print_var, ax
	call print
	push i_1_4
	mov ax, i_1_4
	mov a_1_2, ax
	call foo
	mov ax, ret_temp
	mov t5, ax
	pop i_1_4
	mov ax, t5[di]
	mov t6, ax
	mov k_1_4, ax
	mov print_var, ax
	call print
	push i_1_4
	push j_1_4
	mov ax, i_1_4
	mov a_1_3, ax
	mov ax, j_1_4
	mov b_1_3, ax
	call bar
	mov ax, ret_temp
	mov t7, ax
	pop j_1_4
	pop i_1_4
	mov ax, t7
	mov l_1_4, ax
	mov ax, l_1_4
	mov print_var, ax
	call print
	push i_1_4
	push j_1_4
	mov ax, i_1_4
	mov a_1_3, ax
	mov ax, j_1_4
	mov b_1_3, ax
	call bar
	mov ax, ret_temp
	mov t8, ax
	pop j_1_4
	pop i_1_4
	mov ax, 6
	mov bx, t8
	mul bx
	mov t9, ax
	add ax, 2
	mov t10, ax
	push i_1_4
	mov ax, i_1_4
	mov a_1_2, ax
	call foo
	mov ax, ret_temp
	mov t11, ax
	pop i_1_4
	mov ax, 3
	mov bx, t11
	mul bx
	mov t12, ax
	mov ax, t10
	sub ax, t12
	mov t13, ax
	mov j_1_4, ax
	mov print_var, ax
	call print
	mov ax, 0
	mov ret_temp, ax
main ENDP

END main

