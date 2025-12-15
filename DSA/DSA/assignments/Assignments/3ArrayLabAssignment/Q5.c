#include <stdio.h>
void LeapYearCheck(int year){
    if(year % 400 == 0){
        printf("The Year %d is a Leap Year", year);
    }
    else if(year % 4 == 0 && year % 100 != 0){
        printf("The Year %d is a Leap Year", year);
    }
    else{
        printf("The Year %d is not aLeap Year", year);
    }
}
int main(){
    int year;
    printf("Enter year : ");
    scanf("%d", &year);
    LeapYearCheck(year);
    return 0;
}