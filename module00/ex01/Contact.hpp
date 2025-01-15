/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:30:55 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/14 14:02:47 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
			std::string _firstName;
			std::string _lastName;
			std::string _nickname;
			std::string _phoneNumber;
			std::string _darkestSecret;
	
	public:
			Contact();
			void	setDetails();
			void	displayContacts() const;
			std::string getFirstName() const;
			std::string getLastName() const;
			std::string getNickname() const;
};

#endif