
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV CX, 0000H
MOV AX, 1234H
MOV BH, 00H
MOV BL, 00H
DIV BL
RET
SUBB:MOV BX, 10H
     DIV BX
     PUSH DX
     INC CX
     XOR DX,DX
     CMP AX, 0H
     JNZ SUBB
BACK:MOV AH,0AH
     POP DX
     ADD DX, 48D
     MOV AL, DL
     INT 10H
     DEC CX
     JNZ BACK
     IRET
     



ret




