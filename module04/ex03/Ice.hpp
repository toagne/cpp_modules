/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:57:42 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/28 09:27:02 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
private:
	std::string _type;
public:
	Ice();
	Ice(Ice const & src);
	Ice & operator = (Ice const & src);
	~Ice();
	
	AMateria* clone() const override;
	void use(ICharacter& target) override;
};

#endif