#include "../../../../Include/DynamicLibrary/DynamicLibrary.h"

#include <iostream>

int main()
{
	Mist::DynamicLibrary library;
	auto returnType = library.GetImplementation<float>();

	if (returnType.Verify())
	{
		std::cout << "Success" << std::endl;
		std::cout << returnType.Get() << std::endl;
	}

	char c;
	std::cin >> c;

	return 0;
}