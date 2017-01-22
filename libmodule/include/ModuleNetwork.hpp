//
// ModuleNetwork.hpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/include/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sun Jan 22 05:03:22 2017 Benjamin Grange
// Last update Sun Jan 22 08:22:40 2017 Benjamin Grange
//

#ifndef MODULENETWORK_HPP
# define MODULENETWORK_HPP

# include <string>
# include <ctime>
# include <vector>
# include "IMonitorModule.hpp"

struct NetworkInterface
{
    NetworkInterface();
    ~NetworkInterface();
    NetworkInterface(NetworkInterface const &);
    NetworkInterface &operator=(NetworkInterface);
    std::string _name;
    unsigned long _oldRecvPacket;
    unsigned long _recvPacked;
    unsigned long _oldSendPacket;
    unsigned long _sendPacked;
};

class ModuleNetwork : public IMonitorModule
{
public:
    ModuleNetwork();
    ModuleNetwork(ModuleNetwork const &);
    ModuleNetwork &operator=(ModuleNetwork);
    ~ModuleNetwork();

    virtual void retrieveInformations(void) throw(ModuleException) override;

    std::string getDownloadSpeed(NetworkInterface const &ni) const;
    std::string getUploadSpeed(NetworkInterface const &ni) const;
    std::vector<NetworkInterface> const &getNetworkInterfaces(void) const;
private:
    bool _first;
    std::clock_t _timed;
    std::clock_t _prevTime;
    std::vector<NetworkInterface> _interfaces;
    std::vector<NetworkInterface> _oldInterfaces;
};



#endif /* !MODULENETWORK_HPP */
