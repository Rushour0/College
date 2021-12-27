%macro rw 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

; Section data to store
section .data
    msg db "Enter number: "                         
    msglen equ $-msg
    msg1 db "Sum of array: "
    msg1len equ $-msg1
    count db 5                                      ; storing count of array size

; Section bss to reserve memory space
section .bss
    sum resb 2
    temp resb 2
    num1 resw 10

; Section to get things started
section .text
    global _start

    _start:
        mov bx, 00h
        mov bp, [count]                             ; storing count
        
    addloop:
        rw 1, 1, msg, msglen                        ; display msg
        rw 0, 0, num1, 10                           ; take input into num1
    
    ; process to convert ascii to hex
    hextoascii:    
        mov bl, byte[num1]                          ; move data in num1 to bl register
        cmp bl, 39h                                 ; compare with 39H to check what number it is          
        jbe next                                    ; jump if below or equal to 39H
        sub bl, 07h                                 ; converting ascii number to hex number

    next:
        sub bl, 30h                                 ; converting ascii number to hex number
        add word[sum], bx
        dec bp
        jnz addloop
        rw 1, 1, msg1, msg1len

    ; code to display numbers
    disp:
        mov bp, 4
        mov ax, word[sum]
    up:
        rol ax,4
        mov bx, ax
        and ax, 0fh
        cmp al, 09
        jbe down
        add al, 07

    down: 
        add al,30h
        mov [temp],al
        rw 1, 1,temp, 1
        mov ax, bx
        dec bp
        jnz up

    exit: 
        mov rax,60
        mov rdi,0
        syscall