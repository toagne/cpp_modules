/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:18:05 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/15 09:58:18 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *allocatedZombie = newZombie("allocatedZombie");
	allocatedZombie->announce();
	delete allocatedZombie;
	randomChump("nonAllocatedZombie");
	return 0;
}