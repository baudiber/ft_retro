/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 10:25:03 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 12:06:17 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "Elem.hpp"
# include "GameObject.hpp"

class List
{
	public:
		int			_size;
		Elem		*_first;
		Elem		*_last;
		List(void);
		List(List const &src);
		List		&operator=(List const &rh);
		~List(void);
		// void		push(GameEntity *e);
		GameObject	*pop(GameObject *elem);
		List		&operator<<(GameObject *e);
};

#endif