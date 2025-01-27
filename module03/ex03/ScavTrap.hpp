/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:59:31 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/27 08:25:27 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & src);
	ScavTrap & operator = (ScavTrap const & src);
	~ScavTrap();
	void attack(const std::string& target);
	void guardGate();
protected:
	static const int staticHitPoints;
	static const int staticEnergyPoints;
	static const int staticAttackDamage;
};

#endif