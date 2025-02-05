/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:58:33 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/05 14:38:23 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {
	std::list<int> l = {0, 1, 2, 3, 4};
	std::cout << "std::list<int>\n";
	std::cout << "Value found at index: " << *easyfind(l, 4) << std::endl;
	try {
		std::list<int>::const_iterator it = easyfind(l, 7);
		std::cout << "Value found at index: " << *it << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";

	// *************************************************************
	std::vector<int> v = {5, 6, 7, 8, 9};
	std::cout << "std::vector<int>\n";
	std::cout << "Value found at index: " << *easyfind(v, 7) << std::endl;
	try {
		std::vector<int>::const_iterator it = easyfind(v, 17);
		std::cout << "Value found at index: " << *it << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}