/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:35:10 by athonda           #+#    #+#             */
/*   Updated: 2025/07/16 10:14:52 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_HPP
# define DATABASE_HPP

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

		void	setRate(std::string const &filename);
		double	getRate(std::string const &date);

		void	getterTest(void);
	private:
		std::map<std::string, double>	_ratemap;

};

#endif