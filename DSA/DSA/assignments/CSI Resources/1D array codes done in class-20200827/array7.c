#include<stdio.h>
/*
* ARRAY SIZE HAS TO A CONSTANT
*/

/*This cannot be done
    int size = 5;
    char vowels[size] ={'a','e','i','o','u'};
    instead do this..
    */


#define size 5
int main() {
    int i;
    char vowels[size] ="Hello";
    for(i = 0; i < size; i++)
        printf("%c\n",vowels[i]);
    return 0;
}
