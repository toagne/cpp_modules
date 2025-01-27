/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:24:03 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/27 08:23:49 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

const int FragTrap::staticHitPoints = 100;
const int FragTrap::staticEnergyPoints = 100;
const int FragTrap::staticAttackDamage = 30;

FragTrap::FragTrap() : ClapTrap("unknown",
					   FragTrap::staticHitPoints,
					   FragTrap::staticEnergyPoints,
					   FragTrap::staticAttackDamage) {
	std::cout << "Default constructor called for FragTrap " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name,
									   FragTrap::staticHitPoints,
									   FragTrap::staticEnergyPoints,
									   FragTrap::staticAttackDamage) {
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
	if (_hitPoints > 0)
		std::cout << "FragTrap " << this->_name << " says: Give me a high five!" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " is dead so can't receive an high five" << std::endl;
}