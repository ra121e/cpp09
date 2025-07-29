/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:54:04 by athonda           #+#    #+#             */
/*   Updated: 2025/07/29 20:54:15 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <algorithm>

Pmergeme::Pmergeme()
{}

Pmergeme::Pmergeme(Pmergeme const &other):
	_value(other._value),
	_deque(other._deque)
{

}

Pmergeme	&Pmergeme::operator=(Pmergeme const &other)
{
	if (this != &other)
	{
		_value = other._value;
		_deque = other._deque;
	}
	return (*this);
}

Pmergeme::~Pmergeme()
{}

void	Pmergeme::setInput(int ac, char **av)
{
	std::stringstream	ss;
	for (int i = 1; i < ac; ++i)
	{
		ss << av[i] << " ";
	}

	std::string			line;
	std::getline(ss, line);
	if (line.empty() || ss.fail() || !ss.eof())
	{
		std::cerr << "error: Wrong input of argument." << std::endl;
		return ;
	}

	std::stringstream	ss_input(line);
	std::string			token;
	while (ss_input >> token)
	{
		if (token.empty() || ss_input.fail())
		{
			std::cerr << "error: Wrong input of token." << std::endl;
			return ;
		}
		std::stringstream	ss_num(token);
		unsigned int		num;
		ss_num >> num;
		if (ss_num.fail() || !ss_num.eof())
		{
			std::cerr << "error: Wrong input of numbers." << std::endl;
			return ;
		}
		_value.push_back(num);
	}
}

void	Pmergeme::sort()
{
	size_t i = 0;
	for (; (2 * i + 1) < this->_value.size(); ++i)
	{
		std::pair<unsigned int, unsigned int>	p;
		if (_value[2 * i] < _value[2 * i + 1])
		{
			p = std::make_pair(_value[2 * i + 1], _value[2 * i]);
			_pair.push_back(p);
//			_a.push_back(_value[2 * i + 1]);
//			_b.push_back(_value[2 * i]);
		}
		else
		{
			p = std::make_pair(_value[2 * i], _value[2 * i + 1]);
			_pair.push_back(p);
//			_a.push_back(_value[2 * i]);
//			_b.push_back(_value[2 * i + 1]);
		}

	}
	if ((2 * i + 1) == this->_value.size())
	{
		_odd.push_back(_value[2 * i]);
	}
	print_pair(_pair);
	std::cout << "after print pair" << std::endl;
//	print_a();
//	print_b();

//	std::sort(_a.begin(), _a.end());
//	_a.insert(_a.begin(), *_b.begin());
//	print_a();
}

void	Pmergeme::print_pair(std::vector<std::pair<unsigned int, unsigned int> > const &v) const
{
	for (std::vector<std::pair<unsigned int, unsigned int> >::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	Pmergeme::print(std::vector<unsigned int> const &v) const
{
	for (std::vector<unsigned int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	Pmergeme::print_before() const
{
	print(_value);
}

void	Pmergeme::print_a() const
{
	print(_a);
}

void	Pmergeme::print_b() const
{
	print(_b);
}

std::ostream	&operator<<(std::ostream &os, std::pair<unsigned int, unsigned int> const &p)
{
	os << "[" << p.first << ", " << p.second << "]";
	return (os);
}