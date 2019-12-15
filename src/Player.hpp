/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 12:39:44 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/15 18:01:19 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP
# define KEY_ARROW_UP 259
# define KEY_ARROW_DOWN 258
# define KEY_ARROW_RIGHT 261
# define KEY_ARROW_LEFT 260
# define KEY_SPACE 32
# include "GameEntity.hpp"
# include "Projectile.hpp"
# include <string>

class Player : public GameEntity
{
	private:
		std::string		_name;
		int				_lives;
		int				_level;
		int				_score;
	public:
		int				getScore() const;
		void			score(int value);
		std::string		getName() const;
		int				getLives() const;
		int				getLevel() const;
		void			takeDamage(int value);
		void			levelUp();
		void			input(int key);
		void			process(float const t);
		Player(void);
		Player(Player const &src);
		Player			&operator=(Player &rh);
		~Player();
};

#endif
