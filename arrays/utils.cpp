/*
  Вспомогательные функции
*/

#include <cstdio>
#include <cstdint>


void print_hexdump(const char* title, void const* data, size_t data_size) {
	uint8_t const* p = static_cast<uint8_t const*>(data);

  printf("%s(addr: %p):\n  ", title, p);
	for(size_t i = 0; i < data_size; ++i) {
		printf("%2.2X", p[i]);
	}
	printf("\n");
}
