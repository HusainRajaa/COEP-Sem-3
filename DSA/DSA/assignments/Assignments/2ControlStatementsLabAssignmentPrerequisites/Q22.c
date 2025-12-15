#include <stdio.h>
int main(){
    unsigned int i = 65000;
    while(i++ != 0);
    // When i reaches 65535 (maximum value for a typical unsigned int), the next increment will wrap it around to 0.
    printf("%d",i);
    return 0;
}