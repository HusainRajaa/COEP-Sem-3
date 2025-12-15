#include <stdio.h>
#include "header.h"
#include <string.h>
#include <stdlib.h>

#define MAX_NUMBERS 1000

int main(){
    int question;
    printf("Enter Question Number: ");
    scanf("%d", &question);
    /*
        Clear the input buffer to handle the newline character after scanf("%d", &question)
    */
    getchar();
    switch(question){
        case 1:{
            student students[MAX_NUMBERS];
            int numStudents = 0;

            printf("Enter the number of students: ");
            scanf("%d", &numStudents);
            getchar(); 
            for (int i = 0; i < numStudents; i++) {
                printf("\nEnter details for student %d:\n", i + 1);

                printf("Roll Number: ");
                scanf("%d", &students[i].rollno);
                getchar(); 
                printf("First Name: ");
                scanf("%s", students[i].name.firstName);

                printf("Middle Name: ");
                scanf("%s", students[i].name.middleName);

                printf("Last Name: ");
                scanf("%s", students[i].name.lastName);

                printf("Gender: ");
                scanf("%s", students[i].gender);

                printf("Date of Birth (dd mm yyyy): ");
                scanf("%d %d %d", &students[i].dob.day, &students[i].dob.month, &students[i].dob.year);

                printf("Marks (Mathematics Science Computer Science): ");
                scanf("%d %d %d", &students[i].marks.maths, &students[i].marks.science, &students[i].marks.computerScience);
            }
            printf("\n");
            for (int i = 0; i < numStudents; i++) {
                float aggregatePercentage = calculateAggregatePercentage(&students[i]);
                if (aggregatePercentage < 40) {
                    printf("This student has less than 40%% aggregate and aggregate marks are %f:\n", aggregatePercentage);
                    displayStudent(&students[i]);
                }
                printf("\n");
            }
            break;
        }
        case 2:{
            hotel hotels[MAX_NUMBERS];
            int numHotels = 0;
            printf("Enter the number of hotels: ");
            scanf("%d", &numHotels);
            getchar();
            for (int i = 0; i < numHotels; i++) {
                printf("\nEnter details for hotel %d:\n", i + 1);
                printf("Hotel Name: ");
                scanf("%[^\n]s", hotels[i].name);
                getchar();
                printf("Address: ");
                scanf("%[^\n]s", hotels[i].address);
                printf("Grade: ");
                scanf("%d", &hotels[i].grade);
                printf("Number Of Rooms: ");
                scanf("%d", &hotels[i].number_of_rooms);
                printf("Room Charges: ");
                scanf("%d", &hotels[i].room_charges);
                getchar();
            }
            int g;
            printf("Enter the grade of which hotels you want:");
            scanf("%d", &g);
            for(int i = 0; i < numHotels; i++){
                hotelsInParticularGrade(&hotels[i], g);
            }
            int value;
            printf("Enter the value below which rooms in hotels you want:");
            scanf("%d", &value);
            for(int i = 0; i < numHotels; i++){
                hotelsOfParticularValue(&hotels[i], value);
            }
            break;
        }
        case 3:{
            time start_time, end_time;
            printf("Enter start time (hr min sec): ");
            scanf("%d %d %d", &start_time.hr, &start_time.min, &start_time.sec);
            printf("Enter end time (hr min sec): ");
            scanf("%d %d %d", &end_time.hr, &end_time.min, &end_time.sec);

            printf("\n");
            while (!(start_time.hr == end_time.hr && start_time.min == end_time.min && start_time.sec == end_time.sec)) {
                printf("GOOD DAY\n");
                increment_time(&start_time);
            }
            break;
        }
        case 4:{
            fraction f1, f2;
            printf("Enter numerator and denominator of the first fraction: ");
            scanf("%d %d", &f1.numerator, &f1.denominator);
            printf("Enter numerator and denominator of the second fraction: ");
            scanf("%d %d", &f2.numerator, &f2.denominator);
            int result = compareFractions(f1, f2);
            if (result == 0) {
                printf("The two fractions are equal.\n");
            } else if (result == -1) {
                printf("The first fraction is less than the second fraction.\n");
            } else {
                printf("The first fraction is greater than the second fraction.\n");
            }
            break;
        }
        case 5:{
            date d;
            printf("Enter the date (dd mm yyyy): ");
            scanf("%d %d %d", &d.day, &d.month, &d.year);
            if (validateDate(&d)) {
                printf("The date is: %d/%d/%d valid\n", d.day, d.month, d.year);
            } else {
                printf("Invalid date entered!\n");
            }
            break;
        }
        case 6:{
            time t1, t2;
            printf("Enter t1 (hr min sec): ");
            scanf("%d %d %d", &t1.hr, &t1.min, &t1.sec);
            printf("Enter t2 (hr min sec): ");
            scanf("%d %d %d", &t2.hr, &t2.min, &t2.sec);
            time sum = addTime(t1, t2);
            time difference = subtractTime(t1, t2);
            printf("Sum: %d:%d:%d\n", sum.hr, sum.min, sum.sec);
            printf("Difference: %d:%d:%d\n", difference.hr, difference.min, difference.sec);
            break;
        }
        default:
            break;
    }
    return 0;

}