#pragma once

#include "DynamicLibraryTemplate.h"
#include "../PlatformDefines.h"
#include "../PlatformIncludes.h"

namespace Mist
{
	namespace Detail
	{

	}

#ifdef MIST_WINDOWS
	using DynamicLibrary = DynamicLibraryTemplate<float>;
#else

#endif
}
