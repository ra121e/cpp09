/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:10:39 by athonda           #+#    #+#             */
/*   Updated: 2025/11/16 14:00:22 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "HistoricalDataFileCSV.hpp"
#include "InputDataFilePip.hpp"

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

void	BitcoinExchange::setHistoricalRate(std::string const &filename)
{
	HistoricalDataFileCSV data_file_csv("date,exchange_rate");
	data_file_csv.parseFile(filename);

	this->_ratemap = data_file_csv.getRateMap();
}

void	BitcoinExchange::evaluateBTCTimeSeries(std::string const &filename) const
{
	std::string header_format = "date | value";
	InputDataFilePip	input_file_pip(header_format, _ratemap);

	input_file_pip.parseFile(filename);
}
