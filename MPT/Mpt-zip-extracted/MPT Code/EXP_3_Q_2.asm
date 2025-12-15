
;Use this subroutine in A above in the main program to add two 
;series of 32 bit numbers. Store the result from 1000:3000 onwards. 
;If carry is generated in double word addition store it at
; third location  in sequence of the result.
    
    
MOV AX,1000H
MOV DS,AX


MOV SI,1000H
MOV DI,2000H
MOV BX,3000H

MOV CX,0004H     

MOV [1000H],0D234H
MOV [1002H],0F425H
MOV [1004H],0D234H
MOV [1006H],03425H

MOV [2000H],0AC20H
MOV [2002H],05F01H   
MOV [2004H],0AC20H
MOV [2006H],05F01H



ADD_SERIES:

CALL ADD_32BIT

JC CARRY
BACK:

ADD BX,02H 


ADD SI,02H
ADD DI,02H
DEC CX
JNZ ADD_SERIES

RET




          
          
CARRY:
ADD BX,02H
MOV [BX],0001H 
JMP BACK
         
    

ADD_32BIT:
MOV AX,[SI]
ADD AX,[DI]

MOV [BX],AX

INC SI
INC SI
INC DI
INC DI
ADD BX,02H


MOV AX,[SI]
ADC AX,[DI]

MOV [BX],AX

RET