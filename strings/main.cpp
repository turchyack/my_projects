#include <cstdio>

int main() {
	char const s[] = "abcdef";

    // s:0xabcde00 = "abcdef"
	printf("s = \"%s\"\n", s);
	printf("addr(s) = %p, &s = %p, &s[0] = %p\n", s, &s, &s[0]);
	for(size_t i = 0; i < sizeof(s)/sizeof(s[0]); ++i) {
		printf("%zd: '%c', 0x%x\n", i, s[i], s[i]);
	}
	int a = 176;
	int *p1 = &a;
	int *p2 = p1;
	int *p3 = p2;
	printf("sizeof(a)=%zd, &a = %p, a = %d\n", sizeof(a), &a, a);
  a = 13;
    // * - оператор разыменования, обращение к значению по адресу
	printf("p1=%p, &p1=%p, *p1=%d\n", p1, &p1, *p1);
	printf("p2=%p, &p2=%p, *p2=%d\n", p2, &p2, *p2);
	printf("p3=%p, &p3=%p, *p3=%d\n", p3, &p3, *p3);
	int** pp = &p1;
	printf("pp=%p, *pp=%p, **pp=%d\n", pp, *pp, **pp);
	int m[3] = {10, 11, 12};
	size_t i = 0;
	int* p = &m[0];

	printf("m[%zd]: %d, %d\n", i, p[i], *(p+i)); ++i;
	printf("m[%zd]: %d, %d\n", i, p[i], *(p+i)); ++i;
	printf("m[%zd]: %d, %d\n", i, p[i], *(p+i)); ++i;

    p = &m[0];
	for(size_t i = 0; i<sizeof(m)/sizeof(m[0]); ++i, ++p) {
		printf("*p=%d\n", *p);
	}

}
