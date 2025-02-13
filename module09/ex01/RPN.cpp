/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:08:55 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/13 19:13:06 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const & src) { *this = src; }

RPN & RPN::operator = (RPN const & src) {
	if (this != &src)
		_args = src._args;
	return *this;
}

RPN::~RPN() {}

void RPN::parseArguments(char **av) {
	std::istringstream argsStream(av[1]);
	std::string arg;
	while (argsStream >> arg) {
		try {
			// std::stoi(arg);
			if (std::stoi(arg) > 10)
				throw std::runtime_error(arg + " is bigger than 10, arguments must be between 0 and 9");
		} catch (std::invalid_argument &) {
			if (arg != "+" && arg != "-" && arg != "/" && arg != "*")
				throw std::runtime_error("invalid argument: " + arg);
		} catch (std::out_of_range &) {
			throw std::runtime_error("number is out of range: " + arg);
		}
	}
}

void RPN::processOperator(std::string op) {
	if (_args.size() < 2)
		throw std::runtime_error("too few numbers to perform this operation: " + op);
	int n1 = _args.back();
	_args.pop_back();
	int n2 = _args.back();
	_args.pop_back();
	long long res = 0;
	switch (op[0])
	{
	case '+':
		res = static_cast<long>(n2) + n1;
		break;
	case '-':
		res = static_cast<long>(n2) - n1;
		break;
	case '*':
		res = static_cast<long>(n2) * n1;
		break;
	case '/':
		if (n1 == 0)
			throw std::runtime_error("cannot divide by 0");
		res = n2 / n1;
		break;
	default:
		throw std::runtime_error("unknown operator " + op);
	}
	if (res > std::numeric_limits<int>::max())
		throw std::runtime_error("the result of the operation is bigger than INT_MAX");
	_args.push_back(res);
}

void RPN::execute(char **av) {
	parseArguments(av);
	std::istringstream argsStream(av[1]);
	std::string arg;
	while (argsStream >> arg) {
		try {
			_args.push_back(std::stoi(arg));
		} catch (std::invalid_argument & e) {
			processOperator(arg);
		}
	}
	if (_args.size() != 1) {
		std::cout << "Final stack: [";
		for (auto i = _args.begin(); i != _args.end(); i++) {
			if (i == std::prev(_args.end()))
				std::cout << *i;
			else
				std::cout << *i << ", ";
		}
		std::cout << "]" <<std::endl;
		throw std::runtime_error("invalid RPN expression: too many or too few operators");
	}
	std::cout << _args.back() << std::endl;
}