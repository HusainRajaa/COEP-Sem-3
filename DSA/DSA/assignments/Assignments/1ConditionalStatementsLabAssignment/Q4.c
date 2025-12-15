#include<stdio.h>
void TriangularPattern(int arr[] , int size){
    int i,j;
    for(i = 0 ; i < size ; i++){
        for(j = 0 ; j <= i ; j++){
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
}
int main(){
    int A[] = {60 , 700 , 80 , 900 , 10};
    int size = sizeof(A)/sizeof(A[0]);
    TriangularPattern(A , size);
    return 0;
}