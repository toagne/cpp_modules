/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:01:40 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/29 08:20:01 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	bool _signed;
	int const _gradeForSigning;
	int const _gradeForExecuting;
public:
	AForm();
	AForm(std::string name, int gradeForSigning, int gradeForExecuting);
	AForm(AForm const & src);
	AForm & operator = (AForm const & src);
	~AForm();

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	std::string getName() const;
	bool getSigned() const;
	int getGradeForSigning() const;
	int getGradeForExecuting() const;

	void beSigned(Bureaucrat const & b);

	virtual void execute(Bureaucrat const & executor) const = 0;

	virtual void checkRequirements(Bureaucrat const & executor) const;

	class NoSignException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream & operator << (std::ostream & ofs, AForm const & f);

#endif