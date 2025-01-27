/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:40:02 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/27 13:38:21 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Default constructor called for Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "empty";
}

Brain::Brain(Brain const & src) {
	std::cout << "Copy constructor called for Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	}

Brain & Brain::operator = (Brain const & src) {
	std::cout << "Copy assignment operator called for Brain" << std::endl;
	if (this != &src)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	return *this;
}

Brain::~Brain () { std::cout << "Default destructor called for Brain" << std::endl; }