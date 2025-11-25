#ifndef BaseDataFile_HPP
# define BaseDataFile_HPP

# include <fstream>
# include <string>

class BaseDataFile
{
	public:
		BaseDataFile();
		BaseDataFile(const BaseDataFile &other);
		BaseDataFile& operator=(const BaseDataFile &other);
		virtual ~BaseDataFile();
		static std::string	trim(std::string const &s);
		static bool	validate_date(std::string const &s);
		static bool	IsNotSpace(char const &c);
	protected:
		virtual void	parseFile(const std::string &filename) = 0;
};

#endif // BaseDataFile_HPP
