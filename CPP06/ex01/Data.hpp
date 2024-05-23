#pragma once

#include <iostream>
#include <string>

class Data
{
public:

	std::string	content;

	Data(std::string str);
	~Data();
	Data(const Data &right);
	Data &operator=(const Data &right);
};