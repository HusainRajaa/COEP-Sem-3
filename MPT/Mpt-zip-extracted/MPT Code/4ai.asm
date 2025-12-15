
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
MOV AL,0H    
MOV ES,AX
MOV DX,BreakPoint
MOV AX,CS
MOV ES:[3*4H],DX
MOV ES:[3*4H+2],AX

INT 3H               
ret

BreakPoint:    
STI
msg DB 10,13,'BreakPoint occurred','$'
LEA DX,msg
MOV AH,09H
INT 21H       
MOV al, 0 ; Clear the interrupt flag
OUT 20h, al ; Send EOI signal to PIC 
MOV AX,4C00h
INT 21h
ret

