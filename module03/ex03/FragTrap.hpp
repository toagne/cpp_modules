/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:15:46 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/27 08:21:48 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	FragTrap & operator = (FragTrap const & src);
	~FragTrap();
	void highFivesGuys(void);
protected:
	static const int staticHitPoints;
	static const int staticEnergyPoints;
	static const int staticAttackDamage;
};

#endif