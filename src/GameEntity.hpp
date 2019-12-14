/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:40:59 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 14:54:37 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_H
# define GAMEENTITY_H

# include <iostream>
# include <string>
# include <ncurses.h>
# include "Vect2.hpp"
# include "GameObject.hpp"


class GameEntity : GameObject
{
	protected:
		int				_hp;
		int				_hp_max;
		int				_ep;
		int				_ep_max;
		// static long		_last;
	public:
		GameEntity(void);
		GameEntity(GameEntity const &src);
		GameEntity		operator=(GameEntity const &rh);
		~GameEntity();
		void			takeDamage(int amount);
};

#endif