/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchCounter.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 21:00:31 by athonda           #+#    #+#             */
/*   Updated: 2025/09/26 21:39:02 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCHCOUNTER_HPP
# define BINARYSEARCHCOUNTER_HPP

class BinarySearchCounter
{
    public:
        BinarySearchCounter(unsigned int &_counter);
        ~BinarySearchCounter();
        bool operator()(unsigned int first, unsigned int second);
    private:
        unsigned int &counter;
};

#endif // BinarySearchCounter.hpp