/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:21:35 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/22 11:49:04 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;

	Fixed x(20);
	Fixed y(10);
	Fixed z;

	std::cout << "x	" << x << std::endl;
	std::cout << "y	" << y << std::endl << std::endl;

	z = x + y;
	std::cout << "+	" << z << std::endl;

	z = x - y;
	std::cout << "-	" << z << std::endl;

	z = x * y;
	std::cout << "*	" << z << std::endl;

	z = x / y;
	std::cout << "/	" << z << std::endl << std::endl;

// ***************************************************

	bool q = x > y;
	std::cout << ">	" << q << std::endl;

	q = x < y;
	std::cout << "<	" << q << std::endl;

	q = x >= y;
	std::cout << ">=	" << q << std::endl;

	q = x <= y;
	std::cout << "<=	" << q << std::endl;

	q = x == y;
	std::cout << "==	" << q << std::endl;

	q = x != y;
	std::cout << "!=	" << q << std::endl << std::endl;

// **************************************************

	std::cout << "x	" << x << std::endl;
	++x;
	std::cout << "pre++	" << x << std::endl;
	--x;
	std::cout << "pre--	" << x << std::endl;

	std::cout << "y	" << y << std::endl;
	y++;
	std::cout << "++post	" << y << std::endl;
	y--;
	std::cout << "--post	" << y << std::endl << std::endl;

// **************************************************

	std::cout << "min x, y	" << Fixed::min(x, y) << std::endl;

	Fixed const x1(5);
	Fixed const y1(7);
	std::cout << "min const x1, const y1	" << Fixed::min(x1, y1) << std::endl;

	std::cout << "max x, y	" << Fixed::max(x, y) << std::endl;

	std::cout << "max const x1, const y1	" << Fixed::max(x1, y1) << std::endl;
	
	return 0;
}