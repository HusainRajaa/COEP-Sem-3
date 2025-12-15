#include <stdio.h>
#include <ctype.h>
void VowelConsonant(char ch){
    char chr = tolower(ch);
    int a = (int)chr;
    if(a == 97 || a == 101 || a == 105 || a == 111 || a == 117){
        printf("The character %c is a vowel", ch);
    }
    else{
        printf("The character %c is a consonant", ch);
    }
}
int main(){
    char ch;
    printf("Enter a Character : ");
    scanf("%c", &ch);
    VowelConsonant(ch);
    return 0;
}