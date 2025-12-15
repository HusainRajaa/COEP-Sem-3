#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 65536

// General Purpose Registers
unsigned short AX = 0, BX = 0, CX = 0, DX = 0;

// Segment Registers
unsigned short CS = 0, DS = 0, ES = 0, SS = 0;

// Special Purpose Registers
unsigned short SP = 0, BP = 0, IP = 0;

// Memory
unsigned char memory[MEMORY_SIZE];

// Instruction Structure
typedef struct Instruction {
    char operation[10];
    char dest[20];
    char src[20];
    struct Instruction* next;
} Instruction;

// Function to create an instruction node
Instruction* createInstruction(const char* operation, const char* dest, const char* src) {
    Instruction* newInst = (Instruction*)malloc(sizeof(Instruction));
    strcpy(newInst->operation, operation);
    strcpy(newInst->dest, dest);
    strcpy(newInst->src, src);
    newInst->next = NULL;
    return newInst;
}

// Function to append an instruction to the list
void appendInstruction(Instruction** head, const char* operation, const char* dest, const char* src) {
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

// Function to fetch the instruction from memory at CS:IP
unsigned char fetchInstruction() {
    unsigned short address = (CS << 4) + IP;
    unsigned char instruction = memory[address];
    IP++;  // Increment IP to point to the next instruction
    return instruction;
}

// Function to decode and execute a MOV instruction
void executeMOV(char* dest, char* src) {
    if (strcmp(dest, "AX") == 0) {
        if (strcmp(src, "BX") == 0) {
            AX = BX;
        } else if (strcmp(src, "CX") == 0) {
            AX = CX;
        } else if (strcmp(src, "DX") == 0) {
            AX = DX;
        } else if (strncmp(src, "0x", 2) == 0) {
            AX = (unsigned short)strtol(src, NULL, 16);
        }
    } else if (strcmp(dest, "BX") == 0) {
        if (strcmp(src, "AX") == 0) {
            BX = AX;
        } else if (strcmp(src, "CX") == 0) {
            BX = CX;
        } else if (strcmp(src, "DX") == 0) {
            BX = DX;
        } else if (strncmp(src, "0x", 2) == 0) {
            BX = (unsigned short)strtol(src, NULL, 16);
        }
    }
    // Add more cases for CX, DX, etc.
}

// Function to execute a list of instructions
void executeInstructions(Instruction* head) {
    Instruction* temp = head;
    while (temp != NULL) {
        printf("Executing: %s %s, %s\n", temp->operation, temp->dest, temp->src);
        if (strcmp(temp->operation, "MOV") == 0) {
            executeMOV(temp->dest, temp->src);
        }
        // Implement other operations (ADD, SUB, etc.) here
        temp = temp->next;
    }
}

int main() {
    Instruction* head = NULL;
    char str1[10];
    char str2[20];
    char str3[20];

    // Example input (MOV AX, BX)
    // You can add more inputs to build a sequence of instructions
    scanf("%s", str1); // MOV
    scanf("%s", str2); // AX,
    str2[strlen(str2) - 1] = '\0'; // Remove the comma
    scanf("%s", str3); // BX

    appendInstruction(&head, str1, str2, str3);

    // Set some initial values for demonstration
    BX = 0x1234; // Initialize BX with a value
    CX = 0x5000; // Initialize BX with a value

    // Execute the instructions
    executeInstructions(head);

    // Print the result after execution
    // printf("AX = 0x%04X\n", AX); // Should print 0x1234 if MOV AX, BX was executed
    printf("BX = 0X%04X\n", BX);
    printf("CX = 0X%04X\n", CX);

    // Example of fetching an instruction from memory (hardcoded for demonstration)
    memory[(CS << 4) + 0x0000] = 0xB8; // MOV AX, immediate (just an example opcode)
    unsigned char fetchedInstruction = fetchInstruction();
    printf("Fetched Instruction: 0x%02X from memory address 0x%04X\n", fetchedInstruction, (CS << 4) + 0x0000);

    return 0;
}
