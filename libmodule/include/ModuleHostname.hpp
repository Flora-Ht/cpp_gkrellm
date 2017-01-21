//
// ModuleHostname.hpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/include/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 15:29:36 2017 Benjamin Grange
// Last update Sat Jan 21 17:59:09 2017 Benjamin Grange

#ifndef MODULEHOSTNAME_HPP
# define MODULEHOSTNAME_HPP

# include <string>
# include "IMonitorModule.hpp"

class ModuleHostname : public IMonitorModule
{
    void lookForUsername(int i);

public:
    ModuleHostname();
    ModuleHostname(ModuleHostname const &);
    ModuleHostname &operator=(ModuleHostname);
    ~ModuleHostname();

    virtual void retrieveInformations(void) throw(ModuleException) override;

    std::string const &getHost(void) const;
    std::string const &getUser(void) const;

private:
    std::string _host;
    std::string _user;
};

#endif /* !MODULEHOSTNAME_HPP */
