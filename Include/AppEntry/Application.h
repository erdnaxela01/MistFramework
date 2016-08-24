#pragma once

#include <cstdint>
#include "../String/String.h"
#include "../DynamicArray/DynamicArray.h"

#ifdef EXPORT_DLL
#define APPLICATION_DLL _declspec(dllexport)
#else
#define APPLICATION_DLL
#endif

namespace Mist
{
	namespace Detail
	{
		// Determines the specific success value for the application
		const int32_t APPLICATION_DLL APPLICATION_SUCCESS = 0;
	}


	// Summary: The Application class handles a unified application entry in order to avoid
	//			platform specific program entries. The Application is accessible through the AppEntry
	//			Method
	// Dependencies: Mist::String
	class APPLICATION_DLL Application
	{
	public:
		// Aliases
		using CommandCount		= int32_t;
		using CommandIndex		= int32_t;
		using CommandArgument	= String;
		using CommandContainer	= DynamicArray<CommandArgument>;
		//The mist list format will be rename as CommandContainer

		// The ways that the program can terminate
		enum TerminationFlag
		{
			NoReport = Detail::APPLICATION_SUCCESS,
			ReportedError,
			UnknownError,
			Warning,
		};

		// Loads the c command arguments and stores them in a c++ object rather than c
		// char pointers.
		void LoadCommandArguments(CommandCount argc, const char **argv);

		// Invokes the App entry for the program
		// @Detail: This method invokes AppEntry defined under Mist as an extern
		//			This means that the AppEntry method must be defined somewhere in the program.
		//			The AppEntry method receives the application as a const reference for future use.
		//			The AppEntry signature is: Application::TerminationFlag AppEntry(const Application& application)
		TerminationFlag InvokeApplicationEntry();

		// Returns a specified command argument based on the index of the command argument
		// @Detail: The reasoning behind returning the item based on the index is due to
		//			the added flexibility of keeping the interface opaque.
		CommandArgument GetCommandArgument(CommandCount index) const;

		// Returns the number of command arguments contained inside of the application
		CommandCount GetNumberOfCommandArguments() const noexcept;

	private:
		CommandContainer m_Commands;
	};

	extern Application::TerminationFlag APPLICATION_DLL AppEntry(const Application& application);
}