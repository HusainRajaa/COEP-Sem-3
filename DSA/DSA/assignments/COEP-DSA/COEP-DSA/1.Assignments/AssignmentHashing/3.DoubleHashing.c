#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Double Hashing: Secondary hash function
int hashFunction1(int key) {
    return key % TABLE_SIZE;  // Primary hash function
}

int hashFunction2(int key) {
    return 7 - (key % 7);  // Secondary hash function, must be co-prime with table size
}

// Function to insert a key into the hash table using double hashing
void insertKey(int hashTable[], int key) {
    int index = hashFunction1(key);  // Calculate initial index using the primary hash function
    int i = 1;

    // Double hashing: resolve collision using secondary hash function
    while (hashTable[index] != -1) {
        index = (index + i * hashFunction2(key)) % TABLE_SIZE;
        i++;
    }
    
    // Insert the key at the calculated index
    hashTable[index] = key;
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

// Function to test the performance of double hashing vs. chaining
void compareHashingMethods() {
    // Array for double hashing (initialize all slots as -1 to indicate empty)
    int hashTable1[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable1[i] = -1;  // -1 indicates empty slot
    }

    // Insert some keys into the hash table
    int keys[] = {23, 44, 12, 56, 78, 90, 33, 47, 25, 18};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Insert keys using double hashing
    for (int i = 0; i < n; i++) {
        insertKey(hashTable1, keys[i]);
    }

    // Display hash table after insertion
    displayHashTable(hashTable1);
}

int main() {
    // Compare the double hashing method
    compareHashingMethods();

    return 0;
}
