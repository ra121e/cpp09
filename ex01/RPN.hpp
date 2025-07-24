/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:45:18 by athonda           #+#    #+#             */
/*   Updated: 2025/07/24 16:16:13 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <stack>

class	Rpn
{
	public:
		Rpn();
		Rpn(Rpn const &other);
		Rpn	&operator=(Rpn const &other);
		~Rpn();

		void	calc(char *str);
	private:
		std::stack<int>	_stack;
};


#endif