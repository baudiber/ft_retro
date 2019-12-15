/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:46:35 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/15 04:20:25 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"

GameEntity::GameEntity(void) : _hp(100), _hp_max(100), _ep(100), \
_ep_max(100)
{
	return ;
}

GameEntity::GameEntity(GameEntity const &src) : _hp(src._hp), _hp_max(0), \
_ep(src._ep), _ep_max(src._ep_max)
{
	return ;
}

GameEntity::~GameEntity(void)
{
	return ;
}

GameEntity			GameEntity::operator=(GameEntity const &rh)
{
	std::cout << "Copy Operator GAME ENTITY" << std::endl;
	this->_hp = rh._hp;
	this->_hp_max = rh._hp_max;
	this->_ep = rh._ep;
	this->_ep_max = rh._ep_max;
	this->_speed = rh._speed;
	return (*this);
}

char				GameEntity::actualSprite()
{
	return (this->_sprite[(int)(this->_step) % (this->_sprite.length() - 1)]);
}

void				GameEntity::takeDamage(int amount)
{
	this->_hp -= amount;
	this->_hp = (this->_hp < 0 ? 0 : this->_hp);
	if (this->_hp == 0)
		this->_state = STATE_DEAD;
	else
		this->_state = STATE_DAMAGE;
}
