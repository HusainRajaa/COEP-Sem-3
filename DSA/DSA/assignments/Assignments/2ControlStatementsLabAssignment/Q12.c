#include <stdio.h>
int main(){
    float a,b,c;
    float result;
    printf("Enter three floating point numbers: ");
    scanf("%f%f%f", &a, &b, &c);
    result = a + b + c;
    printf("Their sum is %.2f",result);
    return 0;
}