/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:48:41 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/14 14:03:12 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact() {}

void Contact::setDetails() {
	std::string temp;
	
	std::cout << "Enter First Name: ";
	std::getline(std::cin, _firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, _lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, _nickname);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, _phoneNumber);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, _darkestSecret);

	if (_firstName.empty() || _lastName.empty() || _nickname.empty()
		|| _phoneNumber.empty() || _darkestSecret.empty()) {
			std::cout << "All fields are mandatory. Contact not saved" << std::endl;
			_firstName = _lastName = _nickname = _phoneNumber = _darkestSecret = "";
		}
}

void Contact::displayContacts() const {
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickame: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

std::string Contact::getFirstName() const {
	return _firstName;
}

std::string Contact::getLastName() const {
	return _lastName;
}

std::string Contact::getNickname() const {
	return _nickname;
}
