//
// TModuleNetwork.cpp for  in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/source/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sun Jan 22 06:53:09 2017 Louis Guittard
// Last update Sun Jan 22 07:13:28 2017 Louis Guittard
//

#include "TModuleNetwork.hpp"

TModuleNetwork::TModuleNetwork(int x, int y, int height, int width)
: Window(x, y, height, width), ModuleNetwork()
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

TModuleNetwork::~TModuleNetwork()
{
}

void					TModuleNetwork::update()
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

void					TModuleNetwork::drawContent() const
{
    unsigned int		i;
    unsigned int		size;

    if (this->_error != "")
    {
        mvprintw(_y + 1, _x + 1, "%s", this->_error.c_str());
        return;
    }
    size = this->getNetworkInterfaces().size();
    i = 0;
    mvprintw(_y + (_height * i) / 4 + 1, _x + 1, "NETWORK:");
    for (std::vector<NetworkInterface>::const_iterator it = this->getNetworkInterfaces().begin();
		 it < this->getNetworkInterfaces().end();
     	 ++it)
         {
             mvprintw(_y + (_height / 2) - 1, _x + 5 + (_width * i) / size, it->_name.c_str());
             mvprintw(_y + (_height / 2), _x + 5 + (_width * i) / size, getDownloadSpeed(*it).c_str());
             mvprintw(_y + (_height / 2) + 1, _x + 5 + (_width * i) / size, getUploadSpeed(*it).c_str());
             i += 1;
         }
    wrefresh(this->_window);
}
