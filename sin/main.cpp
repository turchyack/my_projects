//Задачка по алгоритмам 

#include <cstdio>
#include <cstdint>
#include <cmath>
int main() {
  double b;
  double x = 0;
  for(int i = 0;i < 15000000; ++i) {
    x += 0.0000001; 
    b = 1 - x + sin(x) - log(1 + x);
    if(b < 0.00001 and b > 0) {
      printf("х%d = %lf\n", i, x);  
      printf("вывожу решение уравнения b = %lf\n", b);   
    }
  }
	return 0;
}
