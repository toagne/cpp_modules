/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:57:51 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/07 08:13:53 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try {
		BitcoinExchange a;
		a.performExchnge(av[1]);
	} catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}