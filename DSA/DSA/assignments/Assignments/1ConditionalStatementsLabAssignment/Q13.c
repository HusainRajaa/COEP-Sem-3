#include <stdio.h>
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
int main(){ 
    int A[] = { 45, 50, 70, 85, 90};
    int B[] = { 30, 40, 60, 75, 80};
    int C[10];
    SortMixArray(A , B , C);
    for(int i = 0 ; i < 10 ; i++){
        printf("%d ",C[i]);
    }
    return 0;
}