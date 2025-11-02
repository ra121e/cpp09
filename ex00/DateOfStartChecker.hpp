#ifndef STARTDATE_HPP
# define STARTDATE_HPP

#include <string>
#include "Date.hpp"

class	DateOfStartChecker
{
	private:
		unsigned int	_start_year;
		unsigned int	_start_month;
		unsigned int	_start_day;
	public:
		DateOfStartChecker();
		DateOfStartChecker(const DateOfStartChecker &other);
		DateOfStartChecker	&operator=(const DateOfStartChecker &other);
		~DateOfStartChecker();
		bool checkDateBegin(Date const &date) const;
};

#endif //STARTDATE_HPP
