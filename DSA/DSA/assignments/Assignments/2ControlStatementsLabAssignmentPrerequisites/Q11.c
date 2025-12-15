#include <stdio.h>
int main(){
    int i;
    // Warning : Infinite Loop
    for(i = 1 ; i != 10 ; i += 2)
        printf("HelloWorld");
    return 0;
}