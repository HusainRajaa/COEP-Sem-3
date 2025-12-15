#include <stdio.h>
int main(){
    FILE *f1;
    int i = 25;
    float f = 3.14;
    
    f1 = fopen("OUTPUT.txt", "w");
    // Write to the file
    fprintf(f1, "%d %f\n", i, f);
    fclose(f1);
    
    f1 = fopen("OUTPUT.txt", "r");
    // Read from the file
    fscanf(f1, "%d %f", &i, &f);
    fclose(f1);
    
    // Print the values read from the file
    printf("Read from file: %d %f\n", i, f);
}