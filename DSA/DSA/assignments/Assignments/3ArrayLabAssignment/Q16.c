#include <stdio.h>
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
int main(){
    int units;
    float bill;
    printf("Enter Electricity Units : ");
    scanf("%d", &units);
    bill = ElectricityBill(units);
    printf("Total Electricity Bill is %f ", bill);
    return 0;
}