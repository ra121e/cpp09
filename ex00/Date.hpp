#ifndef DATE_HPP
# define DATE_HPP

#include <string>

class Date
{
	private:
		std::string		_date_str;
		unsigned int	_year;
		unsigned int	_month;
		unsigned int	_day;
	public:
		Date();
		Date(std::string const &date_str);
		Date(const Date &other);
		Date	&operator=(const Date &other);
		~Date();
		void	setDateStr(std::string const &date_str);
		void	setYear(unsigned int year);
		void	setMonth(unsigned int month);
		void	setDay(unsigned int day);
		std::string const	&getDateStr() const;
		unsigned int	getYear() const;
		unsigned int	getMonth() const;
		unsigned int	getDay() const;
		bool	isCalendarDateValid();
		bool	isLeapYear(int year);

};
		std::ostream &operator<<(std::ostream &os, const Date &date);


#endif //DATE_HPP
