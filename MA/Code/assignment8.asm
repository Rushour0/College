%macro scall 4
    mov rax,%1
    mov rdi,%2
    mov rsi,%3
    mov rdx,%4
    syscall
%endmacro

section .data
    msg db "Vender name is:", 0ah
    len equ $-msg
    nline db 10
    msg2 db "After EAX=01H:",10
    l1 equ $-msg2
    
section .bss
string resq 2
string2 resq 2
temp resq 1
temp1 resq 1

section .text
    global _start

_start:
    scall 1,1,msg,len
    mov eax,00h
    cpuid
    add [string],ebx
    add [string+4],edx
    add [string+8],ecx
    scall 1,1,string,12
    scall 1,1,nline,1
    
    scall 1,1,msg2,l1
     mov eax,01h
    cpuid
    mov [string2],eax
    call disp
    scall 1,1,nline,1
    mov [string2],ebx
    call disp
    scall 1,1,nline,1
    mov [string2],edx
    call disp
    scall 1,1,nline,1
    mov [string2],ecx
    ;scall 1,1,string,16
    call disp
    scall 1,1,nline,1

     mov rax, 60
    mov rdi, 0
    syscall
disp:
  mov bp,4
mov ax,word[string2]
up1:rol ax,4
mov [temp],ax
and ax,0fh
cmp al,09

jbe down1
add al,07
down1:add al,30h
mov [temp1],al
scall 1,1,temp1,1

mov ax,word[temp]
dec bp
jnz up1
ret