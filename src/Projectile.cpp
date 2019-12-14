/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:59:23 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 14:54:18 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(void) : _source(NULL)
{
	return ;
}

Projectile::Projectile(Projectile const & src) : _source(src._source)
{
	return ;
}

Projectile::Projectile(Weapon &w) : _source(&w)
{
	return ;
}

Projectile::~Projectile(void)
{
	return ;
}

void			Projectile::process(float const t)
{
	GameObject	*obj;

	obj = this;
	obj->process(t);
	if ()

	return ;
}

Projectile			&Projectile::operator=(Projectile const &rh)
{
	this->_source = rh._source;
	return (*this);
}

