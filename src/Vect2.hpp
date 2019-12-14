/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:52:56 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 13:45:40 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define VECT2_HPP

#include <math.h>

class Vect2
{
	public:
		float		_x;
		float		_y;
		Vect2(void);
		Vect2(Vect2 const &src);
		Vect2(float x, float y);
		Vect2(int x, int y);
		~Vect2(void);
		float		magnitude(void) const;
		Vect2		normalized(void) const;
		void		normalize(void);
		Vect2		&operator=(Vect2 const &rh);
		Vect2		operator+(Vect2 const &rh);
		Vect2		operator-(Vect2 const &rh);
		float		operator*(Vect2 const &rh);
		Vect2		operator*(float const n);
		Vect2		operator/(float const n);
};

#endif