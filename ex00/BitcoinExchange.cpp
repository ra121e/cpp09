/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:10:39 by athonda           #+#    #+#             */
/*   Updated: 2025/11/25 14:25:45 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "HistoricalDataFileCSV.hpp"
#include "InputDataFilePip.hpp"
#include "RateFinder.hpp"

BitcoinExchange::BitcoinExchange()
{
}

//BitcoinExchange::BitcoinExchange(const std::string &header_format):
//	_historical_data_file_csv(header_format)
//{
//}
BitcoinExchange::BitcoinExchange(HistoricalDataFileCSV const &datafile):
	_historical_data_file_csv(datafile)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other):
	_historical_data_file_csv(other._historical_data_file_csv)
{}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
	{
		this->_historical_data_file_csv = other._historical_data_file_csv;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

//void	BitcoinExchange::setHistoricalRate(std::string const &filename)
//{
//	_historical_data_file_csv.parseFile(filename);
//}

void	BitcoinExchange::setHistoricalRate(const std::string &filename, const std::string &header_format)
{
	_historical_data_file_csv = HistoricalDataFileCSV(header_format);
	_historical_data_file_csv.parseFile(filename);
}

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
			exchange_rate = rate_finder.findRate(_historical_data_file_csv.getRateMap(), date);
			std::cout << date << " => " << amount << " = " << (amount * exchange_rate) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
