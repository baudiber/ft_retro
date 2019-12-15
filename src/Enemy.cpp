/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:58:17 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/15 06:42:37 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void) : _level(1)
{
	std::cout << "Creating Default Enemy" << std::endl;
	this->lst.push(this);
	this->_sprite = "oO";
	return ;
}

Enemy::Enemy(Enemy const & src) : _level(src._level)
{
	std::cout << "Creating Enemy by copy" << std::endl;
	this->_pos = src._pos;
	this->_dir = src._dir;
	this->_sprite = src._sprite;
	this->lst.push(this);
	return ;
}

Enemy			&Enemy::operator=(Enemy &rh)
{
	this->_pos = rh.getPos();
	return (*this);
}

Enemy::~Enemy(void)
{
	this->lst.pop(this);
	return ;
}

void			Enemy::attack(void)
{
	Projectile	*p;

	p = new Projectile(this);
	p->_speed = 2;
	p->setDamage(10 * this->_level);
	return ;
}

List			Enemy::lst = List();
