#ifndef HistoricalDataFileCSV_HPP
# define HistoricalDataFileCSV_HPP

# include "BaseDataFile.hpp"
# include <map>

class HistoricalDataFileCSV : public BaseDataFile
{
	private:
		std::string _header_format;
		std::map<std::string, double>	_ratemap;

	public:
		HistoricalDataFileCSV() {}
		HistoricalDataFileCSV(const std::string &header_format): _header_format(header_format) {}
		HistoricalDataFileCSV(const HistoricalDataFileCSV &other) : BaseDataFile(other) {}
		HistoricalDataFileCSV& operator=(const HistoricalDataFileCSV&) { return *this; }
		~HistoricalDataFileCSV() {}
		std::string getHeaderFormat() const { return _header_format; }
		std::map<std::string, double>	getRateMap() const;

		void parseFile(const std::string &filename);
};

#endif // HistoricalDataFileCSV_HPP
