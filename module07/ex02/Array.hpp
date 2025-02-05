/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:38:21 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/05 11:21:48 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template < typename T>
class Array
{
private:
	T *_content;
	unsigned int _size;
public:
	Array();
	Array(unsigned int n);
	Array(Array<T> const & src);
	Array<T> & operator = (Array<T> const & src);
	~Array();

	T & operator [] (unsigned int index);
	unsigned int size() const;

	class IndexOutOfBounds : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

#include "Array.tpp"