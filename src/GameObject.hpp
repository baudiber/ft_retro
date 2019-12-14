/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:43:14 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 14:04:35 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_H
# define GAMEOBJECT_H

# include <string>
# include <ncurses.h>
# include "Vect2.hpp"

# define STATE_IDLE		0
# define STATE_WAIT		1
# define STATE_ATTACK	2
# define STATE_DAMAGE	3
# define STATE_DEAD		4

class GameObject
{
	public:
		int				_state;
		float			_step;
		Vect2			_pos;
		Vect2			_dir;
		Vect2			_mov;
		float			_speed;
		std::string		_sprite;
		int				_color;
		GameObject(void);
		GameObject(GameObject const &src);
		GameObject		operator=(GameObject const &rh);
		~GameObject();
		void			move(Vect2 const &v);
		virtual void	process(float const t);
};

#endif