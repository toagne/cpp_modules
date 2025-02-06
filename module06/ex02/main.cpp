/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:53:43 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/06 11:55:27 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main(void) {
	std::cout << "*random generator" << std::endl;
	Base *test = generate();
	identify(test);
	identify(*test);
	delete test;
	std::cout << "\n";

	std::cout << "*identify A" << std::endl;
	A a;
	identify(&a);
	identify(a);
	std::cout << "\n";

	std::cout << "*identify B" << std::endl;
	B b;
	identify(&b);
	identify(b);
	std::cout << "\n";

	std::cout << "*identify C" << std::endl;
	C c;
	identify(&c);
	identify(c);
	std::cout << "\n";

	std::cout << "*with null" << std::endl;
	Base *null = NULL;
	identify(null);
	identify(*null);

	return 0;
}