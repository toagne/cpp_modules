/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:17:11 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/23 14:47:35 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap milio("milio");
	ClapTrap toni("toni");
	
	toni.attack("milio");
	milio.takeDamage(10);
	milio.beRepaired(1);
	toni.attack("milio");
	milio.takeDamage(7);
	milio.attack("gs");
	milio.beRepaired(510);
	toni.beRepaired(123);

	ClapTrap a;

	a.beRepaired(10);

	a = toni;
	
	toni.attack("a");
	a.takeDamage(13);
	
	ClapTrap vito("vito");
	for (int i = 0; i < 10; i++)
	{
		vito.attack("toni");
		toni.takeDamage(1);
	}
	vito.attack("toni");
	vito.beRepaired(51);

	return 0;
}