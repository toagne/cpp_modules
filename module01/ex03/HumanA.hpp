/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:23:55 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/16 09:52:24 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon &_weapon;
public:
	HumanA(std::string main_name, Weapon &main_weapon);
	void attack() const ;
};

#endif