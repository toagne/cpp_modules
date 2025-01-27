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

Animal::Animal() : _type("Generic animal") { std::cout << "Default constructor called for Animal" << std::endl; }

Animal::Animal(std::string type) : _type(type) { std::cout << "Parametrized constructor called for Animal" << std::endl; }

Animal::Animal(Animal const & src) { std::cout << "Copy constructor called for Animal" << std::endl; *this = src; }

Animal & Animal::operator = (Animal const & src) {
	std::cout << "Copy assignment operator called for Animal" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Animal::~Animal() { std::cout << "Default destructor called for Animal" << std::endl; }

std::string Animal::getType() const { return _type; }

void Animal::makeSound() const {
		std::cout << "Generic animal sound" << std::endl;
}