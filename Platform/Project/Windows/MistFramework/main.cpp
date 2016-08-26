#include <iostream>
#include "ErrorTests.h"
#include "ApplicationTest.h"
#include "DynamicLibraryTests.h"

int main(int argc, const char** argv)
{
	RunErrorTests();
	RunApplicationTests();
	RunDynamicLibraryTests();

	char c;
	std::cin >> c;
	return 0;
}
