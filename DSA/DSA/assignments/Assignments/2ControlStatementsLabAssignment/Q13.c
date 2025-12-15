#include <stdio.h>
int main(){
    char s;
    printf("Enter a character: ");
    scanf("%c",&s);
    if(s>='a' && s <='z'){
        printf("It is lower-case alphabet");
    }
    else if(s>='A' && s <='Z'){
        printf("It is upper-case alphabet");
    }
    else if(s>='0' && s<='9'){
        printf("It is Number");
    }
    else{
        printf("It is Special Character");
    }
}