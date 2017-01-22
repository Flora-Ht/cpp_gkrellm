//
// TModuleOS.cpp for  in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/source/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sun Jan 22 00:21:35 2017 Louis Guittard
// Last update Sun Jan 22 00:27:19 2017 Louis Guittard
//

#include "TModuleOS.hpp"

TModuleOS::TModuleOS(int x, int y, int height, int width)
: Window(x, y, height, width), ModuleOS()
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

TModuleOS::~TModuleOS()
{
}

void			TModuleOS::drawContent() const
{
    if (this->_error != "")
    {
        mvprintw(_y + 1, _x + 1, "%s", this->_error.c_str());
        return;
    }
    mvprintw(_y + 1, _x + 1, "OS:");
    mvprintw(_y + (_height * 1) / 3, _x + _width / 3, this->getOS().c_str());
    mvprintw(_y + (_height * 2) / 3, _x + _width / 3 , this->getVersion().c_str());
    wrefresh(this->_window);
}
