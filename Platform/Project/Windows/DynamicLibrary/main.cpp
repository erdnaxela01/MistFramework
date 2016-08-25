#include "../../../../Include/DynamicLibrary/DynamicLibrary.h"

#include <iostream>

int main()
{
	auto libraryResult = Mist::LoadDynamicLibrary("vulkan-1");
	

	if (libraryResult.Verify())
	{
		std::cout << "Success" << std::endl;
		auto library = libraryResult.Get();
		
		auto routineResult = library.GetRoutine<int(*)(int, const char**)>("vkGetInstanceProcAddr");
		if (routineResult.Verify())
		{
			const char** stuff = nullptr;
			//routineResult.Get()(0, stuff);
		}
	}

	char c;
	std::cin >> c;

	return 0;
}