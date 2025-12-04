#include "HistoricalRate.hpp"
#include <stdexcept>

HistoricalRate::HistoricalRate()
{}

HistoricalRate::HistoricalRate(const std::map<std::string, double>& ratemap) :
	IRateAPI(),
	_ratemap(ratemap)
{}

HistoricalRate::HistoricalRate(const HistoricalRate& other) :
	IRateAPI(other),
	_ratemap(other._ratemap)
{}

HistoricalRate& HistoricalRate::operator=(const HistoricalRate& other)
{
	if (this != &other)
	{
		this->_ratemap = other._ratemap;
	}
	return (*this);
}

HistoricalRate::~HistoricalRate()
{}

void HistoricalRate::swap(std::map<std::string, double> &ratemap)
{
	_ratemap.swap(ratemap);
}

double HistoricalRate::getRateAt(Date &date) const
{
	if (_ratemap.empty())
	{
		throw std::runtime_error("Error: no rate available.");
	}
	double rate;
	std::map<std::string, double>::const_iterator it = _ratemap.lower_bound(date.getDateStr());
	if (it == _ratemap.end())
	{
		--it;
		rate = it->second;
	}
	else if (it->first == date.getDateStr())
	{
		rate = it->second;
	}
	else
	{
		if (it == _ratemap.begin())
		{
			throw std::runtime_error("Error: no rate available before this date.");
		}
		--it;
		rate = it->second;
	}
	return (rate);

}
