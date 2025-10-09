/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:58:02 by athonda           #+#    #+#             */
/*   Updated: 2025/10/09 12:12:52 by athonda          ###   ########.fr       */
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
	Pmergeme	a;
	a.setInput(ac, av);
	std::cout << "Before: ";
	print(a.getValue());
//	a.print(a.getIndex());

	long start_time = getTime();
	a.sort(a.getValue());
	long end_time = getTime();
	std::cout << "end time: " << end_time - start_time << " microseconds" << std::endl;

	return (0);
}
