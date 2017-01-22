//
// ModuleNetwork.cpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/source/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sun Jan 22 05:03:20 2017 Benjamin Grange
// Last update Sun Jan 22 05:30:13 2017 Benjamin Grange
//

#include <fstream>
#include <algorithm>
#include "ModuleNetwork.hpp"

ModuleNetwork::ModuleNetwork()
{}

ModuleNetwork::~ModuleNetwork() {}

ModuleNetwork::ModuleNetwork(ModuleNetwork const &)
{}

ModuleNetwork &ModuleNetwork::operator=(ModuleNetwork) {

    return (*this);
}

void ModuleNetwork::retrieveInformations(void) throw(ModuleException)
{
    std::time_t t = std::time(NULL);
    std::ifstream net;

    net.open("/proc/net/dev");


    _prevTime = t;
}
