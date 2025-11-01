#include "DateParser.hpp"
#include <sstream>

DateParser::DateParser()
{}

DateParser::DateParser(const DateParser &other)
{
	(void)other;
}

DateParser	&DateParser::operator=(const DateParser &other)
{
	(void)other;
	return (*this);
}

DateParser::~DateParser()
{}

bool	DateParser::parseDate(std::string const &date_str, Date &date) const
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
