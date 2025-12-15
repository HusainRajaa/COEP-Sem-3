#include <stdio.h>
#include <limits.h>
int SecondLargest(int arr[] , int size){
    int max = INT_MIN;
    int smax = INT_MIN;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] > max){
            smax = max;
            max = arr[i];
        }
        else if(smax < arr[i] && max != arr[i]){
            smax = arr[i];
        }
    }
    return smax;
}
int main(){
    int arr[] = {1 , 2 , 3 , 4 , 5 , 6 , 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int secondLargest = SecondLargest(arr , size);
    printf("%d",secondLargest);
    return 0;
}