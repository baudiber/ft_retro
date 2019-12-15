/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:59:23 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/15 20:38:12 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(void) : _source(NULL)
{
	this->_mov = Vect2(0, 0);
	this->_dir = Vect2(2, 0);
	this->_pos = Vect2(2, 2);
	this->lst << this;
	this->_sprite = "-=-";
	return ;
}

Projectile::Projectile(Projectile const & src) : GameObject(src), \
_source(src._source)
{
	this->lst << this;
	this->_sprite = "-=-";
	return ;
}

Projectile::Projectile(GameEntity *src) : _source(src), _damage(20)
{
	this->lst << this;
	this->_sprite = "-=-";
	this->_pos = src->getPos();
	this->_dir = src->getDir();
	return ;
}

void				Projectile::setDamage(int amount)
{
	this->_damage = amount;
}

Projectile::~Projectile(void)
{
	this->lst << this;
	return ;
}

Projectile			&Projectile::operator=(Projectile const &rh)
{
	this->_source = rh._source;
	return (*this);
}

List			Projectile::lst = List();
