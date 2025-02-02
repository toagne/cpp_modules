/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:46:15 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/02 13:46:06 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <iostream>

Base::~Base() {}

Base *generate(void) {
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> distribution(1,3);
	if (distribution(generator) == 1)
		return new A;
	else if (distribution(generator) == 2)
		return new B;
	else
		return new C;
}

void identify(Base *p) {
	A *a = dynamic_cast<A *>(p);
	
	if (a == nullptr) {
		B *b = dynamic_cast<B *>(p);
		if (b == nullptr)
			std::cout << "type is C" << std::endl;
		else
			std::cout << "type is B" << std::endl;
	}
	else
		std::cout << "type is A" << std::endl;
}

void identify(Base& p) {
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "type is A" << std::endl;
		return ;
	} catch (std::bad_cast &) {
		try {
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "type is B" << std::endl;
			return ;
		} catch (std::bad_cast &) {
			std::cout << "type is C" << std::endl;
			return ;
		}
	}
}