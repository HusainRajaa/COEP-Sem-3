#include <stdio.h>
int main(int argc,char *argv[]){
    while(argc>0) /* print out all arguments in reverse order*/{
        printf("%s\n",argv[argc-1]);
        argc--;
    }
    return 0;
}