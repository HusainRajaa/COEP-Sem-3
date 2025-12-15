#include <stdio.h>
void NoOfPosNumbers(int arr[] , int size){
    int count = 0;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] > 0){
            count++;
        }
    }  
    printf("Number of positive integers in the array is %d\n",count);
}
void NoOfNegNumbers(int arr[] , int size){
    int count = 0;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] < 0){
            count++;
        }
    }  
    printf("Number of negative integers in the array is %d\n",count);
}
void NoOfOddNumbers(int arr[] , int size){
    int count = 0;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] % 2 != 0){
            count++;
        }
    }
    printf("Number of odd integers in the array is %d\n",count);
}
void NoOfEvenNumbers(int arr[] , int size){
    int count = 0;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] % 2 == 0){
            count++;
        }
    }
    printf("Number of even integers in the array is %d\n",count);
}
void NoOfZeroes(int arr[] , int size){
    int count = 0;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == 0){
            count++;
        }
    }
    printf("Number of zeroes in the array is %d\n",count);
}
int main(){
    int arr[20];
    int size = 20;
    for(int i = 0 ; i < 20 ; i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0 ; i < 20 ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    NoOfPosNumbers(arr , size);
    NoOfNegNumbers(arr , size);
    NoOfOddNumbers(arr , size);
    NoOfEvenNumbers(arr, size);
    NoOfZeroes(arr , size);
    return 0;
}