#include <stdio.h>
int main(){
    const float HRA = 10 / 100;
    const float TA = 5 / 100;

    float base, salary;
    printf("Enter the basic salary : ");
    scanf("%f",&base);
    salary = base + (base * HRA) + (base * TA);
    printf("The salary of the employee is : %f",salary);
    return 0;
}