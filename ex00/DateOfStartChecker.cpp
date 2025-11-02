#include "DateOfStartChecker.hpp"
#include <sstream>

DateOfStartChecker::DateOfStartChecker():
	_start_year(2009),
	_start_month(1),
	_start_day(3)
{}

DateOfStartChecker::DateOfStartChecker(const DateOfStartChecker &other):
	_start_year(other._start_year),
	_start_month(other._start_month),
	_start_day(other._start_day)
{}

DateOfStartChecker	&DateOfStartChecker::operator=(const DateOfStartChecker &other)
{
	if (this != &other)
	{
		this->_start_year = other._start_year;
		this->_start_month = other._start_month;
		this->_start_day = other._start_day;
	}
	return (*this);
}

DateOfStartChecker::~DateOfStartChecker()
{}


bool DateOfStartChecker::checkDateBegin(Date const &date) const
{
	if (date.getYear() < _start_year)
		return (false);
	if (date.getYear() == _start_year && date.getMonth() <= _start_month && date.getDay() < _start_day)
		return (false);
	return (true);
}
