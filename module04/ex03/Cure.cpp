/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:04:01 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/28 09:52:52 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure () : AMateria("cure") {}

Cure::Cure (Cure const & src) :AMateria(src._type) {} // to check

Cure & Cure::operator = (Cure const & src) { // to check
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Cure::~Cure () {}

AMateria *Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}