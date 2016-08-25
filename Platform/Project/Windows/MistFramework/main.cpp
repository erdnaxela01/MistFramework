#include <iostream>
#include "ErrorTests.h"
#include "ApplicationTest.h"

int main(int argc, const char** argv)
{
	RunErrorTests();
	RunApplicationTests();

	char c;
	std::cin >> c;
	return 0;
}
