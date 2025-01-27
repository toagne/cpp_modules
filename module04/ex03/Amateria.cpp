/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:06:00 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/27 14:13:37 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : _type(type) {}

std::string const & AMateria::getType() const { return _type; }

void AMateria::use(ICharacter& target) {
	if (this->getType() == "ice")
		std::cout << "* shoots an ice bolt at <name> *" << std::endl;
	else if (this->getType() == "cure")
		std::cout << "* heals <name>’s wounds *" << std::endl;
	else
		std::cout << "WRONG AMATERIA TYPE" << std::endl;
}