#ifndef IMAPAPI_HPP
# define IMAPAPI_HPP

# include <map>
# include <string>

class IMapAPI
{
	public:
		virtual ~IMapAPI() {}
		virtual const std::map<std::string, double> &getRateMap() const = 0;
};

#endif //IMAPAPI_HPP
