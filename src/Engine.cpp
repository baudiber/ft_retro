/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:19:16 by baudiber          #+#    #+#             */
/*   Updated: 2019/12/15 18:35:19 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Engine.hpp"

Engine::Engine(void) {
	std::cout << "Engine Default constructor called" << std::endl;
	this->_win = initscr();
	this->_level = 1;
	this->_count = 0;
	keypad(this->_win, true);
	noecho();
	cbreak();
	curs_set(0);
	getmaxyx(this->_win, this->_win_h, this->_win_w);
    if (this->_win_h <= 20 || this->_win_w <= 100) 
		this->error("Please enlarge your window");
	this->_player._pos = Vect2(5.0f, this->_win_h / 2.0);
	this->_player._sprite = "[";
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
	//std::cout << "Engine Destructor called" << std::endl;
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

void			Engine::run(void) {
	int k = 0;

	for (;;)
	{
		if ((k = getch()) == KEY_ESC)
			break;
		if (_player._state == STATE_DEAD)
			break;
		_player.input(k);
		_player.process(0.1);
		usleep(SLEEP);
		this->process();
		this->render();
	}
	this->gameOver();
}

void			Engine::spawn(void)
{
	Enemy		*e = new Enemy();

	e->_pos = Vect2(this->_win_w - 1, rand() % (this->_win_h));
	e->_dir = Vect2(-1, 0);
	e->_level = rand() % this->_level + 1;
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
		i->_data->process(0.001);
		e = reinterpret_cast<Enemy*>(i->_data);
		if (i->_data->collide(&this->_player))
		{
			this->_player.takeDamage(20);
			e->takeDamage(20);
		}
		if (e->getHp() <= 0)
		{
			this->_player.score(e->_level * 100);
			j = i;
			i = i->_next;
			std::cout<< "Deleting enemy" << std::endl;
			Enemy::lst.pop(j);
			continue ;
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
	_count++;
	if ((this->_count % 1000) == 0)
		spawn();
	if (this->_count % (50000 * this->_level) == 0)
	{
		this->_count = 0;
		this->_level++;
	}
	this->_player.process(0.002);
	_player._pos._x = (_player._pos._x < 0 ? 0 : _player._pos._x);
	_player._pos._y = (_player._pos._y < 0 ? 0 : _player._pos._y);
	_player._pos._x = (_player._pos._x >= _win_w ? _win_w : _player._pos._x);
	_player._pos._y = (_player._pos._y >= _win_h - 2 ? _win_h - 2: _player._pos._y);

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
	{
		mvprintw(obj->_pos._y, obj->_pos._x, obj->_sprite.c_str());
	}
	return;
}

void			Engine::displayHud(void) const {
	//display score
	mvprintw(this->_win_h - 1 , 0, "score: %d", this->_player.getScore());
	mvprintw(this->_win_h - 1 , 40, "enemies: %d", Enemy::lst._size);
	mvprintw(this->_win_h - 1 , 70, "count: %d", _count);
	mvprintw(this->_win_h - 1 , 100, "level: %d", _level);
	mvprintw(this->_win_h - 1 , this->_win_w - 12, "esc to quit");
	return;
}


void			Engine::error(std::string const & msg) {
	std::cout << msg << std::endl;
	exit(0);
	return;
}

void			Engine::gameOver(void) {
	clear();
	mvprintw(this->_win_h * 0.5, this->_win_w * 0.5 - 4, "Game Over");
	mvprintw(this->_win_h * 0.5 + 1, this->_win_w * 0.5 - 4, "Score: %d", this->_player.getScore());
	mvprintw(this->_win_h * 0.6 + 1, this->_win_w * 0.5 - 5, "press   esc");
	refresh();
	int c;
	for (;;)
		if ((c = getch()) == KEY_ESC)
			break;
}

int					Engine::_level = 1;
Player				Engine::_player = Player();
