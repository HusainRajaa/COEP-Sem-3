
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV AX, 1000H
MOV DS, AX
MOV SI, 1000H
MOV BX, 2000H
MOV DI, 3000H
MOV CX, 0000H
MOV [SI], 1100H
MOV [SI+2], 1010H
MOV [BX], 1010H
MOV [BX+2], 1111H
CALL ADDITION
RET 




             
             
           ADDITION:MOV AX, [SI]
                    ADD AX, [BX]
                    JMP LABEL
                    MOV CX,0001H
              LABEL:MOV [DI], AX
                    ADD SI, 02H
                    ADD BX,02H
                    ADD DI, 02H
                    MOV AX, [SI]
                    ADD AX, [BX]
                    ADD AX,CX
                    MOV [DI], AX
                    RET


ret




