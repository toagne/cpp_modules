/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:57:41 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/27 11:36:00 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;

	const Animal *a[10];
	for (int x = 0; x < 5; x++)
		a[x] = new Dog();
	for (int x = 5; x < 10; x++)
		a[x] = new Cat();

	for (int x = 0; x < 10; x++)
		delete a[x];

	std::cout << std::endl;

	Dog *b = new Dog();
	Dog c(*b);
	delete b;
	c.makeSound();

	std::cout << std::endl;

	Cat *d = new Cat();
	Cat e = *d;
	delete d;
	e.makeSound();

	return 0;
}