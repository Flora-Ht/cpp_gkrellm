//
// ModuleOS.cpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/source/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 19:33:28 2017 Benjamin Grange
// Last update Sat Jan 21 19:52:22 2017 Benjamin Grange
//

#include <algorithm>
#include <sys/utsname.h>
#include "ModuleOS.hpp"

ModuleOS::ModuleOS()
: _os()
, _version()
{}

ModuleOS::~ModuleOS() {}

ModuleOS::ModuleOS(ModuleOS const &ref)
: _os(ref._os)
, _version(ref._version)
{}

ModuleOS &ModuleOS::operator=(ModuleOS ref) {
    std::swap(_os, ref._os);
    std::swap(_version, ref._version);
    return (*this);
}

void ModuleOS::retrieveInformations(void) throw(ModuleException)
{
    struct utsname buf;

    if (uname(&buf) == -1) {
        throw ModuleException("Can't retrieve Operating System informations");
    }
    _os = buf.sysname;
    _version = buf.release;

}

std::string const &ModuleOS::getOS(void) const
{
    return (_os);
}

std::string const &ModuleOS::getVersion(void) const
{
    return (_version);
}
