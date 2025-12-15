#include <stdio.h>
void CheckDivisibleBy5And11(int a){
    if((a % 5 == 0) && (a % 11 == 0)){
        printf("The Number %d is divisible by both 5 and 11", a);
    }
    else{
        printf("The Number %d is not divisible by both 5 and 11", a);
    }
}
int main(){
    int a;
    printf("Enter Number : ");
    scanf("%d", &a);
    CheckDivisibleBy5And11(a);
    return 0;
}