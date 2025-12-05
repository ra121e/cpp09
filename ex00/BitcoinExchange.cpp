/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:10:39 by athonda           #+#    #+#             */
/*   Updated: 2025/12/05 10:29:38 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "HistoricalDataFileCSV.hpp"
#include "HistoricalRate.hpp"
#include "InputDataFilePip.hpp"
#include "IRateAPI.hpp"
#include "Date.hpp"

BitcoinExchange::BitcoinExchange(IRateAPI const &rate_api):
	_rate_api(rate_api)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other):
	_rate_api(other._rate_api)
{}

BitcoinExchange::~BitcoinExchange()
{}

void	BitcoinExchange::evaluateBTCTimeSeries(std::string const &filename) const
{
	std::string header_format = "date | value";
	InputDataFilePip	input_file_pip(header_format);

	input_file_pip.parseFile(filename);
//	std::string	date_str;
	Date		date;
	double		amount;
	while (input_file_pip.readNextDateAmount(date, amount))
	{
		double		exchange_rate;
		try
		{
			exchange_rate = _rate_api.getRateAt(date);
			std::cout << date << " => " << amount << " = " << (amount * exchange_rate) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
