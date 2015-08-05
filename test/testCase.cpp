
#include <iostream>
#include "testCase.h"
UnitTest* UnitTest::getInstance(){
	static UnitTest instance;
	return &instance;
}
TestCase* UnitTest::registerTestCase(TestCase *testcase){
	testcases.push_back(testcase);
	return testcase;	
}
int UnitTest::run()
{
	nTestResult = 1;
	for(std::vector<TestCase*>::iterator it=testcases.begin();it!=testcases.end();++it)
	{
		TestCase *testcase = *it;
		currentTestCase = testcase;
		std::cout << GREEN << "===================="<<std::endl;
		std::cout << GREEN << "Run TestCase:"<< testcase->testcase_name<<std::endl;
		testcase->run();
		std::cout << GREEN << "End TestCase:"<<testcase->testcase_name<<std::endl;
		if(testcase->nTestResult)
			nPassed++;
		else
		{
			nFailed++;
			nTestResult=0;
		}
	}
	std::cout << GREEN << "========================"<< std::endl;
	std::cout << GREEN << "Total TestCase:"<< nPassed+nFailed<<std::endl;
	std::cout << GREEN << "Passed:"<<nPassed<<std::endl;
	std::cout << RED << "Failed:"<<nFailed<< std::endl;
	return nTestResult;	
}


