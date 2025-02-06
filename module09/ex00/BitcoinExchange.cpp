/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:57:55 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/06 15:45:24 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { _readCSV(); }

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::_readCSV() {
	std::ifstream infile("data.csv");
	if (!infile)
		throw std::runtime_error("Failed to open file: data.csv");
	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line)) {
		std::string date;
		float rate;
		std::stringstream streamLine(line);
		getline(streamLine, date, ',');
		streamLine >> rate;
		_csvData.insert({date, rate});
	}
	infile.close();
	// for(auto i = _csvData.begin(); i != _csvData.end(); i++)
		// std::cout << i->first << "	" << i->second << std::endl;
}

void BitcoinExchange::checkInputFileLine(std::string line) {
	std::regex lineFormat(R"(\d{4}-\d{2}-\d{2}\s*\|\s*-?\d+(\.\d+)?)");
	if (!std::regex_match(line, lineFormat)) {
		throw std::runtime_error("Error: bad input => " + line);
	}
}

std::string BitcoinExchange::trimSpaces(std::string str) {
	size_t first = str.find_first_not_of(" ");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" ");
	return (str.substr(first, (last - first + 1)));
	
}

void BitcoinExchange::checkInputFileValidDateAndValue(std::string date, float value) {
	if (value > 1000)
		throw std::runtime_error("Error: too large a number.");
	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
	std::istringstream streamDate(date);
	std::tm tm = {};
	streamDate >> std::get_time(&tm, "%Y-%m-%d");
	if (streamDate.fail())
		throw std::runtime_error("Error: not a valid date.");
}

void BitcoinExchange::performExchnge(std::string path) {
	std::ifstream infile(path);
	if (!infile)
		throw std::runtime_error("Failed to open file: " + path);
	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line)) {
		try {
			BitcoinExchange::checkInputFileLine(line);
			std::string date;
			float value;
			std::stringstream streamLine(line);
			getline(streamLine, date, '|');
			date = trimSpaces(date);
			streamLine >> value;
			BitcoinExchange::checkInputFileValidDateAndValue(date, value);
			// std::cout << date << "|" << value << std::endl;
			std::map<std::string, float>::iterator i = _csvData.find(date);
			if (i != _csvData.end())
				std::cout << date << " => " << value << " = " << (i->second * value) << std::endl;
			else {
				std::map<std::string, float>::iterator j = _csvData.lower_bound(date);
				if (j == _csvData.begin())
					std::cout << "TODO" << std::endl;
				else {
					--j;
					std::string closestLowerDate = j->first;
					std::cout << closestLowerDate << " => " << value << " = " << (j->second * value) << std::endl;
				}
			}
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
}