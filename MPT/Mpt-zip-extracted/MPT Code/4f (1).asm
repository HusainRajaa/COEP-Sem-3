
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h                  
MOV ES,AX               ;Move segment address of Vector Table to ES
MOV DX, Divide_by_Zero  ;Move address of subroutine to DX
MOV ES:[00H],DX         ;Move address of subroutine to vector table
MOV AX, CS              ;Move segment address of subroutine to AX
MOV ES:[02H],AX         ;Move segment address of subroutine to vector table

MOV AX, [1000H]         ;Move numerator to AX
MOV BX, [1002H]         ;Move Denominator to BX
DIV BX                  ;Divide AX/BX
         
ret                     ;Return

Divide_by_Zero:                             ;Subroutine label
STI                                         ;Set interrupt flag
msg DB 10,13,'DIVIDE BY ZERO ERROR','$'     ;Write message into array
LEA DX,msg                                  ;Load effective address of the message into DX
MOV AH,09H                                  ;Move 09 to AH
INT 21H                                     ;Call interrupt 21
;Terminate Program
MOV al, 0 
OUT 20h, al 
MOV AX,4C00h
INT 21h
RET


