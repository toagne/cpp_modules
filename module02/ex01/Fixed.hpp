/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:20:31 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/21 19:17:21 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _val;
	static const int _n_of_fract_bits = 8;
public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(Fixed const & src);
	Fixed & operator=(Fixed const & rhs);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & ofs, Fixed const & i);

#endif