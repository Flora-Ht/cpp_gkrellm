//
// ModuleNetwork.hpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/include/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sun Jan 22 05:03:22 2017 Benjamin Grange
// Last update Sun Jan 22 05:21:21 2017 Benjamin Grange
//

#ifndef MODULENETWORK_HPP
# define MODULENETWORK_HPP

# include <string>
# include <ctime>
# include "IMonitorModule.hpp"

class ModuleNetwork : public IMonitorModule
{
public:
    ModuleNetwork();
    ModuleNetwork(ModuleNetwork const &);
    ModuleNetwork &operator=(ModuleNetwork);
    ~ModuleNetwork();

    virtual void retrieveInformations(void) throw(ModuleException) override;

private:
    std::time_t		_prevTime;
    unsigned long	_oldRecvPacket;
    unsigned long	_recvPacketd;
};



#endif /* !MODULENETWORK_HPP */
