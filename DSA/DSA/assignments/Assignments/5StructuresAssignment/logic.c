#include <stdio.h>
#include "header.h"
#include <string.h>
#include <stdlib.h>

void displayStudent(const student *s){
    printf("Roll Number: %d\n", s->rollno);
    printf("Name: %s %s %s\n", s->name.firstName, s->name.middleName, s->name.lastName);
    printf("Gender: %s\n", s->gender);
    printf("Date of Birth: %02d/%02d/%04d\n", s->dob.day, s->dob.month, s->dob.year);
    printf("Marks:\n");
    printf("  Mathematics: %d\n", s->marks.maths);
    printf("  Science: %d\n", s->marks.science);
    printf("  Computer Science: %d\n", s->marks.computerScience);
}


float calculateAverage(const student *s){
    return (s->marks.maths + s->marks.science + s->marks.computerScience) / 3.0;
}

float calculateAggregatePercentage(const student *s){
    int totalMarks = s->marks.maths + s->marks.science + s->marks.computerScience;
    return (totalMarks / 300.0) * 100; 
}

void hotelsInParticularGrade(const hotel *h, int grade){
    if (h->grade == grade){
        printf("Hotel Name: %s\n", h->name);
    }
}
void hotelsOfParticularValue(const hotel *h, int value){
    if(h->room_charges < value){
        printf("Hotel Name: %s\n", h->name);
    }
}
void increment_time(time *t){
    t->sec++;
    if (t->sec == 60) {
        t->sec = 0;
        t->min++;
        if (t->min == 60) {
            t->min = 0;
            t->hr++;
            if (t->hr == 24) {
                t->hr = 0; 
            }
        }
    }
}

int compareFractions(fraction f1, fraction f2){
    float value1 = (float)f1.numerator / f1.denominator;
    float value2 = (float)f2.numerator / f2.denominator;
    if (value1 == value2) {
        return 0;
    } else if (value1 < value2) {
        return -1;
    } else {
        return 1;
    }
}

int isLeapYear(int year){
    if(year % 400 == 0){
        return 1;
    } 
    if(year % 100 == 0){
        return 0;
    }
    if(year % 4 == 0){
        return 1;
    } 
    return 0;
}

int validateDate(date *d){
     if (d->month < 1 || d->month > 12) {
        return 0;
    }
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d->month == 2 && isLeapYear(d->year)) {
        daysInMonth[1] = 29;
    }
    if (d->day < 1 || d->day > daysInMonth[d->month - 1]) {
        return 0;
    }
    return 1;
}

time addTime(time t1, time t2){
    time result;
    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min + (result.sec / 60);
    result.sec %= 60;
    result.hr = t1.hr + t2.hr + (result.min / 60);
    result.min %= 60;
    return result;
}
time subtractTime(time t1, time t2){
    time result;
    result.sec = t1.sec - t2.sec;
    result.min = t1.min - t2.min;
    result.hr = t1.hr - t2.hr;
    if (result.sec < 0) {
        result.sec += 60;
        result.min--;
    }
    if (result.min < 0) {
        result.min += 60;
        result.hr--;
    }
    return result;
}