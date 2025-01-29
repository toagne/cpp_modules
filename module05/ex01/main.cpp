/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:59:53 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/29 08:33:59 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

int main() {
	Form f("fff", 67, 45);
	std::cout << f << std::endl;
	std::cout << std::endl;
// **********************************************
	try {
		Form a("a", 200, 100);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form b("b", 100, 0);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
// **********************************************
	Bureaucrat bb("bb", 100);
	try {
		f.beSigned(bb);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	bb.signForm(f);
	std::cout << std::endl;
// **********************************************
	Bureaucrat b("b", 10);
	f.beSigned(b);
	std::cout << f << std::endl;
	b.signForm(f);
	std::cout << std::endl;
// **********************************************
	Form form("form", 120, 33);
	std::cout << form << std::endl;
	Bureaucrat sandro("sandro", 50);
	Bureaucrat lowGrade("lowGrade", 149);
	try {
		lowGrade.signForm(form);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	sandro.signForm(form);
	std::cout << form << std::endl;

	return 0;
}