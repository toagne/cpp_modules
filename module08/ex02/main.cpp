/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:43:13 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/06 07:40:13 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "\n";
// *********************************************************
	{
		MutantStack<int> mstack;

		mstack.push(10);
		mstack.push(20);
		mstack.push(30);
		mstack.push(40);

		std::cout << "MutantStack contents (forward): ";
		MutantStack<int>::iterator it;
		for (it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "MutantStack contents (reverse): ";
		MutantStack<int>::reverse_iterator rit;
		for (rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
			std::cout << *rit << " ";
		std::cout << std::endl;

		const MutantStack<int> const_mstack = mstack;
		std::cout << "Const MutantStack contents (forward): ";
		MutantStack<int>::const_iterator cit;
		for (cit = const_mstack.cbegin(); cit != const_mstack.cend(); ++cit)
		{
			std::cout << *cit << " ";
			// *cit = 42; // This should not compile! (read-only access)
		}
		std::cout << std::endl;

		std::cout << "Const MutantStack contents (reverse): ";
		MutantStack<int>::const_reverse_iterator crit;
		for (crit = const_mstack.crbegin(); crit != const_mstack.crend(); ++crit)
		{
			std::cout << *crit << " ";
			// *crit = 42; // This should not compile! (read-only access)
		}
		std::cout << std::endl;
	}
	
	return 0;
}