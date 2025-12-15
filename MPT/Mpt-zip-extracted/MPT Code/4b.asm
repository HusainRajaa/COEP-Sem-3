
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

ORG 100h ; COM file starts at address 100h

; Initialize variables
PRESSED DB 0 ; Flag to indicate if B key is pressed

; Main program
MAIN:                   

PUSH AX
PUSH DX
MOV AX,0
MOV ES,AX
MOV DX, DISPLAY
MOV AX,CS
MOV ES:[3*4H],DX
MOV ES:[3*4H+2],AX
POP DX
POP AX
; Your code here

; Check for B key press
CHECK_KEY:
MOV AH, 00H ; BIOS function for keyboard input
INT 16H ; Wait for key press
CMP AL, 'B' ; Check if key pressed is 'B'
JNE NEW ; Jump to MAIN if not 'B'
MOV PRESSED, 1 ; Set flag if 'B' key is pressed

; Insert CC opcode (INT3 instruction) after last instruction in main program
INSERT_INT:
CMP PRESSED, 1 ; Check if 'B' key is pressed
JNE MAIN ; Jump to MAIN if not pressed
INC CX
INT 3 ; Insert INT3 opcode
JMP MAIN ; Jump to MAIN to continue execution
            
            
NEW: MOV PRESSED,0
JMP MAIN


DISPLAY:
msg DB 10,13,'Key B pressed','$'
LEA DX,msg
MOV AH,09H
INT 21H                         
MOV AL,0
OUT 20H,AL
MOV AX,4C00H
INT 21H
ret