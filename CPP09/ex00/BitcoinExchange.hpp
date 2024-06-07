#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <unistd.h>

class BitcoinExchange
{
private:

	// The DataBase
	static const std::string _data_filename;

	// The Query File
	std::string _filename;

	// Bitcoin Data
	std::map<size_t, double> _map;

	BitcoinExchange(); // Not allowed

	void readDataFile();
	void readQueryFile();

public:

	BitcoinExchange(const std::string &_filename);
	~BitcoinExchange();

	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

};