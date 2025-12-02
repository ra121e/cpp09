#include "IRateAPI.hpp"

IRateAPI::IRateAPI()
{}

IRateAPI::IRateAPI(const IRateAPI &other)
{
	(void)other;
}

IRateAPI	&IRateAPI::operator=(const IRateAPI &other)
{
	if (this != &other)
	{
		// 現在はメンバがないので何もしない
		(void)other;
	}
	return (*this);
}

IRateAPI::~IRateAPI()
{}
