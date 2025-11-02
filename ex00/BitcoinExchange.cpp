/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:10:39 by athonda           #+#    #+#             */
/*   Updated: 2025/11/02 09:36:54 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <exception>
#include <fstream>
#include <sstream>
#include "BitcoinExchange.hpp"
#include "DateFormatChecker.hpp"
#include "Date.hpp"
#include "DateOfStartChecker.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other):
	_ratemap(other._ratemap)
{}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
	{
		this->_ratemap = other._ratemap;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

bool	BitcoinExchange::setRate(std::string const &filename)
{

	std::ifstream	ifs(filename.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "error: file not open." << std::endl;
		return (false);
	}

	std::string	line;
	std::getline(ifs, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << "error: header is not valid." << std::endl;
		return (false);
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
		return (false);
	}
	if (errorCount > 0)
	{
		std::cerr << "error: There are " << errorCount << " invalid row(s)." << std::endl;
		return (false);
	}
	_ratemap.swap(tmp);
	return (true);
}

//bool	BitcoinExchange::IsNotSpace::operator()(char c) const
//{
//	unsigned char	safe = static_cast<unsigned char>(c);
//	if (std::isspace(safe))
//		return (false);
//	return (true);
//}

bool	BitcoinExchange::IsNotSpace(char const &c)
{
	unsigned char	safe = static_cast<unsigned char>(c);
	if (std::isspace(safe))
		return (false);
	return (true);
}

std::string	BitcoinExchange::trim(std::string const &s) const
{
	std::string::const_iterator first = std::find_if(s.begin(), s.end(), &IsNotSpace);
	if (first == s.end())
		return ("");
	std::string::const_reverse_iterator last_reverse = std::find_if(s.rbegin(), s.rend(), &IsNotSpace);
	std::string::const_iterator last = last_reverse.base();
	std::string	str(first, last);
	return (str);
}

bool	BitcoinExchange::validate_date(std::string const &input_date) const
{
//	std::string format = "yyyy-mm-dd";
	DateFormatChecker	date_format_checker;
	if (!date_format_checker.checkFormat(input_date))
		return (false);

	Date date;
	if (!date_format_checker.parseDate(input_date, date))
		return (false);

	DateOfStartChecker	start_date_checker;
	if (!start_date_checker.checkDateBegin(date))
		return (false);

	if (!Date::isCalendarDateValid(date))
		return (false);
	return (true);
}

bool	isLeapYear(int year)
{
	bool	yes_leap = false;
	if (year % 4 == 0)
		yes_leap = true;

	if (year % 100 == 0)
	{
		yes_leap = false;
		if (year % 400 == 0)
			yes_leap = true;
	}
	return yes_leap;
}


void	BitcoinExchange::inputFile(std::string const &filename) const
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
			std::cout << "date is beyond the last date in the database, or database is empty." << std::endl;
			continue ;
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
