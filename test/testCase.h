
#ifndef TESTCASE_H
#define TESTCASE_H
#include <string>
#include <vector>
#define GREEN "\033[32m"
#define RED "\033[31m"
class TestCase{
public:
	TestCase(const char *case_name):testcase_name(case_name){}
	virtual void run()=0;
	virtual ~TestCase(){}
	int nTestResult;
	std::string testcase_name;
};

class UnitTest{
public:
	static UnitTest *getInstance();
	TestCase *registerTestCase(TestCase *testcase);
	int run();
	TestCase *currentTestCase;
	int nTestResult;
	int nPassed;
	int nFailed;
protected:
	std::vector<TestCase *> testcases;
};

#define TESTCASE_NAME(testcase_name) \
	testcase_name##_TEST

#define REACER_TEST(testcase_name) \
	class TESTCASE_NAME(testcase_name):public TestCase\
{\
public:\
	TESTCASE_NAME(testcase_name)(const char *case_name):TestCase(case_name){};\
	~TESTCASE_NAME(testcase_name)(){}\
	virtual void run();\
private:\
	static TestCase* const testcase;\
};\
\
TestCase* const TESTCASE_NAME(testcase_name)\
	::testcase=UnitTest::getInstance()->registerTestCase(\
		new TESTCASE_NAME(testcase_name)(#testcase_name));\
void TESTCASE_NAME(testcase_name)::run()

//#define NTEST(testase_name)\
//	REACER_TEST(testcase_name)

#define RUN_ALL_TESTS()\
	UnitTest::getInstance()->run();

#define EXPECT_EQ(m,n)\
	if(m != n)\
	{\
		UnitTest::getInstance()->currentTestCase->nTestResult=0;\
		std::cout << RED << "Failed"<< std::endl;\
		std::cout << RED << "Expect:"<< m << std::endl;\
		std::cout << RED << "Actual:"<< n << std::endl;\
	}

#endif
