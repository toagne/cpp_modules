/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:51:33 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/05 19:36:48 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span const & src) : _N(src._N), _vector(src._vector) {}

Span & Span::operator = (Span const & src) {
	if (this != &src) {
		_N = src._N;
		_vector = src._vector;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_vector.size() >= _N)
		throw std::overflow_error("simple addNumber - maximum size reached, you can't add more values");
	_vector.push_back(n);	
}

int Span::shortestSpan() {
	if (_vector.size() < 2)
		throw std::logic_error("not enough values to calclulate shortest span");
	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());
	int minSpan = copy[1] - copy[0];
	for (size_t i = 1; i < copy.size() - 1; i++)
		minSpan = std::min(minSpan, copy[i + 1] - copy[i]);
	return minSpan;
}

int Span::longestSpan() {
	if (_vector.size() < 2)
		throw std::logic_error("not enough values to calclulate longest span");
	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());
	return copy[copy.size() - 1] - copy[0];
}