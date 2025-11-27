#include "IMapAPI.hpp"

IMapAPI::IMapAPI()
{}

IMapAPI::IMapAPI(const IMapAPI &other)
{
	(void)other;
}

IMapAPI	&IMapAPI::operator=(const IMapAPI &other)
{
	if (this != &other)
	{
		// 現在はメンバがないので何もしない
		(void)other;
	}
	return (*this);
}

IMapAPI::~IMapAPI()
{}
