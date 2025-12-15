#include <stdio.h>
#include <stdlib.h>

typedef struct array{
    int size;
    int len;
    int *A;
} array;

void init(array *arr, int size){
    arr -> size = size;
    arr -> len = 0;
    arr -> A = (int *)malloc(sizeof(int) * size);
}

void append(array *arr, int value){
    if(arr -> len < arr -> size){
        arr -> A[arr -> len++] = value;
    }else{
        return;
    }
}

void display(array arr){
    for(int i = 0; i < arr.len; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
    return;
}

void insertAtIndex(array *arr, int value, int index){
    if(arr -> len >= arr -> size){
        printf("Array is Full\n");
    }else if(index < 0 || index > arr -> len){
        printf("Invalid  Index\n");
    }else{
        for(int i = arr -> len; i > index; i--){
            arr -> A[i] = arr -> A[i-1];
        }
        arr -> A[index] = value;
        arr -> len++;
        printf("Element %d inserted at index %d\n",value, index);
    }
}

void removeAtIndex(array *arr, int index){
    if(index < 0 || index >= arr -> len){       // if len is 9 and index is also 9 but there is no element at index 9 last element is at index 8
        printf("Invalid  Index\n");
    }else{
        for(int i = index; i < arr -> len - 1; i++){
            arr -> A[i] = arr -> A[i+1]; 
        }
        arr -> len--;
        printf("Element removed from index %d\n", index);        
    }
}

int maxelement(array arr){
    int max = arr.A[0];
    for(int i = 0; i < arr.len; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

int minelement(array arr){
    int min = arr.A[0];
    for(int i = 0; i < arr.len; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

int main(){
    array arr;
    int pos, key;
    init(&arr, 10);
    append(&arr, 5);
    append(&arr, 10);
    append(&arr, 15);
    append(&arr, 20);
    append(&arr, 25);
    append(&arr, 30);
    append(&arr, 35);
    append(&arr, 40);
    append(&arr, 45);
    display(arr);
    printf("Lenght of Array is : %d\n", arr.len);
    insertAtIndex(&arr, -55, 9);
    insertAtIndex(&arr, 6, 2);
    display(arr);
    removeAtIndex(&arr, 0);
    display(arr);
    printf("Max element is %d\n", maxelement(arr));
    printf("Min element is %d\n", minelement(arr));
    return 0;
}