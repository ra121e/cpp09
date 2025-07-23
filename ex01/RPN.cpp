/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:49:07 by athonda           #+#    #+#             */
/*   Updated: 2025/07/23 09:04:47 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <cctype>

Rpn::Rpn()
{}

Rpn::Rpn(Rpn const &other):
	_stack(other._stack)
{}

Rpn	&Rpn::operator=(Rpn const &other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return (*this);
}

Rpn::~Rpn()
{}

void	Rpn::calc(char *str)
{
	std::stringstream	ss(str);
	std::string			character;
	while (ss >> character)
	{
		if (ss.fail() || character.empty())
		{
			return ;
		}
		unsigned ch = static_cast<unsigned char>(character[0]);
		if (std::isdigit(ch))
		{
			std::stringstream	ss_c(character);
			unsigned int		num;
			ss_c >> num;
			if (ss_c.fail() || !ss_c.eof())
			{
				return ;
			}
			_stack.push(num);
			std::cout << _stack.top() << " ";
		}
//		else if(ch == "+" || ch == "*" || ch == "-" || ch == "/")
//		else
//		{
//			std::cerr << "error: wrong character." << std::endl;
//			return ;
//		}
	}

}