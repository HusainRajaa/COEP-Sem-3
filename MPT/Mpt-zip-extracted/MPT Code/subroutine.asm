MOV [1000H],0D234H
MOV [1002H],03425H
MOV [2000H],0AC20H
MOV [2002H],05F01H
    
    
    
    
MOV SI,1000H
MOV DI,2000H
MOV BX,3000H  
    
     
    
CLC
CALL SUB
CALL SUB
RET 


SUB:  
MOV AX,[SI]
ADC AX,[DI]
   
MOV [BX],AX
    
INC SI
INC SI
INC DI
INC DI
INC BX
INC BX
    
RET









