#include "ApplicationTest.h"
#include "../../../../Include/AppEntry/Application.h"

#include <iostream>

namespace Mist
{
	Application::TerminationFlag AppEntry(const Application& application)
	{
		std::cout << "Application Invoked" << std::endl;
		for (int i = 0; i < application.GetNumberOfCommandArguments(); i++)
		{
			std::cout << ToStdString(application.GetCommandArgument(i)) << std::endl;
		}
		return Application::NoReport;
	}
}

void RunApplicationTests()
{
	Mist::Application app;
	
	const int MAX_ARGS = 3;
	const char* args[MAX_ARGS];
	for (int i = 0; i < MAX_ARGS; i++)
	{
		args[i] = "Arguments";
	}

	app.LoadCommandArguments(MAX_ARGS, &args[0]);

	Mist::Application::TerminationFlag result = app.InvokeApplicationEntry();
	if (result == Mist::Detail::APPLICATION_SUCCESS)
	{
		std::cout << "No failure on exit" << std::endl;
	}
	else
	{
		std::cout << "Unsafe Termination Error Code: " << result << std::endl;
	}
}