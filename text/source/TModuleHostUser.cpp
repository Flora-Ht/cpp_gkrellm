//
// TModuleHostUser.cpp for  in /home/guitta_l/worktree/Training/ncurses/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sat Jan 21 15:16:40 2017 Louis Guittard
// Last update Sun Jan 22 00:08:49 2017 Louis Guittard
//

#include "TModuleHostUser.hpp"

TModuleHostUser::TModuleHostUser(int x, int y, int height, int width)
: Window(x, y, height, width), ModuleHostname()
{
    try
    {
        this->retrieveInformations();
    }
    catch (ModuleException &e)
    {
        this->_error = e.what();
    }
}

TModuleHostUser::~TModuleHostUser()
{
}

void			TModuleHostUser::drawContent() const
{
    if (this->_error != "")
    {
        mvprintw(_y + 1, _x + 1, "%s", this->_error.c_str());
        return;
    }
    mvprintw(_y + 1, _x + 1, "HOSTNAME:");
    mvprintw(_y + (_height * 1) / 3, _x + (_width - 5) / 5, "HOST:");
    mvprintw(_y + (_height * 1) / 3, _x + (_width - 5) * 3 / 5, this->getHost().c_str());
    mvprintw(_y + (_height * 2) / 3, _x + (_width - 5) / 5, "USER:");
    mvprintw(_y + (_height * 2) / 3, _x + (_width - 5) * 3 / 5, this->getUser().c_str());
    wrefresh(this->_window);
}
