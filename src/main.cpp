/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:38:48 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/14 15:43:57 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "GameEntity.hpp"
#include "Engine.hpp"

int				main()
{
	GameEntity	enemy0;
	GameEntity	*eptr = new GameEntity(enemy0);
	GameEntity	*cpy_ptr;

	cpy_ptr = eptr;
	return (0);
}
