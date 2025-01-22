/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:20:31 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/22 11:44:14 by mpellegr         ###   ########.fr       */
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
	
	bool operator > (Fixed const & src) const;
	bool operator < (Fixed const & src) const;
	bool operator >= (Fixed const & src) const;
	bool operator <= (Fixed const & src) const;
	bool operator == (Fixed const & src) const;
	bool operator != (Fixed const & src) const;
	
	Fixed operator + (Fixed const & src) const;
	Fixed operator - (Fixed const & src) const;
	Fixed operator * (Fixed const & src) const;
	Fixed operator / (Fixed const & src) const;

	Fixed & operator ++ ();
	Fixed operator ++ (int);
	Fixed & operator -- ();
	Fixed operator -- (int);

	static Fixed & min (Fixed & n1, Fixed & n2);
	static const Fixed & min (const Fixed & n1, const Fixed & n2);
	static Fixed & max (Fixed & n1, Fixed & n2);
	static const Fixed & max (const Fixed & n1, const Fixed & n2);
};

std::ostream & operator<<(std::ostream & ofs, Fixed const & i);

#endif