/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 07:48:50 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/05 09:35:30 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) {
	int arr_i[5] = {1, 2, 3, 4, 5};
	const float arr_f[3] = {1.6f, 8.55f, 9.165f};
	std::string arr_s[2] = {"aaa", "bbb"};
	char arr_c[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

	iter<int>(arr_i, 5, f<int>);
	std::cout << "\n";
	iter<const float>(arr_f, 3, f<const float>);
	std::cout << "\n";
	iter<std::string>(arr_s, 2, f<std::string>);
	std::cout << "\n";
	iter<char>(arr_c, 7, f<char>);
	std::cout << "\n";
	iter(arr_i, 5, multiplyByTwo<int>);
}