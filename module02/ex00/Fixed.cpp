/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:25:38 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/21 11:28:43 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _val(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

