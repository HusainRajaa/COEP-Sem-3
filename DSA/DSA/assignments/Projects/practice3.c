#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MEMORY_SIZE 65536

// General Purpose Registers
unsigned short AX = 0, BX = 0, CX = 0, DX = 0;

// Segment Registers
unsigned short CS = 0, DS = 0, ES = 0, SS = 0;

// Special Purpose Registers
unsigned short SP = 0, BP = 0, IP = 0;

// Memory
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
    unsigned short value;
    
    // Helper function to parse value from src or disp
    unsigned short parseValue(const char* str) {
        if (strchr(str, 'H') != NULL) {
            return (unsigned short)strtol(str, NULL, 16); // Hexadecimal
        } else {
            return (unsigned short)atoi(str); // Decimal
        }
    }

    // Determine the type of instruction and operands
    if (strcmp(operation, "MOV") == 0) {
        if (strcmp(dest, "AX") == 0) {
            if (strcmp(src, "BX") == 0) {
                AX = BX;
            } else if (strstr(src, "[BX]") != NULL) {
                // Example: MOV AX, [BX]
                // Read value from memory addressed by BX and store in AX
                AX = memory[BX];
            } else if (strstr(src, "[BX + SI]") != NULL) {
                // Example: MOV AX, [BX + SI]
                // Read value from memory addressed by BX + SI and store in AX
                AX = memory[BX + SI];
            } else if (strstr(src, "+ DISP") != NULL) {
                // Example: MOV AX, [BX + DISP]
                // Extract DISP from src and calculate address
                char* disp = strstr(src, "+") + 2; // Skip "+ " and get DISP
                value = parseValue(disp);
                AX = memory[BX + value];
            } else if (strstr(src, "DISP") != NULL) {
                // Example: MOV AX, [DISP]
                // Extract DISP from src and calculate address
                value = parseValue(src);
                AX = memory[value];
            }
        }
        else if (strcmp(dest, "BX") == 0) {
            if (strcmp(src, "AX") == 0) {
                BX = AX;
            } else if (strstr(src, "[BX]") != NULL) {
                // Example: MOV BX, [BX]
                BX = memory[BX];
            } else if (strstr(src, "[BX + SI]") != NULL) {
                // Example: MOV BX, [BX + SI]
                BX = memory[BX + SI];
            } else if (strstr(src, "+ DISP") != NULL) {
                // Example: MOV BX, [BX + DISP]
                char* disp = strstr(src, "+") + 2; // Skip "+ " and get DISP
                value = parseValue(disp);
                BX = memory[BX + value];
            } else if (strstr(src, "DISP") != NULL) {
                // Example: MOV BX, [DISP]
                value = parseValue(src);
                BX = memory[value];
            }
        }
        // Add similar cases for other general-purpose registers
    } else if (strcmp(operation, "ADD") == 0) {
        if (strcmp(dest, "AX") == 0) {
            if (strcmp(src, "BX") == 0) {
                AX += BX;
            }
            // Handle other addressing modes for ADD
        }
    }
    // Add other operations as needed
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
