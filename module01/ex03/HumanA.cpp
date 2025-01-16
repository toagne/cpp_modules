/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:46:01 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/16 09:52:08 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string main_name, Weapon &main_weapon) : _name(main_name), _weapon(main_weapon) {}

void HumanA::attack() const {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}