#include <stdio.h>

// Define the size of the hash table
#define TABLE_SIZE 10

// Function to hash a key using the Division Method
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

// Function to insert keys into the hash table and display distribution
void hashKeys(int keys[], int n, int hashTable[], int tableSize) {
    // Initialize hash table
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1; // -1 indicates an empty slot
    }

    // Insert keys into the hash table
    for (int i = 0; i < n; i++) {
        int index = hashFunction(keys[i], tableSize);
        if (hashTable[index] == -1) {
            hashTable[index] = keys[i];
        } else {
            printf("Collision occurred for key %d at index %d\n", keys[i], index);
        }
    }

    // Display the hash table
    printf("\nHash Table:\n");
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
}

int main() {
    // Example keys to hash
    int keys[] = {23, 44, 12, 56, 78, 90, 33, 47, 25, 18};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Hash table
    int hashTable[TABLE_SIZE];

    // Hash the keys and display the hash table
    hashKeys(keys, n, hashTable, TABLE_SIZE);

    return 0;
}
