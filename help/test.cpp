//#include "Retro.hpp"
#include "ncurses.h"

#include "bindings.hpp"

int main(void) {
	WINDOW* win = initscr(); 
	keypad(win,true);
	noecho();
	curs_set(0);
	int x,y;
	getmaxyx(win, y, x);
	mvprintw(y * 0.3, x / 2 - 4, "FT_RETRO");
	mvprintw(y * 0.7, x / 2 - 2 , "[ _ ]");
	mvprintw(y * 0.7 + 3, x / 2 - 5, "press space");

	refresh();
	//int	word_w = this->_win_w / 8 - 4;
	//int	word_h = this->_win_h / 3 - 4;
	//int	word_y_start = this->_win_h / 3;
	//for (int x = 0; x < word_w; x++)
	//{
	//	move(word_y_start,x);
	//	addch('#');
	//}


	int c = 0;
	for (;;)
		if ((c = getch()) == KEY_SPACE)
			break;



	nodelay(stdscr, true);

	for (;;)
	{
		clear();
		int c;
		int	nb = 10;

		if ((c = getch()) == KEY_ECHAP)
			break;

		mvprintw(y - 2 , 0, "score: %d", nb );
		mvprintw(y - 1 , x - 12, "esc to quit");


		
		
		refresh();
	}








	endwin();

	return 0;
}
