/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:15:40 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/10 14:42:12 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <limits>
#include <vector>
#include <set>

class PmergeMe
{
private:
	std::vector<int> _args;
public:
	PmergeMe(/* args */);
	~PmergeMe();
	
	void execute(char **av);
	void parseArgs(char **av);
	void sort();
};