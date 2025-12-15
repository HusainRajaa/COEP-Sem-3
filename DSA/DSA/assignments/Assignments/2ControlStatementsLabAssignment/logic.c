#include "header.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

void ThreeNumbersInLine(int n){
    int numbers[n];
    printf("Enter %d Numbers : \n", n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&numbers[i]);
    }
    for(int i = 0 ; i < n ; i++){
        if(i % 3 == 2){
            printf("%d", numbers[i]);
            printf("\n");
        }
        else{
            printf("%d, ", numbers[i]);
        }
    }
}

void EvenNumbersCount(int min , int max){
    int count = 0;
    int sum = 0;
    for(int i = min ; i <= max ; i++){
        if(i % 2 == 0){
            count++;
            sum += i;
        }
    }
    printf("Even Numbers between %d to %d are %d and their sum is : %d", min, max, count, sum);
}

void NumberOfVowels(char str[] , int size){
    int count = 0;
    for(int i = 0 ;  str[i] != '\0' ; i++){
        if((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u') || (str[i] == 'A') || (str[i] == 'E') || (str[i] == 'I') || (str[i] == 'O') || (str[i] == 'U')){
            count++;
        }
    }
    printf("Number of Vowels are %d", count);
}

int AddTwoFloat(float a , float b){
    float sum = a + b;
    int s = (int)sum;
    return s;
}

int RightMost(float a){
    int s = (int)a;
    int r = s % 10;
    return r;
}

float SimpleInterest(float p , float r , float t){
    float si = (p * r * t)/100;
    return si;
}

float CompoundInterest(float p , float r , float t){
    float ci = p * pow((1 + r / 100) , t) - p;
    return ci;
}
void bill(){
    Item items[MAX_ITEMS];
    int n;
    float totalAmount = 0.0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_ITEMS) {
        printf("Invalid number of items.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for item %d:\n", i + 1);
        printf("Item name: ");
        scanf(" %[^\n]", items[i].name);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Price per unit: ");
        scanf("%f", &items[i].pricePerUnit);
    }

    printf("\n************************** B I L L **************************\n");
    printf("ITEM\t\tQUANTITY\tPRICE\t\tAMOUNT\n");
    printf("_____________________________________________________________\n");

    for (int i = 0; i < n; i++) {
        float amount = items[i].quantity * items[i].pricePerUnit;
        printf("%-15s\t%d\t\t%.2f\t\t%.2f\n", items[i].name, items[i].quantity, items[i].pricePerUnit, amount);
        totalAmount += amount;
    }

    printf("-------------------------------------------------------------\n");
    printf("Total Amount: %.2f\n", totalAmount);
    printf("-------------------------------------------------------------\n");
}

void Armstrong(int n){
    int original, power, lastdigit, sum = 0, count = 0;
    original = n;
    while(n != 0){
        n = n / 10;
        count++;
    }
    n = original;

    while(n != 0){
        lastdigit = n % 10;
        power = 1;
        for(int i = 0 ; i < count ; i++){
            power *= lastdigit;
        }
        sum = sum + power;
        n = n / 10;
    }
    if(sum == original){
        printf("The Number %d is an Armstrong Number\n", original);
    }
    else{
        printf("The Number %d is not an Armstrong Number\n", original);
    }
}


void bill2(){
    Item1 item[MAX_ITEMS];
    int n , shipping;
    float Amount , totalAmount , ShippingAmount;
    printf("Enter the number of items : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the item : ");
        scanf("%s", item[i].name);
        printf("Enter the price : ");
        scanf("%f",&item[i].price);
        Amount += item[i].price; 
    }
    printf("Overnight delivery (Enter 0 for no and 1 for yes): ");
    scanf("%d",&shipping);

    if(Amount > 100 && shipping == 1){
        ShippingAmount = 80;
        totalAmount = Amount + 80;
    }
    else if(Amount > 100 && shipping == 0){
        ShippingAmount = 30;
        totalAmount = Amount + 30;
    }
    else if(Amount < 100 && shipping == 1){
        ShippingAmount = 70;
        totalAmount = Amount + 70;
    }
    else{
        ShippingAmount = 20;
        totalAmount = Amount + 20;
    }
    printf(":Invoice\n");
    for(int i = 0 ; i < n ; i++){
        printf("%-15s ",item[i].name);
        printf("Rs. %f \n",item[i].price);
    }
    printf("Shipping Rs. %.2f\n",ShippingAmount);
    printf("Total Amount Rs. %f", totalAmount);
}
