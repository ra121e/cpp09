/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:37:16 by athonda           #+#    #+#             */
/*   Updated: 2025/10/09 12:10:36 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

# include <string>
# include <vector>
# include <utility>


std::ostream	&operator<<(std::ostream &os, std::pair<unsigned int, unsigned int> const &p);

void	print_pair(std::vector<std::pair<unsigned int, unsigned int> > const &v);
void	print(std::vector<unsigned int> const &v);
void	print(std::vector<size_t> const &v);
//void	print_a();
//void	print_b();

#endif // UTILITY_HPP
