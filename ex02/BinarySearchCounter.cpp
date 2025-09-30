/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchCounter.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 21:19:27 by athonda           #+#    #+#             */
/*   Updated: 2025/09/30 21:58:27 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BinarySearchCounter.hpp"
#include <utility>

BinarySearchCounter::BinarySearchCounter(unsigned int &_counter): counter(_counter)
{}

BinarySearchCounter::~BinarySearchCounter()
{}

bool BinarySearchCounter::operator()(std::pair<unsigned int, unsigned int> const &lhs, std::pair<unsigned int, unsigned int> const &rhs)
{
	++counter;
	return lhs.first < rhs.first;
}
