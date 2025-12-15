#include<stdio.h>
/*
* Find maximum marks
*/
#define size 5
int main() {
    int marks[size];
    int i, max;

    /*read array elements*/
    for(i = 0; i < size; i++)
        scanf("%d", &marks[i]);

    printf("\nArray Elements are:\n");
    for(i = 0; i < size; i++)
        printf("%d\n", marks[i]);

    /*highest marks */
    max = marks[0];
    for(i = 1; i < size; i++)
        if(marks[i] > max)
            max = marks[i];
        printf("Highest=%d\n", max);


    /*Average Marks
    float avg;
    int sum;
    for(i = 0, sum = 0; i < size; i++)
        sum = sum + marks[i];
    printf("sum = %d", sum);
    avg = (float)sum/size;
    printf("avg = %.2f", avg);*/



    return 0;
}
