/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:34:18 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/15 19:52:59 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	setType(type);
}

void Weapon::setType(std::string type) {
	_type = type;
}

std::string Weapon::getType() const {
	return _type;
}