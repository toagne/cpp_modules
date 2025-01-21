/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:25:38 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/21 17:53:48 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _val(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy consructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_val = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _val;
}

void Fixed::setRawBits( int const raw ) {
	_val = raw;
}

