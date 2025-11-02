#ifndef DATE_HPP
# define DATE_HPP

#include <string>

class Date
{
	private:
		unsigned int	_year;
		unsigned int	_month;
		unsigned int	_day;
	public:
		Date();
		Date(const Date &other);
		Date	&operator=(const Date &other);
		~Date();
		void	setYear(unsigned int year);
		void	setMonth(unsigned int month);
		void	setDay(unsigned int day);
		unsigned int	getYear() const;
		unsigned int	getMonth() const;
		unsigned int	getDay() const;
		bool	isCalendarDateValid();
		bool	isLeapYear(int year);
};


#endif //DATE_HPP
