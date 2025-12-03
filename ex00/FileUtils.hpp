#ifndef FILEUTILS_HPP
# define FILEUTILS_HPP

# include <string>

class FileUtils
{
public:
	static std::string	trim(std::string const &s);
	static bool	validateDate(std::string const &s);
	static bool	IsNotSpace(char const &c);
private:
	FileUtils();
};

#endif // FILEUTILS_HPP
