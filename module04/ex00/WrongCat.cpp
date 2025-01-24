/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:57:49 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/24 14:19:00 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") { std::cout << "Default constructor called for WrongCat" << std::endl; }

WrongCat::WrongCat(WrongCat const & src) { std::cout << "Copy constructor called for WrongCat" << std::endl; *this = src; }

WrongCat & WrongCat::operator = (WrongCat const & src) {
	std::cout << "Copy assignment operator called for WrongCat" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

WrongCat::~WrongCat() { std::cout << "Default destructor called for WrongCat" << std::endl; }

void WrongCat::makeSound() const {
		std::cout << "MiaoMiao" << std::endl;
}