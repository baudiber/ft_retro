/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:58:17 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 12:11:10 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void) : _level(1)
{
	this->lst << this;
	return ;
}

Enemy::Enemy(Enemy const & src) : _level(src._level)
{
	this->lst << this;
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
	Projectile		p;

	p = Projectile(this);
	p._speed = 2;
	p.setDamage(10 * this->_level);
	return ;
}