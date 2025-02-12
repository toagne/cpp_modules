/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:15:40 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/12 15:25:35 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <limits>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>
#include <deque>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::deque<int> _deque;
public:
	PmergeMe();
	~PmergeMe();
	
	void execute(char **av);
	void parseArgs(char **av);
	
	template <typename T>
	void sort(T &container);
	
	template <typename T>
	int binaryInsertion(T &container, int value);
};