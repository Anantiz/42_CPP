#include "Data.hpp"

/* ######################################################################### */
/* CONSTRUCTORS */


Data::Data(std::string str)
{
	content = str;
}

Data::~Data() {}

Data::Data(const Data &right)
{
	content = right.content;

}
Data &Data::operator=(const Data &right)
{
	content = right.content;

	return *this;
}

/* ######################################################################### */


