#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "project1.h"
char buffer[16] = {0};
unsigned int w, h, d;
void putfour(unsigned int x)
{
  putchar((x >> 24) & 255);
  putchar((x >> 16) & 255);
  putchar((x >> 8) & 255);
  putchar(x & 255);
}
void puttwo(unsigned int x)
{
  putchar((x >> 8) & 255);
  putchar(x & 255);
}
int rgbeq(struct rgb a, struct rgb b)
{
  return (a.r == b.r && a.g == b.g && a.b == b.b);
}
struct runlength *runlength(struct rgb *pix, int num_pix)
{
  if(pix==NULL) {
    return NULL;
  }
  struct rgb prev = pix[0];
  int size = 0;
  for(int i=0; i<num_pix; ++i) {
    if(!rgbeq(pix[i],prev)) {
      ++size;
    }
    prev = pix[i];
    if(i==num_pix-1) {
      ++size;
    }
  }
  struct runlength *res = malloc(sizeof(runlength));
  int *lens = malloc(size*sizeof(int));
  struct rgb *colors = malloc(size*sizeof(struct rgb));
  prev = pix[0];
  int curr_len = 0;
  int curr_size = 0;
  for(int i=0; i<num_pix; ++i) {
    if(rgbeq(pix[i],prev)) {
      ++curr_len;
    } else {
      lens[curr_size] = curr_len;
      colors[curr_size] = prev;
      curr_len = 0;
      ++curr_size;
    }
    prev = pix[i];
    if(i==num_pix-1) {
      lens[curr_size] = curr_len;
      colors[curr_size] = prev;
    }
  }
  res->size = size;
  res->lens = lens;
  res->colors = colors;
  return res;
}      
int main(int argc, char*argv[])
{
  printf("P152v1");
  printf("  ");
  time_t timer = time(NULL);
  struct tm *time;
  time = localtime(&timer);
  putfour((unsigned int)(time->tm_mday + 100*time->tm_mon + 10000*time->tm_year));
  puttwo((unsigned int)(time->tm_min + 100*time->tm_hour));
  scanf("%s %d %d %d",buffer,&w,&h,&d);
  puttwo(w);
  puttwo(h);
  printf("    ");
  struct rgb *pix = malloc(w*h*sizeof(struct rgb));
  int is_grayscale = 1;
  for(int i=0; i<w*h; ++i) {
    scanf(" %c %c %c",&(pix[i].r),&(pix[i].g),&(pix[i].b));
    if(!(pix[i].r = pix[i].g = pix[i].b)) {
      is_grayscale = 0;
    }
  }
  if(is_grayscale == 1) {
    putchar(192);
  } else {
    putchar(128);
  }
  printf("   ");
  if(argc < 2) {
    printf("");
  } else {
    printf("%s",argv[1]);
  }
  for(int i=0; i<3; ++i) {
    putchar(0);
  }
  struct runlength *run = runlength(pix,w*h);
  putfour(run->size);
  for(int i=0; i<run->size; ++i) {
    putfour((run->lens)[i]);
  }
  if(is_grayscale == 0) {
    for(int i=0; i<run->size; ++i) {
      putfour((run->colors)[i].r);
    }
  } else {
    for(int i=0; i<run->size; ++i) {
      putfour((run->colors)[i].r);
      putfour((run->colors)[i].g);
      putfour((run->colors)[i].b);
    }
  }
  return 0;
}
