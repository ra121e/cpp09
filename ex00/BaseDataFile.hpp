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
		static std::string	trim(std::string const &s);
		static bool	validate_date(std::string const &s);
		static bool	IsNotSpace(char const &c);

		virtual std::map<std::string, double> const	&getRateMap() const;
	protected:
		virtual void	parseFile(const std::string &filename) = 0;
};

#endif // BaseDataFile_HPP
