//
// TModuleDate.cpp for  in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/source/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sat Jan 21 22:50:39 2017 Louis Guittard
// Last update Sat Jan 21 23:38:11 2017 Louis Guittard
//

#include "TModuleDate.hpp"

TModuleDate::TModuleDate(int x, int y, int height, int width)
: Window(x, y, height, width), ModuleDate()
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

TModuleDate::~TModuleDate()
{
}

void			TModuleDate::update()
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

void			TModuleDate::drawContent() const
{
    if (this->_error != "")
    {
        mvprintw(_y + 1, _x + 1, "%s", this->_error.c_str());
        return;
    }
    mvprintw(_y + 1, _x + 1, "DATE:");
    mvprintw(_y + (_height / 3), _x + (_width - 13) / 2, "%d / %d / %d",
    this->getDay(), this->getMonth(), this->getYear());
    mvprintw(_y + (_height * 2) / 3, _x + (_width - 12) / 2, "%d : %d : %d",
    this->getHour(), this->getMinute(), this->getSecond());
    wrefresh(this->_window);
}
