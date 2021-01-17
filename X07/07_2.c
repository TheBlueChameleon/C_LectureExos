#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========================================================================= //

typedef struct {
  char   name[21];
  int    age;
  double height;
} person_t, * person_p;

// ========================================================================= //

void enterPerson(person_p array, int ID) {
  //char buffer[8192] = {};
  
  printf("please provide some information about person %d.\n", ID + 1);
  printf("What is their name?\n");
  scanf(" %20[ a-zA-Z]", array[ID].name);
  //setbuf(stdin, buffer);
  
  printf("\nHow old are they?\n");
  scanf(" %d", &array[ID].age);
  //setbuf(stdin, buffer);
  
  printf("\nHow tall are they?\n");
  scanf(" %lf", &array[ID].height);
  //setbuf(stdin, buffer);
  printf("\n");
}

// ------------------------------------------------------------------------- //

void showPersonTable(person_p array, int count) {
  // string length NEGATIVE twenty makes it left-aligned
  printf("%-20s\tage\theight\n", "name");
  
  for (int i=0; i<count; i++) {
    printf(
      "%-20s\t%d\t%lf\n", 
      array[i].name,
      array[i].age,
      array[i].height
    );
  }
}

// ========================================================================= //

void resetPersonTable(person_p array, int count) {
  for (int i=0; i<count; i++) {
    array[i].name[0] = 0;
    array[i].age     = 0;
    array[i].height  = 0;
  }
}

// ========================================================================= //

void writePersonFile(FILE * handle, person_p array, int count) {
  for (int i=0; i<count; i++) {
    fprintf(
      handle,
      "%s, %d %lf\n", 
      array[i].name,
      array[i].age,
      array[i].height
    );
  }
}

// ------------------------------------------------------------------------- //

void readPersonFile(FILE * handle, person_p array, int count) {
  for (int i=0; i<count; i++) {
    fscanf(handle, "%[^,]",  array[i].name  );
    fgetc(handle);    // read the comma separator
    fscanf(handle, " %d"  , &array[i].age   );
    fscanf(handle, " %lf" , &array[i].height);
    fgetc(handle);    // read the end of line symbol
  }
}

// ========================================================================= //

int main () {
  int N = 3;
  person_p people = malloc(N * sizeof(person_t));
  char filename[] = "phonebook.txt";
  
  
  //for (int i=0; i<N; i++) {
  //  enterPerson(people, i);
  //}
  
  strcpy(people[0].name, "Hans Wurst");
  people[0].age    = 99;
  people[0].height = 1.23;
  
  strcpy(people[1].name, "Mario Anner");
  people[1].age    = -1;
  people[1].height = 4.20;
  
  strcpy(people[2].name, "Rosa Schlüpfer");
  people[2].age    = 11;
  people[2].height = 9.87;
  
  printf("writing the following data to the file \"%s\":\n", filename);
  showPersonTable(people, N);
  printf("\n");
  
  
  FILE * hFile = fopen(filename, "w");
  writePersonFile(hFile, people, N);
  fclose(hFile);
  
  
  printf("purging data from memory\n");
  resetPersonTable(people, N);
  printf("\n");
  
  
  printf("reading data back from file\n");
  hFile = fopen(filename, "r");
  readPersonFile(hFile, people, N);
  fclose(hFile);
  showPersonTable(people, N);
  
  free(people);
}
