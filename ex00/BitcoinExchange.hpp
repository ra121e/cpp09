/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:35:10 by athonda           #+#    #+#             */
/*   Updated: 2025/11/27 15:50:59 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include "HistoricalDataFileCSV.hpp"
# include "BaseDataFile.hpp"

class BitcoinExchange
{
	public:
//		BitcoinExchange();
		BitcoinExchange(IMapAPI const &datafile);
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange();

		void	evaluateBTCTimeSeries(std::string const &filename) const;
	private:
		IMapAPI const				&_data_file;

		BitcoinExchange	&operator=(BitcoinExchange const &other);
};

//bool	isLeapYear(int year);

#endif
