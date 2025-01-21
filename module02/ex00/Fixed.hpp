/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:20:31 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/21 17:34:09 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int _val;
	static const int _n_of_fract_bits = 8;
public:
	Fixed();
	Fixed(Fixed const & src);
	Fixed & operator=(Fixed const & rhs);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif