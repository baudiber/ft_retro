/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:59:42 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 14:44:04 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include "Engine.hpp"
# include "GameObject.hpp"
# include "Weapon.hpp"

class Projectile : public GameObject
{
	private:
		Weapon			*_source;
	public:
		Projectile(void);
		Projectile(Projectile const &src);
		Projectile(Weapon &src);
		Projectile		&operator=(Projectile const &rh);
		~Projectile();
		void			process(float const t) override;
};

#endif