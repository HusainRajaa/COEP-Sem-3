


MOV [1000H],0D234H
MOV [1002H],0F425H
MOV [2000H],0AC20H
MOV [2002H],05F01H
    
    
    
    
MOV SI,1000H
MOV DI,2000H
MOV BX,3000H  
    
     
    
CLC
CALL SUB 

LAHF 
OR AL,01H  
MOV [BX + 02H],AL



RET 


SUB:  
MOV CX,[SI]
ADC CX,[DI]
   
MOV [BX],CX
    
INC SI
INC SI
INC DI
INC DI
INC BX
INC BX 

MOV CX,[SI]
ADC CX,[DI]
   
MOV [BX],CX
    
RET



