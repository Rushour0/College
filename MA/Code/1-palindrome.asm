%macro scall 4          ;For 64 Bit we use Marco as in 4 parameters are chosen
        mov rax,%1
        mov rdi,%2
        mov rsi,%3
        mov rdx,%4
        syscall         ;call the kernel (interrupt)       
%endmacro

section .data ; initializing variables whose value is known
        menu db 10d,13d,"              MENU" ; 10d = cursor goes to new line
             db 10d,"1. Enter the String"    ; 13d = cursor goes to start of the line
             db 10d,"2. Calculate Length of the string"
             db 10d,"3. Reverse String"
             db 10d,"4. Check Palindrome"
             db 10d,"5. Exit"
             db 10d,"Enter your choice: "
        menulen equ $-menu  ; storing length of menu string in menulen variable
        
        m1 db 10d,"Enter String: "
        l1 equ $-m1
        m2 db 10d,"Length Of String: "
        l2 equ $-m2
        m3 db 10d,"Reversed String: "
        l3 equ $-m3
        m4 db 10d,"String is Palindrome!!!"
        l4 equ $-m4
        m5 db 10d,"String is not Palindrome!!!"
        l5 equ $-m5
        
section .bss ; declaring variables whose value is unknown
        choice resb 2
        string resb 50
        string2 resb 50
        length resb 16
        answer resb 16
        
section .text
        global _start
_start:
        
        scall 1,1,menu,menulen ; passing 1 means output (1 = monitor)
        scall 0,0,choice,2 ; passing 0 means input (0 = keyboard)
        
        cmp byte[choice],'5'
        jae exit ; jae = jump above equal
        cmp byte[choice],'1'
        je case1 ; je = jump equal
        cmp byte[choice],'2'
        je case2
        cmp byte[choice],'3'
        je case3
        cmp byte[choice],'4'
        je case4
       
case1: 
	scall 1,1,m1,l1
        scall 0,0,string,50

        dec rax                 
        mov [length],rax
jmp _start

case2:
        scall 1,1,m2,l2
        mov rax,[length]
        call display            ;call procedure
jmp _start

case3:  
        call stringreverse      ;call procedure
        
        scall 1,1,m3,l3
        scall 1,1,string2,[length]
jmp _start

case4:  
        call stringreverse      ;call procedure
        
	mov rsi,string
	mov rdi,string2
	mov rcx,[length]
	
loop3:	
	mov al,[rsi]
	mov bl,[rdi]
	inc rsi
	inc rdi
	cmp al,bl
	jne skip2 ; jne = jump not equal
	loop loop3

	scall 1,1,m4,l4
	jmp _start
skip2: 
	scall 1,1,m5,l5
jmp _start    
   
exit:                           ;exit instructions
        mov rax,60
        mov rdx,0
        syscall ; calling the kernel (interrupt)
        
      
; ----------- PROCEDURES -------------------------      

display:                        ;hex to ascii-hex
        mov rsi,answer+15
        mov rcx,16

loop1:	mov rdx,0
        mov rbx,16
        div rbx
        cmp dl,09h
        jbe skip1
        
        add dl,07h
skip1:	add dl,30h
        mov [rsi],dl
        
        dec rsi
        dec rcx
        jnz loop1
        scall 1,1,answer,16       
ret ; return from procedure

stringreverse: 
        mov rsi,string
        mov rdi,string2
        mov rcx,[length]
        add rdi,rcx
        dec rdi
        
loop2:  
        mov al,[rsi]        
        mov [rdi],al
        dec rdi
        inc rsi
        loop loop2

ret ; return from procedure
