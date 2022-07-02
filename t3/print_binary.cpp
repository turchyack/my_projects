/*print_binary(char result, unsigned a){

}*/

#include <cstdio>


void print_binary(unsigned a) {
	unsigned x = 0;
	size_t n = 0;
	const size_t N = sizeof(a)*8;
	int m[N];

	while(a > 0){
		x = a % 2;
		a = a / 2;
		m[n] = x;
		++n;
	}

	for(size_t i=n-1; i>0; --i) {
		printf("%d", m[i]);
	}

	printf("\n");
}

