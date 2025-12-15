#include <stdio.h>
int main(){
    int i = 3;
    switch (i){
        printf("Outside");
        case 1: printf("Hello");
            break;
        case 2: printf("World");
            break;
        default: printf("HelloWorld");
    }
    return 0;
}