/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:42:37 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/17 10:06:54 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error:" << std::endl
		<< "correct input should be: ./harlFilter <level>" << std::endl;
		return 1;
	}

	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	int index = -1;
	std::string input = av[1];
	
	for (int i = 0; i < 4; i++) {
		if (input == levels[i]) {
			index = i;
			break;
		}
	}

	Harl harl;

	switch (index) {
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return 1;
		default:
			for (; index < 4; index++)
				harl.complain(levels[index]);
			return 0;
	}

	return 0;
}