#include "BitcoinExchange.hpp"

// Stupid syntax when a MACRO could just have worked the same way
// At least it's a nice showoff
const std::string BitcoinExchange::_data_filename = "data.csv";
const size_t BitcoinExchange::month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

BitcoinExchange::BitcoinExchange(){} // Not allowed
BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string &query_filename) : _query_filename(query_filename)
{
	_line_number = 0;
	readDataFile();
	readQueryFile();
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	_query_filename = other._query_filename;
	return *this;
}

/////////////////////////////////////////////////
/// PARSING
//////
//


inline static bool is_bisextile(size_t year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

/*
	Returns the Number of days since the Baby Jesus was born at the given date
*/
size_t BitcoinExchange::get_total_days(size_t year, size_t month, size_t day) const
{
	size_t total_days = day;

	// Add all months up to the current one
	for (size_t i = 0; i < month - 1; i++)
	{
		total_days += month_days[i];
	}
	// Add 1 days if we are in a bisextile year and after February
	if (is_bisextile(year) && month > 2)
		total_days++;
	total_days += (year - 1) * 365; // add years
	// Add bisextile days
	total_days += ((year - 1) / 4) - (((year - 1) / 100 ) + ((year - 1) / 400));
	return total_days;
}

#define VALUE_INDEXB 13

void BitcoinExchange::parseQueryLine(std::ifstream &file)
{
	_line_number = 0;
	bool first_line = true;
	std::string line;
	while (std::getline(file, line))
	{
		_line_number++;
		if (first_line)
		{
			if (line != "date | value")
				{std::cerr << "Error: \"" << line << "\""<< std::endl;throw std::runtime_error(BAD_FORMAT);}
			first_line = false;
			continue;
		}

		// Date format: "YYYY-MM-DD" length: 10
		// Fulll format is "YYYY-MM-DD | VALUE" length: at least 14
		size_t	year = 0;
		size_t	month = 0;
		size_t	day = 0;
		double	quantity = 0;

		// Method, check for 4 digits followed by a '-' etc...
		if (line.length() < 14)
			{std::cerr << "l." << _line_number << " Error: date format or no value" << std::endl;continue;}
		for (size_t i=0; i<4 ; i++)
		{
			if (!isdigit(line[i]))
				{std::cerr << "Error: Bad date format" << std::endl;continue;}
			year *= 10;
			year += (line[i] - '0');
		}
		if (line[4] != '-')
			{std::cerr << "Error: Bad date format" << std::endl;continue;}
		for (size_t i=0; i<2 ; i++)
		{
			if (!isdigit(line[i + 5]))
				{std::cerr << "Error: Bad date format" << std::endl;continue;}
			month *= 10;
			month += (line[i + 5] - '0');
		}
		if (month > 12)
			{std::cerr << "Error: Bad date format" << std::endl;continue;}
		if (line[7] != '-')
			{std::cerr << "Error: Bad date format" << std::endl;continue;}
		for (size_t i=0; i<2 ; i++)
		{
			if (!isdigit(line[i + 8]))
				{std::cerr << "Error: Bad date format" << std::endl;continue;}
			day *= 10;
			day += (line[i + 8] - '0');
		}
		if (day > BitcoinExchange::month_days[month - 1])
		{
			if (month == 2 && day == 29 && is_bisextile(year))
				;
			else
				{std::cerr << "Error: Bad date format" << std::endl;continue;}
		}
		if (line[10] != ' ' && line[11] != '|' && line[12] != ' ')
		{
			{std::cerr << "l." << _line_number << " Error: bad format" << std::endl;continue;}
		}

		// Now we have a date, just check that the following is a valid double and we're good
		bool dot = false;
		for(size_t i=VALUE_INDEXB; line[i]; i++)
		{
			if (!isdigit(line[i]) && line[i] != '.')
			{
				{std::cerr << "Error: Bad value format" << std::endl;continue;}
			}
			if (line[i] == '.')
			{
				if (dot)
				{
					{std::cerr << "Error: Bad value format" << std::endl;continue;}
				}
				dot = true;
			}
		}
		quantity = std::atof(&(line.c_str())[VALUE_INDEXB]);

		if (quantity < 0 || quantity > 1000)
			{std::cerr << "Error: Value out of range" << std::endl;continue;}
		size_t baby_jesus_age = get_total_days(year, month, day);
		howMuch(baby_jesus_age, quantity, year, month, day);
}

}
#define VALUE_INDEX 11

void BitcoinExchange::parseDataLine(std::ifstream &file)
{
	bool first_line = true;
	std::string line;
	while (std::getline(file, line))
	{
		_line_number++;
		if (first_line)
		{
			if (line != "date,exchange_rate")
				{std::cerr << "Error: \"" << line << "\""<< std::endl;throw std::runtime_error(BAD_FORMAT);}
			first_line = false;
			continue;
		}

		// Date format: "YYYY-MM-DD" length: 10
		// Fulll format is "YYYY-MM-DD | VALUE" length: at least 14
		size_t	year = 0;
		size_t	month = 0;
		size_t	day = 0;
		double	value = 0;

		// Method, check for 4 digits followed by a '-' etc...
		if (line.length() < 12)
			{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error(BAD_FORMAT);}
		for (size_t i=0; i<4 ; i++)
		{
			if (!isdigit(line[i]))
				{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error(BAD_FORMAT);}
			year *= 10;
			year += (line[i] - '0');
		}
		if (line[4] != '-')
			{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error(BAD_FORMAT);}
		for (size_t i=0; i<2 ; i++)
		{
			if (!isdigit(line[i + 5]))
				{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error(BAD_FORMAT);}
			month *= 10;
			month += (line[i + 5] - '0');
		}
		if (month > 12)
			{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error(BAD_FORMAT);}
		if (line[7] != '-')
			{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error(BAD_FORMAT);}
		for (size_t i=0; i<2 ; i++)
		{
			if (!isdigit(line[i + 8]))
				{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error(BAD_FORMAT);}
			day *= 10;
			day += (line[i + 8] - '0');
		}
		if (day > BitcoinExchange::month_days[month - 1])
		{
			if (month == 2 && day == 29 && is_bisextile(year))
				;
			else
				{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error(BAD_FORMAT);}
		}
		if (line[10] != ',')
		{
			{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error(BAD_FORMAT);}
		}

		// Now we have a date, just check that the following is a valid double and we're good
		bool dot = false;
		for(size_t i=VALUE_INDEX; line[i]; i++)
		{
			if (!isdigit(line[i]) && line[i] != '.')
			{
				{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error(BAD_FORMAT);}
			}
			if (line[i] == '.')
			{
				if (dot)
				{
					{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error(BAD_FORMAT);};
				}
				dot = true;
			}
		}

		value = std::atof(&(line.c_str())[VALUE_INDEX]);
		// if (value < 0 || value > 1000)
		// 	{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error("Error: value out of range");}
		size_t baby_jesus_age = get_total_days(year, month, day);
		if (_map.find(baby_jesus_age) == _map.end())
			_map[baby_jesus_age] = value;
		else
			{std::cerr << "l." << _line_number << " Error: \"" << line << "\"" << "Y-M-D: " << year << "-" << month << "-" << day << std::endl;throw std::runtime_error("Error: duplicate date in query file");}
		// std::cout << "l." << _line_number << " Y-M-D: " << year << "-" << month << "-" << day << " Value: " << value << std::endl;
	}
}

void BitcoinExchange::readDataFile()
{
	std::ifstream file(_data_filename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: Data file not found or not readable");
	}
	parseDataLine(file);
}

void BitcoinExchange::readQueryFile()
{
	std::ifstream file(_query_filename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: query file not found or not readable");
	}
	parseQueryLine(file);
}

void	BitcoinExchange::howMuch(size_t days_since_baby_jesus_birth, double quantity, size_t year, size_t month, size_t day) const
{
	bool done = false;
	for (iterator it = _map.begin(); it != _map.end(); it++)
	{
		if (it->first == days_since_baby_jesus_birth)
		{
			std::cout << year << "-" << ((month < 10) ? "0" : "") << month << "-" << ((day < 10) ? "0" : "") << day << "=> " << quantity << " => " << (it->second * quantity) << std::endl;
			done = true;
			break;
		}
		if (it->first > days_since_baby_jesus_birth)
		{
			if (it == _map.begin())
				break;
			it--;
			std::cout << year << "-" << ((month < 10) ? "0" : "") << month << "-" << ((day < 10) ? "0" : "") << day << "=> " << quantity << " => " << (it->second * quantity) << std::endl;
			done = true;
			break;
		}
	}
	if (!done)
	{
		std::cout << year << "-" << ((month < 10) ? "0" : "") << month << "-" << ((day < 10) ? "0" : "") << day << ": No data available" << std::endl;
	}
}
