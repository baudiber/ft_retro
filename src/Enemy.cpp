/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:58:17 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 13:45:59 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void) : _level(1), _weapon(Weapon())
{
	return ;
}

Enemy::Enemy(Enemy const & src) : _level(src._level), _weapon(src._weapon)
{
	return ;
}

Enemy::Enemy(int level, int weapon) : _level(1), _weapon(1)
{
	return ;
}

Enemy::~Enemy(void)
{
	return ;
}

void			Enemy::attack(void)
{
	if (this->weapon)

	return ;
}

Enemy			&Enemy::operator=(Enemy const &rh)
{
	this->_level = rh._level;
	this->_weapon = rh._weapon;
	return (*this);
}

