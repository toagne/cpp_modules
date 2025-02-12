/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:15:31 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/12 16:03:36 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: correct usage is: ./PmergeMe <positive int0> <positive int1> ... <positive intn>" << std::endl;
		return 1;
	}
	try {
		PmergeMe a;
		a.execute(av);
	} catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}