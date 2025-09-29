/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:54:04 by athonda           #+#    #+#             */
/*   Updated: 2025/09/29 08:01:27 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <algorithm>
#include "BinarySearchCounter.hpp"

Pmergeme::Pmergeme(): is_odd(false), counter(0)
{}

Pmergeme::Pmergeme(Pmergeme const &other):
	_value(other._value),
	is_odd(other.is_odd),
	counter(other.counter),
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

const std::vector<unsigned int>	&Pmergeme::getValue() const
{
	return (_value);
}

const std::vector<size_t>	&Pmergeme::getIndex() const
{
	return (_index);
}

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
	size_t				index = 0;
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
		_pair.push_back(std::make_pair(num, 0));
		_index.push_back(index);
		index++;
	}
}

void	Pmergeme::sort(std::vector<unsigned int> value)
{
	std::vector<std::pair<unsigned int, unsigned int> >	pair;

	size_t i = 0;
	for (; (2 * i + 1) < value.size(); ++i)
	{
		std::pair<unsigned int, unsigned int>	p;
		if (value[2 * i] < value[2 * i + 1])
		{
			p = std::make_pair(value[2 * i + 1], value[2 * i]);
			pair.push_back(p);
		}
		else
		{
			p = std::make_pair(value[2 * i], value[2 * i + 1]);
			pair.push_back(p);
		}
		counter++;
	}
	std::cout << "Initial counter: " << counter << std::endl;
//	if ((2 * i + 1) == this->_value.size())
//	{
//		_odd.push_back(_value[2 * i]);
//	}
	print_pair(pair);

	std::sort(pair.begin(), pair.end());
	print_pair(pair);

	std::vector<std::pair<unsigned int, unsigned int> >::const_iterator it;
	for (it = pair.begin(); it != pair.end(); ++it)
	{
		_a.push_back(it->first);
		_b.push_back(it->second);
	}
	if ((2 * i + 1) == value.size())
	{
		is_odd = true;
		_b.push_back(value[2 * i]);
	}

	print_a();
	print_b();
//	_a.insert(_a.begin(), *_b.begin());
//	print_a();
//	_a.insert(_a.begin(), *_b.begin());
//	print_a();
//	print_b();

	unsigned n = pair.size();
	if (is_odd)
		n++;
	std::cout << "pair size n = " << n << std::endl;
	_jacobsthal.push_back(1);

	unsigned j_prev = 1;
	unsigned j_curr = 3;

	unsigned t = 2;
	while (n > j_curr)
	{
		unsigned int pos = j_curr;
		while (pos > j_prev)
		{
			_jacobsthal.push_back(pos);
//			std::cout << "Jacobsthal: ";
//			print(_jacobsthal);
//			std::cout << std::endl;
			--pos;
		}
		++t;
		j_prev = j_curr;
		j_curr = Jacobsthal(t);
//		std::cout << "j_prev = " << j_prev << ", j_curr = " << j_curr << std::endl;
	}
	while (n > j_prev)
	{
		_jacobsthal.push_back(n);
		--n;
	}
	std::cout << "Jacobsthal: ";
	print(_jacobsthal);
	std::cout << std::endl;

	for (std::vector<unsigned int>::const_iterator it = _jacobsthal.begin(); it != _jacobsthal.end(); ++it)
	{
		const unsigned int index_b = *it - 1; // index into _b (0-based)
		const unsigned int insert_b = _b[index_b];

		std::cout << "Inserting index " << *it << ": ";
		std::cout << "Inserting " << insert_b << std::endl;
		if (index_b < pair.size())
			std::cout << "pair of the index: " << pair[index_b] << std::endl;
		else
			std::cout << "pair of the index: [odd element]" << std::endl;
		// Determine the end of the search range in A
		std::vector<unsigned int>::iterator range_end;
		if (index_b < pair.size())
		{
			const unsigned int target_a = pair[index_b].first;
			range_end = std::find(_a.begin(), _a.end(), target_a);
			if (range_end == _a.end())
				range_end = _a.end();
		}
		else
		{
			// odd element has no paired 'first' in pair; search entire A
			range_end = _a.end();
		}
		std::vector<unsigned int>::iterator insert_pos = std::lower_bound(_a.begin(), range_end, insert_b, BinarySearchCounter(counter));
		_a.insert(insert_pos, insert_b);
		print_a();
		std::cout << "Counter: " << counter << std::endl;
	}
}



std::vector<unsigned int>::size_type Pmergeme::binary_search(std::vector<unsigned int> const &v, unsigned int value)
{
	std::vector<unsigned int>::size_type lo = 0;
	std::vector<unsigned int>::size_type hi = v.size();
	while (lo < hi)
	{
		std::vector<unsigned int>::size_type mid = lo + (hi - lo) / 2;
		if (v[mid] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
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

void	Pmergeme::print(std::vector<size_t> const &v) const
{
	for (std::vector<size_t>::const_iterator it = v.begin(); it != v.end(); ++it)
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
