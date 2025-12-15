#include<stdio.h>
/*
* char array declaration, initialization with " " and delimiter '\0'
*/
int main() {
    char subject[] ="Data Structures";
    int i;
    for(i = 0; subject[i] != '\0'; i++)
        printf("%c\n",subject[i]);
    return 0;
}
