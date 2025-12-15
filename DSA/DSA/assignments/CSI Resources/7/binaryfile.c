#include "binaryfile.h"

void insertrecord(int mis, char name[100], char stream[100], float cgpa)
{
  student s;
  s.mis = mis;
  s.cgpa = cgpa;
  strcpy(s.name, name);
  strcpy(s.stream, stream);
  FILE *fp;
  fp = fopen("student2.dat", "ab");
  if (!fp)
  {
    printf("File not available\n");
  }
  fwrite(&s, sizeof(s), 1, fp);
  fclose(fp);
  return;
}

void display()
{
  student s;
  FILE *fr;
  fr = fopen("student2.dat", "rb");
  if (!fr)
  {
    printf("File not available\n");
    exit(1);
  }
  else
  {
    while (1)
    {
      fread(&s, sizeof(s), 1, fr);
      if (feof(fr))
      {
        break;
      }
      else
      {
        printf("MIS: %d\t", (s.mis));
        printf("Name: %s\t", s.name);
        printf("Stream: %s\t", (s.stream));
        printf("CGPA: %.2f\n\n", (s.cgpa));
      }
    }
  }
  fclose(fr);
  return;
}

int deletion(int mis)
{
  student s;
  int found;
  FILE *fp;
  FILE *tempfp;
  fp = fopen("student2.dat", "rb");
  if (!fp)
  {
    printf("File not available\n");
    return -1;
  }
  tempfp = fopen("temp.dat", "wb");
  if (!tempfp)
  {
    printf("Cannot open temp file\n");
    return -1;
  }
  while (fread(&s, sizeof(student), 1, fp))
  {
    if (mis == s.mis)
    {
      printf("Record Found and Deleted\n");
      found = 1;
    }
    else
    {
      fwrite(&s, sizeof(s), 1, tempfp);
    }
  }
  if (found != 1)
  {
    printf("Record not found\n");
  }
  fclose(fp);
  fclose(tempfp);

  remove("student2.dat");
  rename("temp.dat", "student2.dat");
  return 0;
}

int search(int mis)
{
  student s;
  int found;
  FILE *fp;
  fp = fopen("student2.dat", "rb");
  if (!fp)
  {
    printf("File not available\n");
    return -1;
  }
  while (fread(&s, sizeof(student), 1, fp))
  {
    if (mis == s.mis)
    {
      found = 1;
      break;
    }
  }
  fclose(fp);
  if (found != 1)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

int count(char *stream)
{
  int c = 0;
  student s;
  FILE *fp;
  fp = fopen("student2.dat", "rb");
  if (!fp)
  {
    printf("File not available\n");
    exit(1);
  }
  while (fread(&s, sizeof(student), 1, fp))
  {
    if (strcmp(stream, s.stream) == 0)
    {
      c++;
    }
  }

  fclose(fp);
  return c;
}

