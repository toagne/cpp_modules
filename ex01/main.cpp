/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:07:06 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/14 10:37:21 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	std::string	buffer;
	PhoneBook	phoneBook;
	std::cout << "the phonebook is empty, you can enter one of theese 3 commands: ADD, SEARCH, EXIT" << std::endl;

	while (1) {
		std::cout << "command: ";
		std::getline(std::cin, buffer);
		if (buffer == "EXIT") {
			std::cout << "Exiting... Goodbye!" << std::endl;
			break;
		}
		else if (buffer == "ADD") 
			phoneBook.addContact();
		else if (buffer == "SEARCH")
			phoneBook.searchContact();
		else
			std::cout << "Invalid input. Please enter ADD, SEARCH, or EXIT." << std::endl;
	}
}
