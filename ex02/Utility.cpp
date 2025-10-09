/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:38:49 by athonda           #+#    #+#             */
/*   Updated: 2025/10/09 13:52:22 by athonda          ###   ########.fr       */
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

void	print(std::vector<std::pair<unsigned int, unsigned int> >const &v)
{
	for (std::vector<std::pair<unsigned int, unsigned int> >::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
}

void	print(std::vector<unsigned int> const &v)
{
	for (std::vector<unsigned int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
}

//void	print_before()
//{
//	print(_value);
//	std::cout << std::endl;
//}

//void	print_a()
//{
//	print(_a);
//}
//
//void	print_b()
//{
//	print(_b);
//}
