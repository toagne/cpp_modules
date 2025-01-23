/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:24:03 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/23 16:29:02 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("unknown", 100, 100, 30) {
	std::cout << "Default constructor called for FragTrap " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "Parametrized constructor called for FragTrap " << this->_name << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) { std::cout << "Copy consructor called for FragTrap" << std::endl; *this = src; }

FragTrap & FragTrap::operator = (FragTrap const & src) {
	std::cout << "Copy assignment operator called for FragTrap" << std::endl;
	if (this != &src) {
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() { std::cout << "Destructor called for FragTrap " << this->_name << std::endl; }

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " says: Give me a high five!" << std::endl;
}