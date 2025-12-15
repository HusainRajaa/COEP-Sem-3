
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
MOV ES,AX
MOV DX,KeyPress
MOV AX,CS
MOV ES:[16*4H],DX
MOV ES:[16*4H+2],AX

;MOV CX,0
CALL MAIN

ret

MAIN:
MOV AH,0H
INT 16H


KeyPress:
STI                  
CMP AL,42H
JNE MAIN
msg DB 10,13,'Key B was pressed','$'
LEA DX,msg
MOV AH,09H
INT 21H
MOV al, 0 ; Clear the interrupt flag
OUT 20h, al ; Send EOI signal to PIC 
MOV AX,4C00h
INT 21h
RET



