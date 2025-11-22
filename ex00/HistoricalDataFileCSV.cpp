#include "HistoricalDataFileCSV.hpp"
#include <iostream>
#include <sstream>
#include <map>

std::map<std::string, double> const	&HistoricalDataFileCSV::getRateMap() const
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
		std::stringstream stream_line(line);
		std::string	date_str;
		std::string	rate_str;

		std::getline(stream_line, date_str, ',');
		if (date_str.empty() || stream_line.fail() || stream_line.eof())
		{
			std::cerr << "error: cannot read date correctly." << std::endl;
			errorCount++;
			continue ;
		}
		std::string trimed_date_str = BaseDataFile::trim(date_str);
		if (trimed_date_str.empty())
		{
			std::cerr << "error: invalid date format." << std::endl;
			errorCount++;
			continue ;
		}
		if (!validate_date(trimed_date_str))
		{
			std::cerr << "error: invalid date format." << std::endl;
			errorCount++;
			continue ;
		}
		std::getline(stream_line, rate_str);
		if (rate_str.empty() || stream_line.fail() || !stream_line.eof())
		{
			std::cerr << "error: cannot read rate correctly." << std::endl;
			errorCount++;
			continue ;
		}
	//	std::string trimed_rate_str = BaseDataFile::trim(rate_str);
	//	if (trimed_rate_str.empty())
	//	{
	//		std::cerr << "error: rate cannot be empty." <<  std::endl;
	//		errorCount++;
	//		continue ;
	//	}

		double				rate_double;
		std::stringstream 	stream_line_rate(rate_str);
		stream_line_rate >> rate_double;
		if (stream_line_rate.fail() || !stream_line_rate.eof())
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
