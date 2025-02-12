/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:15:45 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/12 16:07:54 by mpellegr         ###   ########.fr       */
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
			_vector.push_back(static_cast<int>(l));
			_deque.push_back(static_cast<int>(l));
		} catch (std::invalid_argument & e) {
			throw std::runtime_error("invalid argument: " + arg);
		} catch (std::out_of_range &) {
			throw std::runtime_error("number is out of range: " + arg);
		} catch (std::exception & e) {
			throw;
		}
	}
}

template <typename T>
int PmergeMe::binaryInsertion(T &container, int value) {
	int left = 0;
	int right = container.size();
	while (left < right) {
		int mid = left + (right - left)/2;
		if (container[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

template <typename T>
void PmergeMe::sort(T &container) {
	std::vector<std::pair<int, int>> pairs;
	T biggerNumbers;
	for (size_t i = 0; i < container.size() - 1; i += 2) {
		if (container[i] < container[i+1]) {
			int temp = container[i];
			container[i] = container[i+1];
			container[i+1] = temp;
		}
		pairs.push_back({container[i], container[i+1]});
		biggerNumbers.push_back(container[i]);
	}
	if (container.size() % 2 != 0)
		biggerNumbers.push_back(container[container.size() - 1]);
	for (size_t i = 1; i < biggerNumbers.size(); i++) {
		int temp = biggerNumbers[i];
		ssize_t j = i - 1;
		while (j >= 0 && biggerNumbers[j] > temp) {
			biggerNumbers[j + 1] = biggerNumbers[j];
			j--;
		}
		biggerNumbers[j + 1] = temp;
	}
	for (auto it : pairs) {
		int pos = binaryInsertion(biggerNumbers, it.second);
		biggerNumbers.insert(biggerNumbers.begin() + pos, it.second);
	}
	container = biggerNumbers;
}

void PmergeMe::execute(char **av) {
	// parsing
	parseArgs(av);
	// printing unsorted sequence
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << "\n";
	// sorting vector container
	auto start = std::chrono::steady_clock::now();
	sort(_vector);
	auto end = std::chrono::steady_clock::now();
	// printing sorted sequence
	std::cout << "After : ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << "\n";
	// printing time for vector
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : "
			  << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
	// sorting deque container
	auto startD = std::chrono::steady_clock::now();
	sort(_deque);
	auto endD = std::chrono::steady_clock::now();
	// printing time for deque
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : "
			<< std::chrono::duration<double, std::milli>(endD - startD).count() << " ms" << std::endl;
}