#include "DateFormatChecker.hpp"


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
