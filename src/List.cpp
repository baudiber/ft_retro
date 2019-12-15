/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 10:24:54 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/15 07:30:18 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "List.hpp"

List::List(void) : _size(0), _first(0), _last(0)
{
	return ;
}

List::List(List const & src) : _size(src._size), _first(src._first), _last(src._last)
{
	return ;
}

List			&List::operator=(List const &rh)
{
	this->_size = rh._size;
	this->_first = rh._first;
	this->_last = rh._last;
	return (*this);
}

List			&List::operator<<(GameObject *data)
{
	Elem		*e = new Elem(data);

	if (this->_size == 0)
		this->_first = e;
	else
		this->_last->_next = e;
	this->_size++;
	e->_prev = this->_last;
	this->_last = e;
	return (*this);
}

GameObject		*List::pop(GameObject *elem)
{
	Elem		*i;
	GameObject	*o;

	i = this->_first;
	while (i)
	{
		if (i->_data == elem)
		{
			if (i->_prev)
				i->_prev->_next = i->_next;
			else
				this->_first = i->_next;
			if (i->_next)
				i->_next->_prev = i->_prev;
			else
				this->_last = i->_prev;
			o = i->_data;
			this->_size--;
			delete (i);
			return (o);
		}
		i = i->_next;
	}
	return (0);
}

GameObject		*List::pop(Elem *elem)
{
	GameObject	*o;

	if (elem)
	{
		if (elem->_prev)
			elem->_prev->_next = elem->_next;
		else
			this->_first = elem->_next;
		if (elem->_next)
			elem->_next->_prev = elem->_prev;
		else
			this->_last = elem->_prev;
		o = elem->_data;
		this->_size--;
		delete (elem);
		return (o);
	}
	return (0);
}

void			List::push(GameObject *o)
{
	Elem		*e = new Elem(o);

	if (this->_size == 0)
		this->_first = e;
	else
		this->_last->_next = e;
	this->_size++;
	e->_prev = this->_last;
	this->_last = e;
}

List::~List(void)
{
	Elem		*i;
	Elem		*j;

	i = this->_first;
	while (i)
	{
		j = i;
		i = i->_next;
		this->_size--;
		delete (j);
	}
	return ;
}

