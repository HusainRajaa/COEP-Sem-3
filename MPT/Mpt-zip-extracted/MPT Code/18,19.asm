
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov ax, 0000h
mov ds,ax
mov bx,2000h
mov si,00h
mov [3000h],0ah

loop1:  mov al,[bx]
        and al,80h   ; for even numbers and al, 01h
        jnz there     ; for positive number and even numbers jnz there 
        inc si

there:  inc bx
        mov ax,[3000h]
        dec ax
        mov [3000h],ax
        jnz loop1





