/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:16:31 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/29 08:08:43 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form() : _name("unknown"),
			   _signed(false),
			   _gradeForSigning(150),
			   _gradeForExecuting(150) {}

Form::Form(std::string name,
		   int gradeForSigning,
		   int gradeForExecuting) : _name(name),
									_signed(false),
									_gradeForSigning(gradeForSigning),
									_gradeForExecuting(gradeForExecuting) {
	if (_gradeForSigning < 1 || _gradeForExecuting < 1)
		throw Form::GradeTooHighException();
	if (_gradeForSigning > 150 || _gradeForExecuting > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : _name(src._name),
							   _signed(src._signed),
							   _gradeForSigning(src._gradeForSigning),
							   _gradeForExecuting(src._gradeForExecuting) {}

Form & Form::operator = (Form const & src) {
	if (this != &src) {
		_signed = src._signed;
	}
	return *this;
}

Form::~Form () {}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::string Form::getName() const { return _name; }
bool Form::getSigned() const { return _signed; }
int Form::getGradeForSigning() const { return _gradeForSigning; }
int Form::getGradeForExecuting() const { return _gradeForExecuting; }

// other getters or setters

void Form::beSigned(Bureaucrat const & b) {
	if (b.getGrade() <= _gradeForSigning)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream & operator << (std::ostream & ofs, Form const & f) {
	ofs << "Form " << f.getName() << " info: " << std::endl
		<< "- signed " << f.getSigned() << std::endl
		<< "- grade required to sign it " << f.getGradeForSigning() << std::endl
		<< "- grade required to execute it " << f.getGradeForExecuting();
	return ofs;
}