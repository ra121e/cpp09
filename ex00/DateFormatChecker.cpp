#include "DateFormatChecker.hpp"
#include <sstream>

DateFormatChecker::DateFormatChecker():
	_format("yyyy-mm-dd")
{}

DateFormatChecker::DateFormatChecker(const DateFormatChecker &other):
	_format(other._format)
{}

DateFormatChecker	&DateFormatChecker::operator=(DateFormatChecker const &other)
{
	if (this != &other)
	{
		this->_format = other._format;
	}
	return (*this);
}

DateFormatChecker::~DateFormatChecker()
{}

bool DateFormatChecker::checkFormat(std::string const &date) const
{

	if (date.size() != _format.size())
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	return (true);
}

bool	DateFormatChecker::parseDate(std::string const &date_str, Date &date) const
{

	std::stringstream ss(date_str);
	std::string year_str;
	std::string mon_str;
	std::string day_str;
	unsigned int	year;
	unsigned int	mon;
	unsigned int	day;

	getline(ss, year_str, '-');
	std::stringstream	year_ss(year_str);
	getline(ss, mon_str, '-');
	std::stringstream	mon_ss(mon_str);
	getline(ss, day_str);
	std::stringstream	day_ss(day_str);

	year_ss >> year;
	if (year_ss.fail() && !year_ss.eof())
		return (false);
	mon_ss	>> mon;
	if (mon_ss.fail() && !mon_ss.eof())
		return (false);
	day_ss >> day;
	if (day_ss.fail() && !day_ss.eof())
		return (false);

	date.setYear(year);
	date.setMonth(mon);
	date.setDay(day);
	return (true);
}
