/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 06:34:37 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/28 12:14:59 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name), _nUnequipped(0), _maxUnequipped(4) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
	_unequipped = new AMateria* [_maxUnequipped];
}

Character::Character(Character const & src) : _name(src._name),
											  _nUnequipped(src._nUnequipped),
											  _maxUnequipped(src._maxUnequipped) {
	for (int i = 0; i < 4; i++) {
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = nullptr;
	}
	_unequipped = new AMateria* [_maxUnequipped];
	for (int i = 0; i < 4; i++)
		_unequipped[i] = src._unequipped[i]->clone();
}

Character & Character::operator = (Character const & src) {
	if (this != &src) {
		_name = src._name;
		_nUnequipped = src._nUnequipped;
		_maxUnequipped = src._maxUnequipped;
		for (int i = 0; i < 4; i++) {
			delete this->_inventory[i];
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = nullptr;
		}
		for (int i = 0; i < 4; i++)
			delete _unequipped[i];
		delete[] _unequipped;
		_unequipped = new AMateria* [_maxUnequipped];
		for (int i = 0; i < 4; i++)
			_unequipped[i] = src._unequipped[i]->clone();
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
	}
	for (int i = 0; i < _nUnequipped; i++)
		delete _unequipped[i];
	delete[] _unequipped;
}

std::string const & Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		if (_nUnequipped == _maxUnequipped) {
			_maxUnequipped *= 2;
			AMateria **newArray = new AMateria* [_maxUnequipped];
			for (int i = 0; i < _nUnequipped; i++)
				newArray[i] = _unequipped[i];
			delete[] _unequipped;
			_unequipped = newArray;
		}
		_unequipped[_nUnequipped] = _inventory[idx];
		_nUnequipped++;
		_inventory[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4)
		if (_inventory[idx])
			_inventory[idx]->use(target);
}