/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:54:04 by athonda           #+#    #+#             */
/*   Updated: 2025/09/25 14:18:22 by athonda          ###   ########.fr       */
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
		}
		else
		{
			p = std::make_pair(_value[2 * i], _value[2 * i + 1]);
			_pair.push_back(p);
		}

	}
//	if ((2 * i + 1) == this->_value.size())
//	{
//		_odd.push_back(_value[2 * i]);
//	}
	print_pair(_pair);

	std::sort(_pair.begin(), _pair.end());
	print_pair(_pair);

	std::vector<std::pair<unsigned int, unsigned int> >::const_iterator it;
	for (it = _pair.begin(); it != _pair.end(); ++it)
	{
		_a.push_back(it->first);
		_b.push_back(it->second);
	}
	if ((2 * i + 1) == this->_value.size())
		_b.push_back(_value[2 * i]);
	print_a();
	print_b();
//	_a.insert(_a.begin(), *_b.begin());
//	print_a();
	_a.insert(_a.begin(), *_b.begin());
	print_a();
	print_b();

	unsigned n = _pair.size();
	std::cout << "n = " << n << std::endl;
	_jacobsthal.push_back(1);
	std::cout << "Jacobsthal: ";
	print(_jacobsthal);
	std::cout << std::endl;
	unsigned j_prev = 1;
	unsigned j_curr = 3;
	std::cout << "j_prev = " << j_prev << ", j_curr = " << j_curr << std::endl;
	unsigned t = 2;
	while (n > j_curr)
	{
		unsigned int pos = j_curr;
		while (pos > j_prev)
		{
			_jacobsthal.push_back(pos);
			std::cout << "Jacobsthal: ";
			print(_jacobsthal);
			std::cout << std::endl;
			--pos;
		}
		++t;
		j_prev = j_curr;
		j_curr = Jacobsthal(t);
		std::cout << "j_prev = " << j_prev << ", j_curr = " << j_curr << std::endl;
	}
	while (n > j_prev)
	{
		_jacobsthal.push_back(n);
		std::cout << "Jacobsthal: ";
		print(_jacobsthal);
		std::cout << std::endl;
		--n;
	}
	print(_jacobsthal);
}

unsigned int Pmergeme::Jacobsthal(unsigned int n)
{
	if (n == 0)
		return (1);
	if (n == 1)
		return (1);
	return (Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2));
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
