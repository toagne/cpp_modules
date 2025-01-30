/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:29:46 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/30 08:46:59 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & src) { *this = src; }

Intern & Intern::operator = (Intern const & src) {
	if (this != & src)
		*this = src;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
AForm *Intern::createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
AForm *Intern::createPresidential(const std::string& target) { return new PresidentialPardonForm(target); }

std::string Intern::toLower(std::string str) {
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	return str;
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
	std::string lowerName = toLower(formName);
	std::string forms[3] = {
		"shrubbery",
		"robotomy",
		"presidential" };
	AForm *(*functions[3]) (const std::string& target) = {
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	for (int i = 0; i < 3; i++) {
		std::size_t found = lowerName.find(forms[i]);
		if (found!=std::string::npos) {
			std::cout << "Intern creates " << formName << std::endl;
			return functions[i](formTarget);
		}
	}
	std::cout << "Error: Unknown form type '" << formName << "'." << std::endl;
	return nullptr;
}