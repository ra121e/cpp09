/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:58:02 by athonda           #+#    #+#             */
/*   Updated: 2025/07/29 18:43:41 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

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
	a.print_before();
	a.sort();
	return (0);
}