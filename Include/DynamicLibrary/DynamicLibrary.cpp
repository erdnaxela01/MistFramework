#include "DynamicLibrary.h"

namespace Mist
{
	namespace Detail
	{

	}

	ErrorReturn<DynamicLibrary> LoadDynamicLibrary(String libraryName)
	{
		DynamicLibrary requestedLibrary;
		auto loadResult = requestedLibrary.LoadDynamicLibrary(libraryName);
		return MakeErrorReturn(std::move(requestedLibrary), loadResult);
	}
}