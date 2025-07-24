/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:49:07 by athonda           #+#    #+#             */
/*   Updated: 2025/07/24 16:43:58 by athonda          ###   ########.fr       */
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
		if (ss.fail() || character.empty() || character.size() != 1)
		{
			std::cerr << "Error: Wrong syntax(0-9 single digit or operators (+-*/) only)" << std::endl;
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
//			std::cout << _stack.top() << " ";
		}
		else if(ch == '+' || ch == '*' || ch == '-' || ch == '/')
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error: Wrong Syntax (operator needs 2 operands)" << std::endl;
				return ;
			}
			int	next = _stack.top();
			_stack.pop();
			int	first = _stack.top();
			_stack.pop();
			if (ch == '+')
				_stack.push(first + next);
			else if (ch == '-')
				_stack.push(first - next);
			else if (ch == '*')
				_stack.push(first * next);
			else if (ch == '/')
				_stack.push(first / next);
//			std::cout << _stack.top() << std::endl;
		}
		else
		{
			std::cerr << "error: wrong character." << std::endl;
			return ;
		}
	}
	int	result = _stack.top();
	_stack.pop();
	if (!_stack.empty())
	{
		std::cerr << "error: wrong syntax, shortage of operator." << std::endl;
		return ;
	}
	else
		std::cout << result << std::endl;
}