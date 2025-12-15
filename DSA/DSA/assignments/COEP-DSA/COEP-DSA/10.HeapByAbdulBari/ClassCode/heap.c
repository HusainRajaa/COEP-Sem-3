#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"heap.h"

void init_heap(heap *h1, int k){   //Initializes heap with given size
    h1->h=(int *)malloc(sizeof(int) * k);
    h1->rear=-1;
    h1->size=k;
    return;
}

int parent(int index){        //Returns Parent index.
    return ((index-1)/2);
}


void swaph(heap *h1, int a, int b){  //Swaps elements of heap having index as a and b.
    if(a>=h1->size || b >=h1->size)
        return;
    else{
        int k=h1->h[a];
        h1->h[a]=h1->h[b];
        h1->h[b]=k;
        return;
    }
    return;
}
void insert_heap(heap *h1, int k){
    if(h1->rear == h1->size-1)
        return;
    // h1->rear++;
    h1->h[++h1->rear]=k;
    int i = h1 -> rear;
    while(i > 0 && h1->h[i] > h1->h[parent(i)]){
        swaph(h1, i, parent(i));
        i=parent(i);
    }
    return;
}
void print_heap(heap h1){             //Displays heap elements.
    for(int i=0; i<=h1.rear; i++){
        printf("%d\t", h1.h[i]);
        
    }
    printf("\n");
    return;
}
// void heapify(heap *h1){          //Heapify using Top down approch converts array into max heap.
//     if(h1->rear==0 || h1->rear==-1)
//         return;
//     int j=0;
//     while(j <=(h1->rear)){
//         int lchild=2*j+1;
//         int rchild=2*j+2;
        
//         if(lchild > h1->rear)
//             return;
//         if(rchild > h1->rear){
//             if(h1->h[j] < h1->h[lchild]){
//                 swaph(h1, j, lchild);
//             }
//             return;
//         }
//         if((h1->h[j] > h1->h[lchild]) && (h1->h[j] > h1->h[rchild]))
//             return;

//         if(h1->h[lchild] > h1->h[rchild]){
//             swaph(h1, j, lchild);
//             j=lchild;
//         }
//         else{
//             swaph(h1, j, rchild);
//             j=rchild;
//         }
//     }
// }

void heapify(heap *h1, int i) {
    int largest = i;             // Assume the root is the largest
    int left = 2 * i + 1;        // Left child
    int right = 2 * i + 2;       // Right child

    // Check if the left child is larger
    if (left <= h1->rear && h1->h[left] > h1->h[largest]) {
        largest = left;
    }

    // Check if the right child is larger
    if (right <= h1->rear && h1->h[right] > h1->h[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and continue heapifying
    if (largest != i) {
        swaph(h1, i, largest);
        heapify(h1, largest);
    }
}


// void build_max_heap(heap *h1) {
//     for (int i = (h1->rear - 1) / 2; i >= 0; i--) {
//         int j = i;
//         while (j * 2 + 1 <= h1->rear) { // While node has at least one child
//             int maxChild = j * 2 + 1; // Left child
//             if (maxChild + 1 <= h1->rear && h1->h[maxChild + 1] > h1->h[maxChild]) {
//                 maxChild++; // Choose the larger child
//             }
//             if (h1->h[j] >= h1->h[maxChild]) {
//                 break; // Heap property satisfied
//             }
//             swaph(h1, j, maxChild); // Swap and continue
//             j = maxChild;
//         }
//     }
// }

void delete_max(heap *h1) {
    // Check if the heap is empty
    if (h1->rear == -1) {
        printf("Heap is empty, no element to delete.\n");
        return;
    }

    // Replace root (maximum element) with the last element
    h1->h[0] = h1->h[h1->rear];
    
    // Reduce the heap size
    h1->rear--;

    // Heapify from the top (index 0) to restore the max heap property
    heapify(h1, 0);
    
    return;
}

void heap_sort(heap *h1){            //Heap Sort
    int k = h1->rear;
    if(h1 -> rear == -1)
        return;
    for(int i=h1->rear; i>0; i--){
        swaph(h1,i,0);
        h1->rear--;
        heapify(h1);
    }
    h1 -> rear = k;
    print_heap(*h1);
    return;
}

