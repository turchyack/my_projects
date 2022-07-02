#if !defined(__SUM_H_INCLUDED)
#define __SUM_H_INCLUDED

#include <cstdint>
/*return:
	 0 -  ошибок нет
	-1 - переполнение



*/
int sum(const char* title, uint8_t const* a, uint8_t const* b, uint8_t* result, size_t operand_size_bytes);

#endif