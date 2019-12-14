/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elem.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 10:37:50 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 15:40:04 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEM_HPP
# define ELEM_HPP

class GameObject;

class Elem
{
	public:
		GameObject	*_data;
		Elem		*_next;
		Elem		*_prev;
		Elem(void);
		Elem(Elem const &src);
		Elem(GameObject *data);
		Elem		&operator=(Elem const &rh);
		~Elem(void);
};

#endif
