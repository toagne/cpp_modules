/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:17:34 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/15 18:15:19 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void) {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << "memory address of string    = " << &string << std::endl;
	std::cout << "memory address of stringPTR = " << stringPTR << std::endl;
	std::cout << "memory address of stringREF = " << &stringREF << std::endl;
	
	std::cout << std::endl << "value of string               = " << string << std::endl;
	std::cout << "value pointed to by stringPTR = " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF = " << stringREF << std::endl;
}