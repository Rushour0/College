;Macro For Syscalls Print,Read,Exit
%macro PR 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .data

msg1 db 10,"______Factorial______"
msg1len equ $-msg1

msg2 db 10,"Enter A number between 00H-FFH : "
msg2len equ $-msg2

newline db 10

num1 dd 0

section .bss

num2 resb 1

fact resd 1
temp1 resd 1
temp2 resb 1
extra resd 1

temp3 resb 1

section .text

global _start
_start:

;Printing of messages and reading inout for number
PR 1,1,msg1,msg1len
PR 1,1,msg2,msg2len

PR 0,0,num2,1
PR 1,1,num2,1
PR 1,1,newline,1

;Conversion of Ascii to hex
cmp byte[num2],40h
jbe DOWN2
sub byte[num2],07h
DOWN2:sub byte[num2],30h

mov al,byte[num2]
add byte[num1],al

;Resetting eax to zero
mov eax,00000000h

;Loop For multiplying the number in eax
mov eax,dword[num1]
UP1:dec dword[num1]
mul dword[num1]
cmp word[num1],1
ja UP1
mov dword[fact],eax

mov eax,dword[fact]

;Loop to print the contents of EAX after ascii conversion
mov bp,8
UP3:rol eax,4
mov dword[temp1],eax
and al,0fh
cmp al,09h
jbe down1
add al,07h
down1: add al,30h
mov byte[temp2],al
PR 1,1,temp2,1
mov eax,dword[temp1]
dec bp
jnz UP3

;End
PR 1,1,newline,1
PR 60,0,0,0


