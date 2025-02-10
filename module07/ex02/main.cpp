/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:22:03 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/10 09:53:26 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750

int main(void) {
	Array<int> arr(5);
	std::cout << "array arr created with size " << arr.size() << std::endl;

	for (size_t i = 0; i < arr.size(); i++) {
		arr[i] = i + 7;
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
	std::cout << "\n";
	
	try {
		std::cout << arr[7];
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";

	Array<int> arrCopy(arr);
	std::cout << "array arrCopy created with copy constructor with size " << arrCopy.size() << std::endl;
	std::cout << "original arr[0] = " << arr[0] << std::endl;
	std::cout << "changing value of arr[0]\n";
	arr[0] = 222;
	std::cout << "new arr[0] = " << arr[0] << std::endl;
	std::cout << "arrCopy[0] = " << arrCopy[0] << std::endl;
	std::cout << "\n";

	Array<int> arrAssign(3);
	std::cout << "array arrAssign created with copy constructor with size " << arrAssign.size() << std::endl;
	std::cout << "assigning arr with size " << arr.size() << " to arrAssign\n";
	arrAssign = arr;
	std::cout << "arraAssign new size = " << arrAssign.size() << std::endl;
	std::cout << "\n";

	Array<float> arrFloat(3);
	std::cout << "array arrFloat created with size " << arrFloat.size() << std::endl;
	for (size_t i = 0; i < arrFloat.size(); i++) {
		arrFloat[i] = i + 1.1f;
		std::cout << "arrFloat[" << i << "] = " << arrFloat[i] << std::endl;
	}
	std::cout << "\n";

	Array<int> arrEmpty;
	std::cout << "array arrEmpty created with size " << arrEmpty.size() << std::endl;
	std::cout << "\n";

// ************************************************************************************

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete [] mirror;

	return 0;
}