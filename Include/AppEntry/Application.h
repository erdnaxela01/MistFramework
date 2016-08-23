#pragma once

#include <cstdint>

namespace Mist
{
	namespace Detail
	{
		// Determines the specific success value for the application
		const int32_t APPLICATION_SUCCESS = 0;
	}

	// Summary: The Application class handles a unified application entry in order to avoid
	//			platform specific program entries. The Application is accessible through the AppEntry
	//			Method
	// Dependencies:	ErrorReturn
	//					Mist::String
	// Class Application
	//
	//	Public
	//	
	//	The mist string format will be renamed as CommandArgument
	//	The mist list format will be rename as CommandContainer
	//
	//  // Loads the c command arguments and stores them in a c++ object rather than c
	//	// char pointers.
	//	LoadCommandArguments
	//		Loop through all the commands
	//			Convert the current char pointer to our desired string format
	//			Add the converted string to our container
	//	
	//	// Invokes the App entry for the program
	//  // @Detail: This method invokes AppEntry defined under Mist as an extern
	//	//			This means that the AppEntry method must be defined somewhere in the program.
	//	//			The AppEntry method receives the application as a const reference for future use.
	//	//			The AppEntry signature is: Application::TerminationFlag AppEntry(const Application& application)
	//	ErrorReturn Application::TerminationFlag InvokeApplicationEntry
	//		Invoke AppEntry and pass a reference to this object
	//		return the value provided by AppEntry as an error return to mandate checking
	//
	//	// Returns a specified command argument based on the index of the command argument
	//	// @Detail: The reasoning behind returning the item based on the index is due to
	//	//			the added flexibility of keeping the interface opaque.
	//	Argument GetCommandArgument(index)
	//		Verify that the index doesn't go out of range
	//		if it does
	//			assert
	//		retrieve the argument from the container
	//		return the argument
	//
	//	// Returns the number of command arguments contained inside of the application
	//	Size GetNumberOfCommandArguments
	//		Retrieve the size of the container within
	//		Return the size
	//
	//	TerminationFlag
	//		NoReport = Detail::APPLICATION_SUCESS
	//		ReportedError
	//		UnknownError
	//		Warning
	//	
	//	Private
	//	
	//	Container of command arguments
	//	
}