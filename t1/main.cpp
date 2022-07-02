/*
  Типы данных
*/

#include <cstdio>
#include <cstdint>

void print_hexdump(void const* data, size_t data_size);

/*
  Встроенные склалярные элементарные типы
  ---------------------------------------
  (signed,unsigned):
    char: 8bit => 2^8
      unsigned char: 0..255 (0..2^8-1)
      signed char: -128..+127 => -(2^7)..2^7-1
    short: 16bit => 2^16
      unsigned short: 0..65535
      signed short: 16384..-16383
    int: 8*4 = 32 => 2^32
      unsigned int: 0..2^32-1
      signed int = int: -(2^31) .. 2^31-1
    long: 8*8 = 64 => 2^64
      unsigned long int:
      signed long int:
    long long:
      signed long long int

  Библиотечные фиксированные скалярные типы
  -----------------------------------------

  #include <cstdint>

  uint8_t, int8_t
  uint16_t, int16_t
  uint32_t, int32_t
  uint64_t, int64_t

*/


int main() {
	int x = 0x04030201;
	static int g;
	printf("x = %d, 0x%8.8X, &x=%p\n", x, x, &x);
	printf("sizeof(int)=%zd\n", sizeof(int));
	printf("sizeof(x)=%zd\n", sizeof(x));
	print_hexdump(&x, sizeof(x));
	printf("sizeof(long)=%zd\n", sizeof(long));
	printf("sizeof(unsigned long)=%zd\n", sizeof(unsigned long));
	printf("sizeof(long long)=%zd\n", sizeof(signed long long int));
	printf("sizeof(int8_t)=%zd\n", sizeof(int8_t));
	printf("sizeof(int16_t)=%zd\n", sizeof(int16_t));
	printf("sizeof(int32_t)=%zd\n", sizeof(int32_t));
	printf("sizeof(int64_t)=%zd\n", sizeof(int64_t));
	printf("sizeof(size_t)=%zd\n", sizeof(size_t));
	printf("g=%d\n", g);


  printf("code(a)=%d, 0x%x\n", static_cast<unsigned int>('a'), static_cast<unsigned int>('a'));
  int const m[] = {1, 2, 3, 4, 5, 6, 7};
  size_t N=sizeof(m)/sizeof(m[0]);

  for(size_t i = 0; i<N; ++i) {
  	printf("%zd: %d\n", i, m[i]);
  }

	return 0;
}

void print_hexdump(void const* data, size_t data_size) {
	uint8_t const* p = static_cast<uint8_t const*>(data);

  printf("addr: %p:\n", p);
	for(size_t i = 0; i < data_size; ++i) {
		printf("  p[%zd]=0x%2.2X\n", i, p[i]);
	}
	printf("\n");
}
