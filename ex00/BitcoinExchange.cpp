/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:10:39 by athonda           #+#    #+#             */
/*   Updated: 2025/11/27 15:52:20 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "HistoricalDataFileCSV.hpp"
#include "InputDataFilePip.hpp"
#include "RateFinder.hpp"
#include "IMapAPI.hpp"

//BitcoinExchange::BitcoinExchange():
//{
//}

BitcoinExchange::BitcoinExchange(IMapAPI const &datafile):
	_data_file(datafile)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other):
	_data_file(other._data_file)
{}

//BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
//{
//	if (this != &other)
//	{
//		this->_data_file = other._data_file;
//	}
//	return (*this);
//}


BitcoinExchange::~BitcoinExchange()
{}

void	BitcoinExchange::evaluateBTCTimeSeries(std::string const &filename) const
{
	std::string header_format = "date | value";
	InputDataFilePip	input_file_pip(header_format);

	input_file_pip.parseFile(filename);
	std::string	date;
	double		amount;
	while (input_file_pip.readNextDateAmount(date, amount))
	{
		RateFinder	rate_finder;
		double		exchange_rate;
		try
		{
			exchange_rate = rate_finder.findRate(_data_file.getRateMap(), date);
			std::cout << date << " => " << amount << " = " << (amount * exchange_rate) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
