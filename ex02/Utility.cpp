/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:38:49 by athonda           #+#    #+#             */
/*   Updated: 2025/10/09 11:48:00 by athonda          ###   ########.fr       */
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
