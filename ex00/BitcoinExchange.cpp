/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:10:39 by athonda           #+#    #+#             */
/*   Updated: 2025/07/14 08:50:46 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	setRate("data.csv");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other):
	_ratemap(other._ratemap);
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
	while (std::getline(ifd, line))
	{
		std::string	date;
		std::string	rate;

		line.
	}

}