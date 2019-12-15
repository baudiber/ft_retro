/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:20:00 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 11:42:01 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/List.hpp"
#include "src/GameEntity.hpp"

#include <iostream>

int main()
{
	List	lst;
	Elem	*i;
	GameEntity e1;
	GameEntity e2;
	GameEntity e3;
	GameEntity e4;

	lst << &e4 << &e1 << &e2 << &e3;
	i = lst._first;
	while (i)
	{
		std::cout << "Loop" << std::endl;
		i = i->_next;
	}
	return (0);
}