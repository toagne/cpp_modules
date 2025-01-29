/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:14:47 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/29 13:45:04 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5),
												 _target("unknown") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5),
																   _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : _target(src._target) {}

PresidentialPardonForm & PresidentialPardonForm::operator = (PresidentialPardonForm const & src) {
	if (this != &src)
		_target = src._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	checkRequirements(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}