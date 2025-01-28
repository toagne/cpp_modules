/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:59:53 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/28 18:18:44 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	Bureaucrat a("mario", 123);
	std::cout << a << std::endl;
	for (int i = 0; i < 7; i++)
		a.decrementGrade();
	std::cout << a << std::endl;
	for (int i = 0; i < 5; i++)
		a.incrementGrade();
	std::cout << a << std::endl;
	std::cout << std::endl;
// *****************************************
	try {
		Bureaucrat b("b", 190);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
// *****************************************
	try {
		Bureaucrat c("c", 0);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
// *****************************************
	Bureaucrat d;
	std::cout << d << std::endl;
	std::cout << std::endl;
// *****************************************
	Bureaucrat f("ernesto", 1);
	std::cout << f << std::endl;
	try {
		f.incrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << f << std::endl;
	std::cout << std::endl;
// *****************************************
	Bureaucrat g("silvano", 150);
	std::cout << g << std::endl;
	try {
		g.decrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << g << std::endl;
	std::cout << std::endl;
// *****************************************
	
}