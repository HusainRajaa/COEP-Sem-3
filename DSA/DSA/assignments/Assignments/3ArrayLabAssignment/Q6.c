#include <stdio.h>
void AlphabetCheck(char ch){
    int A = (int)ch;
    if((A >= 65 && A <= 90) || (A >= 97 && A <= 122)){
        printf("The Given Character %c is Alphabet", ch);
    }
    else{
        printf("The Given Character %c is not a Alphabet", ch);
    }
}
int main(){
    char ch;
    printf("Enter a Character : ");
    scanf("%c", &ch);
    AlphabetCheck(ch);
    return 0;
}