//
// Window.cpp for Rush in /home/guitta_l/worktree/Training/ncurses/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sat Jan 21 10:46:39 2017 Louis Guittard
// Last update Sat Jan 21 23:17:30 2017 Louis Guittard
//

#include "Window.hpp"

Window::Window(int x, int y, int height, int width)
: _height(height), _width(width), _x(x), _y(y), _error("")
{
    WINDOW *local_win;

    local_win = newwin(_height, _width, _y, _x);
    box(local_win, 0 , 0);
    wrefresh(local_win);
    this->_window = local_win;
}

Window::~Window()
{
    wborder(this->_window, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(this->_window);
	delwin(this->_window);
}

WINDOW			*Window::getWin() const
{
    return (this->_window);
}

int				Window::getHeight() const
{
    return (this->_height);
}

int				Window::getWidth() const
{
    return (this->_width);
}

int				Window::getX() const
{
    return (this->_x);
}

int				Window::getY() const
{
    return (this->_y);
}

void			Window::setWin(WINDOW *win)
{
    this->_window = win;
}

void			Window::setHeight(int height)
{
    this->_height = height;
}

void			Window::setWidth(int width)
{
    this->_width = width;
}

void			Window::setX(int x)
{
    this->_x = x;
}

void			Window::setY(int y)
{
    this->_y = y;
}

void			Window::drawBorder(char lb, char rb, char ub, char db, char corner) const
{
    for (int i = 0; i < this->_height + 1; ++i)
	    mvhline(this->_y + i, this->_x, ' ', this->_width);
    mvaddch(this->_y, this->_x, corner);
    mvaddch(this->_y, this->_x + this->_width, corner);
    mvaddch(this->_y + this->_height, this->_x, corner);
    mvaddch(this->_y + this->_height, this->_x + this->_width, corner);
    mvhline(this->_y, this->_x + 1, db, this->_width - 1);
    mvhline(this->_y + this->_height, this->_x + 1, ub, this->_width - 1);
    mvvline(this->_y + 1, this->_x, lb, this->_height - 1);
    mvvline(this->_y + 1, this->_x + this->_width, rb, this->_height - 1);
}

void			Window::update()
{
}

std::ostream	&operator<<(std::ostream &os, Window const &ref)
{
    os << std::endl << "-- Window --"
    << std::endl << "format: "
    << ref.getWidth() << "x" << ref.getHeight()
    << std::endl << "position: ("
    << ref.getX() << "," << ref.getY() << ")" << std::endl;
    return (os);
}
