#include "Retro.hpp"
#include "bindings.hpp"

int Retro::max_height = 1;
int Retro::max_width = 1;

void Retro::run() {
    while (vrai) {
        if (this->game_over) {
            this->print_game_over();
            refresh();
            usleep(1000000);
            return;
        }

        clear();                                    // efface tout l'ecran
        // fait bouger les etoiles (.) en background
        // fait bouger les ennemis
		// random pour si un ennemi tir
		// fait bouger les asteroides
		// fait bouger les missiles des ennemis
        // detruit les ennemis touchés
        // fait bouger les missiles du pilote
        // fait bouger le pilote
        // detruit les ennemis touchés

        // met le jeu dans le buffer ncurses
        refresh();                                  //  rafraichit la fenetre du terminal

        // detecte les touches
    }
}

void Retro::ini() {
    this->frame = initscr();    // renvoie l'addresse de la fenetre creee
    if (!has_colors()) {
        this->crash("Please enable colors");
        return ;
    } else {
        start_color();              // rend l'utilisation des couleurs possible
    }
	noecho();                       // desactive l'affichage de caractere quand on appuie sur les touches
	curs_set(0);                    // cache le curseur du terminal
    keypad(this->frame, TRUE);       // rend possible la detection de pression sur les touches fleches
    nodelay(this->frame, TRUE);      // rend l'input (avec getch) non bloquant (asynchrome en quelque sorte)

    // recupere les dimensions de la fenetre (getmaxyx est une macro qui set les deux derniers parametres)
    getmaxyx(this->frame, Retro::max_height, Retro::max_width);
    if (Retro::max_height <= 20 || Retro::max_width <= 100) {
        this->crash("Please enlarge window");
    }

    // donner des bordures au spawner d etoiles en background
    init_color(COLOR_RED, 250, 250, 250);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
}

void Retro::end() {
    clear();
    refresh();
    endwin();
}

Retro::~Retro() {
}

Retro::Retro(const Retro & src) {
    *this = src;
    this->init();
}

Retro::Retro(void) {
    this->game_over = false;
    this->score = 0;
    this->init();
}
