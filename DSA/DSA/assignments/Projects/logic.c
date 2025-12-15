#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

// Initialize the hash table
Node* hashTable[TABLE_SIZE] = { NULL };

// Hash function
unsigned int hash(char* mnemonic) {
    unsigned int hashValue = 0;
    for (int i = 0; mnemonic[i] != '\0'; i++) {
        hashValue += mnemonic[i]; // Sum the ASCII values of the characters
    }
    return hashValue % TABLE_SIZE; // Ensure the index is within bounds
}

// Insert an opcode into the hash table
void insertOpcode(char* mnemonic, void (*execute)(GPRegisters*, SegmentRegisters*, Memory*, char*, char*)) {
    unsigned int index = hash(mnemonic); // Compute index
    Node* newNode = (Node*)malloc(sizeof(Node)); // Create new node
    strcpy(newNode->opcode.mnemonic, mnemonic); // Set mnemonic
    newNode->opcode.execute = execute; // Set execution function
    newNode->next = hashTable[index]; // Link to existing nodes
    hashTable[index] = newNode; // Insert at index
}

// Find an opcode in the hash table
Opcode* findOpcode(char* mnemonic) {
    unsigned int index = hash(mnemonic); // Compute index
    Node* current = hashTable[index]; // Get the list at the index
    while (current != NULL) {
        if (strcmp(current->opcode.mnemonic, mnemonic) == 0) {
            return &current->opcode; // Found the mnemonic
        }
        current = current->next; // Move to next node
    }
    return NULL; // Mnemonic not found
}

// Execute MOV instruction
void executeMov(GPRegisters* gp, SegmentRegisters* seg, Memory* mem, char* operand1, char* operand2) {
    int value = getRegisterValue(gp, operand2);
    setRegisterValue(gp, operand1, value);
    printf("MOV %s, %s executed: %s = %d\n", operand1, operand2, operand1, value);
}

// Execute ADD instruction
void executeAdd(GPRegisters* gp, SegmentRegisters* seg, Memory* mem, char* operand1, char* operand2) {
    int regValue = getRegisterValue(gp, operand1);
    int addValue;
    if (operand2[strlen(operand2) - 1] == 'H') {
        // Convert hexadecimal to integer
        sscanf(operand2, "%x", &addValue);
    } else {
        addValue = atoi(operand2);
    }
    setRegisterValue(gp, operand1, regValue + addValue);
    printf("ADD %s, %s executed: %s = %d\n", operand1, operand2, operand1, regValue + addValue);
}

// Get value from a general-purpose register
int getRegisterValue(GPRegisters* gp, char* regName) {
    if (strcmp(regName, "AX") == 0) return gp->AX;
    if (strcmp(regName, "BX") == 0) return gp->BX;
    if (strcmp(regName, "CX") == 0) return gp->CX;
    if (strcmp(regName, "DX") == 0) return gp->DX;
    return 0;
}

// Set value of a general-purpose register
void setRegisterValue(GPRegisters* gp, char* regName, int value) {
    if (strcmp(regName, "AX") == 0) gp->AX = value;
    if (strcmp(regName, "BX") == 0) gp->BX = value;
    if (strcmp(regName, "CX") == 0) gp->CX = value;
    if (strcmp(regName, "DX") == 0) gp->DX = value;
}

// Calculate physical address using segment:offset
int calculatePhysicalAddress(SegmentRegisters* seg, int offset) {
    return seg->CS * 16 + offset;
}
