/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:54:18 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 13:45:57 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "GameEntity.hpp"
# include "Vect2.hpp"

class Enemy : public GameEntity
{
	private:
		int				_level;
		Weapon			_weapon;
	public:
		Enemy(void);
		Enemy(Enemy const &src);
		Enemy		operator=(Enemy const &rh);
		~Enemy();

		void			attack();

}

#endif