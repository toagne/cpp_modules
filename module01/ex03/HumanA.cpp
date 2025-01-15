/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:46:01 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/15 19:43:09 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string main_name, Weapon &main_weapon) : _name(main_name), _weapon(main_weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}