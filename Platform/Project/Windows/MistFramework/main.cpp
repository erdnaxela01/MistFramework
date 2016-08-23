#include "../../../../Include/ErrorHandling/ErrorReturn.h"
#include "../../../../Include/AppEntry/Application.h"

#include <iostream>
#include "ErrorTests.h"

namespace Mist
{
	Application::TerminationFlag AppEntry(const Application& application)
	{
		std::cout << "Application Invoked" << std::endl;
		return Application::NoReport;
	}
}

int main()
{
	RunErrorTests();
	Mist::Application app;
	app.InvokeApplicationEntry();

	char c;
	std::cin >> c;
	return 0;
}