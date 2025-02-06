/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:32:19 by mpellegr          #+#    #+#             */
/*   Updated: 2025/02/06 07:30:10 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();
	MutantStack(MutantStack<T, Container> const & src);
	MutantStack<T, Container> & operator = (MutantStack<T, Container> const & src);
	~MutantStack();

	typedef typename Container::iterator iterator;
	iterator begin();
	iterator end();

	typedef typename Container::const_iterator const_iterator;
	const_iterator cbegin() const;
	const_iterator cend() const;

	typedef typename Container::reverse_iterator reverse_iterator;
	reverse_iterator rbegin();
	reverse_iterator rend();

	typedef typename Container::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator crbegin () const;
	const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"