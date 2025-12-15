#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;

    if (largest != i)
    {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }

}

void heapify_insert(int arr[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] > 0)
    {
        if (arr[i] > arr[parent])
        {
            swap(&arr[i], &arr[parent]);
            heapify_insert(arr, n, parent);
        }
    }
}

void init_heap(Heap *heap, int size)
{
    heap->size = size;
    heap->rear = -1;
    heap->arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        heap->arr[i] = INT_MIN;
    }
}

void printHeap(Heap heap)
{
    int i = 0;
    while (i <= heap.size)
    {
    	if(heap.arr[i] != INT_MIN)
        {
        	printf("%d\n", heap.arr[i]);
        	i++;
        }
        else
        	i++;
    }
}

void insert_heap(Heap *heap, int val)
{
    if (heap->rear == heap->size)
    {
        printf("heap is full");
        return;
    }
    heap->arr[++heap->rear] = val;
    heapify_insert(heap->arr, heap->rear, heap->rear-1);
}

void remove_heap(Heap *heap)
{
    swap(&heap->arr[0], &heap->arr[heap->rear+1]);
    heap->rear--;
    heapify(heap->arr, heap->rear+2, 0);
    return;
}
