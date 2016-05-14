#include "ErrorTests.h"
#include "../../../../Include/ErrorReturn.h"

using namespace Mist;

ErrorReturn<int> SomeRoutine(bool shouldFail)
{
	if (shouldFail)
	{
		return MakeErrorReturn<int>(false);
	}
	else
	{
		return MakeErrorReturn(5, true);
	}
}


void RunErrorTests()
{

}