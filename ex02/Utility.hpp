/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:37:16 by athonda           #+#    #+#             */
/*   Updated: 2025/10/09 14:12:43 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

# include <string>
# include <vector>
# include <utility>


std::ostream	&operator<<(std::ostream &os, std::pair<unsigned int, unsigned int> const &p);

void	print(std::vector<std::pair<unsigned int, unsigned int> > const &v, std::string const &s);
void	print(std::vector<unsigned int> const &v, std::string const &s);
void	print(std::vector<size_t> const &v, std::string const &s);

#endif // UTILITY_HPP
