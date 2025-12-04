#ifndef HISTORICALRATE_HPP
# define HISTORICALRATE_HPP

#include <map>
#include <string>
#include "IRateAPI.hpp"
#include "Date.hpp"
class HistoricalRate: public IRateAPI
{
	private:
		std::map<std::string, double> _ratemap;

	public:
		HistoricalRate();
		HistoricalRate(const std::map<std::string, double>& ratemap);
		HistoricalRate(const HistoricalRate& other);
		HistoricalRate& operator=(const HistoricalRate& other);
		~HistoricalRate();

		void swap(std::map<std::string, double> &ratemap);
		double getRateAt(Date &date) const;
};

#endif // HISTORICALRATE_HPP
