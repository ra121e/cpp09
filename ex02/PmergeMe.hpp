/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:07:27 by athonda           #+#    #+#             */
/*   Updated: 2025/09/30 22:03:26 by athonda          ###   ########.fr       */
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
		std::vector<unsigned int>	sort(std::vector<unsigned int> value);
		void	print_before() const;
		const std::vector<unsigned int>	&getValue() const;
		const std::vector<size_t>	&getIndex() const;
		void	print_pair(std::vector<std::pair<unsigned int, unsigned int> > const &v) const;
		void	print(std::vector<unsigned int> const &v) const;
		void	print(std::vector<size_t> const &v) const;
		void	print_a() const;
		void	print_b() const;


	private:
		std::vector<unsigned int>	_value;
		std::vector<size_t>			_index;
		std::vector<std::pair<unsigned int, unsigned int> >	_pair;
		std::vector<unsigned int>	_odd;
		bool						is_odd;
		unsigned int				counter;
		std::vector<unsigned int>	_a;
		std::vector<unsigned int>	_b;
		std::vector<unsigned int>	_jacobsthal;
		std::deque<unsigned int>	_deque;

		unsigned int Jacobsthal(unsigned int n);
		std::vector<unsigned int>::size_type binary_search(std::vector<unsigned int> const &v, unsigned int value);
};

std::ostream	&operator<<(std::ostream &os, std::pair<unsigned int, unsigned int> const &p);
#endif
