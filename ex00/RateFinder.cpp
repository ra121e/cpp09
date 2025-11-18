#include "RateFinder.hpp"
#include <iostream>

double	RateFinder::findRate(const std::map<std::string, double> &ratemap, const std::string &date) const
{
	if (ratemap.empty())
	{
		throw std::runtime_error("Error: no rate available.");
	}
	double rate;
	std::map<std::string, double>::const_iterator it = ratemap.lower_bound(date);
	if (it == ratemap.end())
	{
		--it;
		rate = it->second;
	}
	else if (it->first == date)
	{
		rate = it->second;
	}
	else
	{
		if (it == ratemap.begin())
		{
			throw std::runtime_error("Error: no rate available before this date.");
		}
		--it;
		rate = it->second;
	}
	return (rate);
}
