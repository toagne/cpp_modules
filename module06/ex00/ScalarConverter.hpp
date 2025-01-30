/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:55:57 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/30 15:08:51 by mpellegr         ###   ########.fr       */
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
	static void convert(std::string type);
};
