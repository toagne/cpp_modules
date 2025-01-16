/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:23:55 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/16 09:34:14 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon *_weapon;
public:
	HumanB(std::string main_name);
	void attack() const;
	void setWeapon(Weapon &main_weapon);
};

#endif