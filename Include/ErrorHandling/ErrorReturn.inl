#include <cassert>

namespace Mist
{
	namespace Detail
	{
		// This is the default validation callback
		// @Detail: It assumes the validation type acts as a bool would
		template<typename ValidationType>
		bool DefaultValidationCallback(ValidationType validation)
		{
			return validation;
		}
	}

	template<typename ReturnType, typename ValidationType>
	ErrorReturn<ReturnType, ValidationType>::ErrorReturn(ReturnType returnValue, ValidationType validation) :
		m_ReturnValue(std::forward<ReturnType>(returnValue)),
		m_Validation(std::forward<ValidationType>(validation)),
		m_IsVerified(false),
		m_ValidationCallback(&Detail::DefaultValidationCallback<ValidationType>)
	{
		// Does nothing
	}

	// Build the error return from only the validation, this is to indicate that there was an error
	template<typename ReturnType, typename ValidationType>
	ErrorReturn<ReturnType, ValidationType>::ErrorReturn(ValidationType validation) :
		m_ReturnValue(),
		m_Validation(std::forward<ValidationType>(validation)),
		m_IsVerified(false),
		m_ValidationCallback(&Detail::DefaultValidationCallback<ValidationType>)
	{

	}

	template<typename ReturnType, typename ValidationType>
	ErrorReturn<ReturnType, ValidationType>::ErrorReturn(const ErrorReturn& other) : 
		m_ReturnValue(other.m_ReturnValue),
		m_Validation(other.m_Validation),
		m_IsVerified(other.m_IsVerified),
		m_ValidationCallback(other.m_ValidationCallback)
	{
		// Does nothing
	}

	template<typename ReturnType, typename ValidationType>
	ErrorReturn<ReturnType, ValidationType>& ErrorReturn<ReturnType, ValidationType>::operator=(const ErrorReturn& other)
	{
		// Copy all of the data into our own
		m_ReturnValue = other.m_ReturnValue;
		m_Validation = other.m_Validation;
		m_IsVerified = other.m_IsVerified;
		m_ValidationCallback = other.m_ValidationCallback;
	}

	template<typename ReturnType, typename ValidationType>
	ErrorReturn<ReturnType, ValidationType>::ErrorReturn(ErrorReturn&& other) :
		m_ReturnValue(std::forward<ReturnType>(other.m_ReturnValue)),
		m_Validation(std::forward<ValidationType>(other.m_Validation)),
		m_IsVerified(other.m_IsVerified),
		m_ValidationCallback(other.m_ValidationCallback)
	{

	}

	template<typename ReturnType, typename ValidationType>
	ErrorReturn<ReturnType, ValidationType>& ErrorReturn<ReturnType, ValidationType>::operator=(ErrorReturn&& other)
	{
		// Move all of the data into our own class
		m_ReturnValue = std::move(other.m_ReturnValue);
		m_Validation = std::move(other.m_Validation);
		m_IsVerified = other.m_IsVerified;
		m_ValidationCallback = other.m_ValidationCallback;
	}

	template<typename ReturnType, typename ValidationType>
	bool ErrorReturn<ReturnType, ValidationType>::Verify() const
	{
		m_IsVerified = true;
		return m_ValidationCallback(m_Validation);
	}

	template<typename ReturnType, typename ValidationType>
	ReturnType ErrorReturn<ReturnType, ValidationType>::Get()
	{
		assert(m_IsVerified);
		return std::forward<ReturnType>(m_ReturnValue);
	}

	template<typename ReturnType, typename ValidationType>
	ValidationType ErrorReturn<ReturnType, ValidationType>::GetError() const
	{
		return m_Validation;
	}

	template<typename ReturnType, typename ValidationType>
	ReturnType ErrorReturn<ReturnType, ValidationType>::UnsafeGet()
	{
		return m_ReturnValue;
	}

	template<typename ReturnType, typename ValidationType>
	void ErrorReturn<ReturnType, ValidationType>::SetValidationCallback(ValidationCallback validationCallback)
	{
		m_ValidationCallback = validationCallback;
	}

	// Builds an error return for convenient returning of errors
	template<typename ReturnType, typename ValidationType>
	ErrorReturn<ReturnType, ValidationType> MakeErrorReturn(ReturnType returnValue, ValidationType validation)
	{
		// Create the error return and return it to the caller
		ErrorReturn<ReturnType, ValidationType> errorToReturn(returnValue, validation);
		return std::move(errorToReturn);
	}

	template<typename ReturnType>
	ErrorReturn<ReturnType, bool> MakeErrorReturn(ReturnType returnValue, bool validation = true)
	{
		// Create the error return and return it to the caller
		ErrorReturn<ReturnType, bool> errorToReturn(returnValue, validation);
		return std::move(errorToReturn);
	}

	// Builds an error return for convenient returning of errors
	template<typename ReturnType, typename ValidationType>
	ErrorReturn<ReturnType, ValidationType> MakeErrorReturn(ValidationType validation)
	{
		// create the error return and return it to the caller
		ErrorReturn<ReturnType, ValidationType> errorToReturn(validation);
		return std::move(errorToReturn);
	}
}