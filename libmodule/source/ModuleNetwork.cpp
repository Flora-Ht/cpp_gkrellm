//
// ModuleNetwork.cpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/source/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sun Jan 22 05:03:20 2017 Benjamin Grange
// Last update Sun Jan 22 08:29:09 2017 Benjamin Grange
//

#include <sys/time.h>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <iostream>
#include "ModuleNetwork.hpp"
#include "Parsotron9000.hpp"

ModuleNetwork::ModuleNetwork()
: _first(true)
, _prevTime(0)
, _interfaces()
, _oldInterfaces()
{}

ModuleNetwork::~ModuleNetwork() {}

ModuleNetwork::ModuleNetwork(ModuleNetwork const &ref)
: _first(ref._first)
, _prevTime(ref._prevTime)
, _interfaces(ref._interfaces)
, _oldInterfaces(ref._oldInterfaces)
{}

ModuleNetwork &ModuleNetwork::operator=(ModuleNetwork ref) {
    std::swap(_first, ref._first);
    std::swap(_prevTime, ref._prevTime);
    std::swap(_interfaces, ref._interfaces);
    std::swap(_oldInterfaces, ref._oldInterfaces);
    return (*this);
}

void ModuleNetwork::retrieveInformations(void) throw(ModuleException)
{
    clock_t t = std::clock();
    std::ifstream net;

    _interfaces.clear();
    net.open("/proc/net/dev");
    if (net.is_open() == false) {
        throw ModuleException("Can't open /proc/net/dev");
    }
    std::string line;
    if (getline(net, line) && getline(net, line)) {
        while (getline(net, line)) {
            std::vector<int> tokens;
            std::string name = parsotron::fromString<std::string>(line.substr(0, line.find(':')));
            parsotron::split_all(tokens, line, ' ');
            _interfaces.push_back(NetworkInterface());
            _interfaces.back()._name = name;
            _interfaces.back()._oldRecvPacket = tokens[1];
            _interfaces.back()._oldSendPacket = tokens[9];
        }
    }
    net.close();
    if (!_first && _interfaces.size() == _oldInterfaces.size()) {
        size_t i = 0;
        while (i < _interfaces.size()) {
            _interfaces[i]._recvPacked = _interfaces[i]._oldRecvPacket - _oldInterfaces[i]._oldRecvPacket;
            _interfaces[i]._sendPacked = _interfaces[i]._oldSendPacket - _oldInterfaces[i]._oldSendPacket;
            ++i;
        }
    }
    _first = false;
    _timed = t - _prevTime;
    _prevTime = t;
    _oldInterfaces = _interfaces;
}

static double humanize_size(double bytes, std::string &label)
{
    std::string units[] = {"B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"};
    int unit_size = sizeof(units) / sizeof(units[0]);
    int index;

    index = 0;
    while (index < unit_size - 1)
    {
        if (bytes <= 2048) {
            break;
        }
        bytes /= 1024.0;
        index++;
    }
    label = units[index];
    return (bytes);
}

std::string ModuleNetwork::getDownloadSpeed(NetworkInterface const &ni) const {
    std::stringstream stream("");
    std::string label;

    double speed = 0.0;
    if (_timed > 0) {
        speed = (double)(ni._recvPacked) / (double)(_timed / 1000.0);
    }
    speed = humanize_size(speed, label);
    stream << std::fixed << std::setprecision(2) << speed << label << "/s";
    return (stream.str());
}

std::string ModuleNetwork::getUploadSpeed(NetworkInterface const &ni) const {
    std::stringstream stream("");
    std::string label;

    double speed = 0.0;
    if (_timed > 0) {
        speed = 1000.0 * (double)(ni._sendPacked) / (_timed);
    }
    speed = humanize_size(speed, label);
    stream << std::fixed << std::setprecision(2) << speed << label << "/s";
    return (stream.str());
}

std::vector<NetworkInterface> const &ModuleNetwork::getNetworkInterfaces(void) const {
    return _interfaces;
}

/******************************************************************************/

NetworkInterface::NetworkInterface()
: _name()
, _oldRecvPacket(0)
, _recvPacked(0)
, _oldSendPacket(0)
, _sendPacked(0)
{}

NetworkInterface::NetworkInterface(NetworkInterface const &ref)
: _name(ref._name)
, _oldRecvPacket(ref._oldRecvPacket)
, _recvPacked(ref._recvPacked)
, _oldSendPacket(ref._oldSendPacket)
, _sendPacked(ref._sendPacked)
{}

NetworkInterface &NetworkInterface::operator=(NetworkInterface ref) {
    std::swap(_name, ref._name);
    std::swap(_oldRecvPacket, ref._oldRecvPacket);
    std::swap(_recvPacked, ref._recvPacked);
    std::swap(_oldSendPacket, ref._oldSendPacket);
    std::swap(_sendPacked, ref._sendPacked);
    return (*this);
}

NetworkInterface::~NetworkInterface() {}
