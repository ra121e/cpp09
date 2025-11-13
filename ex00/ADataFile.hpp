#ifndef ADataFile_HPP
# define ADataFile_HPP

# include <fstream>
# include <string>

class ADataFile
{
	public:
		ADataFile() {}
		ADataFile(const ADataFile&) {}
		ADataFile& operator=(const ADataFile&) { return *this; }
		virtual ~ADataFile() {}
		static std::string	trim(std::string const &s);
		static bool	validate_date(std::string const &s);
		static bool	IsNotSpace(char const &c);

	protected:
		virtual void	parseFile(const std::string &filename) = 0;
//		virtual bool	validateHeader(const std::string &header) = 0;
//		virtual void	parseBody() = 0;
};


#endif // ADataFile_HPP
