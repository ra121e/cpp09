#ifndef IRATEAPI_HPP
# define IRATEAPI_HPP

# include <map>
# include <string>
# include "Date.hpp"
class IRateAPI
{
	public:
		IRateAPI();
		IRateAPI(const IRateAPI &other);
		IRateAPI	&operator=(const IRateAPI &other);
		virtual ~IRateAPI();
//		virtual const std::map<std::string, double> &getRateMap() const = 0;
		virtual double getRateAt(Date &date) const = 0;
};

#endif //IRATEAPI_HPP
