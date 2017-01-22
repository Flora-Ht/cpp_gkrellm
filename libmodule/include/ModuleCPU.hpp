//
// ModuleCPU.hpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/include/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 21:47:44 2017 Benjamin Grange
// Last update Sun Jan 22 03:08:22 2017 Benjamin Grange
//

#ifndef MODULECPU_HPP
# define MODULECPU_HPP

# include <vector>
# include "IMonitorModule.hpp"

struct CPU
{
    CPU();
    CPU(CPU const & ref);
    CPU &operator=(CPU);
    ~CPU();

    std::string _vendor;
    std::string _name;
    double _mhz;
    double _percent;
    std::vector<int> _stats; // Do not print that.
};

class ModuleCPU : public IMonitorModule
{
public:
    ModuleCPU();
    ModuleCPU(ModuleCPU const &);
    ModuleCPU &operator=(ModuleCPU);
    ~ModuleCPU();

    virtual void retrieveInformations(void) throw(ModuleException) override;

    std::vector<CPU> const &getCPUs() const;

private:
    std::vector<CPU> _cpu;
    std::vector<CPU> _oldCpu;
    bool _first;
};


#endif /* !MODULECPU_HPP */
