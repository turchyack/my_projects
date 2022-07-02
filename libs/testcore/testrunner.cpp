#include <testcore/testrunner.h>
//#include <cstddef>
void run_test(TestFunc_t* tf, TestStat *st) {
	ReturnCode tn = tf();
	if (tn == ReturnCode::Fail) {
		st->fail_count += 1;
	}  
	st->total_count += 1;	
}

void run_all_tests(TestFunc_t* tfs[], TestStat *st) {

	for(size_t i = 0; tfs[i] != 0; ++i) {
		run_test(tfs[i], st);
	}
}	

