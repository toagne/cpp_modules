/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:09:58 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/30 08:47:06 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AForm.hpp"

class Intern
{
private:
	static AForm* createShrubbery(const std::string& target);
	static AForm* createRobotomy(const std::string& target);
	static AForm* createPresidential(const std::string& target);
public:
	Intern();
	Intern(Intern const & src);
	Intern & operator = (Intern const & src);
	~Intern();

	AForm *makeForm(std::string formName, std::string formTarget);
	std::string toLower(std::string str);
};

