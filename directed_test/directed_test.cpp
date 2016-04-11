// directed_test.cpp : Defines the entry point for the console application.
//

#include "gtest\gtest.h"
#include "graph_test.h"

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	std::cin.get();
	return 0;
}