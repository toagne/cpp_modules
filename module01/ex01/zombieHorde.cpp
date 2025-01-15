/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:08:21 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/15 10:36:25 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name ) {
	if (N <= 0)
		return NULL;
	Zombie *zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		new (zombieHorde+i) Zombie(name);
		// zombieHorde[i] = Zombie(name);
	return zombieHorde;
}