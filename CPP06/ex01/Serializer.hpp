#pragma once

#include <iostream>
#include <cctype>
#include <stdint.h>
#include <cstdlib>
#include <iomanip>

#include "Data.hpp"

class Serializer
{
private:

	Serializer();
	~Serializer();
	Serializer(const Serializer &cpy);
	Serializer	&operator=(const Serializer &right);

public:

	//It takes a pointer and converts it to the unsigned integer type uintptr_t.
	static uintptr_t serialize(Data* ptr);

	//It takes an unsigned integer parameter and converts it to a pointer to Data.
	static Data* deserialize(uintptr_t raw);
};