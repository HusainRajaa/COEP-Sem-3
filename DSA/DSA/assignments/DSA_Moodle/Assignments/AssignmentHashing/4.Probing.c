#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Linear Probing Hashing Function
int hashFunction1(int key) {
    return key % TABLE_SIZE;  // Primary hash function
}

// Linear Probing: Insert key into hash table
void linearProbingInsert(int hashTable[], int key) {
    int index = hashFunction1(key);  // Calculate initial index using the primary hash function
    int i = 0;
    
    // Linear probing: resolve collision by checking next slots
    while (hashTable[(index + i) % TABLE_SIZE] != -1) {
        i++;
    }

    // Insert key at the available index
    hashTable[(index + i) % TABLE_SIZE] = key;
}

// Quadratic Probing Hashing Function
int quadraticProbingInsert(int hashTable[], int key) {
    int index = hashFunction1(key);  // Calculate initial index using the primary hash function
    int i = 0;
    
    // Quadratic probing: resolve collision using quadratic increments
    while (hashTable[(index + i * i) % TABLE_SIZE] != -1) {
        i++;
    }

    // Insert key at the available index
    hashTable[(index + i * i) % TABLE_SIZE] = key;
}

// Function to display the hash table
void displayHashTable(int hashTable[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
}

// Function to compare Linear Probing and Quadratic Probing
void compareOpenAddressingMethods() {
    // Array for Linear Probing (initialize all slots as -1 to indicate empty)
    int hashTableLinear[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTableLinear[i] = -1;
    }

    // Insert keys using Linear Probing
    int keys[] = {23, 44, 12, 56, 78, 90, 33, 47, 25, 18};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++) {
        linearProbingInsert(hashTableLinear, keys[i]);
    }

    // Display hash table after insertion using Linear Probing
    printf("Linear Probing:\n");
    displayHashTable(hashTableLinear);

    // Array for Quadratic Probing (initialize all slots as -1 to indicate empty)
    int hashTableQuadratic[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTableQuadratic[i] = -1;
    }

    // Insert keys using Quadratic Probing
    for (int i = 0; i < n; i++) {
        quadraticProbingInsert(hashTableQuadratic, keys[i]);
    }

    // Display hash table after insertion using Quadratic Probing
    printf("Quadratic Probing:\n");
    displayHashTable(hashTableQuadratic);
}

int main() {
    // Compare the linear probing and quadratic probing methods
    compareOpenAddressingMethods();

    return 0;
}
