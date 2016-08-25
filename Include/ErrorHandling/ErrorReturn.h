#pragma once

#ifdef EXPORT_DLL
#define ERROR_DLL _declspec(dllexport)
#else
#define ERROR_DLL
#endif

namespace Mist
{
	namespace Detail
	{

	}

	// Summary: The Error return class is used to return a value along with an error checking mechanism,
	//			The class aims to require the checking of the error before capturing the value. The user may also
	//			retrieve the value without checking the error however he has to be explicit about it.
	template<typename ReturnType, typename ValidationType = bool>
	class ERROR_DLL ErrorReturn
	{
	public:
		using ValidationCallback = bool(*)(ValidationType validation);

		// Build the error return from both the return and the validation
		ErrorReturn(ReturnType returnValue, ValidationType validation);

		// Build the error return from only the validation, this is to indicate that there was an error
		ErrorReturn(ValidationType validation);

		// Copy operations
		ErrorReturn(const ErrorReturn& other);
		ErrorReturn& operator=(const ErrorReturn& other);

		// Move operations
		ErrorReturn(ErrorReturn&& other);
		ErrorReturn& operator=(ErrorReturn&& other);

		// Indicates if there was an error or not
		// @Detail: Flips the verification flag to indicate the error
		//			has been verified
		bool Verify() const;

		// Retrieve the constructed return value
		// @Detail: This routine uses verification in order to assure
		//			that the error has been verified.
		ReturnType Get();

		// An accessors function that provides the user 
		// with the opportunity to do more processing with the error
		ValidationType GetError() const;

		// Retrieve the return value without validation
		// @Detail: This routine does not use verification
		//			which means the value might be garbage.
		ReturnType UnsafeGet();

		// Set the validation callback for the verification of the error return value
		void SetValidationCallback(ValidationCallback validationCallback);

	private:
		ReturnType					m_ReturnValue;
		ValidationType				m_Validation;
		mutable bool				m_IsVerified;

		ValidationCallback			m_ValidationCallback;

	};


	// Builds an error return for convenient returning of errors
	template<typename ReturnType, typename ValidationType>
	ErrorReturn<ReturnType, ValidationType> MakeErrorReturn(ReturnType returnValue, ValidationType validation);

	// Builds an error return for convenient returning of errors
	template<typename ReturnType, typename ValidationType = bool>
	ErrorReturn<ReturnType, ValidationType> MakeErrorReturn(ValidationType validation);
}

// Include the template definitions
#include "ErrorReturn.inl"