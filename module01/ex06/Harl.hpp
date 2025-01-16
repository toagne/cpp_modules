/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:43:04 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/16 18:11:48 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
# define HARL_CPP

#include <string>

class Harl
{
private:
	void _debug( void );
	void _info( void );
	void _warning( void );
	void _error( void );
public:
	void complain( std::string level );
};

#endif