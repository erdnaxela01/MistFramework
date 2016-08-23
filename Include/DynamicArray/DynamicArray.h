#pragma once

#include <cstdint>
#include <vector>

#ifdef EXPORT_DLL
#define ARRAY_DLL _declspec(dllexport)
#else
#define ARRAY_DLL
#endif

namespace Mist
{
	namespace Detail
	{

	}

	template<typename ArrayType>
	class ARRAY_DLL DynamicArray
	{
	public:
		using DynamicArraySize	= int32_t;
		using DynamicArrayIndex = int32_t;
		using ContainedType		= ArrayType;

		// Construct an empty dynamic array
		DynamicArray();

		// Construct a dynamic array with the specified size
		explicit DynamicArray(DynamicArraySize desiredSize);
		
		// Copy one array into the other
		DynamicArray(const DynamicArray& otherArray);
		DynamicArray& operator= (const DynamicArray& otherArray);

		// move one array into the other
		DynamicArray(DynamicArray&& otherArray);
		DynamicArray& operator= (DynamicArray&& otherArray);


		// Return the size of the array
		DynamicArraySize Size() const noexcept;

		// Return the maximum size that the array can be
		DynamicArraySize MaximumSize() const noexcept;

		// Size the array to the desired size
		void Resize(DynamicArraySize desiredSize);

		// reset the array to 0
		void Erase();

		// verify if the array is empty
		bool IsEmpty() const noexcept;

		// append an object to the back of the array
		void PushBack(const ContainedType& val);
		void PushBack(ContainedType&& val);

		// Remove the last element of the array
		void PopBack();

		// Retrieve the character at the specified index
		ContainedType& operator[] (DynamicArrayIndex pos);
		const ContainedType& operator[] (DynamicArrayIndex pos) const;

		// Retrieve the character at the back
		ContainedType& Back(DynamicArrayIndex pos);
		const ContainedType& Back(DynamicArrayIndex pos) const;

		// Retrieve the character at the front
		ContainedType& Front(DynamicArrayIndex pos);
		const ContainedType& Front(DynamicArrayIndex pos) const;

	private:
		using ArrayImplementation = std::vector<ContainedType>;

		ArrayImplementation m_DynamicArray;

	};
}

#include "DynamicArray.inl"
