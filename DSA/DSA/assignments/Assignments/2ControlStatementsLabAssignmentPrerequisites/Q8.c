#include <stdio.h>
int main(){
    int c = 5, no = 10;
    do {
        no /= c;
    }while(--c > 0);
    printf("%d\n",no);
    return 0;
}