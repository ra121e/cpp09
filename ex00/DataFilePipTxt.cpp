#include "DataFilePipTxt.hpp"
#include <iostream>
#include <sstream>
#include <map>

DataFilePipTxt::DataFilePipTxt()
{}

DataFilePipTxt::DataFilePipTxt(std::string &header_format) :
	_header_format(header_format)
{}

DataFilePipTxt::DataFilePipTxt(const DataFilePipTxt &other) :
	_header_format(other._header_format)
{}

DataFilePipTxt	&DataFilePipTxt::operator=(const DataFilePipTxt &other)
{
	if (this != &other)
	{
		this->_header_format = other._header_format;
	}
	return (*this);
}

DataFilePipTxt::~DataFilePipTxt()
{}

void	DataFilePipTxt::parseFile(const std::string &filename)
{
	std::ifstream	ifs(filename.c_str());
	std::string		line;

	if (!ifs.is_open())
	{
		std::cerr << "error: file not open.";
	}

	std::getline(ifs, line);
	if (line != "date | value\n" && line != "date | value")
	{
		std::cerr << "Warning: header is not the expected format `date | value`." << std::endl;
	}

	while (std::getline(ifs, line))
	{
		if (ifs.fail() || line.empty())
			continue ;

		std::stringstream	ss(line);
		std::string	date;
		std::getline(ss, date, '|');
		if (ss.fail() || ss.eof() || date.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		date = trim(date);
		if (date.empty())
			continue ;

		if (!validate_date(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}

		std::string	num;
		std::getline(ss, num);
		if (ss.fail() || !ss.eof() || num.empty())
			continue ;
		num = trim(num);
		if (num.empty())
			continue ;

		std::stringstream	sss(num);
		double				value;
		sss >> value;
		if (sss.fail() || !sss.eof())
		{
			std::cerr << "Error: bad input => " << num << std::endl;
			continue ;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		else if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}

		double rate;
		std::map<std::string, double>::const_iterator it = _ratemap.lower_bound(date);
		if (it == _ratemap.end())
		{
			if (_ratemap.empty())
			{
				std::cout << "date is beyond the last date in the database, or database is empty." << std::endl;
				continue ;
			}
			rate = (--it)->second;
		}
		if (it->first == date)
		{
			rate = it->second;
		}
		else if (it->first != date && it == _ratemap.begin())
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		else
		{
			rate = (--it)->second;
		}
		double	total = value * rate;
		std::cout << date << " => " << num << " = " << total << std::endl;
	}

}
