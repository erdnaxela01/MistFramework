#pragma once

#include "../../String/String.h"
#include "../../PlatformIncludes.h"
#include "../../ErrorHandling/ErrorReturn.h"

#include <cstdint>

namespace Mist
{
	namespace Detail
	{
		using WindowsLibraryHandle = HMODULE;
		const WindowsLibraryHandle WINDOWS_NO_MODULE = NULL;
		
		using RoutineReturnType = void*;
		const RoutineReturnType WINDOWS_NO_ROUTINE = nullptr;
	}

	// Summary: This is the implementation for the windows dynamic library, if opens a library and retrieves
	//			routines as expected
	class WindowsDynamicLibrary
	{
	public:
		WindowsDynamicLibrary();

		WindowsDynamicLibrary(const WindowsDynamicLibrary&) = delete;
		WindowsDynamicLibrary& operator= (const WindowsDynamicLibrary&) = delete;

		WindowsDynamicLibrary(WindowsDynamicLibrary&&);
		WindowsDynamicLibrary& operator= (WindowsDynamicLibrary&&);

		~WindowsDynamicLibrary();



		// Loads the platform specific dynamic library
		bool LoadDynamicLibrary(String libraryName);

		// Retrieves a routine from the library based on the routine's name
		template<typename RoutineType = void*>
		ErrorReturn<RoutineType> GetRoutine(String routineName);

		// Closes the library
		void CloseLibrary();

	private:

		Detail::WindowsLibraryHandle m_Handle = Detail::WINDOWS_NO_MODULE;

		// Implements the moving semantics
		void Move(WindowsDynamicLibrary&& otherLibrary);



		// append our platform specific extension
		static void AppendWindowsExtension(String* libraryName);
	};
}

#include "WindowsDynamicLibrary.inl"
