/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:20:49 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/31 10:04:27 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error, correct usage is: ./converter <str>" << std::endl;
		return 1;
	}
	try {
		ScalarConverter::convert(av[1]);
	} catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}