                                                                       
org 100h 
                     
                     
                     
PUSH AX
PUSH DX
MOV AX,0
MOV ES,AX
MOV DX,intthree
MOV AX,CS
MOV ES:[3*4H],DX
MOV ES:[3*4H+2],AX
POP DX
POP AX                     
                     
;LOOKUP TABLE 
mov di,2000h
mov [2000h],'0'  
mov [2001h],'1'
mov [2002h],'2'
mov [2003h],'3'
mov [2004h],'4'
mov [2005h],'5'
mov [2006h],'6'
mov [2007h],'7'
mov [2008h],'8'
mov [2009h],'9'
mov [200Ah],'A'
mov [200Bh],'B'
mov [200Ch],'C'
mov [200Dh],'D'
mov [200Eh],'E'
mov [200Fh],'F'

;REGISTER CONTENT
mov [3000h],ax 
mov [3002h],bx
mov [3004h],cx  
mov [3006h],dx 


mov bp,3000h
mov cl,01h 
mov bx,0000h
int 3h 


ret 


 
intthree:    
    MOV CX,1;
    mov si,[bp]
    mov ax,0000h 
    mov ah,0Ah  
    int 10h
    mov dx,si
    shr dx,12 
    add di,dx
    mov dx,[di] 
    mov al,dl
    int 10h    
    CALL jump 
    mov di,2000h
    mov dx,si
    and dx,0F00h
    ror dx,8 
    add di,dx
    mov dx,[di]
    mov al,dl
    int 10h  
    CALL jump
    mov di,2000h 
    mov dx,si
    and dx,00F0h
    shr dx,4 
    add di,dx
    mov dx,[di] 
    mov al,dl
    int 10h  
    CALL jump
    mov di,2000h 
    mov dx,si
    and dx,000Fh 
    add di,dx
    mov dx,[di]
    mov al,dl
    int 10h  
    CALL jump  
    CALL space
    mov di,2000h 
    add bp,0002h
    cmp bp,3008h
    jne intthree
    iret




      
jump:     
PUSH BX
PUSH AX
PUSH DX
inc bh         ; Increment the value in BH to move the cursor position by 1
mov ah, 02h    ; Set AH to 02h to indicate we want to move the cursor position
int 21h        ; Call interrupt 21h to move the cursor position
POP DX
POP AX
POP BX
ret              

space:
MOV dl,' '
MOV AH,02H
INT 21H
ret