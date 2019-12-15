/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:19:16 by baudiber          #+#    #+#             */
/*   Updated: 2019/12/15 04:31:50 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Engine.hpp"

Engine::Engine(void) : _score(0) {
	std::cout << "Engine Default constructor called" << std::endl;
	this->_win = initscr();
	this->_level = 1;
	keypad(this->_win, true);
	noecho();
	curs_set(0);
	getmaxyx(this->_win, this->_win_h, this->_win_w);
    if (this->_win_h <= 20 || this->_win_w <= 100) 
		this->error("Please enlarge your window");
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
		this->_level = rhs._level;
		this->_win_w = rhs._win_w;
		this->_win_h = rhs._win_h;
	}
	return *this;
}


//void			Engine::addProjectile(Weapon *w) {
//
//}

void			Engine::run(void) {
	int k = 0;

	for (;;)
	{
		//check for game over
		//to break
		if ((k = getch()) == KEY_ESC)
			this->gameOver();
		if (_player._state == STATE_DEAD)
			this->gameOver();
		std::cout << k << std::endl;
		// process input
		this->process();
		this->render();
	}
}

void			Engine::spawn(void)
{
	Enemy		e;

	//               0 est a gauche pour w      et 0 est top  pour h
	e._pos = Vect2(this->_win_w, rand() % this->_win_h - 1);
	e._dir = Vect2(-1, 0);
	e._level = rand() % this->_level + 1;
}

void			Engine::processProjectile(Projectile *p)
{
	Elem		*i;
	Elem		*j;
	Enemy		*e;

	i = Enemy::lst._first;
	while (i)
	{
		e = reinterpret_cast<Enemy*>(i->_data);
		if (p->_source != e && p->collide(e))
		{
			if (p->_source == &this->_player)
				this->_player.score(10);
			e->takeDamage(p->_damage);
			j = i;
			i = i->_next;
			Projectile::lst.pop(j);
			return ;
		}
		i = i->_next;
	}
	if (p->_pos._x > this->_win_w || p->_pos._x < 0 || \
	p->_pos._y > this->_win_h || p->_pos._y < 0)
		Projectile::lst.pop(p);
}

void			Engine::processProjectiles(void)
{
	Elem		*i;
	Elem		*j;
	Projectile	*p;

	i = Projectile::lst._first;
	while (i)
	{
		i->_data->process(0.1);
		p = reinterpret_cast<Projectile*>(i->_data);
		if (p->_source != &this->_player && \
		this->_player.collide(&this->_player))
		{
			this->_player.takeDamage(p->_damage);
			j = i;
			i = i->_next;
			Projectile::lst.pop(j);
			continue ;
		}
		processProjectile(p);
		i = i->_next;
	}
}

void			Engine::processEnemies(void)
{
	Elem		*i;
	Elem		*j;
	Enemy		*e;

	i = Enemy::lst._first;
	while (i)
	{
		i->_data->process(0.1);
		e = reinterpret_cast<Enemy*>(i->_data);
		if (i->_data->collide(&this->_player))
		{
			this->_player.takeDamage(20);
			e->takeDamage(20);
		}
		if (e->_pos._x < 0)
		{
			j = i;
			i = i->_next;
			Enemy::lst.pop(j);
			continue ;
		}
		i = i->_next;
	}
}

void			Engine::process(void)
{
	if (this->_count % (((rand() % 200) + 200) / this->_level) == 0)
		spawn();
	if (this->_count % (10000 * this->_level) == 0)
	{
		this->_count = 0;
		this->_level++;
	}
	if (this->_player.getScore() % (10000 * this->_player.getLevel()))
		this->_player.levelUp();
	this->_player.process(0.2);
	this->processEnemies();
	this->processProjectiles();
}

void			Engine::render(void) const {
	clear();


	displayHud();
	
	attron(A_BOLD); // display player and enemies in BOLD

	displayObject(&_player);
	
	for (Elem* i = Enemy::lst._first; i != 0; i = i->_next)
		displayObject(i->_data);

	attroff(A_BOLD);
	for (Elem* i = Projectile::lst._first; i != 0; i = i->_next)
		displayObject(i->_data);
	
	refresh();	
}

void			Engine::displayMenu(void) const {
	clear();
	mvprintw(this->_win_h * 0.3, this->_win_w / 2 - 4, "FT_RETRO");
	mvprintw(this->_win_h * 0.7, this->_win_w / 2 - 2 , "[ _ ]");
	mvprintw(this->_win_h * 0.7 + 3, this->_win_w / 2 - 5, "press space");
	refresh();
	int c;
	for (;;)
		if ((c = getch()) == KEY_SPACE)
			break;
}

void			Engine::displayObject(GameObject *obj) const {
	// x - half of string size ?
	// is actual pos on the left of the sprite or middle when using multiple chars?
	if (obj->_state != STATE_DEAD)
		mvprintw(obj->_pos._y, obj->_pos._x, obj->_sprite.c_str());
	return;
}

void			Engine::displayHud(void) const {
	//display score
	mvprintw(this->_win_h - 1 , 0, "score: %d",  this->_score);
	mvprintw(this->_win_h - 1 , this->_win_w - 12, "esc to quit");
	return;
}


void			Engine::error(std::string const & msg) {
	std::cout << msg << std::endl;
	//EXIT
	return;
}

void			Engine::gameOver(void) {

}
