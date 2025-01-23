/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:00:14 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/23 11:26:14 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float n1, const float n2) : _x(n1), _y(n2) {}

Point::Point(Point const & src) : _x(src._x), _y(src._y) {}

Point & Point::operator=(Point const &src) {
	if (this != &src)
		return *this;
	else
		return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return _x; }

Fixed Point::getY() const { return _y; }