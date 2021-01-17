#include <stdio.h>

// ========================================================================= //

typedef struct {
  char   name[21];
  int    age;
  double height;
} person_t, * person_p;

// ========================================================================= //

void enterPerson(person_p array, int ID) {
  char buffer[8192] = {};
  
  printf("please provide some information about person %d.\n", ID + 1);
  printf("What is their name?\n");
  scanf("%20[ a-zA-Z]", array[ID].name);
  setbuf(stdin, buffer);
  
  printf("\nHow old are they?\n");
  scanf(" %d", &array[ID].age);
  setbuf(stdin, buffer);
  
  printf("\nHow tall are they?\n");
  scanf(" %lf", &array[ID].height);
  setbuf(stdin, buffer);
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

int main (void) {
  person_t people[3];
  
  for (int i=0; i<3; i++) {
    enterPerson(people, i);
  }
  
  showPersonTable(people, 3);
}
