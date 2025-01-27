/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:57:49 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/27 13:30:12 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat") { std::cout << "Default constructor called for Cat" << std::endl; _brain = (new Brain); }

Cat::Cat(Cat const & src) {
	std::cout << "Copy constructor called for Cat" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Cat & Cat::operator = (Cat const & src) {
	std::cout << "Copy assignment operator called for Cat" << std::endl;
	if (this != &src) {
		delete _brain;
		_brain = new Brain(*src._brain);
	}
	return *this;
}

Cat::~Cat() { delete _brain; std::cout << "Default destructor called for Cat" << std::endl; }

void Cat::makeSound() const {
		std::cout << "MiaoMiao" << std::endl;
}