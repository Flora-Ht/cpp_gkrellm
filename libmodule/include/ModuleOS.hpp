//
// ModuleOS.hpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/include/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 19:33:25 2017 Benjamin Grange
// Last update Sat Jan 21 19:45:54 2017 Benjamin Grange
//

#ifndef MODULEOS_HPP
# define MODULEOS_HPP

# include <string>
# include "IMonitorModule.hpp"

class ModuleOS : public IMonitorModule
{
public:
    ModuleOS();
    ModuleOS(ModuleOS const &);
    ModuleOS &operator=(ModuleOS);
    ~ModuleOS();

    virtual void retrieveInformations(void) throw(ModuleException) override;

    std::string const &getOS(void) const;
    std::string const &getVersion(void) const;

private:
    std::string _os;
    std::string _version;
};


#endif /* !MODULEOS_HPP */
