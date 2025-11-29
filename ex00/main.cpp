/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:37:13 by athonda           #+#    #+#             */
/*   Updated: 2025/11/29 15:43:43 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./btc input.txt" << std::endl;
		return (1);
	}
	std::string	input_file_name(av[1]);

	std::string const data_file_name = "data.csv";
	std::string const header_format = "date,exchange_rate";


//	BitcoinExchange	bitcoin_exchange;
	try
	{
		HistoricalRate historical_rate;
		HistoricalDataFileCSV	historical_data_file_csv(header_format);
		historical_data_file_csv.parseFile(data_file_name, historical_rate);
		BitcoinExchange bitcoin_exchange(historical_rate);
		bitcoin_exchange.evaluateBTCTimeSeries(input_file_name);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
