#include "InputDataFilePip.hpp"
#include <iostream>
#include <sstream>
#include <map>

InputDataFilePip::InputDataFilePip()
{}

InputDataFilePip::InputDataFilePip(const std::string &header_format, const std::map<std::string, double> &ratemap) :
	_header_format(header_format),
	_ratemap(ratemap)
{}

InputDataFilePip::InputDataFilePip(const InputDataFilePip &other) :
	BaseDataFile(other),
	_header_format(other._header_format),
	_ratemap(other._ratemap)
{}

InputDataFilePip	&InputDataFilePip::operator=(const InputDataFilePip &other)
{
	if (this != &other)
	{
		this->_header_format = other._header_format;
		this->_ratemap = other._ratemap;
	}
	return (*this);
}

InputDataFilePip::~InputDataFilePip()
{}

void	InputDataFilePip::parseFile(const std::string &filename)
{
	std::ifstream	ifs(filename.c_str());
	std::string		line;

	if (!ifs.is_open())
	{
		throw std::ios_base::failure("File could not be opened");
	}

	std::getline(ifs, line);
	if (line != _header_format && line != _header_format + "\n")
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

		if (this->_ratemap.empty())
		{
			std::cerr << "Error: no rate available." << std::endl;
			continue ;
		}
		double rate;
		std::map<std::string, double>::const_iterator it = _ratemap.lower_bound(date);
		if (it == _ratemap.end())
		{
			--it;
			rate = it->second;
		}
		else if (it->first == date)
		{
			rate = it->second;
		}
		else
		{
			if (it == _ratemap.begin())
			{
				std::cerr << "Error: no rate available before this date." << std::endl;
				continue ;
			}
			--it;
			rate = it->second;
		}
		double	total = value * rate;
		std::cout << date << " => " << num << " = " << total << std::endl;
	}

}
