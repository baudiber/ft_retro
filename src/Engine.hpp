/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:50:27 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 12:13:17 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_HPP
# define ENGINE_HPP

# include "GameEntity.hpp"
# include "Enemy.hpp"
# include "Projectile.hpp"
# include "Vect2.hpp"

# define MAX_ENEMY		256
# define MAX_PROJECT	256

class Engine
{
	private:
		int					_win_w;
		int					_win_h;
		static int			_enemy_nb;
		static int			_projectile_nb;
		WINDOW*				_win;

	public:
		Engine(void);
		Engine(Engine const &src);
		Engine				&operator=(Engine const &rh);
		~Engine();
		int					load(std::string gamefile);
		Vect2				win;
		static Enemy		_enemies[MAX_ENEMY];
		static Projectile	_projectiles[MAX_PROJECT];
		static GameEntity	_player;
		int					get();
		
		void			render(void) const;
		void			displayMenu(void) const;
		void			run(void) const;
};

#endif
