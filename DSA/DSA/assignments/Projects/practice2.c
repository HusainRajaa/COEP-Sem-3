#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEMORY_SIZE 65536
unsigned short AX = 0, BX = 0, CX = 0, DX = 0;
unsigned short CS = 0, DS = 0, ES = 0, SS = 0;
unsigned short SP = 0, BP = 0, IP = 0;
unsigned char memory[MEMORY_SIZE];

// Structure for Instruction
typedef struct Instruction {
    char operation[10];
    char dest[20];
    char src[20];
    struct Instruction* next;
} Instruction;

// Create a new Instruction
Instruction* createInstruction(const char* operation, const char* dest, const char* src) {
    Instruction* newInst = (Instruction*)malloc(sizeof(Instruction));
    strcpy(newInst->operation, operation);
    strcpy(newInst->dest, dest);
    strcpy(newInst->src, src);
    newInst->next = NULL;
    return newInst;
}

// Append an Instruction to the list
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

// Execute an Instruction
void executeInstruction(const char* operation, const char* dest, const char* src) {
    if (strcmp(operation, "MOV") == 0) {
        if (strcmp(dest, "AX") == 0 && strcmp(src, "BX") == 0) {
            AX = BX;
        }
        // Implement other cases for different registers and operations
    } else if (strcmp(operation, "ADD") == 0) {
        // Implement ADD operation
    }
}

// Execute all Instructions
void executeInstructions(Instruction* head) {
    Instruction* temp = head;
    while (temp != NULL) {
        printf("Executing: %s %s, %s\n", temp->operation, temp->dest, temp->src);
        executeInstruction(temp->operation, temp->dest, temp->src);
        temp = temp->next;
    }
}

// Fetch an Instruction
void fetchInstruction() {
    // Fetch the instruction at CS:IP
    unsigned short address = (CS << 4) + IP;
    unsigned char instruction = memory[address];
    IP++;  // Increment IP to point to the next instruction

    // For this example, just print the fetched instruction
    printf("Fetched Instruction: 0x%02X from memory address 0x%04X\n", instruction, address);
}

// Trim leading and trailing whitespace from a string
char* trimWhitespace(char* str) {
    char* end;
    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    if (*str == 0)  // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null-terminate
    *(end + 1) = '\0';

    return str;
}

// Identify Addressing Mode from instruction
void identifyAddressingMode(const char* dest, const char* src) {
    char cleanDest[30];
    char cleanSrc[30];
    strcpy(cleanDest, trimWhitespace(dest));
    strcpy(cleanSrc, trimWhitespace(src));

    // Check if the source contains brackets indicating an indirect addressing mode
    if (strstr(cleanSrc, "[") != NULL) {
        // Handle base-plus-index addressing modes
        if (strstr(cleanSrc, "+") != NULL) {
            if (strstr(cleanSrc, "SI") != NULL || strstr(cleanSrc, "BX") != NULL) {
                if (strstr(cleanSrc, "+") != NULL && strstr(cleanSrc, "DISP") != NULL) {
                    printf("Addressing Mode: Base-plus-Index-plus-Displacement\n");
                } else {
                    printf("Addressing Mode: Base-plus-Index\n");
                }
            } else {
                printf("Addressing Mode: Register Indirect\n");
            }
        } else {
            printf("Addressing Mode: Register Indirect\n");
        }
    } else if (strstr(cleanSrc, "MOV") != NULL) {
        // Immediate addressing
        printf("Addressing Mode: Immediate\n");
    } else {
        // Register addressing
        printf("Addressing Mode: Register\n");
    }
}

int main() {
    Instruction* head = NULL;
    char str1[10];
    char str2[20];
    char str3[20];
    
    // Read instruction parts from input
    printf("Enter operation: ");
    scanf("%s", str1);
    printf("Enter destination: ");
    scanf("%s", str2);
    printf("Enter source: ");
    scanf("%s", str3);

    appendInstruction(&head, str1, str2, str3);
    executeInstructions(head);

    // Example of fetching an instruction from memory
    memory[(CS << 4) + 0x0000] = 0xB8; // MOV AX, immediate (just as an example opcode)
    fetchInstruction();

    // Identify addressing mode for the instruction
    identifyAddressingMode(str2, str3);

    // Free allocated memory
    Instruction* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
