#pragma once

#include "../String/String.h"

namespace Mist
{
	namespace Detail
	{
		// Strip the platform specific dynamic library extensions from a library if present
		String StripPlatformDynamicLibraryExtensions(const String& libraryName);
	}
}