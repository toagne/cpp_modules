/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:16:31 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/29 08:08:43 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm() : _name("unknown"),
			   _signed(false),
			   _gradeForSigning(150),
			   _gradeForExecuting(150) {}

AForm::AForm(std::string name,
		   int gradeForSigning,
		   int gradeForExecuting) : _name(name),
									_signed(false),
									_gradeForSigning(gradeForSigning),
									_gradeForExecuting(gradeForExecuting) {
	if (_gradeForSigning < 1 || _gradeForExecuting < 1)
		throw AForm::GradeTooHighException();
	if (_gradeForSigning > 150 || _gradeForExecuting > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) : _name(src._name),
							   _signed(src._signed),
							   _gradeForSigning(src._gradeForSigning),
							   _gradeForExecuting(src._gradeForExecuting) {}

AForm & AForm::operator = (AForm const & src) {
	if (this != &src) {
		_signed = src._signed;
	}
	return *this;
}

AForm::~AForm () {}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::string AForm::getName() const { return _name; }
bool AForm::getSigned() const { return _signed; }
int AForm::getGradeForSigning() const { return _gradeForSigning; }
int AForm::getGradeForExecuting() const { return _gradeForExecuting; }

// other getters or setters

void AForm::beSigned(Bureaucrat const & b) {
	if (b.getGrade() <= _gradeForSigning)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream & operator << (std::ostream & ofs, AForm const & f) {
	ofs << "Form " << f.getName() << " info: " << std::endl
		<< "- signed " << f.getSigned() << std::endl
		<< "- grade required to sign it " << f.getGradeForSigning() << std::endl
		<< "- grade required to execute it " << f.getGradeForExecuting();
	return ofs;
}

void AForm::checkRequirements(Bureaucrat const & executor) const {
	if (!_signed)
		throw AForm::NoSignException();
	if (_gradeForExecuting < executor.getGrade())
		throw AForm::GradeTooLowException();
}

const char *AForm::NoSignException::what() const throw() {
	return "Form is not signed";
}