/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:45:20 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/29 11:40:59 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
 # define BUREAUCRAT_HPP

# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat & operator = (Bureaucrat const & src);
	~Bureaucrat();
	
	std::string getName() const;
	int getGrade() const;

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

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm & f);

	void executeForm(AForm const & form);
};

std::ostream & operator<<(std::ostream & ofs, Bureaucrat const & b);

 #endif