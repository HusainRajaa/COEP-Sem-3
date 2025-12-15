#include <stdio.h>
int main(){
    FILE *f1, *f2;
    f1 = fopen("A.txt", "w");
    f2 = fopen("A.txt", "r");
    fclose(f1);
    fclose(f2);
    f1 = fopen("B.txt", "a");
    f2 = fopen("B.txt", "r+");      //r+ open to beginning for both reading/writing
    fclose(f1);
    fclose(f2);
    f1 = fopen("C.txt", "w+");      //w+ same as w except both for reading and writing
    f2 = fopen("C.txt", "a+");      //a+ same as ‘a’ except both for reading and writing
    return 0;
}