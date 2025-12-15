#include <stdio.h>
int main(){
    int i;
    if(printf("0"))     //printf returns the number of characters printed, which in this case is 1.
        i = 3;
    else
        i = 5;
    printf("%d",i);
    return 0;
}