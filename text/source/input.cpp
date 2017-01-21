//
// input.cpp for Rush in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/source/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sat Jan 21 21:56:30 2017 Louis Guittard
// Last update Sat Jan 21 22:03:57 2017 Louis Guittard
//

#include "input.hpp"

void		toggleSort(Terminal &term, int c)
{
    switch(c)
    {
	    case 'r':
    	case 'R':
        	term.sort();
        	term.update();
        	break;
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
