#include "../../Include/DynamicLibrary/PlatformDynamicLibraryExtensions.h"
#include <string>

namespace Mist
{
	namespace Detail
	{
		const String WINDOWS_DYNAMIC_LIBRARY_EXTENSION = ".dll";

		// Strips the windows extension if present from the library name
		String StripWindowsDynamicLibraryExtension(const String& libraryName);

		// Strip the platform specific dynamic library extensions from a library if present
		String StripPlatformDynamicLibraryExtensions(const String& libraryName)
		{
			String extensionlessLibraryName;

			// Windows
			extensionlessLibraryName = StripWindowsDynamicLibraryExtension(libraryName);

			return extensionlessLibraryName;
		}

		String StripWindowsDynamicLibraryExtension(const String& libraryName)
		{
			std::string stdLibraryName = ToStdString(libraryName);
			
			// Find the last period in the library name
			auto lastPeriod = stdLibraryName.find_last_of('.');

			// look for the extension starting at the last period
			auto extensionLocation = stdLibraryName.find(WINDOWS_DYNAMIC_LIBRARY_EXTENSION.ToCString(), lastPeriod - 1);

			// if we find it remove it
			if (extensionLocation != stdLibraryName.npos)
			{
				stdLibraryName.erase(extensionLocation, extensionLocation + WINDOWS_DYNAMIC_LIBRARY_EXTENSION.Size());
			}

			return stdLibraryName.c_str();
		}
	}
}