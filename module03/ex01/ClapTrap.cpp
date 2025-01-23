/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:24:35 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/23 16:05:19 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitpoints, int energyPoints, int attackDamage)
	: _name(name), _hitPoints(hitpoints), _energyPoints(energyPoints), _attackDamage(attackDamage) {
	std::cout << "Parametrized constructor called for ClapTrap " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) { std::cout << "Copy consructor called for ClapTrap" << std::endl; *this = src; }

ClapTrap & ClapTrap::operator = (ClapTrap const & src) {
	std::cout << "Copy assignment operator called for ClapTrap" << std::endl;
	if (this != &src) {
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() { std::cout << "Destructor called for ClapTrap " << this->_name << std::endl; }

void ClapTrap::attack(const std::string& target) {
	if (!_energyPoints)
		std::cout << "ClapTrap " << _name << " can't attack because it has no energy points" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is dead so can't attack" << std::endl;
	else {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Total points: " << _hitPoints;
		if (_hitPoints <= 0)
			std::cout << " | ClapTrap " << _name << " is dead!" << std::endl;
		else
			std::cout << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't take any damage because it is already dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!_energyPoints)
		std::cout << "ClapTrap " << _name << " can't be repaired because it has no energy points" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is dead so can't be repaired" << std::endl;
	else {
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " has been repaired. It gains back " << amount << " points! Total points: " << _hitPoints << std::endl;
	}
}