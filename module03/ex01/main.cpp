/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:17:11 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/24 09:36:15 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
	ClapTrap milio("milio", 10, 10, 3);
	ScavTrap franco("franco");

	milio.attack("franco");
	franco.takeDamage(3);
	franco.beRepaired(1);
	milio.attack("franco");
	franco.takeDamage(3);
	franco.attack("milio");
	milio.takeDamage(20);
	milio.beRepaired(50);

	ScavTrap valerio;

	valerio.guardGate();

	valerio = franco;

	valerio.attack("original franco");
	franco.takeDamage(20);

	for (int i = 0; i < 5; i++)
	{
		valerio.attack("original franco");
		franco.takeDamage(20);
	}
	franco.beRepaired(56);
	franco.attack("fgb");
	franco.guardGate();

	return 0;
}