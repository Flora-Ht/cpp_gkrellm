//
// main.cpp for Rush in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/source/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sat Jan 21 21:58:14 2017 Louis Guittard
// Last update Sun Jan 22 01:22:14 2017 Louis Guittard
//

#include "Window.hpp"
#include "Terminal.hpp"
#include "input.hpp"

int 			main()
{
	Terminal	term;
	int			c;

	c = -1;
	term.update();
	while((c = getch()) != 27)
	{
		term.update();
		refresh();
		actionInput(term, c);
		if (term.getSort())
			sortInput(term, c);
	}
	endwin();
	c = getch();
	std::cout << c << term << std::endl;
	return 0;
}
