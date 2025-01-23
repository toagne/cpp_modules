/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:18:02 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/23 20:14:36 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
protected:
	std::string		_name;
	int				_hitPoints;
	int				_energyPoints;
	int				_attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name, int hitpoints, int energyPoints, int attackDamage);
	ClapTrap(ClapTrap const & src);
	ClapTrap & operator = (ClapTrap const & src);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif