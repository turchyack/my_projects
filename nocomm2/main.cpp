#include <cstddef>
#include <cmath>
#include <cstdio>
#define PI 3.14



int main(){

size_t N = 40;
double S = 0;
double h = (PI*4/5-PI/5)/N;
double x = h;

printf("h = %f\n", h);
while(x <= 4*PI/5){
  for(size_t i = 1; i <= N; ++i) {
    S = S + pow(-1, i + 1) * sin(i * x)/i;

  }

  printf("S = %f; x = %f; ", S, x);

  double y = x/2;

  printf("y = %f;\n", y);

  x = x + h;

}

}
