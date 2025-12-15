#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "heap.h"

int main()
{
    Heap heap;
    init_heap(&heap, 1000);

    void heapSort(Heap *heap)
    {
        int *arr = heap->arr;
        int n = heap->rear+1;
        for (int i = n ; i >= 0; i--) {
          remove_heap(heap);
        }
    }

    FILE *filePtr;
    filePtr = fopen("random.txt", "w");
    for (int i = 0; i < 1000; i++)
    {
        fprintf(filePtr, "%d\n", rand() % 1001);
    }
    fclose(filePtr);

    FILE *filePtr1;
    filePtr1 = fopen("random.txt", "r");

    if (NULL == filePtr1)
    {
        printf("file can't be opened \n");
    }
    char ch = '$';
    int n = 0;
    while (ch != EOF)
    {

        ch = fgetc(filePtr1);
        if (ch == '\n')
        {
            insert_heap(&heap, n);
            n = 0;
        }
        else
        {
            n = n * 10 + (ch - 48);
        }
    }

    printHeap(heap);
    printf("\n");
    printf("Sorted Heap\n");
    heapSort(&heap);
    printHeap(heap);

}
