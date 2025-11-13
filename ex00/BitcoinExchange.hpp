/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:35:10 by athonda           #+#    #+#             */
/*   Updated: 2025/11/13 13:53:20 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange	&operator=(BitcoinExchange const &other);
		~BitcoinExchange();

		void	setHistoricalRate(std::string const &filename);
		void	evaluateBTCTimeSeries(std::string const &filename) const;
	private:
		std::map<std::string, double>	_ratemap;
		std::string	trim(std::string const &s) const;
		bool	validate_date(std::string const &s) const;
		static bool	IsNotSpace(char const &c);

};

//bool	isLeapYear(int year);

#endif
