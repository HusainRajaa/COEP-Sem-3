#include <stdio.h>
void ReverseArray(int arr[] , int size){
    int i,j;
    for(i = 0 , j = size - 1 ; i < j ; i++ , j--){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int main(){
    int arr[] = {10, 45 , 32 , 16 , 88};
    int size = sizeof(arr)/sizeof(arr[0]);
    ReverseArray(arr , size);
    for(int i = 0 ; i < size ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}