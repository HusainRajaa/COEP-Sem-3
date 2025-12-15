
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV AX, 1234H
MOV BX, 4321H
MOV DX, 5678H
MOV SI, 1000H 
MOV DI, 2000H
MOV ES, SI
MOV DS, DI
MOV SP, 0FFFH
MOV CX, 0000H
JNZ ISS
RET 



ISS: MOV AH, 00H
     INT 16H
     CMP AL, 'B'
     INT 3H
     IRET


ret




