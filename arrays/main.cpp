/*
  Типы данных: Массивы
*/

#include <cstdio>
#include <cstdint>
#include "utils.h"

int main() {
  const size_t msize = 3;
  int m[msize] = { 3, 4, 5 };
  const int* p = & (m [0]); 
  for(size_t i = 0; i < msize; ++i) {
    printf("m[%zd]=%d, %d, %d\n", i,
      m[i],
      *(m+i),
      *(p+i)
    );
  }
  print_hexdump("m", m, sizeof(m));

	return 0;
}
