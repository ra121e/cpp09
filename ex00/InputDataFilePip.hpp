#ifndef INPUTDATAFILEPIP_HPP
# define INPUTDATAFILEPIP_HPP

# include <string>
# include <map>
# include "BaseDataFile.hpp"

class InputDataFilePip : public BaseDataFile
{
	private:
		std::string		_header_format;
		std::map<std::string, double>	_ratemap;
		std::ifstream	_ifs;
		bool			_ready;

	public:
		InputDataFilePip();
		InputDataFilePip(const std::string &header_format, const std::map<std::string, double> &ratemap);
		InputDataFilePip(const InputDataFilePip &other);
		InputDataFilePip	&operator=(const InputDataFilePip &other);
		~InputDataFilePip();

		void	parseFile(const std::string &filename);
		bool	readNextDateAmount(std::string &date, double &amount);

};

#endif //INPUTDATAFILEPIP_HPP
