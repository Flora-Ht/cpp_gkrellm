//
// ModuleHostUser.cpp for  in /home/guitta_l/worktree/Training/ncurses/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sat Jan 21 15:16:40 2017 Louis Guittard
// Last update Sat Jan 21 22:35:14 2017 Louis Guittard
//

#include "ModuleHostUser.hpp"

ModuleHostUser::ModuleHostUser(int x, int y, int height, int width)
: Window(x, y, height, width), ModuleHostname()
{
    try
    {
        //throw ModuleException("Can't find a username matching user id in /etc/passwd");
        this->retrieveInformations();
    }
    catch (ModuleException &e)
    {
        this->_error = e.what();
    }
}

ModuleHostUser::~ModuleHostUser()
{
}

void			ModuleHostUser::drawContent() const
{
    if (this->_error != "")
    {
        mvprintw(_y + 1, _x + 1, "%s", this->_error.c_str());
        return;
    }
    mvprintw(_y + 1, _x + 1, "HOSTNAME:");
    mvprintw(_y + 6, _x + 8, "HOST:");
    mvprintw(_y + 6, _x + 20, this->getHost().c_str());
    mvprintw(_y + 11, _x + 8, "USER:");
    mvprintw(_y + 11, _x + 20, this->getUser().c_str());
    wrefresh(this->_window);
}
