
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

IDIV BL
HLT

FUN:MOV AH,0EH
    MOV AL,'D'
    INT 10H
    MOV AL,'I'
    INT 10H
    MOV AL,'V'
    INT 10H
    MOV AL,'I'
    INT 10H
    MOV AL,'D'
    INT 10H
    MOV AL,'E'
    INT 10H
    MOV AL,' '
    INT 10H
    MOV AL,'Z'
    INT 10H
    MOV AL,'E'
    INT 10H 
    MOV AL,'R'
    INT 10H
    MOV AL,'O'
    INT 10H
    MOV AL,' '
    INT 10H
    MOV AL,'E'
    INT 10H
    MOV AL,'R'
    INT 10H
    MOV AL,'R'
    INT 10H
    MOV AL,'O'
    INT 10H
    MOV AL,'R'
    INT 10H
    IRET

ret




