#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include <math.h>
#include <ctype.h>

float MaxBetweenTwo(float a , float b){
    if(a > b){
        return a;
    }
    else
        return b;
}

void Check(float a){
    if(a > 0){
        printf("The Number %f is Positive", a);
    }
    else if(a < 0){
        printf("The Number %f is Negative", a);
    }
    else{
        printf("The Number %f is Zero", a);
    }
}

void CheckDivisibleBy5And11(int a){
    if((a % 5 == 0) && (a % 11 == 0)){
        printf("The Number %d is divisible by both 5 and 11", a);
    }
    else{
        printf("The Number %d is not divisible by both 5 and 11", a);
    }
}

void EvenOdd(int a){
    if(a % 2 == 0){
        printf("The Number %d is Even",a);
    }
    else{
        printf("The Number %d is Odd",a);

    }
}


void isLeapYear(int year){
    if(year % 400 == 0){
        printf("The Year %d is a Leap Year", year);
    } 
    else if(year % 100 == 0){
        printf("The Year %d is not aLeap Year", year);
    }
    else if(year % 4 == 0){
        printf("The Year %d is a Leap Year", year);
    } 
    else{
        printf("The Year %d is not aLeap Year", year);
    }
}

void AlphabetCheck(char ch){
    int A = (int)ch;
    if((A >= 65 && A <= 90) || (A >= 97 && A <= 122)){
        printf("The Given Character %c is Alphabet", ch);
    }
    else{
        printf("The Given Character %c is not a Alphabet", ch);
    }
}

void VowelConsonant(char ch){
    char chr = tolower(ch);
    int a = (int)chr;
    if(a == 97 || a == 101 || a == 105 || a == 111 || a == 117){
        printf("The character %c is a vowel", ch);
    }
    else{
        printf("The character %c is a consonant", ch);
    }
}

void AlphabetDigitSpecialChar(char ch){
    int A = (int)ch;
    if((A >= 65 && A <= 90) || (A >= 97 && A <= 122)){
        printf("The Given Character %c is Alphabet", ch);
    }
    else if(A >= 48 && A <= 57){
        printf("The Given Character %c is Digit", ch);
    }
    else {
        printf("The Given Character %c is a Special Character", ch);
    }
}

void UppercaseLowercase(char ch){
    int A = (int)ch;
    if(A >= 65 && A <= 90){
        printf("The Character %c is Uppercase alphabet", ch);
    }
    else if(A >= 97 && A <= 122){
        printf("The Character %c is Lowercase alphabet", ch);
    }
    else{
        printf("The Character %c is not a alphabet", ch);
    }
}

int NumberOfDaysInMonth(int mn){
    int NoOfDays = 0;
    if(mn <= 0 || mn > 12){
        printf("Invalid Month Number ");
    }
    else if(mn == 1 || mn == 3 || mn == 5 || mn == 7 || mn == 8 || mn == 10 || mn == 12){
        NoOfDays = 31;
    }
    else if(mn == 2){
        NoOfDays = 28;
    }
    else {
        NoOfDays = 30;
    }
    return NoOfDays;
}

void AnglesOfTriangle(float a, float b, float c){
    if(a + b + c == 180){
        printf("The Triangle is Valid");
    }
    else{
        printf("The Triangle is Invalid");
    }
}

void TypeOfTriangle(float a, float b, float c){
    if(a + b + c == 180){
        if(a == b && b == c && a == c){
            printf("The Triangle is Equilateral");
        }
        else if((a == b && a != c) || (b == c && a != b) || (a == c && b != c)){
            printf("The Triangle is Isosceles");
        }
        else{
            printf("The Triangle is Scalene");
        }
    }
    else{
        printf("The Triangle is Invalid");
    }
}

void RootsOfQuadratiEquation(float a, float b, float c){
    float root1, root2, realPart, imaginaryPart;
    float discriminant = b * b - 4 * a * c;
    if(a == 0){
        printf("It is not a quadratic equation");
    }
    else if(discriminant > 0){
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots of the quadratic equation are real and different\n");
        printf("Root1 = %f\n", root1);
        printf("Root2 = %f", root2);

    }
    else if(discriminant == 0){
        root1 = root2 = -b / (2 * a);
        printf("Roots of the quadratic equation are real and same\n");
        printf("Root1 = Root2 = %f\n",root1);
    }
    else{
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots of the quadratic equation are complex and different\n");
        printf("Root1 = %.2f + %.2fi\n", realPart, imaginaryPart);
        printf("Root2 = %.2f + %.2fi\n", realPart, imaginaryPart);
    }
}

char Grade(float a , float b , float c, float d, float e){
    float percentage = (a + b + c + d + e)/5;
    printf("Your Percentage is %f\n", percentage);
    if(percentage >= 90){
        return 'A';
    }
    else if(percentage >= 80){
        return 'B';
    }
    else if(percentage >= 70){
        return 'C';
    }
    else if(percentage >= 60){
        return 'D';
    }
    else if(percentage >= 40){
        return 'E';
    }
    else{
        return 'F';
    }
}

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

float ElectricityBill(int units){
    float bill;
    if(units <= 50){
        bill = units * 0.50;
    }
    else if(units <= 150){
        bill = 50 * 0.5 + (units - 50) * 0.75;
    }
    else if(units <= 250){
        bill = 50 * 0.5 + 100 * 0.75 +(units - 150) * 1.20;
    }
    else if(units > 250){
        bill = 50 * 0.5 + 100 * 0.75 + 100 * 1.20 + (units - 250) * 1.50;
    }
    bill = bill + bill * 20 / 100;
    return bill;
}