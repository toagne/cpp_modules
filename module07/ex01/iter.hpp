/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 07:48:47 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/05 09:33:01 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template<typename T, typename Funct>
void iter(T *arr, size_t lenght, Funct f) {
	for (size_t i = 0; i < lenght; i++)
		f(arr[i], i);
}

template<typename T, typename Funct>
void iter(T const *arr, size_t lenght, Funct f) {
	for (size_t i = 0; i < lenght; i++)
		f(arr[i], i);
}

template<typename T>
void f(T &element, size_t &i) {
	std::cout << "Array element at index " << i << " is: " << element << std::endl;
}

template<typename T>
void multiplyByTwo(T &element, size_t i) {
	element = element * 2;
	std::cout << "Element at index " << i << " after multiplication: " << element << std::endl;
}
