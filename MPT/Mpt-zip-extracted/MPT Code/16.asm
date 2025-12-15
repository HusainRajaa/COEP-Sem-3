
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov si,2000h
mov di,3000h
mov bx,4000h
mov [2000h],0d234h
mov [2002h],0f425h
mov [3000h],0ac20h
mov [3002h],5f01h
mov ax,[si]
add ax,[di]
pushf
mov [bx],ax
add si,02h
add di,02h
add bx,02h
mov ax,[si]
popf
adc ax,[di]
mov [bx],ax





