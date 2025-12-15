#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEMORY_SIZE 65536
unsigned short AX = 0, BX = 0, CX = 0, DX = 0;
unsigned short CS = 0, DS = 0, ES = 0, SS = 0;
unsigned short SP = 0, BP = 0, IP = 0;
unsigned char memory[MEMORY_SIZE];

void fetchInstruction() {
    // Fetch the instruction at CS:IP
    unsigned short address = (CS << 4) + IP;
    unsigned char instruction = memory[address];
    IP++;  // Increment IP to point to the next instruction
    // Add the fetched instruction to the fetch queue (not shown here)
}

void decodeInstruction(unsigned char instruction) {
    // Decode the instruction and determine the operation and operands
    // E.g., MOV, ADD, etc.
    // Add the decoded instruction to the decode queue (not shown here)
}

// Pseudo-code for pipeline stages
/*
void pipelineCycle() {
    // Fetch stage
    if (fetchQueue is not full) {
        fetchInstruction();
    }
    // Decode stage
    if (decodeQueue is not full && fetchQueue is not empty) {
        instruction = dequeue(fetchQueue);
        decodeInstruction(instruction);
    }
    // Execute stage
    if (executionQueue is not full && decodeQueue is not empty) {
        instruction = dequeue(decodeQueue);
        executeInstruction(instruction.operation, instruction.dest, instruction.src);
    }
}
*/

typedef struct Instruction {
    char operation[10];
    char dest[20];
    char src[20];
    struct Instruction* next;
}Instruction;

Instruction* createInstruction(const char* operation, const char* dest, const char* src){
    Instruction* newInst = (Instruction*)malloc(sizeof(Instruction));
    strcpy(newInst->operation, operation);
    strcpy(newInst->dest, dest);
    strcpy(newInst->src, src);
    newInst->next = NULL;
    return newInst;
}

void appendInstruction(Instruction **head, const char* operation, const char*dest, const char* src){
    Instruction* newInst = createInstruction(operation, dest, src);
    if (*head == NULL) {
        *head = newInst;
        return;
    }
    Instruction* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newInst;
}


void executeInstruction(char* operation, char* dest, char* src) {
    if (strcmp(operation, "MOV") == 0) {
        if (strcmp(dest, "AX") == 0 && strcmp(src, "BX") == 0) {
            AX = BX;
        }
        // Add other cases for different registers and operations
    } else if (strcmp(operation, "ADD") == 0) {
        // Implement ADD operation
    }
    // Add the executed instruction to the execution queue (not shown here)
}

void executeInstructions(Instruction* head) {
    Instruction* temp = head;
    while (temp != NULL) {
        printf("Executing: %s %s, %s\n", temp->operation, temp->dest, temp->src);
        executeInstruction(temp-> operation, temp-> dest, temp->src);
        temp = temp->next;
    }
}

void fetchInstruction() {
    // Fetch the instruction at CS:IP
    unsigned short address = (CS << 4) + IP;
    unsigned char instruction = memory[address];
    IP++;  // Increment IP to point to the next instruction

    // For this example, just print the fetched instruction
    printf("Fetched Instruction: 0x%02X from memory address 0x%04X\n", instruction, address);
}

int main(){
    Instruction* head = NULL;
    char str1[10];
    char str2[20];
    char str3[20];
    scanf("%s", str1);
    scanf("%s", str2);
    int size2 = strlen(str2);
    str2[size2 - 1] = '\0';
    scanf("%s", str3);

    appendInstruction(&head, str1, str2, str3);
    executeInstructions(head);

    // Example of fetching an instruction from memory
    memory[(CS << 4) + 0x0000] = 0xB8; // MOV AX, immediate (just as an example opcode)
    fetchInstruction();

    // printf("%s", str1);
    // printf("\n");
    // printf("%s", str2);
    // printf("\n");
    // printf("%s", str3);
    // printf("\n");
    return 0;
}