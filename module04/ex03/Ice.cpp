/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:03:11 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/28 16:27:56 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice () : AMateria("ice") {}

Ice::Ice(Ice const & src) : AMateria(src._type) {} // to check

Ice & Ice::operator = (Ice const & src) { // to check
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Ice::~Ice () {}

AMateria *Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}