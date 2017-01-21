//
// ModuleException.cpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/source/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 15:53:16 2017 Benjamin Grange
// Last update Sat Jan 21 16:04:34 2017 Benjamin Grange
//

#include <algorithm>
#include "ModuleException.hpp"

ModuleException::ModuleException()
: _error("Unknown error")
{}

ModuleException::ModuleException(char const *str)
: _error(str)
{}

ModuleException::~ModuleException() {}

ModuleException::ModuleException(ModuleException const &ref)
: _error(ref._error)
{}

ModuleException &ModuleException::operator=(ModuleException ref) {
    std::swap(this->_error, ref._error);
    return (*this);
}

const char *ModuleException::what(void) const throw() {
    return (_error.c_str());
}
