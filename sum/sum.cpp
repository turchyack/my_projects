#include <cstdint>
#include <cstdio>
#include <math.h>
#include "sum.h"
#include "utils.h"

int sum(const char* title, uint8_t const* a, uint8_t const* b, uint8_t* r, size_t N) {
    print_array("a[N]=", a, N);
    print_array("b[N]=", b, N);

    for(size_t i=0; i < N; ++i) {
		unsigned x = a[i] + b[i];
		r[i] += x;

		if (x > 255) {
			if(i >= N-1) {
				return -1;
			}

			r[i+1] = r[i+1]+1;
    	}
    }

	print_array(title, r, N);

	return 0;
}

void print_array(const char* title, uint8_t const* v, size_t N) {
	printf("%s:", title);
	for(size_t i = N; i > 0 ; --i) {
		printf(" %2.2x", v[i-1]);
	}
	printf("\n");
}