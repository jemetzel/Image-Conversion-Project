#include <stdio.h>
#include <stdlib.h>
struct rgb {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};
struct runlength {
  int size;
  int *lens;
  struct rgb *colors;
};
