/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:58:02 by athonda           #+#    #+#             */
/*   Updated: 2025/10/11 10:22:40 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>
#include "Timer.hpp"
#include "Utility.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: ./PmergeMe num num num ...." << std::endl;
		return (1);
	}
	Pmergeme<std::vector, unsigned int> a;
	a.setInput(ac, av);
	print(a.getValue(), "Before");
//	a.print(a.getIndex());

	long start_time = getTime();
	a.sort(a.getValue());
	print(a.getSorted(), "After");
	long end_time = getTime();
	std::cout << "end time: " << end_time - start_time << " microseconds" << std::endl;

	Pmergeme<std::deque, unsigned int> b;
	b.setInput(ac, av);
	print(b.getValue(), "Before");

	long start_deque = getTime();
	b.sort(b.getValue());
	print(b.getSorted(), "After");
	long end_deque = getTime();
	std::cout << "end deque: " << end_deque - start_deque << " microseconds" << std::endl;
	return (0);
}
