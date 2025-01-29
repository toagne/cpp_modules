/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:09:58 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/29 16:37:53 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const & src);
	Intern & operator = (Intern const & src);
	~Intern();

	AForm *makeForm(std::string formName, std::string formTarget);
	std::string toLower(std::string str);
};

