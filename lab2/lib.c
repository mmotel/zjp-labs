#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void makeFileName(int pid, char *target){

  sprintf(target, "%d.out", pid);
//  strcat(target, ".out");
//  printf("%s\n", target);

}

double timespecDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
  double diff = (((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
           ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec));
  return diff / 1000000000;
}
