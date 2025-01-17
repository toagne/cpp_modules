/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:52:06 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/17 16:06:54 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "correct input should be <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	
	std::string s1(av[2]);
	std::string s2(av[3]);

	if (s1.empty() || s2.empty()) {
		std::cout << "s1 and s2 can't be empty or contain null character" << std::endl;
		return 1;
	}
	
	std::ifstream ifs(av[1]);
	if (!ifs) {
		std::cerr << "error opening input file" << std::endl;
		return 1;
	}
	
	std::stringstream buffer;
	buffer << ifs.rdbuf();
	ifs.close();
	std::string content = buffer.str();

	std::size_t first_char_of_s1 = content.find(s1);
	std::size_t s1_len;
	std::string first_substr;
	std::string second_substr;
	s1_len = s1.length();
	while (s1 != s2 && first_char_of_s1 != std::string::npos) {
		first_substr = content.substr(0, first_char_of_s1);
		second_substr = content.substr(first_char_of_s1 + s1_len);
		content = first_substr + s2 + second_substr;
		first_char_of_s1 = content.find(s1);
	}

	std::string infile_name(av[1]);
	std::string outfile_name(infile_name + ".replace");

	std::ofstream ofs(outfile_name.c_str());
	if (!ofs) {
		std::cerr << "error creating output file" << std::endl;
		return 1;
	}
	ofs << content;// << std::endl;
	ofs.close();
	return 0;
}