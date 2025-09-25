/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:07:27 by athonda           #+#    #+#             */
/*   Updated: 2025/09/25 13:14:53 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <utility>
# include <vector>
# include <deque>
# include <ostream>

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
		std::vector<std::pair<unsigned int, unsigned int> >	_pair;
		std::vector<unsigned int>	_odd;
		bool						is_odd;
		unsigned int				counter;
		std::vector<unsigned int>	_a;
		std::vector<unsigned int>	_b;
		std::vector<unsigned int>	_jacobsthal;
		std::deque<unsigned int>	_deque;

		unsigned int Jacobsthal(unsigned int n);
		unsigned int	binary_search(std::vector<unsigned int> const &v, unsigned int value);
		void	print_pair(std::vector<std::pair<unsigned int, unsigned int> > const &v) const;
		void	print(std::vector<unsigned int> const &v) const;
		void	print_a() const;
		void	print_b() const;
};

std::ostream	&operator<<(std::ostream &os, std::pair<unsigned int, unsigned int> const &p);
#endif
