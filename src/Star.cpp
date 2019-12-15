/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:27:04 by baudiber          #+#    #+#             */
/*   Updated: 2019/12/15 21:36:26 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star.hpp"

Star::Star(void) {
	this->lst.push(this);
	this->_sprite = ".";
	return ;
}

Star::Star(Star const & src) : GameEntity(src)
{
	this->_pos = src._pos;
	this->_dir = src._dir;
	this->_sprite = src._sprite;
	this->lst.push(this);
	return ;
}

Star			&Star::operator=(Star &rh)
{
	this->_pos = rh.getPos();
	return (*this);
}

Star::~Star(void)
{
	this->lst.pop(this);
	return ;
}

List			Star::lst = List();
