#include "../../ErrorHandling/ErrorReturn.h"
#include "../../String/String.h"

namespace Mist
{
	namespace Detail
	{

	}
	// Retrieves a routine from the library based on the routine's name
	template<typename RoutineType>
	ErrorReturn<RoutineType> WindowsDynamicLibrary::GetRoutine(String routineName)
	{
		if (m_Handle == Detail::WINDOWS_NO_MODULE)
		{
			return MakeErrorReturn<RoutineType>(false);
		}

		// Retrieve the routine from the windows system and convert it to our desired type
		auto routine = reinterpret_cast<RoutineType>(GetProcAddress(m_Handle, routineName.ToCString()));
		return MakeErrorReturn(routine, routine != Detail::WINDOWS_NO_ROUTINE);
	}
}