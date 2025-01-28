/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:45:41 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/28 10:18:25 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_materia[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	for (int i = 0; i < 4; i++) {
		if (src._materia[i])
			_materia[i] = src._materia[i]->clone();
		else
			_materia[i] = nullptr;
	}
}

MateriaSource & MateriaSource::operator = (MateriaSource const & src) {
	if (this != &src) {
		for (int i = 0; i < 4; i++) {
			delete _materia[i];
			if (src._materia[i])
				_materia[i] = src._materia[i]->clone();
			else
				_materia[i] = nullptr;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (_materia[i])
			delete _materia[i];
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!_materia[i])
		{
			_materia[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materia[i] && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return 0;
}