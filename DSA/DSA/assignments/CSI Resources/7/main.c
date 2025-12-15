#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryfile.h"

int main()
{
  int mis;
  char name[100];
  char stream[100];
  float cgpa;
  int opt;
  int deleteElem;
  int searchElem;
  int i;

  printf("MENU:\n");
  printf("0.Exit\n1.Insert function\n2.Display File contents\n3.Delete a Record\n4.Search\n5.Count Students from each Stream\n\n");
  printf("Enter option:");
  scanf("%d", &opt);
  while (opt != 0)
  {
    if (opt == 1)
    {
      printf("Inserting\n");
      printf("Enter Mis:\n");
      scanf("%d", &mis);
      printf("Enter Name:\n");
      scanf("%s",name);
      printf("Enter Stream:\n");
      scanf("%s",stream);
      printf("Enter CGPA:\n");
      scanf("%f", &cgpa);
      insertrecord(mis, name, stream, cgpa);
    }
    else if (opt == 2)
    {
      printf("Display the contents\n");
      display();
    }
    else if (opt == 3)
    {
      printf("Delete an element\n");
      printf("Enter MIS of the record to be deleted:\n");
      scanf("%d", &deleteElem);
      int a = deletion(deleteElem);
    }
    else if (opt == 4)
    {
      printf("Search for a particular record\n");
      printf("Enter Mis of the element you want to search for:");
      scanf("%d", &searchElem);
      int s = search(searchElem);
      if (s == 1)
      {
        printf("Found\n");
      }
      else
      {
        printf("Not Found\n");
      }
    }
    else if (opt == 5)
    {
      printf("Count students from each stream\n");
      printf("Computer Branch:%d\n", count("Computer"));
      printf("ENTC Branch:%d\n", count("ENTC"));
      printf("Mechanical Branch:%d\n", count("Mechanical"));
      printf("Manufacturing Branch:%d\n", count("Manufacturing"));
      printf("Electrical Branch:%d\n", count("Electrical"));
      printf("Instru Branch:%d\n", count("Instru"));
      printf("Production Branch:%d\n", count("Prod"));

    }
    printf("Enter option:");
    scanf("%d", &opt);
  }
  return 0;
}

