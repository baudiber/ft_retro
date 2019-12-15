/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:50:27 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/15 13:51:27 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_HPP
# define ENGINE_HPP

# include "GameEntity.hpp"
# include "Enemy.hpp"
# include "Projectile.hpp"
# include "Player.hpp"
# include "Vect2.hpp"
# include "bindings.hpp"
# include "ncurses.h"

# define MAX_ENEMY		256
# define MAX_PROJECT	256

class Engine
{
	private:

		int					_count;
		int					_win_w;
		int					_win_h;
		int					_score;
		static int			_level;
		WINDOW*				_win;
		void				spawn(void);
		void				processCollision(GameEntity);
		void				processEnemies(void);
		void				processProjectiles(void);
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
  
		void			run(void);
		void			error(std::string const & msg);
		void			gameOver(void);
		void			displayObject(GameObject *) const;

		void				process(void);
		void				render(void) const;
		void				displayMenu(void) const;
		void				displayHud(void) const;

};

#endif
