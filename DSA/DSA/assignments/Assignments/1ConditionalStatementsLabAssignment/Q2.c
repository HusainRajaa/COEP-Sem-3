#include <stdio.h>
#define size 10

void ReverseOfArray(int arr[]){
    int i;
    for(i = size-1 ; i >= 0 ; i--){
        printf("%d ",arr[i]);
    }
    return;
}

int main(){
    //Q2
    int arr[size];
    int i;
    for(i = 0 ; i < size ; i++){
        scanf("%d",&arr[i]);
    }
    ReverseOfArray(arr);
}