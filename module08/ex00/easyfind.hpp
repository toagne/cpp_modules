/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:58:28 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/05 14:40:51 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <list>
#include <iostream>
#include <vector>

template <typename T>
typename T::const_iterator easyfind(T &container, int value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return it;
	throw std::runtime_error("Value " + std::to_string(value) + " not found in container");
}