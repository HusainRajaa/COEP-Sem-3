
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV ES, AX
MOV DX, KEYPRESS
MOV AX, CS
MOV ES:[16*4H], DX
MOV ES:[16*4H+2], AX

CALL MAIN

ret
  
MAIN:
MOV AH,0H
INT 16H


KEYPRESS:
STI
CMP AL, 42H
JNE MAIN 
msg DB 10,13, 'KEY B WAS  PRESSED', '$'
LEA DX, msg
MOV AH, 09H
INT 21H
MOV al, 0
OUT 20h, al
MOV AX, 4C00h
INT 21h
RET