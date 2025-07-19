/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:35:10 by athonda           #+#    #+#             */
/*   Updated: 2025/07/19 12:16:14 by athonda          ###   ########.fr       */
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
		void	inputFile(std::string const &filename);
		void	getterTest(void);
	private:
		std::map<std::string, double>	_ratemap;
		double	getRate(std::string const &date);
		std::string	trim(std::string const &s);
		struct	IsNotSpace
		{
			bool	operator()(char c) const;
		};

};

#endif