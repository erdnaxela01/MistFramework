#include "DynamicLibraryTests.h"
#include "../../../../Include/DynamicLibrary/DynamicLibrary.h"

#include <iostream>

void RunDynamicLibraryTests()
{
	auto library = Mist::LoadDynamicLibrary("vulkan-1");
	if (library.Verify())
	{
		std::cout << "Library Successfully opened" << std::endl;
		auto vulkanLibrary = library.Get();
		auto procResult = vulkanLibrary.GetRoutine("vkGetInstanceProcAddr");
		if (procResult.Verify())
		{
			std::cout << "Routine successfully acquired" << std::endl;
		}
		procResult = vulkanLibrary.GetRoutine("NotARealRoutine");
		if (procResult.Verify() == false)
		{
			std::cout << "Routine successfully failed" << std::endl;
		}
	}
	library = Mist::LoadDynamicLibrary("NotARealLibrary");
	if (library.Verify() == false)
	{
		std::cout << "Library successfully failed" << std::endl;
	}
}