#include <stdio.h>
#include <stdlib.h>

// ========================================================================== //

typedef struct listElement_struct {
  int data;
  struct listElement_struct * next;
} listElement_t;

// ========================================================================== //


listElement_t * newElement(int value) {
  listElement_t * reVal = malloc( sizeof(*reVal) );
  
  if (!reVal) {
    printf("Error.\n");
    return reVal;
  }
  
  if (reVal) {
    reVal->data = value;
    reVal->next = NULL;
  }
  
  return reVal; 
}

// -------------------------------------------------------------------------- //

void prepend(listElement_t * head, int value) {
  if (!head) {
    printf("Invalid adress, terminating.\n");
    return;
  }
  
  listElement_t * new = newElement( head->data );
  
  new ->next = head->next;
  head->next = new;
  head->data = value;
}

// -------------------------------------------------------------------------- //

void showList(listElement_t * head) {
  while (head) {
    printf("%d\n", head->data);
    head = head->next;
  }
}

// -------------------------------------------------------------------------- //

int pop(listElement_t ** head) {
  if (!head) {
    printf("Invalid adress, terminating.\n");
    exit(-1);
  }
  
  listElement_t * newHead = (*head)->next;
  int             reVal   = (*head)->data;
  
  free(*head);
  *head = newHead;
  
  return reVal;
}

// -------------------------------------------------------------------------- //

void clearList(listElement_t * head) {
  while (head) {pop(&head);}
}

// -------------------------------------------------------------------------- //

int listLength(listElement_t * head) {
  int reVal = 0;
  
  while (head) {
    head = head->next;
    reVal++;
  }
  
  return reVal;
}

// -------------------------------------------------------------------------- //

void append(listElement_t * head, int value) {
  if (!head) {
    printf("Invalid adress, terminating.\n");
    exit(-1);
  }
  
  while (head->next) {head = head->next;}
  
  head->next = newElement(value);
}

// -------------------------------------------------------------------------- //

void insert(listElement_t * head, int pos, int value) {
  if (!head) {
    printf("Invalid adress, terminating.\n");
    return;
  }
  
  int len = listLength(head);
  
  if ( pos < 0 || pos > len ) {
    printf("Invalid index, terminating.\n");
    return;
  }
  
  if (pos == len) {
    append(head, value);
    return;
  }
  
  listElement_t * prev = head;
  for (int i = 0; i < pos; i++) {prev = prev->next;}
  
  prepend(prev, value);
}

// -------------------------------------------------------------------------- //



// ========================================================================== //


int main () {
  listElement_t * firstElement;
  
  printf("=== TEST 1 ===\n");
  printf("\tnewElement\n");
  firstElement = newElement(5);
  showList(firstElement);
  printf("\n");
  
  
  
  printf("=== TEST 2 ===\n");
  printf("\tprepend\n");
  for (int i=4; i>=0; i--) {
    prepend(firstElement, i);
  }
  showList(firstElement);
  printf("\n");
  
  
  
  printf("=== TEST 3 ===\n");
  printf("\tpop: returns %d\n", pop(&firstElement) );
  printf("\trest of list:\n");
  showList(firstElement);
  printf("\n");
  
  
  
  printf("=== TEST 4 ===\n");
  printf("\tthe above list has %d elements.\n", listLength(firstElement) );
  printf("\n");
  
  
  
  printf("=== TEST 5 ===\n");
  printf("\tappend\n");
  append(firstElement, 6);
  showList(firstElement);
  printf("\n");
  
  
  printf("=== TEST 6 ===\n");
  insert(firstElement, 6, 99);
  insert(firstElement, 0, 97);
  insert(firstElement, 2, 98);
  showList(firstElement);
  printf("\n");
  
  clearList(firstElement);
}
