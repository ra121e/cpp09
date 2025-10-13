/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:35:10 by athonda           #+#    #+#             */
/*   Updated: 2025/10/13 22:03:16 by athonda          ###   ########.fr       */
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

		bool	setRate(std::string const &filename);
		void	inputFile(std::string const &filename) const;
	private:
		std::map<std::string, double>	_ratemap;
		std::string	trim(std::string const &s) const;
		bool	validate_date(std::string const &s) const;
//		struct	IsNotSpace
//		{
//			bool	operator()(char c) const;
//		};
		static bool	IsNotSpace(char const &c);

};

#endif
