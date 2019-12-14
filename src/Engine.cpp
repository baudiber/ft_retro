/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:19:16 by baudiber          #+#    #+#             */
/*   Updated: 2019/12/14 12:15:09 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Engine.hpp"

Engine::Engine(void) {
	std::cout << "Engine Default constructor called" << std::endl;
	this->_win = initscr();
	keypad(this->_win, true);
	noecho();
	curs_set(0);
	getmaxyx(this->_win, this->_win_h, this->_win_w);
	//if (this->//
	this->displayMenu();
	nodelay(stdscr, true);
	init_color(COLOR_RED, 250, 250, 250);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	return;
}	

Engine::Engine(Engine const & src) {
	std::cout << "Engine Copy constructor called" << std::endl;
	*this = src;
	return;
}

Engine::~Engine(void) {
	std::cout << "Engine Destructor called" << std::endl;
	nodelay(stdscr, false);
	getch();
	endwin();
	return;
}	

Engine &		Engine::operator=(Engine const & rhs) {
	std::cout << "Engine Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_win_w = rhs._win_w;
		this->_win_h = rhs._win_h;
		this->_enemy_nb = rhs._enemy_nb;
		this->_projectile_nb = rhs._projectile_nb;
	}
	return *this;
}

void			Engine::run(void) const {
	for (;;)
	{
		//check for game over
		//to break

		this->render();
	}
}

void			Engine::render(void) const {
	clear();

	attron(A_BOLD); // display player and enemies in BOLD

	//display Player		
	move(this->_player._pos.y, this->_player._pos.y)
	addch(this->player._sprite[0]);

	//display enemies
	for (int i = 0; i < this->_enemy_nb; i++)
	{
		move(this->_enemies[i]._pos.y, this->_enemies[i]._pos.y)
		addch(this->_enemies[i]._sprite[0]);
	}
	attroff(A_BOLD);
	//display projectiles
	for (int i = 0; i < this->_projectile_nb; i++)
	{
		move(this->_projectiles[i]._pos.y, this->_projectiles[i]._pos.y)
		addch(this->_projectiles[i]._sprite[0]);
	}
	
	refresh();	
}

void			Engine::displayMenu(void) const {
	clear();
	mvprintw(y / 2, x / 2, "FT_RETRO");
	refresh();
	int c;
	for (;;)
		if ((c = getch()) == KEY_SPACE)
			break;
}

