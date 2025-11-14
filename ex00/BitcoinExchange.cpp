/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:10:39 by athonda           #+#    #+#             */
/*   Updated: 2025/11/14 15:33:31 by athonda          ###   ########.fr       */
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
#include "DataFileCSV.hpp"
#include "DataFilePipTxt.hpp"

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
	DataFileCSV dataFileCSV("date,exchange_rate");
	dataFileCSV.parseFile(filename);

	this->_ratemap = dataFileCSV.getRateMap();
}

void	BitcoinExchange::evaluateBTCTimeSeries(std::string const &filename) const
{
	std::string header_format = "date | value";
	DataFilePipTxt	data_file_pip_txt(header_format, _ratemap);

	data_file_pip_txt.parseFile(filename);
}
