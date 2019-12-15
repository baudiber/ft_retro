/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 12:39:31 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 15:41:38 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void) : _name("PLAYER ONE"), _lives(5), _level(1), _score(0)
{
	return ;
}

Player::Player(Player const & src) : _name(src._name), _lives(src._lives), \
_level(src._level), _score(src._score)
{
	this->_dir = src._dir;
	this->_pos = src._pos;
	return ;
}

Player			&Player::operator=(Player &rh)
{
	this->_name = rh._name;
	this->_level = rh._level;
	this->_lives = rh._lives;
	this->_score = rh._score;
	this->_pos = rh.getPos();
	this->_dir = rh.getDir();
	return (*this);
}

int				Player::getScore() const
{
	return (_score);
}

int				Player::getLives() const
{
	return (_lives);
}

int				Player::getLevel() const
{
	return (_level);
}

void			Player::score(int value)
{
	this->_score += value;
}

std::string		Player::getName() const
{
	return (_name);
}

void			Player::levelUp()
{
	this->_level++;
	this->_score += 1000;
}

Player::~Player(void)
{
	return ;
}
