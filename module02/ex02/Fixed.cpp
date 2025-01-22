/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:25:38 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/22 11:45:40 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _val(0) {
	// std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int i) : _val(i << _n_of_fract_bits) {
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _val((int)roundf(f * (1 << _n_of_fract_bits))) {
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	// std::cout << "Copy consructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_val = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return _val;
}

void Fixed::setRawBits( int const raw ) {
	_val = raw;
}

int Fixed::toInt( void ) const {
	return (_val >> _n_of_fract_bits);
}

float Fixed::toFloat( void ) const {
	return ((float)_val / (1 << _n_of_fract_bits));
}

std::ostream & operator<<(std::ostream & ofs, Fixed const & i) {
	ofs << i.toFloat();
	return ofs;
}

bool Fixed::operator > (Fixed const & src) const { return (this->toFloat() > src.toFloat()); }
bool Fixed::operator < (Fixed const & src) const { return (this->toFloat() < src.toFloat()); }
bool Fixed::operator >= (Fixed const & src) const { return (this->toFloat() >= src.toFloat()); }
bool Fixed::operator <= (Fixed const & src) const { return (this->toFloat() <= src.toFloat()); }
bool Fixed::operator == (Fixed const & src) const { return (this->toFloat() == src.toFloat()); }
bool Fixed::operator != (Fixed const & src) const { return (this->toFloat() != src.toFloat()); }

Fixed Fixed::operator + (Fixed const & src) const { return Fixed(this->toFloat() + src.toFloat()); }
Fixed Fixed::operator - (Fixed const & src) const { return Fixed(this->toFloat() - src.toFloat()); }
Fixed Fixed::operator * (Fixed const & src) const { return Fixed(this->toFloat() * src.toFloat()); }
Fixed Fixed::operator / (Fixed const & src) const { return Fixed(this->toFloat() / src.toFloat()); }

Fixed & Fixed::operator ++ () { ++_val; return *this; }
Fixed Fixed::operator ++ (int) { Fixed temp = *this; ++_val; return temp; }
Fixed & Fixed::operator -- () { --_val; return *this; }
Fixed Fixed::operator -- (int) { Fixed temp = *this; --_val; return temp; }

Fixed & Fixed::min(Fixed & n1, Fixed & n2) { if (n1 < n2) return n1; else return n2; }
const Fixed & Fixed::min(const Fixed & n1, const Fixed & n2) { if (n1 < n2) return n1; else return n2; }
Fixed & Fixed::max(Fixed & n1, Fixed & n2) { if (n1 > n2) return n1; else return n2; }
const Fixed & Fixed::max(const Fixed & n1, const Fixed & n2) { if (n1 > n2) return n1; else return n2; }