#if !defined(__TESTCORE_TESTRUNNER_H_INCLUDED)
#define __TESTCORE_TESTRUNNER_H_INCLUDED

enum class ReturnCode {
	Success,
	Fail
};
struct TestStat {
	unsigned total_count = 0;
	unsigned fail_count = 0;
};
typedef ReturnCode TestFunc_t();

void run_all_tests(TestFunc_t* tfs[], TestStat *st);


#endif