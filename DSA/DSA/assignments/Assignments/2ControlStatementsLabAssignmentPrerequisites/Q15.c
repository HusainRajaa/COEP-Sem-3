#include <stdio.h>
int main(){
    int check = 20, arr[] = {10,20,30};
    switch(check){
        /* The case labels require constant values that are known at compile time. 
        While array elements can be used as constants when they are part of an expression evaluated at compile time, 
        the compiler typically does not consider array elements as constant expressions for case labels.*/
        case arr[0]: printf("Hello");
        case arr[1]: printf("World");
        case arr[2]: printf("HelloWorld");
    }
    return 0;
}