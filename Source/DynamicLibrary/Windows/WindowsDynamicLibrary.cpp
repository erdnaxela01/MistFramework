#include "../../../Include/DynamicLibrary/Windows/WindowsDynamicLibrary.h"
#include <Windows.h>

namespace Mist
{
	namespace Detail
	{

	}

	WindowsDynamicLibrary::WindowsDynamicLibrary()
	{

	}

	WindowsDynamicLibrary::WindowsDynamicLibrary(WindowsDynamicLibrary&& otherLibrary)
	{
		Move(std::move(otherLibrary));
	}

	WindowsDynamicLibrary& WindowsDynamicLibrary::operator= (WindowsDynamicLibrary&& otherLibrary)
	{
		Move(std::move(otherLibrary));
		return *this;
	}

	WindowsDynamicLibrary::~WindowsDynamicLibrary()
	{
		CloseLibrary();
	}



	// Loads the platform specific dynamic library
	bool WindowsDynamicLibrary::LoadDynamicLibrary(String libraryName)
	{
		AppendWindowsExtension(&libraryName);
		m_Handle = LoadLibrary(libraryName.ToCString());
		return m_Handle != Detail::WINDOWS_NO_MODULE;
	}

	// Closes the library
	void WindowsDynamicLibrary::CloseLibrary()
	{
		if (m_Handle != Detail::WINDOWS_NO_MODULE)
		{
			FreeLibrary(m_Handle);
		}
	}

	void WindowsDynamicLibrary::Move(WindowsDynamicLibrary&& otherLibrary)
	{
		m_Handle = otherLibrary.m_Handle;
		otherLibrary.m_Handle = Detail::WINDOWS_NO_MODULE;
	}

	void WindowsDynamicLibrary::AppendWindowsExtension(String* libraryName)
	{
		*libraryName += ".dll";
	}
}