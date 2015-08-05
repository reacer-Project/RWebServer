

#include "testCase.h"
#include <iostream>

int Foo(int a,int b){
	return a+b;
}

REACER_TEST(FooTest_PassDemo){
	EXPECT_EQ(3,Foo(1,2));
	EXPECT_EQ(2,Foo(1,1));
}
REACER_TEST(FooTest_FailDemo){
	EXPECT_EQ(4,Foo(1,2));
	EXPECT_EQ(2,Foo(1,2));
}

int main(int argc,char **argv){
	return RUN_ALL_TESTS();
}
