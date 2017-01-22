//
// TModuleRAM.cpp for  in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/source/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sun Jan 22 05:40:56 2017 Louis Guittard
// Last update Sun Jan 22 07:30:49 2017 Louis Guittard
//

#include "TModuleRAM.hpp"

TModuleRAM::TModuleRAM(int x, int y, int height, int width)
: Window(x, y, height, width), ModuleRAM()
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

TModuleRAM::~TModuleRAM()
{
}

void			TModuleRAM::update()
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

void			TModuleRAM::drawContent() const
{
    unsigned int	i;
    double			used_perc;

    if (this->_error != "")
    {
        mvprintw(_y + 1, _x + 1, "%s", this->_error.c_str());
        return;
    }
    mvprintw(_y + 1, _x + 1, "RAM:");
    if (this->toGigabyte(this->getTotalRam()) == 0)
    {
        mvprintw(_y + (_height) / 5 + 1, _x + 1, " %.2f/%.2f",
        this->toGigabyte(this->getTotalRam()) - this->toGigabyte(this->getFreeRam()),
        this->toGigabyte(this->getTotalRam()));
        wrefresh(this->_window);
        return;
    }
    used_perc = (1 - this->toGigabyte(this->getFreeRam()) / this->toGigabyte(this->getTotalRam())) * 100;
    mvprintw(_y + (_height) / 5, _x + 1, " %.2f/%.2f      %.2f%%",
    	this->toGigabyte(this->getTotalRam()) - this->toGigabyte(this->getFreeRam()),
        this->toGigabyte(this->getTotalRam()), used_perc);
    i = 0;
    attron(COLOR_PAIR(3));
    while (this->_width - 4 > 0 &&
           i < (unsigned int)(this->_width - 3))
       {
           if ((i / (double)(this->_width - 4)) * 100 >= used_perc)
           {
               attroff(COLOR_PAIR(3));
               attron(COLOR_PAIR(1));
           }
           mvprintw(_y + (_height) / 5 + 2, _x + 2 + i, "|");
           i += 1;
       }
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(3));
    mvprintw(_y + 1 + _height / 2, _x + 1, "SWAP:");
    if (this->toGigabyte(this->getTotalSwap()) == 0)
    {
        mvprintw(_y + (_height * 4) / 5 - 1, _x + 1, " %.2f/%.2f",
        this->toGigabyte(this->getTotalSwap()) - this->toGigabyte(this->getFreeSwap()),
        this->toGigabyte(this->getTotalSwap()));
        wrefresh(this->_window);
        return;
    }
    used_perc = (1 - this->toGigabyte(this->getFreeSwap()) / this->toGigabyte(this->getTotalSwap())) * 100;
    mvprintw(_y + (_height * 4) / 5 - 1, _x + 1, " %.2f/%.2f      %.2f%%",
    this->toGigabyte(this->getTotalSwap()) - this->toGigabyte(this->getFreeSwap()),
    this->toGigabyte(this->getTotalSwap()), used_perc);
    i = 0;
    attron(COLOR_PAIR(3));
    while (this->_width - 4 > 0 &&
           i < (unsigned int)(this->_width - 3))
       {
           if ((i / (double)(this->_width - 4)) * 100 >= used_perc)
           {
               attroff(COLOR_PAIR(3));
               attron(COLOR_PAIR(1));
           }
           mvprintw(_y + (_height * 4) / 5 + 1, _x + 2 + i, "|");
           i += 1;
       }
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(3));
    wrefresh(this->_window);
}
