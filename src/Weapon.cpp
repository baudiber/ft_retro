/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:58:55 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 14:53:37 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : _owner(NULL), _damage(20), _projectile_nbr(1), \
_projectile_speed(3), _fire_angle(0), _fire_speed(1)
{
	return ;
}

Weapon::Weapon(Weapon const & src) : _owner(src._owner), _damage(src._damage), \
_projectile_nbr(src._projectile_nbr), _projectile_speed(src._projectile_speed), \
_fire_angle(src._fire_angle), _fire_speed(src._fire_speed)
{
	return ;
}

Weapon::Weapon(GameEntity *owner, int damage, int p_nbr, \
float p_speed, float angle, float f_speed) : _owner(owner), _damage(damage), \
_projectile_nbr(p_nbr), _projectile_speed(p_speed), _fire_angle(0), \
_fire_speed(f_speed)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

void			Weapon::use(void)
{
	Engine::addProjectile(this);
	return ;
}

Weapon			&Weapon::operator=(Weapon const &rh)
{
	this->_level = rh._level;
	this->_weapon = rh._weapon;
	return (*this);
}

