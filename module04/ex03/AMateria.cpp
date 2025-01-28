/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:06:00 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/28 09:54:21 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include "Character.hpp"

AMateria::AMateria() : _type("unknown") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(AMateria const & src) :_type(src._type) {}

AMateria & AMateria::operator = (AMateria const & src) {
	if (this != &src)
		this->_type = src._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const { return _type; }

void AMateria::use(ICharacter& target) {
	(void)target;
}