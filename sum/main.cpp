/*
   Changelog:
   0.0.1:
     - исправлена обработка переполнений
     - внедрнена обработка ошибок
     - добавлен вывод сообщений об ошибках на  stderr
     - вывод версии программы
 */
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "sum.h"
#include "utils.h"

const char version[] = "0.0.1";

int main(int argc, char* argv[]) {
	if(argc >= 2) {
		if(argc == 2) {
			if (strcmp("-V", argv[1]) == 0) {
				printf("%s\n", version);
				return EXIT_SUCCESS;
			}

			fprintf(stderr,"ошибка: неизвестный аргумент: '%s'\n", argv[1]);
			return EXIT_FAILURE;
		}
		fprintf(stderr,"ошибка: неправильное количество аргументов\n");
		return EXIT_FAILURE;
	}

	for(int i=0; i<argc; ++i) {
		fprintf(stdout, "argv[%d] = '%s'\n", i, argv[i]);

	}

	const size_t N=5;  //sizeof()*8;

	//uint8_t a[N] = { 0x10, 0x21, 0x45 };
  	uint8_t a[N] = { 0x10, 0x21, 0x45, 0x71, 0x01 };
   //uint8_t b[N] = { 0x47, 0xf3, 0xbd, 0x71 };
   	uint8_t b[N] = { 0x47, 0xf3, 0xbd, 0x71, 0xfa };
   	uint8_t r[N] = { 0x00 ,0x00, 0x00, 0x00, 0x00 };
   	uint8_t	expected[N] = { 0x57, 0x14, 0x03, 0x72 };
   	print_array("exp  ", expected, N);

    if (sum("Сумма", a, b, r, N) == -1) {
    	fprintf(stderr, "ошибка: переполнение\n");
    	return EXIT_FAILURE;
 	}
    printf("size(a)=%ld\n",sizeof(b[N]));

    return EXIT_SUCCESS;
}