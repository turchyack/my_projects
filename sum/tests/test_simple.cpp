#include <cstdio>
#include <cstdlib>
#include <testcore/testrunner.h>

ReturnCode test1() { return  ReturnCode::Fail; }
ReturnCode test2() { return  ReturnCode::Success; }
ReturnCode test3() { return  ReturnCode::Fail; }

int main(void) {
	TestStat test_stat;
	TestFunc_t* test_funcs[] = {
		&test1,
		&test2,
		&test3,
		0,
	};
	run_all_tests(test_funcs, &test_stat);
	printf("Tests: total: %u, success: %u, failed: %u\n",
		test_stat.total_count,
		test_stat.total_count - test_stat.fail_count, 
		test_stat.fail_count);

	if(test_stat.fail_count > 0) {
		printf("Failed");
		return EXIT_FAILURE;
	}
	else {
		printf("Success");
		return EXIT_SUCCESS;
	}	

}
