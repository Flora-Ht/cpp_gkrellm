//
// Terminal.cpp for  in /home/guitta_l/worktree/Training/ncurses/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sat Jan 21 14:22:56 2017 Louis Guittard
// Last update Sun Jan 22 05:18:49 2017 Louis Guittard
//

#include "Terminal.hpp"

Terminal::Terminal()
: _sort(false), _selected(0)
{
    initscr();
    this->_cols = COLS;
    this->_lines = LINES;
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    timeout(200);
    this->_modules.push_back(new TModuleHostUser());
    this->_modules.push_back(new TModuleDate(0, 17));
    this->_modules.push_back(new TModuleOS(0, 34));
    this->_modules.push_back(new TModuleCPU(41, 0));
}

Terminal::~Terminal()
{
    for (std::vector<Window *>::iterator it = this->_modules.begin();
    	 it != this->_modules.end();
         ++it)
         {
             delete *it;
         }
    endwin();
}

int			Terminal::getCols() const
{
    return (this->_cols);
}

int			Terminal::getLines() const
{
    return (this->_lines);
}

std::vector<Window *>	Terminal::getModules() const
{
    return (this->_modules);
}

bool		Terminal::getSort() const
{
    return (this->_sort);
}

void		Terminal::setTimeout(int value)
{
    timeout(value);
}

void		Terminal::pushModule(Window &mod)
{
    for (std::vector<Window *>::iterator it = this->_modules.begin();
		 it != this->_modules.end();
    	 ++it)
         {
             if (*it == &mod)
	             return;
         }
    this->_modules.push_back(&mod);
}

void		Terminal::addModule(char mod)
{
    switch (mod) {
        case 0:
        	this->_modules.push_back(new TModuleHostUser(this->_cols / 10, this->_lines / 10));
        	break;
        case 1:
	        this->_modules.push_back(new TModuleDate(this->_cols / 10, this->_lines / 10));
        	break;
        case 2:
	        this->_modules.push_back(new TModuleOS(this->_cols / 10, this->_lines / 10));
        	break;
        case 3:
	        this->_modules.push_back(new TModuleCPU(this->_cols / 10, this->_lines / 10));
        	break;
    }
}

void		Terminal::removeModule()
{
    std::vector<Window *>::iterator	it;

    if (!this->_modules.size() || !this->_sort)
	    return;
    it = this->_modules.begin();
    this->_modules.erase(it + this->_selected);
    if (this->_selected)
    	this->_selected -= 1;
    if (!this->_modules.size())
    	this->_sort = false;
}

void		Terminal::moveModule(int x, int y)
{
    std::vector<Window *>::iterator	it;

    if (!this->_modules.size() || !this->_sort)
	    return;
    it = this->_modules.begin() + this->_selected;
    x = (*it)->getX() + x > this->_cols - (*it)->getWidth() - 1 ?
    	this->_cols - (*it)->getWidth() - 1 : (*it)->getX() + x;
    x = x < 0 ? 0 : x;
    y = (*it)->getY() + y > this->_lines - (*it)->getHeight() - 5 ?
    	this->_lines - (*it)->getHeight() - 5 : (*it)->getY() + y;
    y = y < 0 ? 0 : y;
    (*it)->setX(x);
    (*it)->setY(y);
}

Terminal	&Terminal::operator++()
{
    this->_selected = (this->_selected + 1) % this->_modules.size();
    return (*this);
}

void		Terminal::update() const
{
    erase();
    this->drawModules();
    refresh();
}

void		Terminal::drawModules() const
{
    int		i;

    i = 0;
    for (std::vector<Window *>::const_iterator it = this->_modules.begin();
         it != this->_modules.end();
         ++it)
         {
             (*it)->update();
             if (i == this->_selected && this->_sort)
	             attron(COLOR_PAIR(1));
             (*it)->drawBorder();
             attroff(COLOR_PAIR(1));
             (*it)->drawContent();
             i += 1;
         }
}

void		Terminal::sort()
{
    if (!this->_modules.size())
	    return;
    this->_selected = 0;
    this->_sort = !this->_sort;
}

std::ostream	&operator<<(std::ostream &os, Terminal const &ref)
{
    std::vector<Window *>	mods;

    mods = ref.getModules();
    os << std::endl << "-- TERMINAL --" << std::endl;
    for (std::vector<Window *>::const_iterator it = mods.begin();
         it != mods.end();
         ++it)
         {
             std::cout << **it;
         }
    return (os);
}
