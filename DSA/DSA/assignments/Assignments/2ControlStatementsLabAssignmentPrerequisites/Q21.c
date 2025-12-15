#include <stdio.h>
int main(){
    int j = 0;
    for( ; j < 10 ;){
        if(j < 10){
            printf("Hello %d\n",j++);
        }
        else{
            continue;
        }
        printf("World\n");
    }
    return 0;
}
