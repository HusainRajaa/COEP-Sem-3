#include <stdio.h>
int FindingElement(float arr[] , int size , float target){
    int i, flag = 0;
    for(i = 0 ; i < size ; i++){
        if(arr[i] == target){
            return i;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        return 0;
    }
}
int main(){
    float arr[50];
    int i, answer;
    float target;
    for(i = 0 ; i < 50 ; i++){
        scanf("%f",&arr[i]);
    }
    printf("Enter Target\n");
    scanf("%f",&target);
    answer = FindingElement(arr , 50 , target);
    if(answer != 0){
        printf("%d",answer);
    }
    else{
        printf("Not Found");
    }
    return 0;
}