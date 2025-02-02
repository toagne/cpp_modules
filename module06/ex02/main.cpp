/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:53:43 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/02 13:51:35 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main(void) {
	std::cout << "random generator" << std::endl;
	Base *test = generate();
	identify(test);
	identify(*test);
	std::cout << "\n";

	std::cout << "identify A" << std::endl;
	A a;
	identify(&a);
	identify(a);
	std::cout << "\n";

	std::cout << "identify B" << std::endl;
	B b;
	identify(&b);
	identify(b);
	std::cout << "\n";

	std::cout << "identify C" << std::endl;
	C c;
	identify(&c);
	identify(c);
	std::cout << "\n";

	return 0;
}