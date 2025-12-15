#include "header.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
// Q1
int SumOfSquares(int arr[], int size){
    int i , sum = 0;
    for(i = 0 ; i < size ; i++){
        sum += (arr[i]*arr[i]);
    }
    return sum;
}
// Q2
void ReverseOfArray(int arr[] , int size){
    int i;
    for(i = size-1 ; i >= 0 ; i--){
        printf("%d ",arr[i]);
    }
    return;
}
// Q3
int FindingElement(float arr[] , int size , float target){
    int i;
    for(i = 0 ; i < size ; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return 0;
}
// Q4
void TriangularPattern(int arr[] , int size){
    int i,j;
    for(i = 0 ; i < size ; i++){
        for(j = 0 ; j <= i ; j++){
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
}
// Q5
int NumberOfElements(int size){
    int number = size/sizeof(int);
    return number;
}
// Q6
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

// Q7
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

// Q8
void RandomNoGenerator(int min , int max , int no){
    int c, n;
    for (c = 1; c <= no; c++) {
        n = rand() % (max - min + 1) + min;
        printf("%d\n", n);
    }
}

// Q9
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

// Q10

void Palindrome(int arr[] , int size){
    int flag = 0;
    for(int i = 0, j = size - 1; i < size/2; i++ , j--){
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

// Q11
void ReverseArray(int arr[] , int size){
    int i,j;
    for(i = 0 , j = size - 1 ; i < j ; i++ , j--){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Q12
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
    int greater = target;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] > target){
            greater = arr[i];
        }
    }
    return greater;
}

// Q13  
void SortMixArray(int A[] , int B[] , int C[] ){
    int i,j = 0 ,k = 0;
    for(i = 0 ; i < 10 ; i++){
        if(j < 5 && (k >= 5 || A[j] <= B[k])){
            C[i] = A[j];
            j++;
        }
        else{
            C[i] = B[k];
            k++;
        }
    }
}

// Q14
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

// Q15
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