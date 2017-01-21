//
// kek.cpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/source/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 15:33:47 2017 Benjamin Grange
// Last update Sat Jan 21 17:31:22 2017 Benjamin Grange
//

#define _DEFAULT_SOURCE
#include <sys/param.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream> //TODO FIXME

#include "ModuleHostname.hpp"

ModuleHostname::ModuleHostname()
: _host("Unknown Host")
, _user("Unknown User")
{}

ModuleHostname::~ModuleHostname() {}

ModuleHostname::ModuleHostname(ModuleHostname const &ref)
: _host(ref._host)
, _user(ref._user)
{}

ModuleHostname &ModuleHostname::operator=(ModuleHostname ref) {
    std::swap(this->_host, ref._host);
    std::swap(this->_user, ref._user);
    return (*this);
}

void ModuleHostname::lookForUsername(int i) {
    std::ifstream passwd;

    passwd.open("/etc/passwd");
    if (passwd.is_open() == false) {
        throw ModuleException("Can't open file /etc/passwd");
    }
    std::string line;
    while (std::getline(passwd, line)) {
        std::vector<std::string> tokens;
        std::istringstream iss(line);
        std::string tmp;
        while (std::getline(iss, tmp, ':')) {
            tokens.push_back(tmp);
        }
        if (tokens.size() >= 3 && std::stoi(tokens[2]) == i) {
            _user = tokens[0];
            return ;
        }
    }
    // On error
    throw ModuleException("Can't find a username matching user id in /etc/passwd");
}

void ModuleHostname::retrieveInformations(void) throw(ModuleException) {
    char buffer[MAXHOSTNAMELEN + 1];
    if (gethostname(buffer, MAXHOSTNAMELEN + 1) == -1) {
        throw ModuleException(std::strerror(errno));
    }
    _host = buffer;
    lookForUsername(getuid());
}

std::string const &ModuleHostname::getHost(void) const {
    return _host;
}

std::string const &ModuleHostname::getUser(void) const {
    return _user;
}
