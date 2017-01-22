//
// TModuleCPU.cpp for Rush in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/source/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sun Jan 22 01:06:24 2017 Louis Guittard
// Last update Sun Jan 22 05:35:00 2017 Louis Guittard
//

#include "TModuleCPU.hpp"

TModuleCPU::TModuleCPU(int x, int y, int height, int width)
: Window(x, y, height, width), ModuleCPU()
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

TModuleCPU::~TModuleCPU()
{
}

void					TModuleCPU::update()
{
    this->_error = "";
    try
    {
        this->retrieveInformations();
    }
    catch (ModuleException &e)
    {
        this->_error = e.what();
    }
}

void					TModuleCPU::drawContent() const
{
    unsigned int		i;
    unsigned int		j;
    int					length;

    if (this->_error != "")
    {
        mvprintw(_y + 1, _x + 1, "%s", this->_error.c_str());
        return;
    }
    i = 0;
   for (std::vector<CPU>::const_iterator it = this->getCPUs().begin();
    	 it < this->getCPUs().end();
     	 ++it)
         {
             mvprintw(_y + (_height * i) / 4 + 1, _x + 1, it->_name.c_str());
             mvprintw(_y + (_height * i) / 4 + 1, _x + 15 + it->_name.size(), "%f mhz", it->_mhz);
             mvprintw(_y + (_height * i) / 4 + 2, _x + 1, it->_vendor.c_str());
             j = 0;
             attron(COLOR_PAIR(2));
             length = this->_width - it->_vendor.size() - 6;
             while (length > 0 &&
             		j < (unsigned int)length &&
                    (j / (double)length) * 100 < it->_percent)
             {
                 mvprintw(_y + (_height * i) / 4 + 2, _x + 5 + it->_vendor.size()+ j, "|");
                 j += 1;
             }
             attroff(COLOR_PAIR(2));
             i += 1;
         }
    wrefresh(this->_window);
}
