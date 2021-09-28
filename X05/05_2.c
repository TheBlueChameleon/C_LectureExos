#include <stdio.h>

// ========================================================================= //

typedef struct {
  char   name[21];
  int    age;
  double height;
} person_t, * person_p;

// ========================================================================= //

void enterPerson(person_p array, int ID) {
  /* Note that ALL scanf format strings begin with a whitespace.
   * We do not need that for the very first time, but enterPerson is called in
   * a loop. That is, the scanf in line 24 is only the very first scanf for the
   * first passage of the loop. Thereafter, the keyboard buffer is "polluted"
   * with residual characters from entering the height of the previous person.
   * ==> get rid of that by the whitespace trick.
   */

  printf("please provide some information about person %d.\n", ID + 1);
  printf("What is their name?\n");
  scanf(" %20[ a-zA-Z]", array[ID].name);

  printf("\nHow old are they?\n");
  scanf(" %d", &array[ID].age);

  printf("\nHow tall are they?\n");
  scanf(" %lf", &array[ID].height);
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
