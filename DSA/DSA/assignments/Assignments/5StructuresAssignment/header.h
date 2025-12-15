typedef struct student{
    int rollno;
    struct name{
        char firstName[20];
        char middleName[20];
        char lastName[20];
    }name;
    char gender[15];
    struct dob{
        int day;
        int month;
        int year;
    }dob;
    struct marks{
        int maths;
        int science;
        int computerScience;
    }marks;
}student;

typedef struct hotel{
    char name[50];
    char address[100];
    int grade;
    int number_of_rooms;
    int room_charges;
}hotel;

typedef struct time{
    int hr;
    int min;
    int sec;
}time;

typedef struct fraction{
    int numerator;
    int denominator;
}fraction;

typedef struct date{
    int year;
    int month;
    int day;
}date;

void displayStudent(const student *s);
float calculateAverage(const student *s);
float calculateAggregatePercentage(const student *s);
void hotelsInParticularGrade(const hotel *h, int grade);
void hotelsOfParticularValue(const hotel *h, int value);
void increment_time(time *t);
int compareFractions(fraction f1, fraction f2);
int isLeapYear(int year);
int validateDate(date *d);
time addTime(time t1, time t2);
time subtractTime(time t1, time t2);