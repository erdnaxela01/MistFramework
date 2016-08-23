
namespace Mist
{
	namespace Detail
	{

	}

	template<typename ArrayType>
	DynamicArray<ArrayType>::DynamicArray()
	{

	}

	template<typename ArrayType>
	DynamicArray<ArrayType>::DynamicArray(typename DynamicArray<ArrayType>::DynamicArraySize desiredSize) : m_DynamicArray(desiredSize)
	{

	}

	template<typename ArrayType>
	DynamicArray<ArrayType>::DynamicArray(const DynamicArray& otherArray) : m_DynamicArray(otherArray.m_DynamicArray)
	{

	}

	template<typename ArrayType>
	DynamicArray<ArrayType>& DynamicArray<ArrayType>::operator= (const DynamicArray& otherArray)
	{
		m_DynamicArray = otherArray.m_DynamicArray;
		return *this;
	}

	template<typename ArrayType>
	DynamicArray<ArrayType>::DynamicArray(DynamicArray&& otherArray) : m_DynamicArray(otherArray.m_DynamicArray)
	{

	}

	template<typename ArrayType>
	DynamicArray<ArrayType>& DynamicArray<ArrayType>::operator= (DynamicArray&& otherArray)
	{
		m_DynamicArray = otherArray.m_DynamicArray;
		return *this;
	}


	template<typename ArrayType>
	typename DynamicArray<ArrayType>::DynamicArraySize DynamicArray<ArrayType>::Size() const noexcept
	{
		return m_DynamicArray.size();
	}

	template<typename ArrayType>
	typename DynamicArray<ArrayType>::DynamicArraySize DynamicArray<ArrayType>::MaximumSize() const noexcept
	{
		return m_DynamicArray.max_size();
	}

	template<typename ArrayType>
	void DynamicArray<ArrayType>::Resize(DynamicArraySize desiredSize)
	{
		m_DynamicArray.resize(desiredSize);
	}

	template<typename ArrayType>
	void DynamicArray<ArrayType>::Erase()
	{
		m_DynamicArray.clear();
	}

	template<typename ArrayType>
	bool DynamicArray<ArrayType>::IsEmpty() const noexcept
	{
		return m_DynamicArray.empty();
	}

	template<typename ArrayType>
	void DynamicArray<ArrayType>::PushBack(const typename DynamicArray<ArrayType>::ContainedType& val)
	{
		m_DynamicArray.push_back(val);
	}

	template<typename ArrayType>
	void DynamicArray<ArrayType>::PushBack(typename DynamicArray<ArrayType>::ContainedType&& val)
	{
		m_DynamicArray.push_back(val);
	}

	template<typename ArrayType>
	void DynamicArray<ArrayType>::PopBack()
	{
		m_DynamicArray.pop_back();
	}

	template<typename ArrayType>
	typename DynamicArray<ArrayType>::ContainedType& DynamicArray<ArrayType>::operator[] (DynamicArrayIndex pos)
	{
		return m_DynamicArray[pos];
	}

	template<typename ArrayType>
	const typename DynamicArray<ArrayType>::ContainedType& DynamicArray<ArrayType>::operator[] (DynamicArrayIndex pos) const
	{
		return m_DynamicArray[pos];
	}

	template<typename ArrayType>
	typename DynamicArray<ArrayType>::ContainedType& DynamicArray<ArrayType>::Back(DynamicArrayIndex pos)
	{
		return m_DynamicArray.back();
	}

	template<typename ArrayType>
	const typename DynamicArray<ArrayType>::ContainedType& DynamicArray<ArrayType>::Back(DynamicArrayIndex pos) const
	{
		return m_DynamicArray.back();
	}

	template<typename ArrayType>
	typename DynamicArray<ArrayType>::ContainedType& DynamicArray<ArrayType>::Front(DynamicArrayIndex pos)
	{
		return m_DynamicArray.front();
	}

	template<typename ArrayType>
	const typename DynamicArray<ArrayType>::ContainedType& DynamicArray<ArrayType>::Front(DynamicArrayIndex pos) const
	{
		return m_DynamicArray.front();
	}
}