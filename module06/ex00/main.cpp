/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:20:49 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/30 15:20:02 by mpellegr         ###   ########.fr       */
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
	std::string str = av[1];
	ScalarConverter::convert(str);

	return 0;
}