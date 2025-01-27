/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:12 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/27 08:33:06 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("unknown_clap_name"), _name("unknown") {
	_hitPoints = FragTrap::staticHitPoints;
	_energyPoints = ScavTrap::staticEnergyPoints;
	_attackDamage = FragTrap::staticAttackDamage;
	std::cout << "Default constructor called for DiamondTrap " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name) {
	_hitPoints = FragTrap::staticHitPoints;
	_energyPoints = ScavTrap::staticEnergyPoints;
	_attackDamage = FragTrap::staticAttackDamage;
	std::cout << "Parametrized constructor called for DiamondTrap " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) { std::cout << "Copy consructor called for DiamondTrap" << std::endl; *this = src; }

DiamondTrap & DiamondTrap::operator = (DiamondTrap const & src) {
	std::cout << "Copy assignment operator called for DiamondTrap" << std::endl;
	if (this != &src) {
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() { std::cout << "Destructor called for DiamondTrap " << this->_name << std::endl; }

void DiamondTrap::whoAmI() {
	if (_hitPoints > 0)
		std::cout << "DiamondTrap name: " << _name << ". ClapTrap name: " << ClapTrap::_name << std::endl;
	else
		std::cout << "DiamondTrap " << _name << " is dead so it can't speak" << std::endl;

}