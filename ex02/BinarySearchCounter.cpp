/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchCounter.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 21:19:27 by athonda           #+#    #+#             */
/*   Updated: 2025/09/26 21:45:24 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BinarySearchCounter.hpp"

BinarySearchCounter::BinarySearchCounter(unsigned int &_counter): counter(_counter)
{}
    
BinarySearchCounter::~BinarySearchCounter()
{}

bool BinarySearchCounter::operator()(unsigned int first, unsigned int second)
{   
    ++counter;
    return first < second;
}