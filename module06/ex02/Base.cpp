/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:46:15 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/06 12:18:20 by mpellegr         ###   ########.fr       */
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
	int randomValue = distribution(generator);
	if (randomValue == 1)
		return new A;
	else if (randomValue == 2)
		return new B;
	else if (randomValue == 3)
		return new C;
	else {
		std::cout << "random generator failed\n";
		return nullptr;
	}
}

void identify(Base *p) {
	A *a = dynamic_cast<A *>(p);

	if (a == nullptr) {
		B *b = dynamic_cast<B *>(p);
		if (b == nullptr) {
			C *c = dynamic_cast<C *>(p);
			if (c == nullptr)
				std::cout << "no type found" << std::endl;
			else
				std::cout << "type is C" << std::endl;
		}
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
			try {
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "type is C" << std::endl;
				return ;
			} catch (std::bad_cast &) {
				std::cout << "no type found" << std::endl;
				return ;
			}
		}
	}
}