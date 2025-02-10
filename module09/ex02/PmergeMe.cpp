/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:15:45 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/10 14:54:08 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArgs(char **av) {
	std::set<int> uniqueArgs;
	for (int i = 1; av[i]; i++) {
		std::string arg(av[i]);
		try {
			long l = std::stol(arg);
			if (l < 0)
				throw std::runtime_error(arg + " is negative");
			if (l > std::numeric_limits<int>::max())
				throw std::runtime_error(arg + " is bigger than INT_MAX");
			if (static_cast<double>(static_cast<int>(std::stod(arg))) != static_cast<double>(std::stod(arg)))
				throw std::runtime_error(arg + " is a floating-point number, expected an integer");
			if (!uniqueArgs.insert(static_cast<int>(l)).second)
				throw std::runtime_error("found a duplicate argument: " + arg);
			_args.push_back(static_cast<int>(l));
		} catch (std::invalid_argument & e) {
			throw std::runtime_error("invalid argument: " + arg);
		} catch (std::out_of_range &) {
			throw std::runtime_error("number is out of range: " + arg);
		} catch (std::exception & e) {
			throw;
		}
	}
}

void PmergeMe::sort() {
	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i , _args.size(); i++)
		pairs.emplace_back(_args[i], _args[i + 1]);
}

void PmergeMe::execute(char **av) {
	parseArgs(av);
	sort();
}