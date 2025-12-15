#ifndef HEADER_H
#define HEADER_H

#define TABLE_SIZE 10
#define MEMORY_SIZE 65536 // 64 KB memory

// Structure for general-purpose registers
typedef struct {
    int AX;
    int BX;
    int CX;
    int DX;
} GPRegisters;

// Structure for segment registers
typedef struct {
    int CS;
    int DS;
    int ES;
    int SS;
    int IP;  // Instruction Pointer
} SegmentRegisters;

// Structure for memory (simplified)
typedef struct {
    unsigned char memory[MEMORY_SIZE];
} Memory;

// Opcode structure and hash table
typedef struct Opcode {
    char mnemonic[10];
    void (*execute)(GPRegisters* gp, SegmentRegisters* seg, Memory* mem, char* operand1, char* operand2);
} Opcode;

typedef struct Node {
    Opcode opcode;
    struct Node* next;
} Node;

extern Node* hashTable[TABLE_SIZE];

// Function prototypes
unsigned int hash(char* mnemonic);
void insertOpcode(char* mnemonic, void (*execute)(GPRegisters*, SegmentRegisters*, Memory*, char*, char*));
Opcode* findOpcode(char* mnemonic);

void executeMov(GPRegisters* gp, SegmentRegisters* seg, Memory* mem, char* operand1, char* operand2);
void executeAdd(GPRegisters* gp, SegmentRegisters* seg, Memory* mem, char* operand1, char* operand2);
int getRegisterValue(GPRegisters* gp, char* regName);
void setRegisterValue(GPRegisters* gp, char* regName, int value);
int calculatePhysicalAddress(SegmentRegisters* seg, int offset);

#endif
