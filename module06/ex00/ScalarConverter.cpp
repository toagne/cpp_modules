/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:11:35 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/30 15:21:40 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & src) { (void)src; }
ScalarConverter & ScalarConverter::operator = (ScalarConverter const & src) { (void)src; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string type) {
	char c;
	int i;
	// float f;
	// double d;
	if (type[0] >= 32 && type[0] <= 126) {
		c = type[0];
		if (c >= '0' && c <= '9') {
			i = static_cast<int>(c);
		}
		else
			i = -117;
	}
	else {
		c = '~';
		i = -117;
	}
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
}