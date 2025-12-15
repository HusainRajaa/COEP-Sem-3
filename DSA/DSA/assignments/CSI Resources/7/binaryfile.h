#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentInfo
{
  int mis;
  char name[100];
  float cgpa;
  char stream[100];
} student;

void insertrecord(int mis, char name[100], char stream[100], float cgpa);
void display();
int deletion(int mis);
int search(int mis);
int count(char *stream);
