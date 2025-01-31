/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:18:48 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/31 15:41:57 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void) {
	Data *data = new Data;
	data->age = 28;
	
	uintptr_t raw = Serializer::serialize(data);
	Data *new_data = Serializer::deserialize(raw);
	std::cout << "address of original Data: " << data << std::endl;
	std::cout << "address of   new    Data: " << new_data << std::endl;

	delete data;
}