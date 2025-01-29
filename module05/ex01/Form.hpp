/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:01:40 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/29 08:20:01 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	bool _signed;
	int const _gradeForSigning;
	int const _gradeForExecuting;
public:
	Form();
	Form(std::string name, int gradeForSigning, int gradeForExecuting);
	Form(Form const & src);
	Form & operator = (Form const & src);
	~Form();

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
};

std::ostream & operator << (std::ostream & ofs, Form const & f);

#endif