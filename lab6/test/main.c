#include <stdio.h>
#include <math.h>

int main(){

  int i;
  double sum = 0;

  #pragma omp parallel for private(i), reduction(+:sum) 
  for(i=0; i < 50; i++){
    sum += 1;
  }

  printf("wynik: %f \n", sum);

  return 0;
}
