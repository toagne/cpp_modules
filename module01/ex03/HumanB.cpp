/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:13:45 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/15 19:52:18 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string main_name) : _name(main_name) {}

void HumanB::setWeapon(Weapon &main_weapon) {
	_weapon = &main_weapon;
}

void HumanB::attack() {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}