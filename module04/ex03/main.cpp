/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:04:04 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/28 16:16:56 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout << std::endl;

// **************************************************

	IMateriaSource *a = new MateriaSource();
	for (int i = 0; i < 10; i++)
		a->learnMateria(new Ice());

	ICharacter *b = new Character("plinio");
	AMateria *c;
	
	for (int i = 0; i < 10; i++) {
		c = a->createMateria("ice");
		b->equip(c);
	}

	ICharacter *d = new Character("d");
	b->use(5, *d);
	b->use(3, *d);

	delete d;
	delete b;
	delete a;
	std::cout << std::endl;

// **************************************************

	IMateriaSource *e = new MateriaSource();
	e->learnMateria(new Ice());
	e->learnMateria(new Cure());
	e->learnMateria(new Ice());
	e->learnMateria(new Cure());

	ICharacter *f = new Character("gelindo");
	AMateria *g;
	g = e->createMateria("ice");
	f->equip(g);
	g = e->createMateria("cure");
	f->equip(g);
	g = e->createMateria("ice");
	f->equip(g);
	g = e->createMateria("cure");
	f->equip(g);

	ICharacter *h = new Character("enido");
	g = e->createMateria("aaa");
	h->equip(g);
	h->use(0, *f);
	
	for (int i = 0; i < 4; i++)
		f->use(i, *h);
	std::cout << std::endl;
	f->unequip(2);
	f->unequip(10);
	for (int i = 0; i < 4; i++)
		f->use(i, *h);

	delete e;
	delete f;
	delete h;

	return 0;
}