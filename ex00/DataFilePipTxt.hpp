#ifndef DATAFILEPIPTXT_HPP
# define DATAFILEPIPTXT_HPP

# include <string>
# include "ADataFile.hpp"

class DataFilePipTxt : public ADataFile
{
	private:
		std::string		_header_format;

	public:
		DataFilePipTxt();
		DataFilePipTxt(std::string &header_format);
		DataFilePipTxt(const DataFilePipTxt &other);
		DataFilePipTxt	&operator=(const DataFilePipTxt &other);
		~DataFilePipTxt();

		void	parseFile(const std::string &filename);

};

#endif //DATAFILEPIPTXT_HPP
