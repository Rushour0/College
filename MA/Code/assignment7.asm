; Algorithm
; 1.	Order – ascending / descending
; 2.	Array elements :  i/p or hard coded section .bss
; 3.	Rsi = array
; 4.	Cl = counter1 = no of elements
; 5.	Counter2 = no of elements – 1
; 6.	Cmp rsi, rsi+1
; 7.	If greater, jae / jbe
; 8.	swap ;  xchg rsi, rsi+1
; 9.	If less, no swap
; 10.	Increment array location
; 11.	Dec counter2
; 12.	Jnz step no 6
; 13.	Inc base rsi,
; 14.	dec counter1
; 15.	Jnz step5

%macro rw 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data
	msg db "Array in Ascending Order:", 0ah
	msgLen equ $-msg
	
	msg1 db "Array Elements:", 0ah
	msgLen1 equ $-msg1

	msg2 db "Array in Descending Order:", 0ah
	msg2Len equ $-msg2

	newLine db 0ah
	newLineLen equ $-newLine

	array db 73h, 34h, 46h, 56h, 21h
	cnt1 db 5
	cnt2 db 4

section .bss
	result resb 10
	temp resb 21	

section .text
	global _start

_start:
	rw 1,1,msg1,msgLen1
	call display

	rw 1,1,newLine,newLineLen

	mov cl,byte[cnt1]
outer:	
	mov bl,byte[cnt2]
	mov rsi,array

up:	
	mov al,byte[rsi]
	cmp al,byte[rsi+1]
	jbe only_inc
	xchg al,byte[rsi+1]
	mov byte[rsi],al

only_inc: inc rsi
	dec bl
	jnz up
	inc rsi
	dec cl
	jnz outer

	rw 1,1,msg,msgLen
	call display

	mov cl,byte[cnt1]
outer2:	
	mov bl,byte[cnt2]
	mov rsi,array

up2:	
	mov al,byte[rsi]
	cmp al,byte[rsi+1]
	jae only_inc2
	xchg al,byte[rsi+1]
	mov byte[rsi],al

only_inc2: 
	inc rsi
	dec bl
	jnz up2
	inc rsi
	dec cl
	jnz outer2

	rw 1,1,newLine,newLineLen
	rw 1,1,msg2,msg2Len
	call display

	mov rax, 60
	mov rdi, 0
	syscall

display:
	mov rdi, array
	mov rsi,result
	mov dl,10

display_loop1:
	mov cl,2
	mov al,[rdi]

againx:
	rol al,4
	mov bl,al
	and al,0FH
	cmp al,09H
	jbe downx
	add al,07H

downx:
	add al,030H
	mov byte[rsi],al
	mov al,bl
	inc rsi
	dec cl
	jnz againx
	inc rsi
	inc rdi
	dec dl
	jnz display_loop1

	rw 1,1,result,15
	ret

	
