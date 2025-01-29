/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:59:53 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/29 15:03:14 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat a("AaA", 127);
	Bureaucrat b("BbB", 45);
	Bureaucrat c("CcC", 3);
	ShrubberyCreationForm scf("home");
	RobotomyRequestForm rrf("hello");
	PresidentialPardonForm ppf("ppf");

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;

	std::cout << scf << std::endl;
	std::cout << rrf << std::endl;
	std::cout << ppf << std::endl;
	std::cout << std::endl;

	a.signForm(scf);
	a.executeForm(scf);
	b.signForm(rrf);
	b.executeForm(rrf);
	c.signForm(ppf);
	c.executeForm(ppf);
	std::cout << std::endl;
	
	a.executeForm(rrf);
	a.executeForm(ppf);
	std::cout << std::endl;
	
	b.executeForm(scf);
	b.executeForm(ppf);
	std::cout << std::endl;
	
	c.executeForm(scf);
	c.executeForm(rrf);
	std::cout << std::endl;

	PresidentialPardonForm ppf_1("ppf_1");
	c.executeForm(ppf_1);

	return 0;
}