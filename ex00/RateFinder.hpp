#ifndef RATEFINDER_HPP
# define RATEFINDER_HPP

#include <string>
#include <map>


class RateFinder
{
	public:
		RateFinder() {}
		RateFinder(const RateFinder&) {}
		RateFinder& operator=(const RateFinder&) { return *this; }
		~RateFinder() {}

		double	findRate(const std::map<std::string, double> &ratemap, const std::string &date) const;
};

#endif // RATEFINDER_HPP
