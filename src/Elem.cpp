/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elem.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 10:42:38 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 11:49:31 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Elem.hpp"

Elem::Elem(void) : _data(0), _next(0), _prev(0)
{
	return ;
}

Elem::Elem(Elem const & src) : _data(src._data), _next(src._next), _prev(src._prev)
{
	return ;
}

Elem::Elem(GameObject *data) : _data(data), _next(0), _prev(0)
{
	return ;
}

Elem			&Elem::operator=(Elem const &rh)
{
	this->_data = rh._data;
	this->_next = rh._next;
	this->_prev = rh._prev;
	return (*this);
}

Elem::~Elem(void)
{
	return ;
}

