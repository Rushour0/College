; Macro to perform system call
%macro RW 4
   mov rax, %1
   mov rdi, %2
   mov rsi, %3
   mov rdx, %4
   syscall
%endmacro

; Section data to store
section .data
   msg1 db '--This is protected mode--',10
   msg1_len equ $-msg1
   msg2 db 'GDTR value is:-', 32
   msg2_len equ $-msg2
   msg3 db 'MSW value is:-', 32
   msg3_len equ $-msg3
   msg4 db 'IDTR value is:-', 32
   msg4_len equ $-msg4
   msg5 db 'LDTR value is:-', 32
   msg5_len equ $-msg5
   msg6 db 'TR value is:-', 32
   msg6_len equ $-msg6
   cnt2 db 04
   line db 10

; Section bss to reserve memory space
section .bss
   g resb 6
   id resb 6
   msw resd 1
   value resb 4
   temp resb 1
   ld resb 4
   tr resb 4

; Section to get things started
section .text
   global _start
_start:
   smsw [msw]
   mov eax, dword[msw]
   bt eax, 0
   jc next
   jmp exit

next:
   RW 1,1,msg1,msg1_len
   RW 1,1,msg2,msg2_len
   SGDT[g]
   mov bx, word[g+4]
   call HextoA
   mov bx, word[g+2]
   call HextoA
   mov bx, word[g]
   call HextoA

   RW 1,1,line,1
   RW 1,1,msg3,msg3_len
   mov bx, word[msw]
   call HextoA
 
   RW 1,1,line,1
   RW 1,1,msg4,msg4_len
   sidt[id]
   mov bx, word[id+4]
   call HextoA
   mov bx, word[id+2]
   call HextoA
   mov bx, word[id]
   call HextoA

   sldt[ld]
   RW 1,1,line,1
   RW 1,1,msg5,msg5_len
   mov bx, word[ld]
   call HextoA

   str[tr]
   RW 1,1,line,1
   RW 1,1,msg6,msg6_len
   mov bx, word[tr]
   call HextoA
   
;Exit function
exit:
   mov rax, 60
   mov rdi,0
   syscall

;Converting hexadecimal number to ascii
HextoA:
   mov rdi, value
   mov byte[cnt2],4H
   
aup:
   rol bx,04
   mov cl,bl
   and cl,0FH
   cmp cl,09H
   jbe anext
   add cl, 07H
   anext:
   add cl,30H
   mov byte[rdi],cl
   inc rdi
   dec byte[cnt2]
   jnz aup
   RW 1,1,value,4
ret