/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:44:25 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/29 13:45:32 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45),
												 _target("Runknown") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45),
																   _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : _target(src._target) {}

RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm const & src) {
	if (this != &src)
		_target = src._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	checkRequirements(executor);
	std::srand(static_cast<unsigned int>(std::time(0)));
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}