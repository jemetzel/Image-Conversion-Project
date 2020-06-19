#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "project1.h"
char buffer[16] = {0};
unsigned int w, h, d;
unsigned int gettwo()
{
  unsigned int p1 = getchar();
  unsigned int p2 = getchar();
  return ((p1 << 8) | p2);
}
unsigned int getfour()
{
  unsigned int p1 = getchar();
  unsigned int p2 = getchar();
  unsigned int p3 = getchar();
  unsigned int p4 = getchar();
  return (((p1 << 24) | (p2 << 16)) | ((p3 << 8) | p4));
}
int main()
{
  for(int i=0; i<14; ++i) {
    getchar();
  }
  w = gettwo();
  h = gettwo();
  for(int i=0; i<4; ++i) {
    getchar();
  }
  unsigned char c22 = getchar();
  int is_grayscale;
  if(c22 == 192) {
    is_grayscale = 1;
  } else {
    is_grayscale = 0;
  }
  for(int i=0; i<3; ++i) {
    getchar();
  }
  int more_string = 1;
  unsigned char curr_char = getchar();
  while(more_string) {
    if(curr_char == '\0') {
      more_string = 0;
    } else {
      curr_char = getchar();
    }
  }
  for(int i=0; i<4; ++i) {
    getchar();
  }
  struct runlength *run = malloc(sizeof(struct runlength));
  run->size = getfour();
  run->lens = malloc(run->size * sizeof(int));
  run->colors = malloc(run->size * sizeof(struct rgb));
  for(int i=0; i<run->size; ++i) {
    (run->lens)[i] = getfour();
  }
  if(is_grayscale) {
    unsigned char curr_color;
    for(int i=0; i<run->size; ++i) {
      curr_color = getchar();
      (run->colors)[i].r = curr_color;
      (run->colors)[i].g = curr_color;
      (run->colors)[i].b = curr_color;
    }
  } else {
    for(int i=0; i<run->size; ++i) {
      (run->colors)[i].r = getchar();
      (run->colors)[i].g = getchar();
      (run->colors)[i].b = getchar();
    }
  }
  printf("P3\n%d %d\n255\n",w,h);
  for(int i=0; i<run->size; ++i) {
    for(int j=0; j<(run->lens)[i]; ++j) {
      printf("%d %d %d\n",(run->colors)[i].r,(run->colors)[i].g,(run->colors)[i].b);
    }
  }
  return 0;
}
