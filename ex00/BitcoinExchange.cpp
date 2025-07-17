/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:10:39 by athonda           #+#    #+#             */
/*   Updated: 2025/07/17 15:17:14 by athonda          ###   ########.fr       */
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

void	BitcoinExchange::inputFile(std::string const &filename)
{
	std::ifstream	ifs(filename.c_str());
	std::string		line;

	if (!ifs.is_open())
	{
		std::cerr << "error: file not open.";
	}
	std::getline(ifs, line);
	while (getline(ifs, line))
	{

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