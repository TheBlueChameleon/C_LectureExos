#include <stdio.h>
#include <math.h>

typedef struct {
  double x;
  double y;
  double z;
} vector_3d;

#define ASSIGN(var, a, b, c) (var.x = a, var.y = b, var.z = c)
#define VECRAD(var)          (sqrt(var.x * var.x  + var.y * var.y  + var.z * var.z))
#define VECPHI(var)          (atan2(var.y, var.x))
#define VECTHE(var)          (acos(var.z / VECRAD(var)))

int main (void) {
  vector_3d myVec;
  
  ASSIGN(myVec, 0, 3, 3);
  
  printf("%lf\n", VECRAD(myVec));
  printf("%lf\n", VECPHI(myVec));
  printf("%lf\n", VECTHE(myVec));
}
