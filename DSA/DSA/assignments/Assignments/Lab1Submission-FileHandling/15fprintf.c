#include <stdio.h>
int main(){
    int month = 11, date = 10, year = 2017;
    float rate = 65.00000000;
    char dateStr[10] = "Today is";
    char rateStr[20] = "and exchange rate is";
    FILE *fp;
    fp = fopen("INPUT.txt","a+");
    if(fp!=NULL){
        fprintf(fp,"%s %d %d %d %s %f \n",dateStr, date, month, year, rateStr,rate);
        return 0;
    }
    fclose(fp);
    return 1;
}