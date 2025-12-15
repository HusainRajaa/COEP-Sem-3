#include <stdio.h>
float GrossSalary(float basic_salary){
    float gross_salary, hra, da;
    if(basic_salary <= 10000){
        hra = (0.20) * basic_salary;
        da = (0.80) * basic_salary;
    }
    else if(basic_salary <= 20000){
        hra = (0.25) * basic_salary;
        da = (0.90) * basic_salary;
    }
    else {
        hra = (0.30) * basic_salary;
        da = (0.95) * basic_salary;
    }
    gross_salary = basic_salary + hra + da;
    return gross_salary;
}
int main(){
    float basic_salary , gross_salary;
    printf("Enter Basic Salary : ");
    scanf("%f", &basic_salary);
    gross_salary = GrossSalary(basic_salary);
    printf("The gross salary of the employee is : %.2f\n", gross_salary);
    return 0;
}