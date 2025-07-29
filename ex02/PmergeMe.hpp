/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:07:27 by athonda           #+#    #+#             */
/*   Updated: 2025/07/29 18:33:12 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

class Pmergeme
{
	public:
		Pmergeme();
		Pmergeme(Pmergeme const &other);
		Pmergeme	&operator=(Pmergeme const &other);
		~Pmergeme();

		void	setInput(int ac, char **av);
		void	sort();
		void	print_before() const;


	private:
		std::vector<unsigned int>	_value;
		std::vector<unsigned int>	_a;
		std::vector<unsigned int>	_b;
		std::deque<unsigned int>	_deque;

		void	print(std::vector<unsigned int> v) const;
		void	print_a() const;
		void	print_b() const;
};

#endif