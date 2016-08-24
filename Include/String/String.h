#pragma once

#include <cstdint>
#include <string>

#ifdef EXPORT_DLL
#define STRING_DLL _declspec(dllexport)
#else
#define STRING_DLL
#endif

namespace Mist
{
	namespace Detail
	{
		
	}

	// Summary:	The Mist string class is used as an abstraction layer between the framework
	//			and the user. Abstracting away which string class is being used.
	class STRING_DLL String
	{
	public:
		using StringSize = int32_t;
		using StringIndex = int32_t;

		// Construct an empty string
		String();

		// Copy the string from another string
		String(const String& otherString);
		String& operator= (const String& otherString);

		// Move the string from another string
		String(String&& otherString) noexcept;
		String& operator= (String&& otherString) noexcept;

		// Build the string from a c string
		String(const char* cString);
		String& operator= (const char* cString);

		// Replace the current string with a character
		String& operator= (char character);



		// Return the number of characters in the string
		StringSize Size() const noexcept;

		// Return the maximum size that the string can reach
		StringSize MaximumSize() const noexcept;
		
		// Set the size of the string
		void Resize(StringSize desiredSize);

		// remove all data in the string
		void Erase() noexcept;

		bool IsEmpty() const noexcept;

		// Retrieve the character at the specified index
		char& operator[] (StringIndex pos);
		const char& operator[] (StringIndex pos) const;



		// Add another string to this string
		String& operator+= (const String& rightString);
		
		// Add a char string to this string
		String& operator+= (const char* rightCString);
		
		// Add a character to this string
		String& operator+= (char character);



		// Convert the String to a c char array
		const char* ToCString() const;

	private:
		using StringImplementation = std::string;

		StringImplementation m_String;
		
	};

	// Helper Methods
	std::string ToStdString(const String& conversionTarget);

}