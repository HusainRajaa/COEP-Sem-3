#include <stdio.h>
#include <stdlib.h>
void GenerateArray(int arr[]){
    int i, n;
    for (i = 1; i < 1000; i++) {
        n = rand() % (1000 - 1 + 1) + 1;
        arr[i] = n;
    }
}
int NewArray(int arr[] , int newarr[]){
    int size = 0;
    for(int i = 0 ; i < 1000 ; i++){
        if((arr[i] % 8 == 0) || (arr[i] % 15 == 0)){
            newarr[size] = arr[i];
            size++;
        }
    }
    return size;
}
int main(){
    int arr[1000];
    int newarr[1000];
    GenerateArray(arr);
    for (int i = 0; i < 1000; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int size = NewArray(arr , newarr);
    for (int i = 0 ; i < size ; i++){
        printf("%d ", newarr[i]);
    }
    return 0;
}