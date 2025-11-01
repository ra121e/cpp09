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
		DateOfStartChecker(): _start_year(2009), _start_month(1), _start_day(3) {}
		DateOfStartChecker(const DateOfStartChecker &other);
		DateOfStartChecker	&operator=(const DateOfStartChecker &other);
		~DateOfStartChecker();
		bool checkDateBegin(Date const &date) const;
};

#endif //STARTDATE_HPP
