/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:57:49 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/24 12:05:11 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

AAnimal::AAnimal() : _type("Generic animal") { std::cout << "Default constructor called for Animal" << std::endl; }

AAnimal::AAnimal(std::string type) : _type(type) { std::cout << "Parametrized constructor called for Animal" << std::endl; }

AAnimal::AAnimal(AAnimal const & src) { std::cout << "Copy constructor called for Animal" << std::endl; *this = src; }

AAnimal & AAnimal::operator = (AAnimal const & src) {
	std::cout << "Copy assignment operator called for Animal" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

AAnimal::~AAnimal() { std::cout << "Default destructor called for Animal" << std::endl; }

std::string AAnimal::getType() const { return _type; }

void AAnimal::makeSound() const {
		std::cout << "Generic animal sound" << std::endl;
}