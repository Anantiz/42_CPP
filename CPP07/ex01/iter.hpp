#pragma once

#include <iostream>
#include <string>

/*
Implement a function template iter that takes 3 parameters and returns nothing.
• The first parameter is the address of an array.
• The second one is the length of the array.
• The third one is a function that will be called on every element of the array.

Your iter function template must work with any type of array. The third parameter
can be an instantiated function template.w
*/
template <typename T>
void InternationalThermonuclearExperimentalReactor(T arr[], size_t len, void (*f)(T))
{
	if (!len || !arr || !f)
		return ;

	for (size_t i=0; i < len; i++)
	{
		f(arr[i]);
	}
}

template<typename Ty> void test(Ty x)
{
	std::cout << "  " << x << std::endl;
}