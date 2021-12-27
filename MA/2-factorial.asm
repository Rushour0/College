; macro to perform system call
%macro RW 4
    mov rax, %1
    mov rdi, %2
    mov rsi, %3
    mov rdx, %4
    syscall
%endmacro

; Section data to store
section .data
    msg db 'Enter a number:', 32
    msg_len equ $-msg
    msg1 db 'The Factorial of the number is : ', 32
    msg1_len equ $-msg1

; Section bss to reserve memory space
section .bss
    temp resb 1
    temp1 resb 1
    num1 resw 10

; Section to get things started
section .text
    global _start
    
    _start:
        mov bp, 4
        RW 1, 1, msg, msg_len                       ; display msg
        RW 0, 0, num1, 10                           ; take input into num1
        RW 1, 1, msg1, msg1_len                     ; display msg1
        mov al, byte[num1]                          ; move data in num1 to al register
        cmp al, 39h                                 ; compare with 39H to check what number it is          
        jbe next                                    ; jump if below or equal to 39H
        sub al, 07h                                 ; converting ascii number to hex number

    next:
        sub al, 30h                                 ; converting ascii number to hex number
        mov word[num1], ax                          ; store al register value in num1
        mov ax, 01h
        
    factorial:
        mul word[num1]                              ; multiply num1 with ax   
        dec word[num1]                              ; decrease num1 by 1
        cmp word[num1], 0000h                       ; check if num1 has become 0
        jnz factorial                               ; jump to factorial if num1 not zero
    
    ; code to display two characters in the al register
    up: 
        rol ax, 4       
        mov bx, ax
        and al, 0fh
        cmp al, 09h
        jbe down
        add al, 07
    
    down:
        add al, 30h
        mov byte[temp1], al
        RW 1, 1, temp1, 1
        mov ax, bx
        dec bp
        jnz up
    
    RW 60,0,0,0                                     ; system end call