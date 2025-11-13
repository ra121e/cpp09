#ifndef DataFileCSV_HPP
# define DataFileCSV_HPP

# include "ADataFile.hpp"
# include <map>

class DataFileCSV : public ADataFile
{
	private:
		std::string _header_format;
		std::map<std::string, double>	_ratemap;

	public:
		DataFileCSV() {}
		DataFileCSV(std::string header_format): _header_format(header_format) {}
		DataFileCSV(const DataFileCSV &other) : ADataFile(other) {}
		DataFileCSV& operator=(const DataFileCSV&) { return *this; }
		~DataFileCSV() {}
		std::string getHeaderFormat() const { return _header_format; }

		void parseFile(const std::string &filename);
};

#endif // DataFileCSV_HPP
