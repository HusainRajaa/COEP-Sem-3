#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct bst{
	int *a;
	int size;
}bst;

void init_bst(bst *t, int size){
	t -> a = malloc(sizeof(int) * size);
	t -> size = size; 
	for(int i = 0; i < size; i++){
		t -> a[i] = INT_MIN;
	}
}

void insert(bst *t, int d){
	int i = 0;                  //root element
	if(t -> a[i] == INT_MIN){
		t -> a[i] = d;
		return;
	}
	while (i < t->size && t->a[i] != INT_MIN) {
        if (t->a[i] == d) {
            return; // Duplicate value; do not insert
        }

        if (d < t->a[i]) {
            int left_child_index = 2 * i + 1;
            if (left_child_index < t->size) {
                if (t->a[left_child_index] == INT_MIN) {
                    t->a[left_child_index] = d; // Insert as left child
                    return;
                }
                i = left_child_index; // Move to left child
            } else {
                printf("Tree is full, cannot insert %d\n", d);
                return; // No space for new left child
            }
        } else {
            int right_child_index = 2 * i + 2;
            if (right_child_index < t->size) {
                if (t->a[right_child_index] == INT_MIN) {
                    t->a[right_child_index] = d; // Insert as right child
                    return;
                }
                i = right_child_index; // Move to right child
            } else {
                printf("Tree is full, cannot insert %d\n", d);
                return; // No space for new right child
            }
        }
    }
}

void inorder_traversal(bst *t, int index) {
    if (index >= t->size || t->a[index] == INT_MIN) return;
    inorder_traversal(t, 2 * index + 1); // Left
    printf("%d ", t->a[index]);          // Root
    inorder_traversal(t, 2 * index + 2); // Right
}

// Preorder Traversal
void preorder_traversal(bst *t, int index) {
    if (index >= t->size || t->a[index] == INT_MIN) return;
    printf("%d ", t->a[index]);          // Root
    preorder_traversal(t, 2 * index + 1); // Left
    preorder_traversal(t, 2 * index + 2); // Right
}

// Postorder Traversal
void postorder_traversal(bst *t, int index) {
    if (index >= t->size || t->a[index] == INT_MIN) return;
    postorder_traversal(t, 2 * index + 1); // Left
    postorder_traversal(t, 2 * index + 2); // Right
    printf("%d ", t->a[index]);          // Root
}

int main(){
	bst tree;
    int size = 15; // Set size for the array
    init_bst(&tree, size);
    
    insert(&tree, 10);
    insert(&tree, 5);
    insert(&tree, 15);
    insert(&tree, 3);
    insert(&tree, 7);
    insert(&tree, 12);
    insert(&tree, 18);
    
    printf("Inorder Traversal: ");
    inorder_traversal(&tree, 0);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder_traversal(&tree, 0);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder_traversal(&tree, 0);
    printf("\n");

    // Free the allocated memory
    free(tree.a);
	return 0;
}