#include "../../Include/String/String.h"

namespace Mist
{
	namespace Detail
	{

	}

	// Construct an empty string
	String::String()
	{

	}

	// Copy the string from another string
	String::String(const String& otherString) : m_String(otherString.m_String)
	{

	}


	String& String::operator= (const String& otherString)
	{
		m_String = otherString.m_String;
		return *this;
	}

	// Move the string from another string
	String::String(String&& otherString) noexcept : m_String(std::move(otherString.m_String))
	{

	}


	String& String::operator= (String&& otherString) noexcept
	{
		m_String = std::move(otherString.m_String);
		return *this;
	}

	// Build the string from a c string
	String::String(const char* cString) : m_String(cString)
	{

	}

	String& String::operator= (const char* cString)
	{
		m_String = cString;
		return *this;
	}

	// Replace the current string with a character
	String& String::operator= (char character)
	{
		m_String = character;
		return *this;
	}



	// Return the number of characters in the string
	String::StringSize String::Size() const noexcept
	{
		return m_String.size();
	}

	// Return the maximum size that the string can reach
	String::StringSize String::MaximumSize() const noexcept
	{
		return m_String.max_size();
	}

	// Set the size of the string
	void String::Resize(StringSize desiredSize)
	{
		m_String.resize(desiredSize);
	}

	// remove all data in the string
	void String::Erase() noexcept
	{
		m_String.clear();
	}

	bool String::IsEmpty() const noexcept
	{
		return m_String.empty();
	}

	// Retrieve the character at the specified index
	char& String::operator[] (StringIndex pos)
	{
		return m_String[pos];
	}

	const char& String::operator[] (StringIndex pos) const
	{
		return m_String[pos];
	}



	// Add another string to this string
	String& String::operator+= (const String& rightString)
	{
		m_String += rightString.m_String;
		return *this;
	}

	// Add a char string to this string
	String& String::operator+= (const char* rightCString)
	{
		m_String += rightCString;
		return *this;
	}

	// Add a character to this string
	String& String::operator+= (char character)
	{
		m_String += character;
		return *this;
	}


	
	const char* String::ToCString() const
	{
		return m_String.c_str();
	}

	std::string ToStdString(const String& conversionTarget)
	{
		return conversionTarget.ToCString();
	}
}