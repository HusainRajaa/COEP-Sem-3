#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MEMORY_SIZE 65536
unsigned char memory[MEMORY_SIZE];

unsigned short AX = 0, BX = 0, CX = 0, DX = 0, SI = 0;
unsigned short CS = 0, DS = 0, ES = 0, SS = 0;
unsigned short SP = 0, BP = 0, IP = 0;

// Helper function to parse value from src or disp
unsigned short parseValue(const char* str) {
    if (strchr(str, 'H') != NULL) {
        return (unsigned short)strtol(str, NULL, 16); // Hexadecimal
    } else {
        return (unsigned short)atoi(str); // Decimal
    }
}

void executeInstruction(const char* operation, const char* dest, const char* src) {
    unsigned short value;
    int opcode[16];
    int disp[4];
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
            else if (strstr(src, "[]"))
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

int main() {
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

    return 0;
}
