#include "Date.hpp"

Date::Date():
	_year(0),
	_month(0),
	_day(0)
{}

Date::Date(const Date &other):
	_year(other._year),
	_month(other._month),
	_day(other._day)
{}

Date 	&Date::operator=(const Date &other)
{
	if (this != &other)
	{
		this->_year = other._year;
		this->_month = other._month;
		this->_day = other._day;
	}
	return (*this);
}

Date::~Date()
{}

void	Date::setYear(unsigned int year)
{
	_year = year;
}

void	Date::setMonth(unsigned int month)
{
	_month = month;
}

void	Date::setDay(unsigned int day)
{
	_day = day;
}

unsigned int	Date::getYear() const
{
	return (_year);
}

unsigned int	Date::getMonth() const
{
	return (_month);
}

unsigned int	Date::getDay() const
{
	return (_day);
}

bool	Date::isCalendarDateValid(Date const &date)
{
	if (date.getMonth() < 1 || date.getMonth() > 12)
		return (false);
	unsigned int	days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (date.getMonth() == 2 && isLeapYear(date.getYear()))
		days[2] = 29;
	if (date.getDay() <= 0 || date.getDay() > days[date.getMonth()])
		return (false);
	return (true);
}

bool	Date::isLeapYear(int year)
{
	bool	yes_leap = false;
	if (year % 4 == 0)
		yes_leap = true;

	if (year % 100 == 0)
	{
		yes_leap = false;
		if (year % 400 == 0)
			yes_leap = true;
	}
	return yes_leap;
}
