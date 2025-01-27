/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:48:49 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/27 13:29:08 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class AAnimal
{
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(AAnimal const & src);
	AAnimal & operator = (AAnimal const & src);
	virtual ~AAnimal();

	std::string getType() const;
	virtual void makeSound() const = 0;
};

#endif