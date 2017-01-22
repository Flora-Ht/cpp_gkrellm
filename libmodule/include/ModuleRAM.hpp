//
// ModuleRAM.hpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/include/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sun Jan 22 04:05:43 2017 Benjamin Grange
// Last update Sun Jan 22 04:31:03 2017 Benjamin Grange
//

#ifndef MODULERAM_HPP
# define MODULERAM_HPP

# include "IMonitorModule.hpp"

class ModuleRAM : public IMonitorModule
{
public:
    ModuleRAM();
    ModuleRAM(ModuleRAM const &);
    ModuleRAM &operator=(ModuleRAM);
    ~ModuleRAM();

    virtual void retrieveInformations(void) throw(ModuleException) override;

    unsigned long const &totalRam(void) const;
    unsigned long const &freeRam(void) const;
    unsigned long const &totalSwap(void) const;
    unsigned long const &freeSwap(void) const;

    double toGigabyte(unsigned long const &) const;

private:
    unsigned long _totalRam;
    unsigned long _freeRam;
    unsigned long _totalSwap;
    unsigned long _freeSwap;
};


#endif /* !MODULERAM_HPP */
