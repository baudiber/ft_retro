/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 12:39:44 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/15 04:33:22 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "GameEntity.hpp"
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
		Player(void);
		Player(Player const &src);
		Player			&operator=(Player &rh);
		~Player();
};

#endif
