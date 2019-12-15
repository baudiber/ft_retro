/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 12:39:31 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/15 20:38:40 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void) : _name("PLAYER ONE"), _lives(5), _level(1), _score(0)
{
	this->_mov = Vect2(0, 0);
	this->_dir = Vect2(0, 0);
	this->_pos = Vect2(2, 2);
	return ;
}

Player::Player(Player const & src) : GameEntity(src), _name(src._name), _lives(src._lives), \
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

void			Player::fire() {
	Projectile   *p= new Projectile(this);
  	p->_pos = this->_pos;
  	p->_dir = Vect2(2, 0);
}

void			Player::takeDamage(int value)
{
	this->_hp -= value;
	this->_hp = (this->_hp < 0 ? 0 : this->_hp);
	if (this->_hp <= 0)
	{
		this->_lives--;
		if (_lives >= 0)
		{
			this->resetPos();
			this->_hp = _hp_max;
		}
		else
			this->_state = STATE_DEAD;
	}
}

void		Player::process(float const t) {
	this->_pos._x = this->_pos._x + this->_mov._x / 2;
	this->_pos._y = this->_pos._y - this->_mov._y / 2;
	this->_mov = this->_mov* t;
}

void		Player::input(int key) {
	if (key == KEY_ARROW_UP)
		this->_mov._y = 1;
	else if (key == KEY_ARROW_DOWN)
		this->_mov._y = -1;
	if (key == KEY_ARROW_RIGHT)
		this->_mov._x = 1;
	else if (key == KEY_ARROW_LEFT)
		this->_mov._x = -1;
	if (key == KEY_SPACE)
		this->fire();
}

void			Player::setSpawn(Vect2 const &v) {
	this->_pos = v;
	this->_spawn = v;
}

void			Player::resetPos(void) {
	this->_pos = this->_spawn;
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
