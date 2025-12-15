
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV AX, 1100H
MOV BX, 1111H
MOV CX, 0001H
MOV DX, 2233H
INT 3
ISS:MOV BX, AX
    MOV SI, BX
    MOV DI, DX
    MOV BP, CX
    MOV AH, 0EH
    MOV DX, BX
    AND DH, 01H
    MOV CL, 04H
    SHR DH, CL
    ADD DH,30H
    MOV AL, DH
    INT 10
    MOV DX, BX
    AND DH, 01H
    ADD DH, 30H
    MOV AL, 0H
    INT 10
    MOV DX, BX
    AND DH, 01H
    ADD DH, 30H
    MOV AL, 0H
    INT 10
    MOV DX, BX
    AND DL, 01H
    ADD DL, 30H
    MOV AL, DL 
    INT 10
                    

ret




