/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:37:13 by athonda           #+#    #+#             */
/*   Updated: 2025/07/21 15:41:45 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Usage: ./btc filename.csv" << std::endl;
	}
	BitcoinExchange	a;
//	a.setRate("data.csv");
	a.inputFile("input.txt");
	return (0);
}