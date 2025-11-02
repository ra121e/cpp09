#ifndef DATEFORMATCHECKER_HPP
# define DATEFORMATCHECKER_HPP

# include <string>

class	DateFormatChecker
{
	private:
		std::string _format;
	public:
		DateFormatChecker();
		DateFormatChecker(const DateFormatChecker &other);
		DateFormatChecker	&operator=(const DateFormatChecker &other);
		~DateFormatChecker();
		bool checkFormat(std::string const &date) const;
};

#endif //DATEFORMATCHECKER_HPP
