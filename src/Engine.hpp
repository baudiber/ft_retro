/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:50:27 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 14:56:16 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_HPP
# define ENGINE_HPP

# include "GameEntity.hpp"
# include "Enemy.hpp"
# include "Projectile.hpp"
# include "Weapon.hpp"
# include "Vect2.hpp"

# define MAX_ENEMY		256
# define MAX_PROJECT	256

class Engine
{
	public:
		Engine(void);
		Engine(Engine const &src);
		Engine			&operator=(Engine const &rh);
		~Engine();
		Vect2			win;
		Enemy			_enemies[MAX_ENEMY];
		Projectile		_projectiles[MAX_PROJECT];
		GameEntity		_player;
		void			addProjectile(Weapon *w);
};

#endif