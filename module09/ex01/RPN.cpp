/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:08:55 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/07 16:20:31 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

void RPN::checkArgsErr(std::string arg, int *n_of_n) {
	try{
		if (*n_of_n >= 10)
			throw std::runtime_error("input has more than 10 numbers");
		std::stoi(arg);
		(*n_of_n)++;
	} catch (std::invalid_argument & e) {
		if (arg != "+" && arg != "-" && arg != "/" && arg != "*")
			throw std::runtime_error("invalid argument: " + arg);
	} catch (std::out_of_range & e) {
		throw std::runtime_error("number is out of range: " + arg);
	}
}

void RPN::parseArguments(int ac, char **av) {
	int n_of_n = 0;
	if (ac == 2) {
		std::istringstream argsStream(av[1]);
		std::string arg;
		while (argsStream >> arg)
			checkArgsErr(arg, &n_of_n);
	}
	else {
		for (int i = 1; av[i]; i++) {
			std::string arg(av[i]);
			checkArgsErr(arg, &n_of_n);
		}
	}
}

void RPN::processOperator(std::string op) {
	if (_args.size() < 2)
		throw std::runtime_error("too few numbers to perform this operation: " + op);
	auto it1 = std::prev(_args.end());
	auto it2 = std::prev(_args.end(), 2);
	int n1 = stoi(*it1);
	int n2 = stoi(*it2);
	int res = 0;
	switch (op[0])
	{
	case '+':
		res = n2 + n1;
		break;
	case '-':
		res = n2 - n1;
		break;
	case '*':
		res = n2 * n1;
		break;
	case '/':
		if (n1 == 0)
			throw std::runtime_error("cannot divide by 0");
		res = n2 / n1;
		break;
	default:
		throw std::runtime_error("unknown operator " + op);
	}
	_args.pop_back();
	_args.pop_back();
	_args.push_back(std::to_string(res));
}

void RPN::execCalc(int ac, char **av) {
	if (ac == 2) {
		std::istringstream argsStream(av[1]);
		std::string arg;
		while (argsStream >> arg) {
			try {
				std::stoi(arg);
				// std::cout << arg << " ";
				_args.push_back(arg);
			} catch (std::invalid_argument & e) {
				processOperator(arg);
			}
		}
		for (auto i = _args.begin(); i != _args.end(); i++)
			std::cout << *i << std::endl;
	}
	// else {
	// 	for (int i = 1; av[i]; i++) {
	// 		std::string arg(av[i]);
	// 	}
	// }
}

void RPN::execute(int ac, char **av) {
	try {
		parseArguments(ac, av);
		execCalc(ac, av);
	} catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}