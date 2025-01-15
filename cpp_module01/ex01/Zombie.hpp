/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:06:39 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/15 10:13:39 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce( void );
};

Zombie *zombieHorde( int N, std::string name );

#endif