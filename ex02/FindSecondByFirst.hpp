/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FindSecondByFirst.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:31:50 by athonda           #+#    #+#             */
/*   Updated: 2025/09/29 22:52:57 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FINDSECONDBYFIRST_HPP
# define FINDSECONDBYFIRST_HPP

#include <vector>

class FindSecondByFirst
{
	private:
		unsigned int	_first;

	public:
		FindSecondByFirst(unsigned int value);
		~FindSecondByFirst();
		bool	operator()(std::pair<unsigned int, unsigned int> const &p) const;
};

#endif // FINDSECONDBYFIRST_HPP
