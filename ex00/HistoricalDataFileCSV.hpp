#ifndef HistoricalDataFileCSV_HPP
# define HistoricalDataFileCSV_HPP

# include "BaseDataFile.hpp"
# include "HistoricalRate.hpp"
# include <map>
# include "IMapAPI.hpp"

class HistoricalDataFileCSV : public BaseDataFile
{
	private:
		std::string _header_format;
//		std::map<std::string, double>	_ratemap;

	public:
		HistoricalDataFileCSV();
		HistoricalDataFileCSV(const std::string &header_format);
		HistoricalDataFileCSV(const HistoricalDataFileCSV &other);
		HistoricalDataFileCSV& operator=(const HistoricalDataFileCSV& other);
		~HistoricalDataFileCSV();
		std::string getHeaderFormat() const { return _header_format; }

		// IMapAPI implementation
//		std::map<std::string, double> const	&getRateMap() const;

		// File initializer
		void parseFile(const std::string &filename);
		void parseFile(const std::string &filename, HistoricalRate &historicalRate);
};

#endif // HistoricalDataFileCSV_HPP
