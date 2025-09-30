/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FindSecondByFirst.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:39:33 by athonda           #+#    #+#             */
/*   Updated: 2025/09/29 22:53:38 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FindSecondByFirst.hpp"

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
