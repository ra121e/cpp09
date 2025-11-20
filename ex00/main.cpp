/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:37:13 by athonda           #+#    #+#             */
/*   Updated: 2025/11/20 12:56:44 by athonda          ###   ########.fr       */
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

	std::string const header_format = "date,exchange_rate";
	BitcoinExchange	bitcoin_exchange(header_format);
	try
	{
		bitcoin_exchange.setHistoricalRate("data.csv");
		bitcoin_exchange.evaluateBTCTimeSeries(input_file_name);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
