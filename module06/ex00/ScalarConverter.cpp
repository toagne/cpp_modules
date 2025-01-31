/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:11:35 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/31 14:56:43 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & src) { (void)src; }
ScalarConverter & ScalarConverter::operator = (ScalarConverter const & src) { (void)src; return *this; }
ScalarConverter::~ScalarConverter() {}

int ScalarConverter::isChar(std::string const &input) {
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(static_cast<unsigned char>(input[0])))
		return 1;
	return 0;
}

int ScalarConverter::isInt(std::string const &input) {
	size_t i = 0;
	if ((input[i] == '-' || input[i] == '+') && input.length() > 1)
		i++;
	for (; i < input.length(); i++)
		if (input[i] == '.' || !std::isdigit(static_cast<unsigned char>(input[i])))
			return 0;
	return 2;
}

int ScalarConverter::isDouble(std::string const &input) {
	size_t i = 0;
	int dot_flag = 0;
	if ((input[i] == '-' || input[i] == '+') && input.length() > 1)
		i++;
	for (; i < input.length(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(input[i]))) {
			if (input[i] == '.') {
				if (dot_flag)
					return 0;
				dot_flag = 1;
			}
			else
				return 0;
		}
	}
	if (input.back() == '.')
		return 0;
	return 3;
}

int ScalarConverter::isFloat(std::string const &input) {
	size_t i = 0;
	int dot_flag = 0;
	int f_flag = 0;
	if ((input[i] == '-' || input[i] == '+') && input.length() > 1)
		i++;
	for (; i < input.length(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(input[i]))) {
			if (input[i] == '.') {
				if (dot_flag)
					return 0;
				dot_flag = 1;
			} else if (input[i] == 'f') {
				if (f_flag)
					return 0;
				f_flag = 1;
			} else
				return 0;
		}
	}
	if (input.back() != 'f' || !std::isdigit(static_cast<unsigned char>(input[0]))
		|| !std::isdigit(static_cast<unsigned char>(input[input.length() - 2])))
		return 0;
	return 4;
}

int ScalarConverter::isPseudo(std::string const &input) {
	if (!input.compare("+inff") || !input.compare("-inff") || !input.compare("nanf")
		|| !input.compare("+inf") || !input.compare("-inf") || !input.compare("nan"))
			return 5;
	return 0;
}

void ScalarConverter::printChar(char c) {
	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

int ScalarConverter::countDecimalPlaces(std::string const &input) {
	size_t dotPos = input.find('.');
	if (dotPos == std::string::npos)
		return 1;
	if (input.find('f') != std::string::npos)
		dotPos++;
	return (input.length() - dotPos - 1);
}

void ScalarConverter::convertChar(std::string const &input) {
	char c = input[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertInt(std::string const &input) {
	int i = std::stoi(input);

	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else
		ScalarConverter::printChar(static_cast<char>(i));
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertDouble(std::string const &input) {
	double d = std::stod(input);
	int precision = ScalarConverter::countDecimalPlaces(input);

	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else
		ScalarConverter::printChar(static_cast<char>(d));
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFloat(std::string const &input) {
	float f = std::stof(input);
	int precision = ScalarConverter::countDecimalPlaces(input);

	if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else
		ScalarConverter::printChar(static_cast<char>(f));
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<float>(f) << std::endl;
}

void ScalarConverter::convertPseudo(std::string const &input) {
	double d = std::stod(input);

	if (std::isnan(d)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (std::isinf(d)) {
		if (d > 0) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		} else {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	}
}

void ScalarConverter::convert(std::string input) {
	int (*checkers[5]) (const std::string& input) = {
		isChar,
		isInt,
		isDouble,
		isFloat,
		isPseudo
	};
	void (*converters[5]) (const std::string& input) = {
		convertChar,
		convertInt,
		convertDouble,
		convertFloat,
		convertPseudo
	};
	for (int i = 0; i < 5; i++) {
		if (checkers[i](input)) {
			return converters[i](input);
		}
	}
	std::cout << "invalid input, no coversion executed" << std::endl;
}