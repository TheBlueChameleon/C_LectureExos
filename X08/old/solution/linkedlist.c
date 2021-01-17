#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ========================================================================= //

typedef struct {
  char   firstName [25];
  char   lastName  [25];
  char   department[25];
  double salary;
} employee_t;

typedef struct listElement_struct {
  employee_t *                data;
  struct listElement_struct * next;
} listElement_t;

typedef struct {
  listElement_t * first;
  int             size;
  
  int             memoryAutoManaged;
  void (*printElement)(void *);
} linkedList_t;

// ========================================================================= //

linkedList_t * make_linkedList ();
void           free_linkedList(linkedList_t * list);

listElement_t * get_linkedList_element(linkedList_t * list, int index);

int delete_from_linkedList(linkedList_t * list, int index);
int add_to_linkedList     (linkedList_t * list, int index, employee_t * newData, size_t bytes);

void print_all_from_linkedlist(linkedList_t * list);

int    find_biggest_salary   (linkedList_t * list);
char * find_longest_name     (linkedList_t * list);
void   swap_list_items       (linkedList_t * list, int idx1, int idx2);
void   bubblesort_list       (linkedList_t * list, int  (*comp)  (void * a, void * b));
void   for_each_in_linkedlist(linkedList_t * list, void (*action)(void * data));
int    comp_sortBySalary   (void * a, void * b);
void   capitalize_firstname(void * data);

// ========================================================================= //

void printEmployee(void * employee) {
  printf("%25s | %25s | %25s | %8.2lf\n",
    ((employee_t *) employee)->firstName,
    ((employee_t *) employee)->lastName,
    ((employee_t *) employee)->department,
    ((employee_t *) employee)->salary
  );
}

void printTableHead() {
  printf(
    "%25s | %25s | %25s | %8s\n",
    "Vorname",
    "Nachname",
    "Abteilung",
    "Lohn"
  );
  printf(
    "--------------------------+-"
    "--------------------------+-"
    "--------------------------+-"
    "--------\n"
  );
}

// ========================================================================= //

int main () {
  linkedList_t * list = make_linkedList();
  
  list->memoryAutoManaged = 0;
  list->printElement = printEmployee;
  
  employee_t * emp = malloc(sizeof(*emp));
    strcpy(emp->firstName , "Vanessa");
    strcpy(emp->lastName  , "Schmetterling");
    strcpy(emp->department, "Betriebsarzt");
    emp->salary     = 7000.0;
  add_to_linkedList(list, 0, emp, 0);
  
  emp = malloc(sizeof(*emp));
    strcpy(emp->firstName , "Rebecka");
    strcpy(emp->lastName  , "Rein");
    strcpy(emp->department, "R&D");
    emp->salary     = 420.69;
  add_to_linkedList(list, 0, emp, 0);
  
  emp = malloc(sizeof(*emp));
    strcpy(emp->firstName , "Tina");
    strcpy(emp->lastName  , "Mauler");
    strcpy(emp->department, "Ethik-Kommission");
    emp->salary     = 9999.0;
  add_to_linkedList(list, 0, emp, 0);
  
  emp = malloc(sizeof(*emp));
    strcpy(emp->firstName , "ELiza");
    strcpy(emp->lastName  , "Carbos");
    strcpy(emp->department, "International Office");
    emp->salary     = 9876.0;
  add_to_linkedList(list, 0, emp, 0);
  
  emp = malloc(sizeof(*emp));
    strcpy(emp->firstName , "Ali");
    strcpy(emp->lastName  , "Berchan");
    strcpy(emp->department, "Marketing");
    emp->salary     = 6789.0;
  add_to_linkedList(list, 0, emp, 0);
  
  emp = malloc(sizeof(*emp));
    strcpy(emp->firstName , "Ce");
    strcpy(emp->lastName  , "Saurus");
    strcpy(emp->department, "Accounting");
    emp->salary     = 5555.0;
  add_to_linkedList(list, 0, emp, 0);
  
  
  printf("List in its initial state:\n");
  printTableHead();
  print_all_from_linkedlist(list);
  printf("\n");
  
  printf("Biggest salaray on list positon #%d\n", find_biggest_salary(list));
  printf("longest first name in list: %s\n", find_longest_name(list));
  printf("\n");
  
  printf("List after swapping some elements:\n");
  printTableHead();
  swap_list_items(list, 0, 5);
  swap_list_items(list, 1, 4);
  swap_list_items(list, 2, 3);
  print_all_from_linkedlist(list);
  printf("\n");
  
  printf("List, sorted by salary:\n");
  printTableHead();
  bubblesort_list(list, comp_sortBySalary);
  print_all_from_linkedlist(list);
  printf("\n");
  
  printf("List, after capitalize_firstname:\n");
  printTableHead();
  for_each_in_linkedlist(list, capitalize_firstname);
  print_all_from_linkedlist(list);
  printf("\n");
  
  list->memoryAutoManaged = 1;
  free_linkedList(list);
}

// ========================================================================= //

// constructor and destructor

linkedList_t * make_linkedList () {
  linkedList_t * reVal = malloc(sizeof(*reVal));
  if (!reVal) {
    printf("Fehler: Speicher konnte nicht alloziert werden\n");
    return NULL;
  }
  
  reVal->first        = NULL;
  reVal->size         = 0;
  reVal->printElement = NULL;
  
  return reVal;
}

void free_linkedList(linkedList_t * list) {
  while (list->size) {
    delete_from_linkedList(list, 0);
  }
  
  free(list);
}

// ========================================================================= //
// index access

listElement_t * get_linkedList_element(linkedList_t * list, int index) {
  if (index < 0 || index >= list->size) {
    printf("Fehler: ungültiger Index\n");
    return NULL;
  }
  
  listElement_t * element = list->first;
  for (int i=0; i<index; i++) {
    element = element->next;
  }
  
  return element;
}

// ========================================================================= //
// add and delete

int delete_from_linkedList(linkedList_t * list, int index) {
  if (index < 0 || index >= list->size) {
    printf("Fehler: ungültiger Index\n");
    return -1;
  }
  
  listElement_t * prev, * self, * next;
  
  if (index == 0) {
    prev = NULL;
    self = list->first;
    list->first = self->next;
    
  } else {
    prev = get_linkedList_element(list, index - 1);
    self = prev->next;
  }
  
  next = self->next;
  if (prev) {prev->next = next;}
  
  if (list->memoryAutoManaged) {free(self->data);}
  free(self);
  
  return --list->size;
}

// ------------------------------------------------------------------------- //

int add_to_linkedList(linkedList_t * list, int index, employee_t * newData, size_t bytes) {
  if (index < 0 || index > list->size) {
    printf("Fehler: ungültiger Index\n");
    return -1;
  }
  
  listElement_t * prev, * self, * next;
  
  
  self = malloc(sizeof(*self));
  if (!self) {
    printf("Fehler: Speicher konnte nicht alloziert werden\n");
    return -1;
  }
  
  if (list->memoryAutoManaged) {
    self->data = malloc(bytes);
    if (!self->data) {
      printf("Fehler: Speicher konnte nicht alloziert werden\n");
      free(self);
      return -1;
    }
    
    memcpy(self->data, newData, bytes);
  } else {
    self->data = newData;
  }
  
  if (index == 0) {
    prev = NULL;
    next = list->first;
    list->first = self;
    
  } else {
    prev = get_linkedList_element(list, index - 1);
    next = prev->next;
  }
  
  if (prev) {prev->next = self;}
  self->next = next;
  
  return ++list->size;
}

// ========================================================================= //
// screen output

void print_all_from_linkedlist(linkedList_t * list) {
  listElement_t * element = list->first;
  while (element != NULL) {
    list->printElement(element->data);
    element = element->next;
  }
}

// ========================================================================= //
// solutions to the exercise

int    find_biggest_salary(linkedList_t * list) {
  double maxSalary = 0;
  int    maxIdx    = 0;
  
  listElement_t * element = list->first;
  for (int i=0; i<list->size; i++) {
    if (element->data->salary > maxSalary) {
      maxSalary = element->data->salary;
      maxIdx = i;
    }
    element = element->next;
  }
  
  return maxIdx;
}

// ------------------------------------------------------------------------- //

char * find_longest_name  (linkedList_t * list) {
  char *       longestName   = NULL;
  unsigned int longestLength = 0;
  
  listElement_t * element = list->first;
  for (int i=0; i<list->size; i++) {
    if ( strlen(element->data->firstName) > longestLength) {
      longestLength = strlen(element->data->firstName);
      longestName = element->data->firstName;
    }
    element = element->next;
  }
  
  return longestName;
}

// ------------------------------------------------------------------------- //

void   swap_list_items    (linkedList_t * list, int idx1, int idx2) {
  if (idx1 == idx2) {return;}
  
  listElement_t * element1 = get_linkedList_element(list, idx1),
                * element2 = get_linkedList_element(list, idx2);
  
  if (!element1 || !element2) {return;}
  
  void * dummy = element1->data;
  element1->data = element2->data;
  element2->data = dummy;
  
}

// ------------------------------------------------------------------------- //

void bubblesort_list (linkedList_t * list, int (*comp)(void * a, void * b)) {
  int flagSwap = 0;
  void * dummy;
  listElement_t * element1, * element2;
  
  do {
    flagSwap = 0;
    for (int i = 0; i < list->size - 1; i++) {
      element1 = get_linkedList_element(list,  i );
      element2 = get_linkedList_element(list, i+1);
      if ( comp(element1->data, element2->data) < 0 ) {
        flagSwap = 1;
        
        dummy = element1->data;
        element1->data = element2->data;
        element2->data = dummy;
      }
    }
  } while(flagSwap);
}

// ......................................................................... //

int comp_sortBySalary(void * a, void * b) {
  if (a == NULL) {return 0;}
  if (b == NULL) {return 0;}
  
  double salarayA = ((employee_t *) a)->salary;
  double salarayB = ((employee_t *) b)->salary;
  
  if (salarayA < salarayB) {return +1;}
  if (salarayA > salarayB) {return -1;}
  return 0;
}

// ------------------------------------------------------------------------- //

void   for_each_in_linkedlist(linkedList_t * list, void (*action)(void * data)) {
  listElement_t * element = list->first;
  
  while (element != NULL) {
    action(element->data);
    element = element->next;
  }
}

// ......................................................................... //

void capitalize_firstname(void * data) {
  int    i      = 0;
  char * string = ((employee_t *)data)->firstName;
  
  while (string[i]) {string[i] = toupper(string[i]); i++;}
}
