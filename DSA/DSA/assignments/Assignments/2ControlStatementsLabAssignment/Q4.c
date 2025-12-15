#include <stdio.h>
int AddTwoFloat(float a , float b){
    float sum = a + b;
    int s = (int)sum;
    return s;
}
int main(){
    float a , b;
    scanf("%f%f", &a, &b);
    int sum = AddTwoFloat(a, b);
    printf("Sum of %f and %f converted to int is %d", a, b, sum);
    return 0;
}