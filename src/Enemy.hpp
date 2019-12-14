/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:54:18 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 15:40:15 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "GameEntity.hpp"
# include "Projectile.hpp"
# include "List.hpp"

class Enemy : public GameEntity
{
	public:
		static List	lst;
		int			_level;
		Enemy(void);
		Enemy(Enemy const &src);
		Enemy		&operator=(Enemy &rh);
		~Enemy();
		void			attack();
};

#endif
