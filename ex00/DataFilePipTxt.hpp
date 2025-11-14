#ifndef DATAFILEPIPTXT_HPP
# define DATAFILEPIPTXT_HPP

# include <string>
# include <map>
# include "ADataFile.hpp"

class DataFilePipTxt : public ADataFile
{
	private:
		std::string		_header_format;
		std::map<std::string, double>	_ratemap;

	public:
		DataFilePipTxt();
		DataFilePipTxt(const std::string &header_format, const std::map<std::string, double> &ratemap);
		DataFilePipTxt(const DataFilePipTxt &other);
		DataFilePipTxt	&operator=(const DataFilePipTxt &other);
		~DataFilePipTxt();

		void	parseFile(const std::string &filename);

};

#endif //DATAFILEPIPTXT_HPP
