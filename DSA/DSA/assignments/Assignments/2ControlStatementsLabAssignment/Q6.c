#include <stdio.h>
#include <math.h>
float SimpleInterest(float p , float r , float t){
    float si = (p * r * t)/100;
    return si;
}
float CompoundInterest(float p , float r , float t){
    float ci = p * pow((1 + r / 100) , t) - p;
    return ci;
}
int main(){
    float principal, rate, time, simpleInterest, compoundInterest;
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the rate of interest (in percentage): ");
    scanf("%f", &rate);
    printf("Enter the time period (in years): ");
    scanf("%f", &time);
    printf("Simple Interest = %.2f\n", SimpleInterest(principal , rate , time));
    printf("Compound Interest = %.2f\n", CompoundInterest(principal , rate , time));
    return 0;
}