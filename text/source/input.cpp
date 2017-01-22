//
// input.cpp for Rush in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/source/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sat Jan 21 21:56:30 2017 Louis Guittard
// Last update Sun Jan 22 07:17:36 2017 Louis Guittard
//

#include <ncurses.h>
#include "input.hpp"

void		menuInput(Terminal &term)
{
    int		c;

    clear();
    mvprintw((term.getLines() / 2) - 4, (term.getCols() - 12) / 2, "0 - Hostname");
    mvprintw((term.getLines() / 2) - 2, (term.getCols() - 8) / 2, "1 - Date");
    mvprintw((term.getLines() / 2), (term.getCols() - 6) / 2, "2 - OS");
    mvprintw((term.getLines() / 2) + 2, (term.getCols() - 7) / 2, "3 - CPU");
    mvprintw((term.getLines() / 2) + 4, (term.getCols() - 7) / 2, "4 - RAM");
    mvprintw((term.getLines() / 2) + 6, (term.getCols() - 11) / 2, "5 - Network");
    refresh();
    term.setTimeout(15000);
    c = getch();
    if (c >= '0' && c <= '9')
	    term.addModule(c - 48);
    term.setTimeout(1000);
}

void		actionInput(Terminal &term, int c)
{
    switch(c)
    {
	    case 'r':
    	case 'R':
        	term.sort();
        	break;
        case 'n':
        case 'N':
        	menuInput(term);
            break;
        term.update();
    }
}

void		sortInput(Terminal &term, int c)
{
    switch (c)
    {
        case 9:
            ++term;
            break;
        case 263:
            term.removeModule();
            break;
        case KEY_LEFT:
            term.moveModule(-1, 0);
            break;
        case KEY_RIGHT:
            term.moveModule(1, 0);
            break;
        case KEY_UP:
            term.moveModule(0, -1);
            break;
        case KEY_DOWN:
            term.moveModule(0, 1);
            break;
        term.update();
    }
}
