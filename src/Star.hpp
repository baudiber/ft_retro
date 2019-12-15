/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:27:06 by baudiber          #+#    #+#             */
/*   Updated: 2019/12/15 21:35:56 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_HPP
# define STAR_HPP

# include "GameEntity.hpp"
# include "List.hpp"

class Star : public GameEntity
{
	public:
		static List	lst;
		Star(void);
		Star(Star const &src);
		Star		&operator=(Star &rh);
		~Star();
};

#endif
