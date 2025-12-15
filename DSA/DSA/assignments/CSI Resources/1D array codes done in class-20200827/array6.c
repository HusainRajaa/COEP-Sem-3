#include<stdio.h>
/*
* character array initialized with individual elements does not append '\0'
*/
int main() {
    char vowels[] ={'a','e','i','o','u'};
    int i;
    for(i = 0; i < 10; i++)
        printf("%c\n",vowels[i]);
    return 0;
}
