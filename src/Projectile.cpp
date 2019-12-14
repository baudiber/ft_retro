/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:59:23 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 12:09:54 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(void) : _source(NULL)
{
	this->lst << this;
	return ;
}

Projectile::Projectile(Projectile const & src) : \
_source(src._source)
{
	this->lst << this;
	return ;
}

Projectile::Projectile(GameEntity *src) : _damage(20), _source(src)
{
	this->lst << this;
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

