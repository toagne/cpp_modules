/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:24:16 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/15 10:31:26 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *horde = zombieHorde(7, "milio");
	for (int i = 0; i < 7; i++)
		horde->announce();
	delete[] horde;
	return 0;
}