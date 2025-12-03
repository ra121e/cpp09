#ifndef BaseDataFile_HPP
# define BaseDataFile_HPP

# include <fstream>
# include <string>
# include <map>

class BaseDataFile
{
	public:
		BaseDataFile();
		BaseDataFile(const BaseDataFile &other);
		BaseDataFile& operator=(const BaseDataFile &other);
		virtual ~BaseDataFile();

	protected:
		virtual void	parseFile(const std::string &filename) = 0;
};

#endif // BaseDataFile_HPP
