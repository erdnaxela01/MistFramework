#include "../ErrorHandling/ErrorReturn.h"
#include <type_traits>

namespace Mist
{
	namespace Detail
	{

	}

	template<typename Implementation>
	DynamicLibraryTemplate<Implementation>::DynamicLibraryTemplate(DynamicLibraryTemplate&& otherLibrary) : m_Implementation(std::move(otherLibrary.m_Implementation))
	{

	}

	template<typename Implementation>
	DynamicLibraryTemplate<Implementation>& DynamicLibraryTemplate<Implementation>::operator= (DynamicLibraryTemplate&& otherLibrary)
	{
		m_Implentation = std::move(otherLibrary.m_Implementation);
	}

	template<typename Implementation>
	bool DynamicLibraryTemplate<Implementation>::LoadDynamicLibrary(String libraryName)
	{
		return m_Implementation.LoadDynamicLibrary(libraryName);
	}

	template<typename Implementation>
	template<typename RoutineType>
	RoutineType DynamicLibraryTemplate<Implementation>::GetRoutine(String routineName)
	{
		return m_Implentation.GetRoutine<RoutineType>(routineName);
	}

	template<typename Implementation>
	void DynamicLibraryTemplate<Implementation>::CloseLibrary()
	{
		m_Implementation.CloseLibrary();
	}

	template<typename Implementation>
	template<typename DesiredImplementation>
	ErrorReturn<Implementation&> DynamicLibraryTemplate<Implementation>::GetImplementation()
	{
		return MakeErrorReturn<Implementation&>(m_Implementation, std::is_same<Implementation, DesiredImplementation>::value);
	}
}