#pragma once

#include "DynamicLibraryTemplate.h"
#include "../String/String.h"
#include "../ErrorHandling/ErrorReturn.h"
#include "../PlatformDefines.h"

#ifdef MIST_WINDOWS

#include "Windows\WindowsDynamicLibrary.h"
namespace Mist
{
	using DynamicLibrary = DynamicLibraryTemplate<WindowsDynamicLibrary>;
}

#else

#endif

namespace Mist
{
	namespace Detail
	{
	}

	// Load a dynamic library and return it if it loaded
	ErrorReturn<DynamicLibrary> LoadDynamicLibrary(String libraryName);


}

