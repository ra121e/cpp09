#ifndef DATEPARSER_HPP
# define DATEPARSER_HPP

#include "Date.hpp"

class DateParser
{
	private:

	public:
		DateParser();
		DateParser(const DateParser &other);
		DateParser	&operator=(const DateParser &other);
		~DateParser();

		bool	parseDate(std::string const &date_str, Date &date) const;
};
#endif //DATEPARSER_HPP
