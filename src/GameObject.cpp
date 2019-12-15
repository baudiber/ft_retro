/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:42:38 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/15 08:34:38 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"

GameObject::GameObject(void) : _state(STATE_IDLE), _step(0), _pos(Vect2()), \
_dir(Vect2(1, 0)), _speed(1), _sprite("oO"), _color(COLOR_RED)

{
	return ;
}

GameObject::GameObject(GameObject const &src) : _state(src._state), _step(0), \
_pos(src._pos), _dir(src._dir), _speed(src._speed), _sprite(src._sprite), \
_color(src._color)
{
	return ;
}

GameObject::~GameObject(void)
{
	return ;
}

GameObject			GameObject::operator=(GameObject const &rh)
{
	this->_state = rh._state;
	this->_step = rh._step;
	this->_pos = rh._pos;
	this->_dir = rh._dir;
	this->_sprite = rh._sprite;
	this->_color = rh._color;
	return (*this);
}

void				GameObject::move(Vect2 const &v)
{
	if (this->_state == STATE_DEAD)
		return ;
	this->_mov = v.normalized();
}

Vect2				GameObject::getPos()
{
	return (this->_pos);
}

Vect2				GameObject::getDir()
{
	return (this->_dir);
}

GameObject			*GameObject::collide(GameObject *o)
{
	if (this != o && (int)o->_pos._x == (int)this->_pos._x && \
	(int)o->_pos._y == (int)this->_pos._y)
		return (o);
	return (0);
}

void				GameObject::process(float const t)
{
	// this->_step += this->_speed * t;
	// if (this->_step >= 2.0)
	// {
	// 	if (this->_state != STATE_DEAD)
	// 	{
	// 		this->_state = STATE_IDLE;
	// 		this->_step = 0;
	// 	}
	// }
	// this->_pos = (Vect2(1, 0) + this->_mov) * this->_speed * t;
	this->_pos = this->_pos + ((this->_dir + this->_mov) * t);
	this->_mov = this->_mov * t;
}

