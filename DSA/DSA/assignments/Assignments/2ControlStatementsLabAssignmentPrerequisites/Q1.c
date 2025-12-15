#include <stdio.h>
int main(){
    int i = 1024;
    // i = 10000000000 in binary
    for(; i ; i >>= 1)
        printf("Hello World\n");
    return 0;
}