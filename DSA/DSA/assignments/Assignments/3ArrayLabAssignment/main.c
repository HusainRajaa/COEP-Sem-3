#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(){
    int question;
    printf("Enter Question Numnber: ");
    scanf("%d", &question);
    getchar();
    switch(question){
        case 1:{
            float a, b;
            printf("Enter Two Numbers : ");
            scanf("%f%f", &a, &b);
            float max = MaxBetweenTwo(a , b);
            printf("Maximum Between %f and %f is : %f", a, b, max);
            break;
        }
        case 2:{
            float a;
            printf("Enter the Number : ");
            scanf("%f",&a);
            Check(a);
            break;
        }
        case 3:{
            int a;
            printf("Enter Number : ");
            scanf("%d", &a);
            CheckDivisibleBy5And11(a);
            break;
        }
        case 4:{
            int a;
            printf("Enter Number : ");
            scanf("%d", &a);
            EvenOdd(a);
            break;
        }
        case 5:{
            int year;
            printf("Enter year : ");
            scanf("%d", &year);
            isLeapYear(year);
            break;
        }
        case 6:{
            char ch;
            printf("Enter a Character : ");
            scanf("%c", &ch);
            AlphabetCheck(ch);
            break;
        }
        case 7:{
            char ch;
            printf("Enter a Character : ");
            scanf("%c", &ch);
            VowelConsonant(ch);
            break;
        }
        case 8:{
            char ch;
            printf("Enter a Character : ");
            scanf("%c", &ch);
            AlphabetDigitSpecialChar(ch);
            break;
        }
        case 9:{
            char ch;
            printf("Enter a Character : ");
            scanf("%c", &ch);
            UppercaseLowercase(ch);
            break;
        }
        case 10:{
            int mn;
            printf("Enter Month Number : ");
            scanf("%d", &mn);
            int days = NumberOfDaysInMonth(mn);
            printf("Number of Days in month no %d are : %d", mn, days);
            break;
        }
        case 11:{
            float a , b , c;
            printf("Enter Angles of Triangle : ");
            scanf("%f%f%f", &a, &b, &c);
            AnglesOfTriangle(a, b, c);
            break;
        }
        case 12:{
            float a , b , c;
            printf("Enter Angles of Triangle : ");
            scanf("%f%f%f", &a, &b, &c);
            TypeOfTriangle(a, b, c);
            break;
        }
        case 13:{
            float a, b, c;
            printf("Enter Coefficients a, b, c of Quadratic Equation: ");
            scanf("%f%f%f", &a, &b, &c);
            RootsOfQuadratiEquation(a, b, c);
            break;
        }
        case 14:{
            float a, b, c, d, e;
            printf("Enter Marks of Five Subjects : ");
            scanf("%f%f%f%f%f", &a, &b, &c, &d, &e);
            char grade = Grade(a, b, c, d, e);
            printf("Your Grade is %c",grade);
            break;
        }
        case 15:{
            float basic_salary , gross_salary;
            printf("Enter Basic Salary : ");
            scanf("%f", &basic_salary);
            gross_salary = GrossSalary(basic_salary);
            printf("The gross salary of the employee is : %.2f\n", gross_salary);
            break;
        }
        case 16:{
            int units;
            float bill;
            printf("Enter Electricity Units : ");
            scanf("%d", &units);
            bill = ElectricityBill(units);
            printf("Total Electricity Bill is %f ", bill);
            break;
        }
        default:
            break;
    }
    return 0;
}