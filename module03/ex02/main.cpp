/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:17:11 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/24 09:35:20 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
	ClapTrap milio("milio", 10, 10, 3);
	FragTrap franco("franco");

	milio.attack("franco");
	franco.takeDamage(3);
	franco.beRepaired(1);
	milio.attack("franco");
	franco.takeDamage(3);
	franco.attack("milio");
	milio.takeDamage(20);
	milio.beRepaired(50);

	FragTrap valerio;

	valerio.highFivesGuys();

	valerio = franco;

	valerio.attack("original franco");
	franco.takeDamage(20);

	for (int i = 0; i < 4; i++)
	{
		valerio.attack("original franco");
		franco.takeDamage(30);
	}
	franco.beRepaired(56);
	franco.attack("fgb");
	franco.highFivesGuys();

	return 0;
}