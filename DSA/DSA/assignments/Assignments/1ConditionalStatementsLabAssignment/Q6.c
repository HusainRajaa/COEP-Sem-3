#include <stdio.h>
void RightShift(int arr[] , int size, int n){
    for(int i = 1 ; i <= n ; i++){
        int temp = arr[size-1];
        for(int j = size-1 ; j >= 0 ; j-- ){
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}
void LeftShift(int arr[] , int size , int n){
    for(int i = 1 ; i <= n ; i++){
        int temp = arr[0];
        for(int j = 0 ; j < size - 1 ; j++){
            arr[j] = arr[j + 1];
        }
        arr[size-1] = temp;
    }
}
int main(){
    int arr[] = {70 , 80 , 90 , 100 , 110};
    int size = sizeof(arr)/sizeof(int);
    int n;
    scanf("%d",&n);
    // int ch;
    // scanf("%c",&ch);
    // RightShift(arr , size , n);
    // for(int i = 0 ; i < size ; i++){
    //     printf("%d ",arr[i]);
    // }
    printf("\n");
    LeftShift(arr , size , n);
    for(int i = 0 ; i < size ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}