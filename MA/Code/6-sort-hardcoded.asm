%macro rw 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
    arr db 4,5,6,7,3
    msg1 db "Sorted array: ", 32
    msg1len equ $-msg1
    space db " "
    count equ 5

section .bss
    num resb 2
    temp resw 2
    result resb 15

section .text
    global _start

_start:
    mov dl, count
    oloop:
        mov cl, count
        dec cl
        mov rsi, arr

        iloop:
            mov al, byte[rsi]                   
            cmp al, bl
            jl proceed                          
            xchg [rsi], bl
            mov [rsi+1], bl                 

        proceed:
            inc rsi
            dec cl
            jnz iloop

        dec dl
        jnz oloop

    rw 1, 1, msg1, msg1len              

    lea rsi, arr
    lea rdi, result
    mov sp, count

showloop:
    mov bp, 2
    mov al,[rsi]

    up:
        rol al, 4
        mov bl, al
        and al, 0fh
        cmp al, 09
        jbe down
        add al, 07

    down: 
        add al, 30h
        mov byte[rdi], al
        mov al, bl
        inc rdi
        dec bp
        jnz up

    mov byte[rdi], " "
    inc rdi
    inc rsi
    dec sp
    jnz showloop

rw 1, 1, result, 15

exit: 
    mov rax,60
    mov rdi,0
    syscall