#include "BaseDataFile.hpp"
#include <iostream>
#include <cctype>
#include <algorithm>
#include "DateFormatChecker.hpp"
#include "DateOfStartChecker.hpp"
#include "Date.hpp"

BaseDataFile::BaseDataFile()
{}

BaseDataFile::BaseDataFile(const BaseDataFile &other)
{
	(void)other;
}

BaseDataFile& BaseDataFile::operator=(const BaseDataFile &other)
{
	if (this != &other)
	{
		// 現在はメンバがないので何もしない
		(void)other;
	}
	return (*this);
}

BaseDataFile::~BaseDataFile()
{}
