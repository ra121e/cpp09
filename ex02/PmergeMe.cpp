/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:54:04 by athonda           #+#    #+#             */
/*   Updated: 2025/10/11 14:15:56 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <sys/time.h>

std::ostream	&operator<<(std::ostream &os, std::pair<unsigned int, unsigned int> const &p)
{
	os << "[" << p.first << ", " << p.second << "]";
	return (os);
}

void	print(std::vector<std::pair<unsigned int, unsigned int> >const &v, std::string const &s)
{
	std::cout << s << ": ";
	for (std::vector<std::pair<unsigned int, unsigned int> >::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	print(std::vector<unsigned int> const &v, std::string const &s)
{
	std::cout << s << ": ";
	for (std::vector<unsigned int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	print(std::vector<size_t> const &v, std::string const &s)
{
	std::cout << s << ": ";
	for (std::vector<size_t>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	print(std::deque<std::pair<unsigned int, unsigned int> >const &v, std::string const &s)
{
	std::cout << s << ": ";
	for (std::deque<std::pair<unsigned int, unsigned int> >::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	print(std::deque<unsigned int> const &v, std::string const &s)
{
	std::cout << s << ": ";
	for (std::deque<unsigned int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	print(std::deque<size_t> const &v, std::string const &s)
{
	std::cout << s << ": ";
	for (std::deque<size_t>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

long	getTime()
{
	struct timeval	tv;
	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

BinarySearchCounter::BinarySearchCounter(unsigned int &_counter): counter(_counter)
{}

BinarySearchCounter::~BinarySearchCounter()
{}

bool BinarySearchCounter::operator()(std::pair<unsigned int, unsigned int> const &lhs, std::pair<unsigned int, unsigned int> const &rhs)
{
	++counter;
	return lhs.first < rhs.first;
}

FindSecondByFirst::FindSecondByFirst(unsigned int value)
{
	_first = value;
}

FindSecondByFirst::~FindSecondByFirst()
{}

bool	FindSecondByFirst::operator()(std::pair<unsigned int, unsigned int> const &p) const
{
	return (p.first == _first);
}
