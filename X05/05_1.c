#include <stdio.h>

// ========================================================================= //

typedef struct {
  double x;
  double y;
  double z;
} vector_3d_t;

// ========================================================================= //

double dotproduct (vector_3d_t a, vector_3d_t b) {
  return a.x * b.x   +   a.y * b.y   +  a.z * b.z;
}

// ------------------------------------------------------------------------- //

vector_3d_t crossproduct (vector_3d_t a, vector_3d_t b) {
  vector_3d_t reVal;
  
  reVal.x = a.y * b.z   -   a.z * b.y;
  reVal.y = a.z * b.x   -   a.x * b.z;
  reVal.z = a.x * b.y   -   a.y * b.x;
  
  return reVal;
}

// ========================================================================= //

int main (void) {
  vector_3d_t a, b, c;
  
  a.x = 1;
  a.y = 2;
  a.z = 3;
  
  b.x = 1.2;
  b.y = 3.4;
  b.z = 5.6;
  
  c = crossproduct(a, b);
  
  // the cross product a x b of two vectos is perpendicular to both, a and b.
  // the dot product of two perpendicular vectors will always be zero.
  // thus, the below will prove/disprove whether the algorithm works correctly.
  
  printf("dot product of perpendicular vectors: %lf\n", dotproduct(a, c));
}
