/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:58:38 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/28 09:27:08 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{
private:
	std::string _type;
public:
	Cure();
	Cure(Cure const & src);
	Cure & operator = (Cure const & src);
	~Cure();

	AMateria* clone() const override;
	void use(ICharacter& target) override;
};

#endif