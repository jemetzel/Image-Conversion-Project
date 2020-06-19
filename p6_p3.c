#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project1.h"
char buffer[16] = {0};
int w, h, d;
unsigned char r, g, b;
int main()
{
  fscanf(stdin,"%s",buffer);
  if (strcmp(buffer,"P6")!=0) {
    fprintf(stderr,"p6_p3: input file should start with P6");
    exit(1);
  }
  printf("P3\n");
  if (fscanf(stdin,"%d %d",&w,&h)!=2) {
    fprintf(stderr,"p6_p3: width or height value not found");
    exit(1);
  }
  printf("%d %d\n",w,h);
  if (fscanf(stdin,"%d",&d)!=1) {
    fprintf(stderr,"p6_p3: color depth value not found");
    exit(1);
  } else if (d!=255) {
    fprintf(stderr,"p6_p3: color depth should be 255");
  }
  printf("%d\n",d);
  getchar();
  printf("%d %d %d\n",r,g,b);
  for(int i=0; i<w*h; ++i) {
    r = getchar();
    g = getchar();
    b = getchar();
    printf("%d %d %d\n",r,g,b);
  }
  return 0;
}
