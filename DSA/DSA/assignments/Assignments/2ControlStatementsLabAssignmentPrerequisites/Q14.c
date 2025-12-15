#include <stdio.h>
int main(){
    char check = 'a';
    switch(check){
        // the use of the || (logical OR) operator within the case labels is incorrect.
        case ('a' || 1) : printf("Hello");
            break;
        // case ('b' || 2) : printf("World");
            // break;
        default:printf("HelloWorld");
    }
}
