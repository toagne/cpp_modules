/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:07:06 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/13 18:38:01 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string	buffer;

	std::cout << "the phonebook is empty, you can enter one of theese 3 commands: ADD, SEARCH, EXIT" << std::endl;

	while (1)
	{
		std::cout << "command: ";
		//std::cin >> buffer; // to check if better to use std::getline(std::cin, buffer)
		std::getline(std::cin, buffer);
		if (buffer == "EXIT")
			break;
		else if (buffer == "ADD")
			;
		else if (buffer == "SEARCH")
			;
        else
            std::cout << "Invalid input. Please enter ADD, SEARCH, or EXIT." << std::endl;
	}
}
