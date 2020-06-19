#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project1.h"
char buffer[16] = {0};
unsigned int w, h, d, r, g, b;
int main()
{
  fscanf(stdin,"%s",buffer);
  if (strcmp(buffer,"P3")!=0) {
    fprintf(stderr,"p3_p6: input file should start with P3");
    exit(1);
  }
  printf("P6\n");
  if (fscanf(stdin,"%d %d",&w,&h)!=2) {
    fprintf(stderr,"p3_p6: width or height value not found");
    exit(1);
  }
  printf("%d %d\n",w,h);
  if (fscanf(stdin,"%d",&d)!=1) {
    fprintf(stderr,"p3_p6: color depth value not found");
    exit(1);
  } else if (d!=255) {
    fprintf(stderr,"p3_p6: color depth should be 255");
  }
  printf("%d\n",d);
  int there_is_more = 1;
  while(there_is_more) {
    if (fscanf(stdin,"%d %d %d",&r,&g,&b)!=3) {
      there_is_more = 0;
    }
    putchar(r);
    putchar(g);
    putchar(b);
  }
  return 0;
}
