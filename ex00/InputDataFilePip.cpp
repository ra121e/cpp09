#include "InputDataFilePip.hpp"
#include "FileUtils.hpp"
#include <iostream>
#include <sstream>
#include <map>

InputDataFilePip::InputDataFilePip()
{}

InputDataFilePip::InputDataFilePip(const std::string &header_format) :
	_header_format(header_format),
	_ready(false)
{}

InputDataFilePip::InputDataFilePip(const InputDataFilePip &other) :
	BaseDataFile(other),
	_header_format(other._header_format),
	_ready(other._ready)
{}

InputDataFilePip	&InputDataFilePip::operator=(const InputDataFilePip &other)
{
	if (this != &other)
	{
		this->_header_format = other._header_format;
		this->_ready = other._ready;
	}
	return (*this);
}

InputDataFilePip::~InputDataFilePip()
{}

void	InputDataFilePip::parseFile(const std::string &filename)
{
	std::string		line;

	if (this->_ifs.is_open())
		this->_ifs.close();
	_ifs.open(filename.c_str());

	if (!_ifs.is_open())
	{
		throw std::ios_base::failure("File could not be opened");
	}

	std::getline(_ifs, line);
	if (line != _header_format && line != _header_format + "\n")
	{
		std::cerr << "Warning: header is not the expected format `date | value`." << std::endl;
	}
	_ready = true;
}

bool	InputDataFilePip::readNextDateAmount(Date &date, double &amount)
{
	std::string				line;

	if (!_ready)
	{
		throw std::runtime_error("Error: File not initialized. Call initialize() before reading data.");
	}
	while (std::getline(_ifs, line))
	{
		if (_ifs.fail() || line.empty())
			continue ;

		std::stringstream	ss(line);
		std::string	date_str;
		std::getline(ss, date_str, '|');
		if (ss.fail() || ss.eof() || date_str.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		std::string trimmed_date_str = FileUtils::trim(date_str);
		date.setDateStr(trimmed_date_str);
		if (trimmed_date_str.empty())
			continue ;

		if (!FileUtils::validateDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}

		std::string	num_str;
		std::getline(ss, num_str);
		if (ss.fail() || !ss.eof() || num_str.empty())
			continue ;
		num_str = FileUtils::trim(num_str);
		if (num_str.empty())
			continue ;

		std::stringstream	sss(num_str);
		sss >> amount;
		if (sss.fail() || !sss.eof())
		{
			std::cerr << "Error: bad input => " << num_str << std::endl;
			continue ;
		}
		if (amount < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		else if (amount > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}

		return (true);
	}
	return (false);
}
