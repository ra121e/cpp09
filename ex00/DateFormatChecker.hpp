#ifndef DATEFORMATCHECKER_HPP
# define DATEFORMATCHECKER_HPP

# include <string>
# include "Date.hpp"

class	DateFormatChecker
{
	private:
		std::string _format;
	public:
		DateFormatChecker();
		DateFormatChecker(const DateFormatChecker &other);
		DateFormatChecker	&operator=(const DateFormatChecker &other);
		~DateFormatChecker();
		bool	checkFormat(std::string const &date) const;
		bool	parseDate(std::string const &date_str, Date &date) const;
};

#endif //DATEFORMATCHECKER_HPP
