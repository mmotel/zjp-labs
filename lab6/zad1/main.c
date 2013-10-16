#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(){

  long int i; 
  long int n =100000000;
  long long int sum = 0;
  int *tab = malloc( n * sizeof(int) );

  srand( 151013 );
  #pragma omp parallel for private(i), shared(tab)
  for(i=0; i < n; i++){
    tab[i] = rand() % 100;
   // printf("[ %d ] ", tab[i]);
  }
  //printf("\n");

  #pragma omp parallel for private(i), reduction(+:sum) 
  for(i=0; i < n; i++){
   sum += tab[i];
   // printf("[ %d ] ", tab[i]);
  }
 // printf("\n");

  printf("wynik: %lld\n", sum);

  free(tab);

  return 0;
}
