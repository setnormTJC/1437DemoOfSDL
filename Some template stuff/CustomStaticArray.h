#pragma once

template<typename SomeDataType, int size> 
class CustomStaticArray
{
	//C-style 
	SomeDataType cStyleArray[size]; 

public: 
	CustomStaticArray() = delete; 
	CustomStaticArray(SomeDataType initialValueOfAllArrayElements)
	{
		for (int i = 0; i < size; ++i)
		{
			cStyleArray[i] = initialValueOfAllArrayElements;
		}
	}
};