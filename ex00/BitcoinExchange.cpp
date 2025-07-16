/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:10:39 by athonda           #+#    #+#             */
/*   Updated: 2025/07/16 10:20:22 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		if (!std::getline(ss, date_str, ','))
		{
			std::cerr << "error: cannot read line(date)." << std::endl;
			continue ;
		}
		if (!std::getline(ss, rate_str))
		{
			std::cerr << "error: cannot read line(rate)." << std::endl;
			continue ;
		}

		std::stringstream ss_rate(rate_str);
		if (!(ss_rate >> rate_double))
		{
			std::cerr << "error: cannot convert rate to double." << std::endl;
			continue ;
		}
		_ratemap[date_str] = rate_double;
	}
	ifs.close();
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