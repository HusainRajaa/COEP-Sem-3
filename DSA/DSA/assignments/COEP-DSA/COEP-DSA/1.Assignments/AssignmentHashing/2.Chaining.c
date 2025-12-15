#include <stdio.h>
#include <stdlib.h>

// Define the size of the hash table
#define TABLE_SIZE 10

// Node structure for linked list
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Hash function using the division method
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key into the hash table
void insertKey(Node* hashTable[], int key) {
    int index = hashFunction(key);

    // Create a new node
    Node* newNode = createNode(key);

    // Insert at the beginning of the linked list
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        // Collision occurred
        printf("Collision occurred for key %d at index %d\n", key, index);
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

// Function to display the hash table
void displayHashTable(Node* hashTable[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to calculate average and maximum chain lengths
void analyzeChains(Node* hashTable[]) {
    int totalChains = 0, totalLength = 0, maxLength = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int chainLength = 0;
        Node* temp = hashTable[i];
        while (temp != NULL) {
            chainLength++;
            temp = temp->next;
        }
        if (chainLength > 0) {
            totalChains++;
            totalLength += chainLength;
            if (chainLength > maxLength) {
                maxLength = chainLength;
            }
        }
    }

    printf("\nChain Analysis:\n");
    printf("Average Chain Length: %.2f\n", (totalChains > 0) ? (float)totalLength / totalChains : 0.0);
    printf("Maximum Chain Length: %d\n", maxLength);
}

int main() {
    // Hash table with chaining
    Node* hashTable[TABLE_SIZE] = {NULL};

    // Example keys to insert
    int keys[] = {23, 44, 12, 56, 78, 90, 33, 47, 25, 18};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Insert keys into the hash table
    for (int i = 0; i < n; i++) {
        insertKey(hashTable, keys[i]);
    }

    // Display the hash table
    displayHashTable(hashTable);

    // Analyze chains
    analyzeChains(hashTable);

    return 0;
}
