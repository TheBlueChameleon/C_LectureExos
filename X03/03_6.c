#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ========================================================================= //

void prepareCards(int * cards) {
  for (int i=0; i<52; i++) {cards[i] = i;}
}

// ========================================================================= //

char cardValueChar(int cardCode) {
  int value = cardCode % 13;
  
  if (value ==  0) {return 'A';}
  if (value <   9) {return value + '1';}
  if (value ==  9) {return 'X';}
  if (value == 10) {return 'J';}
  if (value == 11) {return 'Q';}
  if (value == 12) {return 'K';}
  
  return '\0'; 
}

// -------------------------------------------------------------------------- //

char cardColourChar(int cardCode) {
  switch (cardCode / 13) {
    case 0 :
      return 'H';
    case 1 :
      return 'D';
    case 2 :
      return 'C';
    case 3 :
      return 'S';
  }
  return '\0'; 
}

// ========================================================================= //

void swap (int * a, int * b) {
  int dummy = *b;
  *b = *a;
  *a = dummy;
}

// -------------------------------------------------------------------------- //

void shuffleDeck (int * cards) {
  int offset_A, offset_B;
  
  for (int k=0; k< 500; k++) {
    offset_A = rand() % 52;
    offset_B = rand() % 52;
    
    swap (cards + offset_A, 
          cards + offset_B
         );
  }
}

// ========================================================================= //

void showCard (int cardCode) {
  printf("%c%c", cardColourChar(cardCode), cardValueChar(cardCode));
}

// ========================================================================= //

int compareCards(int cardA, int cardB) {
  if   (cardColourChar(cardA) == 'H') {
    if (cardColourChar(cardB) == 'H') {
      goto label_noTrump;
      
    } else {
      return +1;
    }
  }
  
  if (cardColourChar(cardB) == 'H') {
    return -1;
  }
  
  label_noTrump:
  if      ((cardA % 13) > (cardB % 13)) {return +1;} 
  else if ((cardA % 13) < (cardB % 13)) {return -1;} 
  else                                  {return  0;}
}

// ========================================================================= //

int main () {
  srand(time(NULL));
  
  int cards[52];
  
  prepareCards(cards);
  shuffleDeck(cards);
  
  int  score = 0;
  char choice[2];
  int  cardID = 0;
  int  cardA, cardB;
  int  comparison;
  
  while (1) {
    printf("Nächste Karte aufdecken (j/n)?\n");
    scanf("%1s", choice);
    
    if (!(*choice == 'j')  &&  !(*choice == 'J')) {break;}
    
    cardA = cards[cardID];
    cardID++;
    
    printf("Deine Karte ist: ");
    showCard(cardA);
    printf("\n");
    
    printf("Ist deine Karte höherwertig als die des Computers (j/n)?\n");
    scanf("%1s", choice);
    
    cardB = cards[cardID];
    cardID++;
    
    printf("Der Computer zieht: ");
    showCard(cardB);
    printf("\n");
    
    comparison = compareCards(cardA, cardB);
    
    printf("Dbg: A = %d, B = %d\n", cardA, cardB);
    printf("Dbg: cmp = %d\n", comparison);
    
    if (comparison > 0) {
      printf("Deine Karte war höherwertig!\n");
    } else if (comparison < 0) {
      printf("Die Karte des Computers war höherwertig!\n");
    } else {
      printf("Die Karten sind gleichwertig!\n");
    }
    score += comparison * ( (*choice == 'j'  ||  *choice == 'J')  ?  +1  :  -1 );
    
    if (cardID == 52) {
      cardID = 0;
      shuffleDeck(cards);
    }
  }
  
  printf("Gesamtpunktzahl: %d\n", score);
}
