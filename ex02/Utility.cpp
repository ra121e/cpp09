/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:38:49 by athonda           #+#    #+#             */
/*   Updated: 2025/10/09 14:12:51 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utility.hpp"
#include <iostream>
#include <utility>
#include <string>

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
