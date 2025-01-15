/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:27:34 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/14 10:27:00 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook
{
	private:
			Contact	contacts[8];
			int	count;
			int	oldestIndex;

	public:
			PhoneBook();
			void	addContact();
			void	searchContact() const;
			std::string truncate(const std::string &str) const;
};

#endif