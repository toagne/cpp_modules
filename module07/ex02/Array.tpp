/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:09:39 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/05 13:08:56 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template < typename T>
Array<T>::Array() : _content(nullptr), _size(0) {}

template < typename T>
Array<T>::Array(unsigned int n) : _content(new T[n]()), _size(n) {}

template < typename T>
Array<T>::Array(Array<T> const & src) : _content(new T[src._size]()), _size(src._size) {
	for (unsigned int i = 0; i < _size; i++)
		_content[i] = src._content[i];
}

template < typename T>
Array<T> &Array<T>::operator = (Array<T> const & src) {
	if (this != &src) {
		delete[] _content;
		_size = src._size;
		_content = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
			_content[i] = src._content[i];
	}
	return *this;
}

template < typename T>
Array<T>::~Array() { delete[] _content; }

template <typename T>
T & Array<T>::operator [] (unsigned int index) {
	if (index >= _size || _content == nullptr)
		throw IndexOutOfBounds();
	return _content[index];
}

template <typename T>
unsigned int Array<T>::size() const { return _size; }

template <typename T>
const char* Array<T>::IndexOutOfBounds::what() const throw() {
	return "Error: index is out of bounds";
}