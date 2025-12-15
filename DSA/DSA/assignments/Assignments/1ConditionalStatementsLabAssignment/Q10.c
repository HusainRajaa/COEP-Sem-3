#include <stdio.h>

void Palindrome(int arr[] , int size){
    int flag = 0;
    for(int i = 0 , j = size - 1; i < size/2 , j >= size/2 ; i++ , j--){
        if(arr[i] == arr[j]){
            flag = 0;
        }
        else{
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Palindrome");
    }
    else{
        printf("Not Palindrome");
    }
}
int main(){
    int arr[] = {3 , 6 , 0 , 6 , 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    Palindrome(arr , size);
    return 0;
}