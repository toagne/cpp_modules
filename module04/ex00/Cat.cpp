/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:57:49 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/24 14:19:00 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") { std::cout << "Default constructor called for Cat" << std::endl; }

Cat::Cat(Cat const & src) { std::cout << "Copy constructor called for Cat" << std::endl; *this = src; }

Cat & Cat::operator = (Cat const & src) {
	std::cout << "Copy assignment operator called for Cat" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Cat::~Cat() { std::cout << "Default destructor called for Cat" << std::endl; }

void Cat::makeSound() const {
		std::cout << "MiaoMiao" << std::endl;
}