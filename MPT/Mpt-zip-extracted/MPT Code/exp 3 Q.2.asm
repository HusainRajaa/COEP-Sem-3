
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

            MOV AX, 1000H
            MOV DS, AX
            MOV SI, 1000H
            MOV BX, 2000H
            MOV DI, 3000H
            MOV CX, 000AH
            MOV DX, 0000H
INITIALIZE: MOV [SI], AX
            ADD SI, 02H
            ADD AX, 0201H
            MOV [BX], AX
            ADD BX, 02H
            ADD AX, 0201H
            DEC CX
            JNZ INITIALIZE
            MOV SI, 1000H
            MOV SI, 2000H
            MOV DI, 3000H
            MOV CX, 0005H
    LABEL1:CALL ADDITION
            ADD DI,0001H
            ADD SI,02H
            ADD BX, 02H
            MOV DX, 0000H
            DEC CX
            JNZ LABEL 1
            RET  
             
             
             
                            ADDITION: MOV AX, [SI]
                                      ADD SI, 02H
                                      ADD AX, [BX]
                                      JNC LABEL 2
                                      MOV DX, 0001H
                              LABEL2:MOV [DI], AX
                                      ADD BX, 02H
                                      ADD DI, 02H
                                      MOV AX, [SI]
                                      ADD AX, [BX]
                                      ADD AX, DX
                                      JC CARRY
                                      JMP NOCARRY
                                CARRY:MOV DL, 01H
                                      JMP LABEL 3
                             NOCARRY:MOV DL, 00H
                              LABEL3:MOV [DI], AX
                                      ADD DI, 02H
                                      MOV [DI], DL
                                      RET 
                                    

ret




