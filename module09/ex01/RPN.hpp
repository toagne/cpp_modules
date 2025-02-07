/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:09:21 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/07 16:20:04 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <sstream>

class RPN
{
private:
	std::list<std::string> _args;
public:
	RPN();
	RPN(RPN const & src);
	RPN & operator = (RPN const & src);
	~RPN();

	void execute(int ac, char **av);
	void parseArguments(int ac, char **av);
	void checkArgsErr(std::string arg, int *n_of_n);
	void execCalc(int ac, char **av);
	void processOperator(std::string op);
};