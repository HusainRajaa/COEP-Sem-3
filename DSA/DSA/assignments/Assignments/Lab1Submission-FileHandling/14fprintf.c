#include <stdio.h>
void main(){
    FILE *fptr;
    char name[20];
    int age;
    fptr = fopen("emp.txt", "w"); /* open for writing */
    printf("Enter the name \n");
    scanf("%s", name);
    fprintf(fptr, "Name = %s\n", name);
    printf("Enter the age\n");
    scanf("%d", &age);
    fprintf(fptr, "Age = %d\n", age);
    fclose(fptr);
}