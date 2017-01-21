//
// ModuleCPU.hpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/include/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 21:47:44 2017 Benjamin Grange
// Last update Sat Jan 21 23:39:25 2017 Benjamin Grange
//

#ifndef MODULECPU_HPP
# define MODULECPU_HPP

# include <vector>
# include "IMonitorModule.hpp"

struct CPU
{
    CPU();
    ~CPU();

    std::string _vendor;
    std::string _name;
    double _mhz;
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
};


#endif /* !MODULECPU_HPP */
