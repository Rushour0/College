%macro rw 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
    arr db 4,5,6,7,3
    msg1 db "Sum of array: ",10
    msg1len equ $-msg1
    count db 5

section .bss
    sum resb 2
    num resb 2
    temp resb 2 

section .text
    global _start

_start:
    mov rsi, arr
    mov ax, 00h
    mov bx, 00h
    mov cx, [count]

addloop:
    mov bl, byte[rsi]
    add ax, bx
    jnc skip
    inc ah
    
skip:
    inc rsi
    dec cx
    jnz addloop
    mov word[sum], ax
    rw 1, 1, msg1, msg1len              ; display msg1

    mov bp, 4
    mov ax, word[sum]
    
up:
    rol ax, 4
    mov bx, ax
    and ax, 0fh
    cmp al, 09
    jbe down
    add al, 07

down: 
    add al, 30h
    mov [temp], al
    rw 1, 1, temp, 1
    mov ax, bx
    dec bp
    jnz up

exit: 
    mov rax,60
    mov rdi,0
    syscall