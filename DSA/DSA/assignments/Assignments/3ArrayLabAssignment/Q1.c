#include <stdio.h>
float MaxBetweenTwo(float a , float b){
    if(a > b){
        return a;
    }
    else
        return b;
}
int main(){
    float a, b;
    printf("Enter Two Numbers : ");
    scanf("%f%f", &a, &b);
    float max = MaxBetweenTwo(a , b);
    printf("Maximum Between %f and %f is : %f", a, b, max);
}