#include <stdio.h>
int main(){
    int wind;
    float temp;
    float WCI;
    printf("Enter the wind speed:");
    scanf("%d",&wind);
    printf("Enter the temperature:");
    scanf("%f", &temp);
    if(wind >= 0 && wind <= 4){
        WCI = temp;
        printf("The value of WCI is: %f.\n", WCI);
    }
    else if(wind >= 45){
        WCI = 1.6 * temp - 55;
        printf("The value of WCI is: %f.\n",WCI);
    }
    else{
        WCI = 91.4 + (91.4 - temp) * (0.0203 * wind - 0.304 * wind * 0.5 - 0.474);
        printf("The value of WCI is: %f.\n",WCI);
    }

    return 0;
}