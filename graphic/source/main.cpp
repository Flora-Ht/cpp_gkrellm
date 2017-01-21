//
// main.cpp for  in /home/grange_c/rendu/cpp_gkrellm/graphic/source/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 11:49:31 2017 Benjamin Grange
// Last update Sat Jan 21 15:13:09 2017 Benjamin Grange
//

#include <iostream>
#include "libmodule.hpp"

int main()
{
    std::cout << "Hello World (Graphic !)" << std::endl;
    libmodule_init();
    #ifdef _DEBUG
    std::cout << "Debug !" << std::endl;
    #endif
    return (0);
}
