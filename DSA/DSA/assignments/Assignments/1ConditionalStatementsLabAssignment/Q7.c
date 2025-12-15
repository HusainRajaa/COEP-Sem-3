#include <stdio.h>
void DeleteDuplicate(int arr[] , int size){
    for(int i = 0 ; i < size ; i++){
        for(int j = i+1 ; j < size ; j++){
            if(arr[i] == arr[j]){
                for(int k = j ; k < size - 1 ; k++){
                    arr[k] = arr[k+1];
                }
                size--;
                j--;
            }
        }
    }
    for(int i = 0 ; i < size ; i++){
        printf("%d " , arr[i]);
    }
}
int main(){
    int arr[] = {40 , 50 , 50 , 50 , 60 , 70 , 80 , 90 , 60 , 100 , 10};
    int size = sizeof(arr)/sizeof(int);
    DeleteDuplicate(arr , size);
    
    return 0;
}