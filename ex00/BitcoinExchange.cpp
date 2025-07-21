/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:10:39 by athonda           #+#    #+#             */
/*   Updated: 2025/07/21 13:24:15 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <exception>
#include <fstream>
#include <sstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	setRate("data.csv");
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

void	BitcoinExchange::setRate(std::string const &filename)
{

	std::ifstream	ifs(filename.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error: file not open." << std::endl;
		return ;
	}

	std::string	line;
	std::getline(ifs, line);
	std::cout << line << std::endl;

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
			continue ;
		}
		std::getline(ss, rate_str);
		if (rate_str.empty() || ss.fail() || !ss.eof())
		{
			std::cerr << "error: cannot read rate correctly." << std::endl;
			continue ;
		}

		std::stringstream ss_rate(rate_str);
		ss_rate >> rate_double;
		if (ss_rate.fail() || !ss_rate.eof())
		{
			std::cerr << "error: cannot convert rate to double." << std::endl;
			continue ;
		}
		_ratemap[date_str] = rate_double;
	}
	ifs.close();
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

bool	BitcoinExchange::validate_date(std::string const &s) const
{
	std::string format = "yyyy-mm-dd";
	if (s.size() != format.size())
		return (false);
	if (s[4] != '-' || s[7] != '-')
		return (false);

	std::stringstream ss(s);
	std::string year_str;
	std::string mon_str;
	std::string day_str;
	unsigned int	year;
	unsigned int	mon;
	unsigned int	day;

	getline(ss, year_str, '-');
	std::stringstream	year_ss(year_str);
	getline(ss, mon_str, '-');
	std::stringstream	mon_ss(mon_str);

	year_ss >> year;
	mon_ss	>> mon;
	ss >> day;

	if (year < 2009 )
		return (false);
	if (year == 2009 && mon <= 1 && day < 3)
		return (false);
	if (mon < 1 || mon > 12)
		return (false);
	unsigned int	days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (mon == 2 && (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
		days[2] = 29;
	if (day <= 0 || day > days[mon])
		return (false);
	return (true);
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

	while (std::getline(ifs, line))
	{
		if (ifs.fail() || line.empty())
			continue ;

		std::stringstream	ss(line);
		std::string	date;
		std::getline(ss, date, '|');
		if (ss.fail() || ss.eof() || date.empty())
			continue ;

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

		std::cout << date << " ";
		std::cout << num << std::endl;
	}
}

void	BitcoinExchange::getterTest(void)
{
	for (std::map<std::string, double>::const_iterator it = this->_ratemap.begin(); it != _ratemap.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}

//double	BitcoinExchange::getRate(std::string const &date)
//{
//	for
//	return ()
//}