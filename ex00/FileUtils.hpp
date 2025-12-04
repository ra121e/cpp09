#ifndef FILEUTILS_HPP
# define FILEUTILS_HPP

# include <string>
# include "Date.hpp"

class FileUtils
{
public:
	static std::string	trim(std::string const &s);
	static bool	validateDate(Date const &s);
	static bool	IsNotSpace(char const &c);
private:
	FileUtils();
};

#endif // FILEUTILS_HPP
