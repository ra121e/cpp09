/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:37:13 by athonda           #+#    #+#             */
/*   Updated: 2025/12/02 16:31:38 by athonda          ###   ########.fr       */
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
	std::string	input_file(av[1]);

	std::string const csv_data_file = "data.csv";
	std::string const header_format = "date,exchange_rate";


//	BitcoinExchange	bitcoin_exchange;
	try
	{
		HistoricalRate historical_rate; // is the domain object for data holder
		HistoricalDataFileCSV	historical_data_file_csv(header_format); // is the infrastructure to read data file
		historical_data_file_csv.parseFile(csv_data_file, historical_rate); // which fills the domain object
		BitcoinExchange bitcoin_exchange(historical_rate); // is the use case handler
		bitcoin_exchange.evaluateBTCTimeSeries(input_file);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
