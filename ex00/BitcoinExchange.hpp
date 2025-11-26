/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:35:10 by athonda           #+#    #+#             */
/*   Updated: 2025/11/26 22:49:33 by athonda          ###   ########.fr       */
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
		BitcoinExchange();
//		BitcoinExchange(const std::string &header_format);
//		BitcoinExchange(HistoricalDataFileCSV const &datafile);
		BitcoinExchange(BaseDataFile const &datafile);
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange	&operator=(BitcoinExchange const &other);
		~BitcoinExchange();

//		void	setHistoricalRate(std::string const &filename);
//		void	setHistoricalRate(std::string const &filename, std::string const &header_format);
		void	evaluateBTCTimeSeries(std::string const &filename) const;
	private:
//		std::map<std::string, double>	_ratemap;
//		HistoricalDataFileCSV			_historical_data_file_csv;
		BaseDataFile const				*_data_file;

};

//bool	isLeapYear(int year);

#endif
