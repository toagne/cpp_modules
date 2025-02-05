/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:42:20 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/05 16:38:17 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _vector;
public:
	Span();
	Span(unsigned int N);
	Span(Span const & src);
	Span & operator = (Span const & src);
	~Span();

	void addNumber(int n);
	int shortestSpan();
	int longestSpan();

	template <typename Iterator>
	void addNumber(Iterator begin, Iterator end) {
		if (_vector.size() + std::distance(begin, end) > _N) {
			throw std::overflow_error("maximum size reached, you can't add more values");
		}
		_vector.insert(_vector.end(), begin, end);
	}
};