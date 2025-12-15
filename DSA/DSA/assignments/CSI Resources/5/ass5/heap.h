typedef struct
{
    int *arr;
    int size;
    int rear;
} Heap;

void init_heap(Heap *heap, int size);
void insert_heap(Heap *heap, int val);
void printHeap(Heap heap);
void remove_heap(Heap *heap);
