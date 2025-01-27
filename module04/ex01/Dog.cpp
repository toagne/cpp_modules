/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:57:49 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/27 11:27:01 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") { std::cout << "Default constructor called for Dog" << std::endl; _brain = (new Brain); }

Dog::Dog(Dog const & src) {
	std::cout << "Copy constructor called for Dog" << std::endl;
	this->_brain = new Brain(*src._brain);
	}

Dog & Dog::operator = (Dog const & src) {
	std::cout << "Copy assignment operator called for Dog" << std::endl;
	if (this != &src) {
		delete _brain;
		_brain = new Brain(*src._brain);
	}
	return *this;
}

Dog::~Dog() { delete _brain; std::cout << "Default destructor called for Dog" << std::endl; }

void Dog::makeSound() const {
		std::cout << "BauBau" << std::endl;
}