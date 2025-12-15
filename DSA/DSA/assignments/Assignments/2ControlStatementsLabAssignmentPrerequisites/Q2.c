#include <stdio.h>
int main(){
    // int i = 48;  // to print Hello
    // int i = 49;  // to print World
    int i = 0;      // to execute default
    switch(i){
        case '0': printf("Hello");
            break;
        case '1': printf("World");
            break;
        default: printf("Hello World");
    }
    return 0;
}