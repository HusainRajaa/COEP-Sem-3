#include <stdio.h>
void UppercaseLowercase(char ch){
    int A = (int)ch;
    if(A >= 65 && A <= 90){
        printf("The Character %c is Uppercase alphabet", ch);
    }
    else if(A >= 97 && A <= 122){
        printf("The Character %c is Lowercase alphabet", ch);
    }
    else{
        printf("The Character %c is not a alphabet", ch);
    }
}
int main(){
    char ch;
    printf("Enter a Character : ");
    scanf("%c", &ch);
    UppercaseLowercase(ch);
    return 0;
}