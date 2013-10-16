#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

#include "lib.h"

int main(int argc, char **argv){

  if( argc < 3 ){
    printf("To few arguments\n");
    return -1;
  }

  struct timespec start, end, start2, end2;

  int i, j, pid, dataPart;

  int sum = 0;
  int finalSum = 0;

  int *tab;

  FILE *f;

  char fname[15];
  char f2name[15];

  int size = atoi(argv[1]);
  int procs = atoi(argv[2]);

  if( size < 1 || procs < 1 ) {
    return -2;
  }

  tab = (int*) malloc( size * sizeof(int) );

  for(i=0; i < size; i++){
    tab[i] = 1;
  }

  /*for(i=0; i < size; i++){
    printf("[ %d ] ", tab[i]);
  }
  printf("\n");*/

  clock_gettime(CLOCK_MONOTONIC, &start);

  for(i = 0; i < procs; i++){
    
    pid = fork();
    if( pid > 0 ){
     // printf("parent : %d\n", getpid());
    }
    else if( pid == 0 ){
    //PROCES POTOMNY
      clock_gettime(CLOCK_MONOTONIC, &start2);

      //printf("%d : %d \n", i, getpid());
      
      //printf("%d: < %d , %d )\n", i, i * size / procs, (i+1) * size / procs);
      for(j = i * size / procs ; j <(i+1) * size / procs; j++){
        sum += tab[j];
      }
      //printf("suma z %d = %d\n", i, sum);

      makeFileName(getpid(), fname);

      f = fopen(fname, "wa");
      fprintf(f, "%d", sum);
      fclose(f);

      //printf("koniec %d : %d\n", i, getpid());

      clock_gettime(CLOCK_MONOTONIC, &end2);
      printf("time%d: %.16f\n", i, timespecDiff(&end2, &start2));
      
      return 0;
    } //KONIEC PROCESU POTOMNEGO
    
  }
  
  for(i =0; i < procs; i++){
    pid = wait(NULL);
    makeFileName(pid, f2name);
    f= fopen(f2name, "r");
    fscanf(f, "%d", &dataPart);
    finalSum += dataPart;
  }

  printf("suma: %d\n", finalSum);

  clock_gettime(CLOCK_MONOTONIC, &end);
  printf("time:  %.16f\n", timespecDiff(&end, &start));

  free(tab);

  return 0;
}
