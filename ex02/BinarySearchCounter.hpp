/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchCounter.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 21:00:31 by athonda           #+#    #+#             */
/*   Updated: 2025/09/30 22:02:05 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCHCOUNTER_HPP
# define BINARYSEARCHCOUNTER_HPP

#include <utility>
class BinarySearchCounter
{
	public:
		BinarySearchCounter(unsigned int &_counter);
		~BinarySearchCounter();
		bool operator()(std::pair<unsigned int, unsigned int> const &lhs, std::pair<unsigned int, unsigned int> const &rhs);
	private:
		unsigned int &counter;
};

#endif // BinarySearchCounter.hpp
