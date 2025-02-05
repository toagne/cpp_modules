/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:14:34 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/05 19:39:22 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "* subject test\n";
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "\n";
// ***********************************************
	std::cout << "* adding a sixth element to a size 5\n";
	try {
		sp.addNumber(9);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
// ***********************************************
	std::cout << "* size 1\n";
	Span small = Span(1);
	small.addNumber(9);
	try {
		std::cout << small.shortestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << small.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
// ***********************************************
	std::cout << "* test with 100k values\n";
	Span big = Span(100000);
	std::vector<int> v;
	for (int i = 0; i < 100000; i++)
		v.push_back(i);
	big.addNumber(v.begin(), v.end());
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;
	std::cout << "\n";
// ***********************************************
	std::cout << "* test with addNumber range fail\n";
	Span s = Span(3);
	std::vector<int> v1 = {1, 2, 3, 4};
	try {
		big.addNumber(v1.begin(), v.end());
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}