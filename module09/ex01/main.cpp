/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:09:49 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/07 12:56:25 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	(void)av;
	// if (ac > 11) { // not sure
		// std::cerr << "Error: " << std::endl;
		// return 1;
	// }
	RPN rpn;
	rpn.execute(ac, av);
}