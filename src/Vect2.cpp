/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:52:43 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 13:45:31 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vect2.hpp"

Vect2::Vect2(void) : _x(0), _y(0)
{
	return ;
}

Vect2::Vect2(Vect2 const &src) : _x(src._x), _y(src._y)
{
	return ;
}

Vect2::Vect2(float x, float y) : _x(x), _y(y)
{
	return ;
}

Vect2::Vect2(int x, int y) : _x(x), _y(y)
{
	return ;
}

Vect2				Vect2::operator+(Vect2 const &rh)
{
	return (Vect2(this->_x + rh._x, this->_y + rh._y));
}

void				Vect2::normalize(void)
{
	float			mag;

	mag = this->magnitude();
	this->_x = this->_x / mag;
	this->_y = this->_y / mag;
}

Vect2				Vect2::normalized(void) const
{
	float			mag;

	mag = this->magnitude();
	return (Vect2(this->_x / mag, this->_y / mag));
}

Vect2				Vect2::operator-(Vect2 const &rh)
{
	return (Vect2(this->_x - rh._x, this->_y - rh._y));
}

Vect2				Vect2::operator*(float const n)
{
	return (Vect2(this->_x * n, this->_y * n));
}

Vect2				Vect2::operator/(float const n)
{
	return (Vect2(this->_x / n, this->_y / n));
}

float				Vect2::operator*(Vect2 const &rh)
{
	return (this->_x * this->_y + rh._y * rh._y);
}

float				Vect2::magnitude(void) const
{
	return (sqrt(this->_x * this->_x + this->_y * this->_y));
}

Vect2				&Vect2::operator=(Vect2 const &rh)
{
	this->_x = rh._x;
	this->_y = rh._y;
	return (*this);
}

Vect2::~Vect2(void)
{
	return ;
}