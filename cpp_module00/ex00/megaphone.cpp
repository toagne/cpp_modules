/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:48:09 by mpellegr          #+#    #+#             */
/*   Updated: 2024/12/16 13:40:57 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int i = 0;
	char ch;
	int j = -1;
	if (argc > 1)
	{
		while (++i < argc)
		{
			j = -1;
			while (argv[i][++j])
			{
				ch = toupper(argv[i][j]);
				std::cout << ch;
			}
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}