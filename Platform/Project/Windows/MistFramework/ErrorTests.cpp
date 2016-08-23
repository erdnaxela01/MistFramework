#include "ErrorTests.h"
#include "../../../../Include/ErrorHandling/ErrorReturn.h"

#include <iostream>

using namespace Mist;

ErrorReturn<int> SomeRoutine(bool shouldFail)
{
	if (shouldFail)
	{
		return MakeErrorReturn<int>(false);
	}
	else
	{
		return MakeErrorReturn(5);
	}
}

template<typename ErrorReturn>
void CheckError(ErrorReturn&& error, bool crash = false)
{
	if (crash)
	{
		error.Get();
	}

	if(error.Verify())
	{
		std::cout << "Error check successful"	<< std::endl;
		std::cout << error.Get()				<< std::endl;
		std::cout << error.UnsafeGet()			<< std::endl;
		std::cout << error.GetError()			<< std::endl;
	}
	else
	{
		std::cout << "Error has occurred"		<< std::endl;
		std::cout << error.Get()				<< std::endl;
		std::cout << error.UnsafeGet()			<< std::endl;
		std::cout << error.GetError()			<< std::endl;

	}
}


void RunErrorTests()
{
	auto failedResult		= SomeRoutine(true);
	CheckError(failedResult);

	auto successfulResult	= SomeRoutine(false);
	CheckError(successfulResult);

}