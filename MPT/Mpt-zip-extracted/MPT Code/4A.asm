
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

NEXT:MOV AX, 1000H
     MOV BX, 2000H
     MOV CX, 0000H
     MOV DX, 3829H
     PUSH CS
     CALL FUNC
     
FUNC: POP BX
      MOV AH, 00H
      
BACK: INT 16H
      CMP AL, 'B'
      JNZ BACK
      POP AX
      MOV DS, AX
      MOV [BX], 00H
      JMP NEXT

ret




