// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ncurses.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 15:29:27 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/14 15:29:28 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ncurses.hpp"

Ncurses::Ncurses() {


	initscr();
	getmaxyx(stdscr, _maxheight, _maxwidth);
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(0);
	start_color();
	noecho();

	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
  	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
  	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);

  	_data = new DateTime();

	refresh();
}

void	Ncurses::box() {

	oldalchar = (char)42;
	attron(COLOR_PAIR(3));
	for (int i = 0; i < _maxwidth - 1; i++) {

		move(0, i);
		addch(oldalchar);
	}
	for (int i = 0; i < _maxwidth - 1; i++) {

		move(_maxheight - 2, i);
		addch(oldalchar);
	}
	for (int i = 0; i < _maxheight - 2; i++) {

		move(i, 0);
		addch(oldalchar);
	}
	for (int i = 0; i < _maxheight - 2; i++) {

		move(i, _maxwidth - 2);
		addch(oldalchar);
	}
	attroff(COLOR_PAIR(3));
}

void	Ncurses::printmodule() {


	attron(COLOR_PAIR(4));


	const char *sys = "             \n"
"     _                                    _         __  \n"   
"    | |              _                   (_)      / __)            \n" 
"     \\ \\  _   _  ___| |_  ____ ____       _ ____ | |__ ___       \n"
"      \\ \\| | | |/___)  _)/ _  )    \\     | |  _ \\|  __) _ \\   \n "
"  _____) ) |_| |___ | |_( (/ /|| | |   | | | | | | | |_| |       \n"
" (______/ \\__  (___/ \\___)____)_|_|_|    |_|_| |_|_|  \\___/     \n"
"         (____/\n                                             ";

	mvprintw(0, 1, sys);

	mvprintw(9, 16, _data->getHour());


	// const char *cpu = "\n";
	// const char *ram = "\n";
	// const char *disk = "\n";
	// const char *network = "\n";

	attroff(COLOR_PAIR(4));
	box();

	refresh();

}





Ncurses::Ncurses(Ncurses const & src) {

    *this = src;
}


Ncurses::~Ncurses() {

	nodelay(stdscr, false);
	getch();
	endwin();
}

void Ncurses::start() {

	while(1) {	
		printmodule();
		if (getch() == 27)
			break ;
		}
		usleep(CYCLEDELAY);
}
    
     
   




