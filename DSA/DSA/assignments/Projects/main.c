#include <stdio.h>
#include <string.h>
#include "header.h"

// Function to execute an instruction
void executeInstruction(char* instruction, GPRegisters* gp, SegmentRegisters* seg, Memory* mem);

int main() {
    // Initialize registers and memory
    GPRegisters gp = { .AX = 0, .BX = 1234, .CX = 5678, .DX = 91011 };
    SegmentRegisters seg = { .CS = 0x1000, .DS = 0x2000, .ES = 0x3000, .SS = 0x4000, .IP = 0x0000 };
    Memory mem = { .memory = {0} };

    // Insert instructions into the hash table
    insertOpcode("MOV", executeMov);
    insertOpcode("ADD", executeAdd);

    // Sample instructions
    char instruction1[] = "MOV AX, BX";
    char instruction2[] = "ADD AX, 1000H";

    // Execute instructions
    executeInstruction(instruction1, &gp, &seg, &mem);
    executeInstruction(instruction2, &gp, &seg, &mem);

    // Find the address of AX using CS:IP
    int address = calculatePhysicalAddress(&seg, gp.AX);
    printf("Address of AX using CS:IP = %04X:%04X = %05X\n", seg.CS, seg.IP, address);

    return 0;
}

void executeInstruction(char* instruction, GPRegisters* gp, SegmentRegisters* seg, Memory* mem) {
    char mnemonic[10], operand1[10], operand2[10];
    sscanf(instruction, "%s %[^,], %s", mnemonic, operand1, operand2);
    
    Opcode* opcode = findOpcode(mnemonic);
    if (opcode != NULL) {
        opcode->execute(gp, seg, mem, operand1, operand2);
    } else {
        printf("Unknown instruction: %s\n", instruction);
    }
}
