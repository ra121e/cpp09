/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:54:04 by athonda           #+#    #+#             */
/*   Updated: 2025/09/30 22:05:59 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <algorithm>
#include "BinarySearchCounter.hpp"
#include "FindSecondByFirst.hpp"

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
//		if (num < 0)
//		{
//			std::cerr << "error: Negative number is not allowed." << std::endl;
//			_value.clear();
//			_pair.clear();
//			return ;
//		}
		_value.push_back(num);
		_pair.push_back(std::make_pair(num, 0));
	}
}

std::vector<unsigned int>	Pmergeme::sort(std::vector<unsigned int> value)
{
	std::vector<std::pair<unsigned int, unsigned int> >	pair;

	// stop condition
	if (value.size() <= 1)
		return (value);

	// forming pairs and sorting each pair
	std::vector<unsigned int> firsts;
	std::vector<unsigned int> seconds;
	size_t i = 0;
	for (; (2 * i + 1) < value.size(); ++i)
	{
		std::pair<unsigned int, unsigned int>	p;
		if (value[2 * i] < value[2 * i + 1])
		{
			p = std::make_pair(value[2 * i + 1], value[2 * i]);
			pair.push_back(p);
			firsts.push_back(p.first);
		}
		else
		{
			p = std::make_pair(value[2 * i], value[2 * i + 1]);
			pair.push_back(p);
			firsts.push_back(p.first);
		}
		counter++;
	}
	std::cout << "Initial counter: " << counter << std::endl;
//	if ((2 * i + 1) == this->_value.size())
//	{
//		_odd.push_back(_value[2 * i]);
//	}
	print_pair(pair);

	// recursively sort the firsts
	std::vector<unsigned int>	a;
	a = sort(firsts);
	print_pair(pair);

	// extract the seconds according to the order of firsts
	std::vector<unsigned int>	b;
	for (std::vector<unsigned int>::iterator it = a.begin(); it != a.end(); ++it)
	{
		std::vector<std::pair<unsigned int, unsigned int> >::iterator found = std::find_if(pair.begin(), pair.end(), FindSecondByFirst(*it));
		b.push_back(found->second);
		pair.erase(found);
	}
	if ((2 * i + 1) == value.size())
	{
		is_odd = true;
		b.push_back(value[2 * i]);
	}

	print_a();
	print_b();
//	_a.insert(_a.begin(), *_b.begin());
//	print_a();
//	_a.insert(_a.begin(), *_b.begin());
//	print_a();
//	print_b();

	pair.clear();
	std::vector<std::pair<unsigned int, unsigned int> > a_with_index;
	for (size_t j = 0; j < a.size(); ++j)
	{
		a_with_index.push_back(std::make_pair(a[j], j));
	}
	print_pair(a_with_index);
	// Generate Jacobsthal sequence up to size of pair (or size of pair + 1 if odd)
	_jacobsthal.clear();
	unsigned n = a_with_index.size();
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
		const unsigned int insert_b = b[index_b];
		std::pair<unsigned int, unsigned int>	b_with_index = std::make_pair(insert_b, index_b);

		std::cout << "Inserting index " << *it << ": ";
		std::cout << "Inserting " << insert_b << std::endl;
		if (index_b < b.size())
			std::cout << "number of the index: " << b[index_b] << std::endl;
		else
			std::cout << "pair of the index: [odd element]" << std::endl;
		// Determine the end of the search range in A
		std::vector<std::pair<unsigned int, unsigned int> >::iterator range_end;
		if (index_b < a_with_index.size())
		{
			const std::pair<unsigned int, unsigned int> target_a = a_with_index[index_b];
			range_end = std::find(a_with_index.begin(), a_with_index.end(), target_a);
			if (range_end == a_with_index.end())
				range_end = a_with_index.end();
		}
		else
		{
			// odd element has no paired 'first' in _pair; search entire A
			range_end = a_with_index.end();
		}
		std::vector<std::pair<unsigned int, unsigned int> >::iterator insert_pos = std::lower_bound(a_with_index.begin(), range_end, b_with_index, BinarySearchCounter(counter));
		a_with_index.insert(insert_pos, b_with_index);
		print_pair(a_with_index);

	}
	std::vector<unsigned int> a_temp;
	for (size_t k = 0; k < a_with_index.size(); ++k)
	{
		a_temp.push_back(a_with_index[k].first);
	}
	print(a_temp);
	std::cout << "Counter: " << counter << std::endl;
	return (a_temp);
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
