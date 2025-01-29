/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:29:46 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/29 16:40:57 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & src) { *this = src; }

Intern & Intern::operator = (Intern const & src) {
	if (this != & src)
		*this = src;
	return *this;
}

Intern::~Intern() {}

std::string Intern::toLower(std::string str) {
	for (int i = 0; i < str.length(); i++)
		if (str[i] > 'A' && str[i] < 'Z')
			str[i] += 32;
	return str;
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
	std::string lowerName = toLower(formName);
}