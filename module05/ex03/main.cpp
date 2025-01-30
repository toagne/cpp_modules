/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:59:53 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/30 08:49:19 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Intern i;
	AForm *f;
	Bureaucrat b("Berto", 3);
	std::cout << b << std::endl << std::endl;
	
	f = i.makeForm("robotomy", "gino");
	std::cout << *f << std::endl;
	b.signForm(*f);
	b.executeForm(*f);
	delete f;
	std::cout << std::endl;
	
	f = i.makeForm("PRESIDENTIAL request", "gino");
	std::cout << *f << std::endl;
	b.signForm(*f);
	b.executeForm(*f);
	delete f;
	std::cout << std::endl;

	f = i.makeForm("ShRuBbEry form", "gino");
	std::cout << *f << std::endl;
	b.signForm(*f);
	b.executeForm(*f);
	delete f;
	std::cout << std::endl;
	
	f = i.makeForm("not existing", "gino");

	delete f;
}