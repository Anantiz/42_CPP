#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <stdexcept>
#include <cstdlib>

#define BAD_FORMAT "Bad file format"

class BitcoinExchange
{
private:

	typedef std::map<size_t, double>::const_iterator iterator;

	// The DataBase
	static const std::string _data_filename;
	size_t	_line_number;

	// The Query File
	std::string _query_filename;

	// Bitcoin Data
	std::map<size_t, double> _map;

	BitcoinExchange(); // Not allowed

	void howMuch(size_t days_since_baby_jesus_birth, double quantity, size_t year, size_t month, size_t day) const;


	void parseQueryLine(std::ifstream &file);
	void parseDataLine(std::ifstream &file);

	void readDataFile();
	void readQueryFile();

public:
	static const size_t month_days[];

	BitcoinExchange(const std::string &_filename);
	~BitcoinExchange();

	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	size_t get_total_days(size_t year, size_t month, size_t day) const;

	double	getValue(const size_t days_since_baby_jesus_birth) const;
};