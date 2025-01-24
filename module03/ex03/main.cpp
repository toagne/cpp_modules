/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:17:11 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/24 09:37:11 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap cesare("cesare");

	cesare.whoAmI();
	cesare.attack("someone");
	cesare.beRepaired(3);
	cesare.takeDamage(8);
	cesare.guardGate();
	cesare.highFivesGuys();

	DiamondTrap ugo("ugo");
	
	ugo.attack("cesare");
	cesare.takeDamage(10);
	cesare.attack("a");
	cesare.beRepaired(32);
	cesare.whoAmI();
	cesare.guardGate();
	cesare.highFivesGuys();

	return 0;
}