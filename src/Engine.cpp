/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:19:16 by baudiber          #+#    #+#             */
/*   Updated: 2019/12/15 22:39:38 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Engine.hpp"

Engine::Engine(void) {
	//std::cout << "Engine Default constructor called" << std::endl;
	this->_win = initscr();
	this->_level = 1;
	this->_count = 0;
	keypad(this->_win, true);
	noecho();
	cbreak();
	curs_set(0);
	getmaxyx(this->_win, this->_win_h, this->_win_w);
	this->_player.setSpawn(Vect2(5.0f, this->_win_h / 2.0));
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
	endwin();
    if (this->_win_h <= 20 || this->_win_w <= 150) 
		std::cout << "Please enlarge your window" << std::endl;
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
    if (this->_win_h <= 20 || this->_win_w <= 150) 
		return;

	for (;;)
	{
		if ((k = getch()) == KEY_ESC)
			break;
		if (_player._state == STATE_DEAD)
			break;
		_player.input(k);
		_player.process(1);
		usleep(SLEEP);
		this->process();
		this->render();
	}
	this->gameOver();
}

void			Engine::spawn(void)
{
	Enemy		*e = new Enemy();

	e->_pos = Vect2(this->_win_w - 1, rand() % (this->_win_h - 2));
	e->_dir = Vect2(-1, 0);
	e->_level = rand() % this->_level + 1;
}

void			Engine::spawnStars(void)
{
	Star		*s = new Star();

	s->_pos = Vect2(this->_win_w - 1, rand() % (this->_win_h - 2));
	s->_dir = Vect2(-1, 0);
	s->_mov = Vect2(2, 0);
}

void			Engine::processProjectile(Projectile *p)
{
	Elem		*i;
	Enemy		*e;

	i = Enemy::lst._first;
	while (i && p->_state != STATE_DEAD)
	{
		e = reinterpret_cast<Enemy*>(i->_data);
		if (p->collide(e))
		{
			if (p->_source == &this->_player)
				this->_player.score(10);
			e->takeDamage(p->_damage);
			p->_state = STATE_DEAD;
		}
		i = i->_next;
	}
	if (p->_pos._x > this->_win_w - 1 || p->_pos._x < 0 || \
	p->_pos._y > this->_win_h - 1 || p->_pos._y < 0)
		Projectile::lst.pop(p);
}

void			Engine::processProjectiles(void)
{
	Elem		*i;
	Projectile	*p;

	i = Projectile::lst._first;
	while (i)
	{
		i->_data->process(0.1);
		p = reinterpret_cast<Projectile*>(i->_data);
		if (p->collide(&this->_player))
		{
			if (p->_source != &this->_player)
			{
				this->_player.takeDamage(p->_damage);
				p->_state = STATE_DEAD;
			}
		}
		processProjectile(p);
		i = i->_next;
	}
}

void			Engine::processStars(void)
{
	Elem		*i;
	Elem		*j;
	Star		*e;

	i = Star::lst._first;
	while (i)
	{
		i->_data->process(0.1);
		e = reinterpret_cast<Star*>(i->_data);
		if (e->_pos._x < 0)
		{
			j = i;
			i = i->_next;
			Star::lst.pop(j);
			continue ;
		}
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
		int	nb = rand() % 5000;
		i->_data->process(0.001);
		e = reinterpret_cast<Enemy*>(i->_data);
		if (nb == 4)
			e->attack();
		if (e->_level == 1)
			e->_sprite = "O";
		if (e->_level == 2)
			e->_sprite = "oO";
		if (e->_level == 3)
			e->_sprite = "oOo";
		if (e->_level == 4)
			e->_sprite = "oOoO";
		if (e->_level == 5)
			e->_sprite = "oOoOo";
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
	if ((this->_count % 100) == 0)
		this->spawnStars();
	if ((this->_count % 1000) == 0)
		this->spawn();
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
	this->processStars();
}

void			Engine::render(void) const {
	clear();


	displayHud();
	
	attron(A_BOLD); // display player and enemies in BOLD

	displayObject(&_player);
	
	for (Elem* i = Enemy::lst._first; i != 0; i = i->_next)
		displayObject(i->_data);

	attroff(A_BOLD); //but projectiles in normal font
	for (Elem* i = Projectile::lst._first; i != 0; i = i->_next)
		displayObject(i->_data);

	for (Elem* i = Star::lst._first; i != 0; i = i->_next)
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
	if (obj->_state != STATE_DEAD)
		mvprintw(obj->_pos._y, obj->_pos._x, obj->_sprite.c_str());
	return;
}

void			Engine::displayHud(void) const {
	//display score
	mvprintw(this->_win_h - 1 , 0, "score: %d", this->_player.getScore());
	mvprintw(this->_win_h - 1 , 30, "enemies: %d", Enemy::lst._size);
	mvprintw(this->_win_h - 1 , 60, "frames: %d", this->_count);
	mvprintw(this->_win_h - 1 , 90, "level: %d", this->_level);
	mvprintw(this->_win_h - 1 , 120, "lives: %d", this->_player.getLives());
	mvprintw(this->_win_h - 1 , this->_win_w - 12, "esc to quit");
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
