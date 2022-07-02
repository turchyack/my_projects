#include <cstdio>
#include <cstdint>
#include "print_binary.h"

void print_binary1(unsigned a);

int main() {
	uint8_t a = 2;
	uint16_t b = 10;
	unsigned int c = a + b;
	unsigned int d = b + a;
	uint8_t e = a + b;


	printf("d(~)=%x\n", d);

	print_binary(b);
	for(int i = 0; i < 8; ++i) {
		print_binary1(1<<i);
	}
	print_binary1(0x55 | 0xffffffff);
	print_binary1((0x55 | 0xff000000) ^ 0x20000000);
}

void print_binary1(unsigned a) {
	const int nbits = sizeof(a)*8;
    for(int i = 0; i < nbits; ++i) {
    	int v = (a >> (nbits-i-1)) & 1;
    	printf("%d", v);
    }
    printf("\n");
}