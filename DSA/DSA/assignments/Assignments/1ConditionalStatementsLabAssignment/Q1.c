#include <stdio.h>
#define size 10

int SumOfSquares(int arr[]){
    int i , sum = 0;
    for(i = 0 ; i < size ; i++){
        sum += (arr[i]*arr[i]);
    }
    return sum;
}


int main(){

    // Q1
    int arr[size];
    int i , answer;
    for(i = 0 ; i < size ; i++){
        scanf("%d",&arr[i]);
    }
    for(i = 0 ; i < size ; i++){
        printf("%d ",arr[i]);
    }
    answer = SumOfSquares(arr);
    printf("\n");
    printf("%d",answer);

    /*
        while (scanf("%d", &num) != EOF && size < MAX_SIZE) {
        array[size] = num;
        size++;
    }
    */

    return 0;
}
