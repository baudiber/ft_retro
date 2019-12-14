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

void Engine::end() {
    clear();
    refresh();
    endwin();
}