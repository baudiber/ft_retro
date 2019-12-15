/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:38:48 by mbuch             #+#    #+#             */
/*   Updated: 2019/12/15 11:52:32 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "GameEntity.hpp"
#include "Engine.hpp"

int				main()
{
	Engine		game;

	game.run();
	return (0);
}
