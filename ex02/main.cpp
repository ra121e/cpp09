/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:58:02 by athonda           #+#    #+#             */
/*   Updated: 2025/10/11 13:09:13 by athonda          ###   ########.fr       */
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
	if (!a.setInput(ac, av))
		return 1;
	print(a.getValue(), "Before");
//	a.print(a.getIndex());

	long start_time = getTime();
	a.sort(a.getValue());
	print(a.getSorted(), "After");
	long end_time = getTime();
	std::cout << "Time to process a rage of the elements with vector: ";
	std::cout << end_time - start_time << " microseconds" << std::endl;
	std::cout << "Counter: " << a.getCounter() << std::endl;

	Pmergeme<std::deque, unsigned int> b;
	if (!b.setInput(ac, av))
		return 1;
	print(b.getValue(), "Before");

	long start_deque = getTime();
	b.sort(b.getValue());
	print(b.getSorted(), "After");
	long end_deque = getTime();
	std::cout << "Time to process a rage of the elements with deque: ";
	std::cout << end_deque - start_deque << " microseconds" << std::endl;
	std::cout << "Counter: " << b.getCounter() << std::endl;
	return (0);
}
