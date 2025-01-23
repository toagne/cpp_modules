/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:21:35 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/23 11:44:12 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include "Point.hpp"

void check_point(float x1, float y1, float x2, float y2, float x3, float y3, float px, float py)
{
	Point a(x1, y1);
	Point b(x2, y2);
	Point c(x3, y3);

	Point point(px, py);
	
	std::cout << std::endl << "Triangle vertices: a(" << a.getX() << "; " << a.getY() << ") "
									 "b(" << b.getX() << "; " << b.getY() << ") "
									 "c(" << c.getX() << "; " << c.getY() << ")" << std::endl;
	std::cout << "Point to check (" << point.getX() << "; " << point.getY() << ")" << std::endl;

	if (bsp(a, b, c, point) == true)
		std::cout << "The point (" << point.getX() << "; " << point.getY() << ") is inside the triangle" << std::endl;
	else
		std::cout << "The point (" << point.getX() << "; " << point.getY() << ") is NOT inside the triangle" << std::endl << std::endl;
		
}

int main( void )
{
	check_point(1, 1, 5, 1, 3, 5, 2, 2); // inside
	check_point(1.5, 1.5, 5.7, 1.2, 3.3, 4.8, 3.2, 2.5); // inside
	check_point(0, 0, 4, 0, 2, 6, 5, 5); // outside
	check_point(-2, -2, 2, -2, 0, 3, -2, -2); // on a vertex
	check_point(0, 0, 3.5, 0, 1.5, 4.5, 2.25, 0); // on an edge
	
	return 0;
}