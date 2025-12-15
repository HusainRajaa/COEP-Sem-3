#include <stdio.h>
int i;
int main(){
    if(i);      // In C, global variables are automatically initialized to 0.
    else
        printf("ELSE");
    return 0;
}