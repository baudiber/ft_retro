/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:59:42 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 15:40:34 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include "GameObject.hpp"
# include "GameEntity.hpp"
# include "List.hpp"

class Projectile : public GameObject
{
	private:
	public:
		GameEntity		*_source;
		int				_damage;
		static List		lst;
		Projectile(void);
		Projectile(Projectile const &src);
		Projectile(GameEntity *src);
		void			setDamage(int amount);
		Projectile		&operator=(Projectile const &rh);
		~Projectile();
		void			process(float const t);
};

#endif
