/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:57:21 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/22 12:05:33 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;
	// 
public:
	Point();
	Point(const float n1, const float n2);
	Point(Point const & src);
	Point & operator=(Point const & src);
	~Point();
};

#endif