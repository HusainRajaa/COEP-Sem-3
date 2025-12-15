
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h  
mov ax, 0000h
mov ds, ax
mov es,ax
mov cx,000ah
mov si,2000h
mov di,3000h

cld
rep movsb






