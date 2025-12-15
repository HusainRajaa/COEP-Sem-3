#include <stdio.h>
#include <limits.h>
int NearestLesser(int arr[] , int size , int target){
    int lesser = INT_MIN;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] < target && arr[i] > lesser){
            lesser = arr[i];
        }
    }
    return lesser;
}

int NearestGreater(int arr[] , int size , int target){
    int greater = INT_MAX;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] > target && arr[i] < greater){
            greater = arr[i];
        }
    }
    return greater;
}
int main(){
    int arr[] = {1 , 2 , 3 , 4 , 5 , 6 , 11 , 8 , 12 , 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 8;
    printf("Nearest Lesser : %d\n",NearestLesser(arr , size , target));
    printf("Nearest Greater : %d\n",NearestGreater(arr , size , target));
    return 0;
}