#include <stdio.h>

int ThreeNumbersInLine(int n){
    int numbers[n];
    printf("Enter %d Numbers : \n", n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&numbers[i]);
    }
    for(int i = 0 ; i < n ; i++){
        if(i % 3 == 2){
            printf("%d", numbers[i]);
            printf("\n");
        }
        else{
            printf("%d, ", numbers[i]);
        }
    }
    return 0;
}
int main(){
    ThreeNumbersInLine(10);
    return 0;
}