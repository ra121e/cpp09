#include "BaseDataFile.hpp"
#include <iostream>
#include <cctype>
#include <algorithm>
#include "DateFormatChecker.hpp"
#include "DateOfStartChecker.hpp"
#include "Date.hpp"

BaseDataFile::BaseDataFile()
{}

BaseDataFile::BaseDataFile(const BaseDataFile &other)
{
	(void)other;
}

BaseDataFile& BaseDataFile::operator=(const BaseDataFile &other)
{
	if (this != &other)
	{
		// 現在はメンバがないので何もしない
		(void)other;
	}
	return (*this);
}

BaseDataFile::~BaseDataFile()
{}

bool	BaseDataFile::IsNotSpace(char const &c)
{
	unsigned char	safe = static_cast<unsigned char>(c);
	if (std::isspace(safe))
		return (false);
	return (true);
}

std::string	BaseDataFile::trim(std::string const &s)
{
	std::string::const_iterator first = std::find_if(s.begin(), s.end(), &BaseDataFile::IsNotSpace);
	if (first == s.end())
		return ("");
	std::string::const_reverse_iterator last_reverse = std::find_if(s.rbegin(), s.rend(), &BaseDataFile::IsNotSpace);
	std::string::const_iterator last = last_reverse.base();
	std::string	str(first, last);
	return (str);
}

bool	BaseDataFile::validate_date(std::string const &input_date)
{
	DateFormatChecker	date_format_checker;
	if (!date_format_checker.checkFormat(input_date))
		return (false);

	Date date;
	if (!date_format_checker.parseDate(input_date, date))
		return (false);

	DateOfStartChecker	start_date_checker;
	if (!start_date_checker.checkDateBegin(date))
		return (false);

	if (!date.isCalendarDateValid())
		return (false);
	return (true);
}
