/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:09:21 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/13 19:05:49 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <sstream>
#include <limits>

class RPN
{
private:
	std::list<int> _args;
public:
	RPN();
	RPN(RPN const & src);
	RPN & operator = (RPN const & src);
	~RPN();

	void execute(char **av);
	void parseArguments(char **av);
	void processOperator(std::string op);
};