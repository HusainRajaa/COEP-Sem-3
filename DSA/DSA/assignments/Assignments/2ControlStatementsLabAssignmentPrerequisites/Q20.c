#include <stdio.h>

// Incorrect Code

// int main(){
//     int i = 1,j;
//     for( ; ; ){
//         if(i){
//             j--;
//         }
//         if(j < 10)
//             printf("HelloWorld",j++);
//         else   
//             break;
//     }
// }

// Corrected Code

#include <stdio.h>
int main()
{
    int i = 1, j;
    for ( ; ; )
    {
        if (i)
            j = --i;
        if (j < 10)
            printf("HelloWorld %d\n", j++);
        else
            break;
    }
    return 0;
}