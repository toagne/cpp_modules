/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:57:54 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/06 15:07:59 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <regex>
#include <iomanip>

class BitcoinExchange
{
private:
	std::map<std::string, float> _csvData;
	void _readCSV();
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & src);
	BitcoinExchange & operator = (BitcoinExchange const & src);
	~BitcoinExchange();

	void performExchnge(std::string path);
	void checkInputFileLine(std::string line);
	std::string trimSpaces(std::string str);
	void checkInputFileValidDateAndValue(std::string date, float value);
};