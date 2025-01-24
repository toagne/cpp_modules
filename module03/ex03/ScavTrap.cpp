/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:08:18 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/24 09:29:06 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("unknown", 100, 50, 20) {
	std::cout << "Default constructor called for ScavTrap " << this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "Parametrized constructor called for ScavTrap " << this->_name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) { std::cout << "Copy consructor called for ScavTrap" << std::endl; *this = src; }

ScavTrap & ScavTrap::operator = (ScavTrap const & src) {
	std::cout << "Copy assignment operator called for ScavTrap" << std::endl;
	if (this != &src) {
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() { std::cout << "Destructor called for ScavTrap " << this->_name << std::endl; }

void ScavTrap::attack(const std::string& target) {
	if (!_energyPoints)
		std::cout << "ScavTrap " << _name << " can't attack because it has no energy points" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap " << _name << " is dead so can't attack" << std::endl;
	else {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void ScavTrap::guardGate() {
	if (_hitPoints > 0)
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " is dead so can't go in Gate keeper mode" << std::endl;
}