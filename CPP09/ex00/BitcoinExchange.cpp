#include "BitcoinExchange.hpp"

// Stupid syntax when a MACRO could just have worked the same way
// At least it's a nice showoff
const std::string BitcoinExchange::_data_filename = "data.csv";

BitcoinExchange::BitcoinExchange(){} // Not allowed
BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string &_filename) : _filename(_filename)
{
	if (access(_filename.c_str(), R_OK) == -1)
	{
		throw std::runtime_error("Error: file not found or not readable");
	}
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	_filename = other._filename;
	return *this;
}

/////////////////////////////////////////////////
/// PARSING
//////
//


static void parseQueryLine(std::ifstream &file)
{
	bool first_line = true;
	std::string line;
	while (std::getline(file, line))
	{
		if (first_line)
		{
			if (line != "date | value")
				throw std::runtime_error("Error: invalid query file format");
			first_line = false;
			continue;
		}
		{
			// Date format: "YYYY-MM-DD" length: 10
			// Fulll format is "YYYY-MM-DD | VALUE" length: at least 14

			size_t	year = 0;
			size_t	month = 0;
			size_t	day = 0;
			double	value = 0;

			// Method, check for 4 digits followed by a '-' etc...
			if (line.length() < 14)
				throw std::runtime_error("Error: invalid query file format");
			for (int i=0; i<3 ; i++)
			{
				if (!isdigit(line[i]))
					throw std::runtime_error("Error: invalid query file format");
				year += (line[i] - '0') * (1000 / (i + 1));
			}
			if (line[4] != '-')
				throw std::runtime_error("Error: invalid query file format");
			for (int i=0; i<2 ; i++)
			{
				if (!isdigit(line[i + 5]))
					throw std::runtime_error("Error: invalid query file format");
				month += (line[i + 5] - '0') * (10 / (i + 1));
			}
			if (line[7] != '-')
				throw std::runtime_error("Error: invalid query file format");
			for (int i=0; i<2 ; i++)
			{
				if (!isdigit(line[i + 8]))
					throw std::runtime_error("Error: invalid query file format");
				day += (line[i + 8] - '0') * (10 / (i + 1));
			}
			if (line[10] != ' ')
				throw std::runtime_error("Error: invalid query file format");
			if (line[11] != '|')
				throw std::runtime_error("Error: invalid query file format");
			if (line[12] != ' ')
				throw std::runtime_error("Error: invalid query file format");
			// Now we have a date, just check that the following is a valid double and we're good
			bool dot = false;
			for(int i=12; line[i]; i++)
			{
				if (!isdigit(line[i]) && line[i] != '.')
					throw std::runtime_error("Error: invalid query file format");
				if (line[i] == '.')
				{
					if (dot)
						throw std::runtime_error("Error: invalid query file format");
					dot = true;
				}
			}
			value = std::atof(&(line.c_str())[12]);
		}
	}
}

void BitcoinExchange::readQueryFile()
{
	std::ifstream file(_data_filename);
	if (!file.is_open())
	{
		throw std::runtime_error("Error: query file not found or not readable");
	}
	parseQueryLine(file);
}