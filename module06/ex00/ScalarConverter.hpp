/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:55:57 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/31 13:24:33 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & src);
	ScalarConverter & operator = (ScalarConverter const & src);
	~ScalarConverter();
public:
	static void convert(std::string input);

	static int isChar(std::string const &input);
	static int isInt(std::string const &input);
	static int isFloat(std::string const &input);
	static int isDouble(std::string const &input);
	static int isPseudo(std::string const &input);

	static void convertChar(std::string const &input);
	static void convertInt(std::string const &input);
	static void convertDouble(std::string const &input);
	static void convertFloat(std::string const &input);
	static void convertPseudo(std::string const &input);

	static void printChar(char c);
	static int countDecimalPlaces(std::string const &input);
};
