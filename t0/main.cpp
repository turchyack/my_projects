/*
  CPP* -preprocessor-> PP* -compiler-> OBJ* -linker-> ELF
*/

#include <cstdio>
#include "f1.h"


int main() {
	int x = f1(0);

	printf("x = %d\n", x);

	return x;
}

