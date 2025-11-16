#include "HistoricalDataFileCSV.hpp"
#include <iostream>
#include <sstream>
#include <map>

std::map<std::string, double>	HistoricalDataFileCSV::getRateMap() const
{
	return (this->_ratemap);
}

void	HistoricalDataFileCSV::parseFile(const std::string &filename)
{
	std::ifstream	ifs(filename.c_str());
	if (!ifs.is_open())
	{
		throw std::ios_base::failure("File could not be opened");
	}
	std::string	line;
	std::getline(ifs, line);
	if (line != _header_format && line != _header_format + "\n")
	{
		throw std::runtime_error("error: header is not valid.");
	}

	std::map<std::string, double>	tmp;
	size_t	errorCount = 0;
	while (std::getline(ifs, line))
	{
		std::stringstream ss(line);
		std::string	date_str;
		std::string	rate_str;
		double		rate_double;

		std::getline(ss, date_str, ',');
		if (date_str.empty() || ss.fail() || ss.eof())
		{
			std::cerr << "error: cannot read date correctly." << std::endl;
			errorCount++;
			continue ;
		}
		date_str = BaseDataFile::trim(date_str);
		if (date_str.empty())
		{
			std::cerr << "error: invalid date format." << std::endl;
			errorCount++;
			continue ;
		}
		if (!validate_date(date_str))
		{
			std::cerr << "error: invalid date format." << std::endl;
			errorCount++;
			continue ;
		}
		std::getline(ss, rate_str);
		if (rate_str.empty() || ss.fail() || !ss.eof())
		{
			std::cerr << "error: cannot read rate correctly." << std::endl;
			errorCount++;
			continue ;
		}

		std::stringstream ss_rate(rate_str);
		ss_rate >> rate_double;
		if (ss_rate.fail() || !ss_rate.eof())
		{
			std::cerr << "error: cannot convert rate to double." << std::endl;
			errorCount++;
			continue ;
		}
		if (rate_double < 0)
		{
			std::cerr << "error: rate cannot be negative." << std::endl;
			errorCount++;
			continue ;
		}
		if (tmp.find(date_str) != tmp.end())
		{
			std::cerr << "error: duplicate date entry." << std::endl;
			errorCount++;
			continue ;
		}
		tmp[date_str] = rate_double;
	}
	ifs.close();
	if (tmp.empty())
	{
		std::cerr << "error: no valid data found." << std::endl;
	}
	if (errorCount > 0)
	{
		std::cerr << "error: There are " << errorCount << " invalid row(s)." << std::endl;
	}
	_ratemap.swap(tmp);
}
