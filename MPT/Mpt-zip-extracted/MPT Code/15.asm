
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV AX, 9244H
MOV BX, 0a545H
ADD AX, BX
JPO ISS


ISS:    mov ah,0eh
        mov al,'o'
        int 10h
        mov al,'v'
        int 10h
        mov al,'e'
        int 10h
        mov al,'r'
        int 10h
        mov al,'f'
        int 10h
        mov al,'l'
        int 10h
        mov al,'o'
        int 10h
        mov al,'w'
        int 10h
        mov al,' '
        int 10h
        mov al,'E'
        int 10h
        mov al,'R'
        int 10h
        mov al,'R'
        int 10h
        mov al,'O'
        int 10h
        mov al,'R'
        int 10h






