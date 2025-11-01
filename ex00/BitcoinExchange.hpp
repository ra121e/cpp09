/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:35:10 by athonda           #+#    #+#             */
/*   Updated: 2025/11/01 13:18:31 by athonda          ###   ########.fr       */
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

bool	isLeapYear(int year);

class	DateFormat
{
	private:
		std::string _format;
	public:
		DateFormat(): _format("yyyy-mm-dd") {}
		DateFormat(const DateFormat &other);
		DateFormat	&operator=(const DateFormat &other);
		~DateFormat();
		bool checkFormat(std::string const &date) const;
		bool checkDateBegin(std::string const &date) const;

};

class	StartDate
{
	private:
		unsigned int	_year;
		unsigned int	_month;
		unsigned int	_day;
	public:
		StartDate(): _year(2009), _month(1), _day(3) {}
		StartDate(const StartDate &other);
		StartDate	&operator=(const StartDate &other);
		~StartDate();
};

#endif
