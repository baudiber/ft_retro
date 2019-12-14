/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:59:41 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 14:55:20 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include "GameObject.hpp"
# include "GameEntity.hpp"
# include "Engine.hpp"

class Weapon : public GameObject
{
	private:
		GameEntity		*_owner;
		int				_damage;
		int				_projectile_nbr;
		float			_projectile_speed;
		float			_fire_angle;
		float			_fire_speed;
	public:
		Weapon(void);
		Weapon(Weapon const &src);
		Weapon(GameEntity *owner, int damage, int p_nbr, \
		float p_speed, float angle, float f_speed);
		Weapon		&operator=(Weapon const &rh);
		~Weapon();
		void			use(void);
};

#endif