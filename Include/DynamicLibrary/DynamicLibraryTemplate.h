#pragma once

#include "../String/String.h"
#include "../ErrorHandling/ErrorReturn.h"

#ifdef EXPORT_DLL
#define DYNAMIC_LIBRARY_DLL _declspec(dllexport)
#else
#define DYNAMIC_LIBRARY_DLL
#endif

namespace Mist
{
	namespace Detail
	{

	}

	// Summary: The dynamic library template class acts as an interface to multiple different
	//			dynamic library implementations based on different platforms. The reasoning behind
	//			using static polymorphism such as templates is due to the ability of defining a 
	//			dynamic library without using a heap allocation and pointers while still maintaining
	//			a interface requirement. Hopefully, as concepts are implemented in c++, the class will
	//			provide better error messages as to the problems defined by the implementation class
	template<typename Implementation>
	class DYNAMIC_LIBRARY_DLL DynamicLibraryTemplate
	{
	public:
		using ImplementationType = Implementation;

		DynamicLibraryTemplate() = default;

		DynamicLibraryTemplate(const DynamicLibraryTemplate&)				= delete;
		DynamicLibraryTemplate& operator= (const DynamicLibraryTemplate&)	= delete;

		DynamicLibraryTemplate(DynamicLibraryTemplate&&);
		DynamicLibraryTemplate& operator= (DynamicLibraryTemplate&&);

		~DynamicLibraryTemplate() = default;



		// Loads the platform specific dynamic library
		bool LoadDynamicLibrary(String libraryName);

		// Retrieves a routine from the library based on the routine's name
		template<typename RoutineType = void*>
		RoutineType GetRoutine(String routineName);

		// Closes the library
		void CloseLibrary();


		// Retrieve the implementation for platform specific use
		template<typename DesiredImplementation>
		ErrorReturn<ImplementationType&> GetImplementation();
	private:
		ImplementationType m_Implementation;
	};

}

#include "DynamicLibraryTemplate.inl"