/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:50:52 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/29 13:46:03 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
# define tree "\
      *\n\
     ***\n\
    *****\n\
   *******\n\
  *********\n\
 ***********\n\
*************\n\
     |||\n"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137),
												 _target("unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137),
																   _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : _target(src._target) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (ShrubberyCreationForm const & src) {
	if (this != &src)
		_target = src._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char *ShrubberyCreationForm::FileOpenException::what() const throw() {
	return "Error opening outfile";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	checkRequirements(executor);
	std::string outfile = _target + "_shrubbery";
	std::ofstream ofs(outfile.c_str());
	if (!ofs.is_open())
		throw ShrubberyCreationForm::FileOpenException();
	ofs << tree;
	ofs.close();
}