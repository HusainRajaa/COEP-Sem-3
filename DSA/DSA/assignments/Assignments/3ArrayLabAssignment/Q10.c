#include <stdio.h>
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
int main(){
    int mn;
    printf("Enter Month Number : ");
    scanf("%d", &mn);
    int days = NumberOfDaysInMonth(mn);
    printf("Number of Days in month no %d are : %d", mn, days);
    return 0;
}