/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:43:39 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/17 10:15:37 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::_debug() {
	std::cout << "[ DEBUG ]"
			  << std::endl
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
			  << std::endl
			  << "I really do!"
			  << std::endl
			  << std::endl;
}

void Harl::_info() {
	std::cout << "[ INFO ]"
			  << std::endl
			  << "I cannot believe adding extra bacon costs more money."
			  << std::endl
			  <<"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl
			  << std::endl;
}

void Harl::_warning() {
	std::cout << "[ WARNING ]"
			  << std::endl
			  << "I think I deserve to have some extra bacon for free."
			  << std::endl
			  << "I’ve been coming for years whereas you started working here since last month."
			  << std::endl
			  << std::endl;
}

void Harl::_error() {
	std::cout << "[ ERROR ]"
			  << std::endl
			  << "This is unacceptable! I want to speak to the manager now."
			  << std::endl
			  << std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void (Harl::*functions[4])() = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};
	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*functions[i])();
			return;
		}
	}
}