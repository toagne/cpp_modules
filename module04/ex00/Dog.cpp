/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:57:49 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/24 14:18:44 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") { std::cout << "Default constructor called for Dog" << std::endl; }

Dog::Dog(Dog const & src) { std::cout << "Copy constructor called for Dog" << std::endl; *this = src; }

Dog & Dog::operator = (Dog const & src) {
	std::cout << "Copy assignment operator called for Dog" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Dog::~Dog() { std::cout << "Default destructor called for Dog" << std::endl; }

void Dog::makeSound() const {
		std::cout << "BauBau" << std::endl;
}