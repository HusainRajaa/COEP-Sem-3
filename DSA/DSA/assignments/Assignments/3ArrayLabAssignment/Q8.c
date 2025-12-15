#include <stdio.h>
void AlphabetDigitSpecialChar(char ch){
    int A = (int)ch;
    if((A >= 65 && A <= 90) || (A >= 97 && A <= 122)){
        printf("The Given Character %c is Alphabet", ch);
    }
    else if(A >= 48 && A <= 57){
        printf("The Given Character %c is Digit", ch);
    }
    else {
        printf("The Given Character %c is a Special Character", ch);
    }
}
int main(){
    char ch;
    printf("Enter a Character : ");
    scanf("%c", &ch);
    AlphabetDigitSpecialChar(ch);
    return 0;
}