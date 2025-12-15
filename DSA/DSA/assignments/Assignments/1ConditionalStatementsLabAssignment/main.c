#include "header.h"
#include <stdio.h>

int main(){
    int questionNumber;
    printf("Enter Question Number ( 1 - 15 ):");
    scanf("%d",&questionNumber);
    switch (questionNumber)
    {
    case 1: {
        // Q1
        int size = 10;
        int arr1[size];
        int i, answer;
        printf("Enter %d numbers:\n", size);
        for(i = 0 ; i < size ; i++){
            scanf("%d",&arr1[i]);
        }printf("Given numbers are : \n");

        for(i = 0 ; i < size ; i++){
            printf("%d ",arr1[i]);
        }
        answer = SumOfSquares(arr1 , size);
        printf("\n");
        printf("The Sum of Squares of given %d numbers is %d\n",size ,answer);
        break;
    }
    case 2: {
        // Q2
        int size = 10;
        int arr2[size];
        printf("Enter %d numbers:\n", size);
        for(int i = 0 ; i < size ; i++){
            scanf("%d",&arr2[i]);
        }
        printf("Reverse of Given Array of Integers is : \n");
        ReverseOfArray(arr2 , size);
        printf("\n");
        break;
    }
    case 3: {
        // Q3
        int size = 50;
        float arr3[size];
        float target;
        printf("Enter %d numbers:\n", size);
        for(int i = 0 ; i < 50 ; i++){
            scanf("%f",&arr3[i]);
        }
        printf("Enter Target\n");
        scanf("%f",&target);
        int answer = FindingElement(arr3 , size , target);
        if(answer != 0){
            printf("Index of Given Target Number is %d\n",answer);
        }
        else{
            printf("Not Found\n");
        }
        break;
    }
    case 4: {
        // Q4
        int arr4[] = {60 , 700 , 80 , 900 , 10};
        int size = sizeof(arr4)/sizeof(arr4[0]);
        TriangularPattern(arr4 , size);
        break;
    }
    case 5: {
        // Q5
        int size;
        printf("Enter size of integer array in bytes : ");
        scanf("%d",&size);
        printf("Number of Elements in arrya is %d",NumberOfElements(size));
        break;
    }
    case 6: {
        // Q6
        int arr5[] = {70 , 80 , 90 , 100 , 110};
        printf("Original Array: ");
        for(int i = 0; i < 5; i++){
            printf("%d ",arr5[i]);
        }
        printf("\n");
        int size = sizeof(arr5)/sizeof(arr5[0]);
        int n;
        printf("Enter no of rotations : ");
        scanf("%d",&n);
        RightShift(arr5 , size , n);
        printf("Right Shift with %d rotations : ",n);
        for(int i = 0 ; i < size ; i++){
            printf("%d ",arr5[i]);
        }
        int arr6[] = {70 , 80 , 90 , 100 , 110};
        printf("\n");
        LeftShift(arr6 , size , n);
        printf("Left Shift with %d rotations : ",n);
        for(int i = 0 ; i < size ; i++){
            printf("%d ",arr6[i]);
        }
        printf("\n");
        break;
    }
    case 7: {
        // Q7
        int arr7[] = {40 , 50 , 50 , 50 , 60 , 70 , 80 , 90 , 60 , 100 , 10};
        printf("Original Array: ");
        for(int i = 0; i < 11; i++){
            printf("%d ",arr7[i]);
        }
        printf("\n");
        int size = sizeof(arr7)/sizeof(int);
        printf("Array after Deleting Duplicate Elements : ");
        DeleteDuplicate(arr7 , size);
        break;
    }
    case 8: {
        // Q8
        printf("Ten random numbers in [1,100]\n");
        RandomNoGenerator(1 , 100 , 10);
        break;
    }
    case 9: {
    
        // Q9
        int arr9[20];
        int size = 20;
        printf("Enter %d numbers:\n", size);
        for(int i = 0 ; i < 20 ; i++){
            scanf("%d",&arr9[i]);
        }
        printf("Given Numbers are : \n");
        for(int i = 0 ; i < 20 ; i++){
            printf("%d ",arr9[i]);
        }
        printf("\n");
        NoOfPosNumbers(arr9 , size);
        NoOfNegNumbers(arr9 , size);
        NoOfOddNumbers(arr9 , size);
        NoOfEvenNumbers(arr9, size);
        NoOfZeroes(arr9 , size);
        break;
    }
    case 10: {
        // Q10
        int arr10[] = {3 , 6 , 0 , 6 , 3};
        int size = sizeof(arr10)/sizeof(arr10[0]);
        printf("Given Numbers are : \n");
        for(int i = 0 ; i < size ; i++){
            printf("%d ",arr10[i]);
        }
        printf("\n");
        Palindrome(arr10 , size);
        break;
    }
    case 11: {
        // Q11
        int arr11[] = {10, 45 , 32 , 16 , 88};
        printf("Original Array: ");
        for(int i = 0; i < 5; i++){
            printf("%d ",arr11[i]);
        }
        printf("\n");
        int size = sizeof(arr11)/sizeof(arr11[0]);
        ReverseArray(arr11 , size);
        printf("Reverse of Given Array is : ");
        for(int i = 0 ; i < size ; i++){
            printf("%d ",arr11[i]);
        }
        break;
    }
    case 12: {
        // Q12
        int arr12[] = {1 , 2 , 3 , 4 , 5 , 6 , 11 , 8 , 12 , 10};
        printf("Original Array: ");
        for(int i = 0; i < 10; i++){
            printf("%d ",arr12[i]);
        }
        printf("\n");
        int size = sizeof(arr12)/sizeof(arr12[0]);
        int target;
        printf("Enter Target Number : \n");
        scanf("%d",&target);
        printf("Nearest Lesser : %d\n",NearestLesser(arr12 , size , target));
        printf("Nearest Greater : %d\n",NearestGreater(arr12 , size , target));
        break;
    }
    case 13: {
        // Q13
        int A[] = { 45, 50, 70, 85, 90};
        int B[] = { 30, 40, 60, 75, 80};
        int C[10];
        SortMixArray(A , B , C);
        printf("Sorted Mixed Array is : \n");
        for(int i = 0 ; i < 10 ; i++){
            printf("%d ",C[i]);
        }   
        break;
    }
    case 14: {
    
        // Q14
        int arr14[1000];
        int newarr[1000];
        GenerateArray(arr14);
        printf("Random Generated Array is : ");
        for (int i = 0; i < 1000; i++) {
            printf("%d ", arr14[i]);
        }
        printf("\n");
        printf("Numbers which are divisible by 8 or 25 in the array are : \n");
        int size = NewArray(arr14 , newarr);
        for (int i = 0 ; i < size ; i++){
            printf("%d ", newarr[i]);
        }
        break;
    }
    case 15: {
        // Q15
        int arr15[] = {1 , 2 , 3 , 4 , 5 , 6 , 7};
        printf("Original Array: ");
        for(int i = 0; i < 7; i++){
            printf("%d ",arr15[i]);
        }
        printf("\n");
        int size = sizeof(arr15)/sizeof(arr15[0]);
        int secondLargest = SecondLargest(arr15 , size);
        printf("Second Largest Element in the Given Array is : %d",secondLargest);
        break;
    }
    default:
        break;
    }
    return 0;
}