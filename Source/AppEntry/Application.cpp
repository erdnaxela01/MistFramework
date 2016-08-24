#include "../../Include/AppEntry/Application.h"

#include <cassert>

namespace Mist
{
	namespace Detail
	{

	}

	void Application::LoadCommandArguments(Application::CommandCount argc, const char **argv)
	{
		// Loop through all the commands
		for (CommandCount index = 0; index < argc; index++)
		{
			// Convert the current char pointer to our desired string format
			CommandArgument argument = argv[index];
			// Add the converted string to our container
			m_Commands.PushBack(argument);
		}
	}

	Application::TerminationFlag Application::InvokeApplicationEntry()
	{
		// Invoke AppEntry and pass a reference to this object
		Application::TerminationFlag flag = AppEntry(*this);
		// return the value provided by AppEntry
		return flag;
	}

	Application::CommandArgument Application::GetCommandArgument(Application::CommandCount index) const
	{
		//Verify that the index doesn't go out of range
		if (index >= m_Commands.Size())
		{
			//	if it does
			//		assert
			assert(false);
		}
		//	retrieve the argument from the container
		//	return the argument
		return m_Commands[index];
	}

	Application::CommandCount Application::GetNumberOfCommandArguments() const noexcept
	{
		// Retrieve the size of the container within
		// Return the size
		return m_Commands.Size();
	}
}