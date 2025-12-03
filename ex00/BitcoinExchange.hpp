/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:35:10 by athonda           #+#    #+#             */
/*   Updated: 2025/12/03 15:08:57 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include "HistoricalDataFileCSV.hpp"
# include "BaseDataFile.hpp"
# include "HistoricalRate.hpp"

class BitcoinExchange
{
	public:
		BitcoinExchange(IRateAPI const &rate_api);
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange();

		void	evaluateBTCTimeSeries(std::string const &filename) const;
	private:
		BitcoinExchange();
		IRateAPI const				&_rate_api;
		BitcoinExchange	&operator=(BitcoinExchange const &other);
};

#endif // BITCOINEXCHANGE_HPP
