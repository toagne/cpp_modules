/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:58:33 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/11 08:38:21 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {
	std::list<int> l = {0, 1, 2, 3, 4};
	std::cout << "std::list<int>\n";
	std::cout << "Value " << *easyfind(l, 4) << " found in container" << std::endl;
	try {
		std::list<int>::const_iterator it = easyfind(l, 7);
		std::cout << "Value " << *it << " found in container" << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";

	// *************************************************************
	std::vector<int> v = {5, 6, 7, 8, 9};
	std::cout << "std::vector<int>\n";
	std::cout << "Value " << *easyfind(v, 7) << " found in container" << std::endl;
	try {
		std::vector<int>::const_iterator it = easyfind(v, -17);
		std::cout << "Value " << *it << " found in container" << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}