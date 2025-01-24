/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:57:49 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/24 12:05:11 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() { std::cout << "Default constructor called for WrongAnimal" << std::endl; }

WrongAnimal::WrongAnimal(std::string type) : _type(type) { std::cout << "Parametrized constructor called for WrongAnimal" << std::endl; }

WrongAnimal::WrongAnimal(WrongAnimal const & src) { std::cout << "Copy constructor called for WrongAnimal" << std::endl; *this = src; }

WrongAnimal & WrongAnimal::operator = (WrongAnimal const & src) {
	std::cout << "Copy assignment operator called for WrongAnimal" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "Default destructor called for WrongAnimal" << std::endl; }

std::string WrongAnimal::getType() const { return _type; }

void WrongAnimal::makeSound() const {
		std::cout << "......." << std::endl;
}