/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:58:47 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/14 14:08:09 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), oldestIndex(0) {}

void PhoneBook::addContact() {
	if (count < 8) {
		contacts[count].setDetails();
		if (!contacts[count].getFirstName().empty())
			count++;
	} else {
		std::cout << "Phonebook is full. Replacing the oldest contact." << std::endl;
		contacts[oldestIndex].setDetails();
		if (!contacts[oldestIndex].getFirstName().empty())
			oldestIndex = (oldestIndex + 1) % 8;
	}
}

void PhoneBook::searchContact() const {
	if (count == 0) {
		std::cout << "Phonebook is empty. No contacts to display." << std::endl;
		return;
	}
	
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << std::string(44, '_') << std::endl;

	for (int i = 0; i < count; i++) {
		std::cout << std::setw(10) << i + 1 << "|"
					<< std::setw(10) << truncate(contacts[i].getFirstName()) << '|'
					<< std::setw(10) << truncate(contacts[i].getLastName()) << '|'
					<< std::setw(10) << truncate(contacts[i].getNickname()) << '|' << std::endl;
	}

	std::cout << "Enter index to view details: ";
	int index;
	std::cin >> index;
	std::cin.ignore();

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index. Returning to main menu." << std::endl;
		return;
	}

	if (index >= 1 && index <= count) {
		contacts[index - 1].displayContacts();
	} else {
		std::cout << "Invalid index. Returning to main menu." << std::endl;
	}
	
}

std::string PhoneBook::truncate(const std::string &str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}