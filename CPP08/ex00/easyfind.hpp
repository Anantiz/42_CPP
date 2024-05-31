#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(T a, int b)
{
	if (std::find(a.begin(), a.end(), b) == a.end())
		std::cout << "Element not found" << std::endl;
	else
		std::cout << "Element found" << std::endl;
}