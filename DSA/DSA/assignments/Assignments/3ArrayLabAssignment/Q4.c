#include <stdio.h>
void EvenOdd(int a){
    if(a % 2 == 0){
        printf("The Number %d is Even",a);
    }
    else{
        printf("The Number %d is Odd",a);

    }
}
int main(){
    int a;
    printf("Enter Number : ");
    scanf("%d", &a);
    EvenOdd(a);
    return 0;
}