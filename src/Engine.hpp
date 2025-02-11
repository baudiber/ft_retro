/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:50:27 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/15 17:54:41 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <unistd.h>
# include "GameEntity.hpp"
# include "Enemy.hpp"
# include "Star.hpp"
# include "Projectile.hpp"
# include "Player.hpp"
# include "Vect2.hpp"
# include "bindings.hpp"

# define MAX_ENEMY		256
# define MAX_PROJECT	256
# define SLEEP	100

class Engine
{
	private:

		int					_count;
		int					_win_w;
		int					_win_h;
		static int			_level;
		WINDOW*				_win;
		void				spawn(void);
		void				spawnStars(void);
		void				processCollision(GameEntity);
		void				processEnemies(void);
		void				processProjectiles(void);
		void				processStars(void);
		void				processProjectile(Projectile *p);

	public:
		Engine(void);
		Engine(Engine const &src);
		Engine				&operator=(Engine const &rh);
		~Engine();
		int					load(void);
		Vect2				win;
		static Enemy		_enemies[MAX_ENEMY];
		static Projectile	_projectiles[MAX_PROJECT];
		static Player		_player;
		static std::string	level;
		int					get();
  
		void				run(void);
		void				gameOver(void);
		void				displayObject(GameObject *) const;

		void				process(void);
		void				render(void) const;
		void				displayMenu(void) const;
		void				displayHud(void) const;

};

#endif
