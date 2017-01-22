//
// ModuleRAM.cpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/source/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sun Jan 22 04:05:12 2017 Benjamin Grange
// Last update Sun Jan 22 05:28:07 2017 Benjamin Grange
//

#include <algorithm>
#include <sys/sysinfo.h>
#include "ModuleRAM.hpp"

ModuleRAM::ModuleRAM()
: _totalRam(0)
, _freeRam(0)
, _totalSwap(0)
, _freeSwap(0)
, _bufferRam(0)
{}

ModuleRAM::~ModuleRAM() {}

ModuleRAM::ModuleRAM(ModuleRAM const &ref)
: _totalRam(ref._totalRam)
, _freeRam(ref._freeRam)
, _totalSwap(ref._totalSwap)
, _freeSwap(ref._freeSwap)
, _bufferRam(ref._bufferRam)
{}

ModuleRAM &ModuleRAM::operator=(ModuleRAM ref) {
    std::swap(_totalRam, ref._totalRam);
    std::swap(_freeRam, ref._freeRam);
    std::swap(_totalSwap, ref._totalSwap);
    std::swap(_freeSwap, ref._freeSwap);
    std::swap(_bufferRam, ref._bufferRam);
    return (*this);
}

void ModuleRAM::retrieveInformations(void) throw(ModuleException) {
    struct sysinfo info;
    if (sysinfo(&info) == -1) {
        throw ModuleException("Can't find RAM informations");
    }
    _totalRam = info.totalram;
    _freeRam = info.freeram;
    _totalSwap = info.totalswap;
    _freeSwap = info.freeswap;
    _bufferRam = info.bufferram;
}

double ModuleRAM::toGigabyte(unsigned long const &byte) const {
    return (byte / (1024.0 * 1024.0 * 1024.0));
}

unsigned long const &ModuleRAM::getTotalRam() const
{
    return (_totalRam);
}

unsigned long const &ModuleRAM::getFreeRam() const
{
    return (_freeRam);
}

unsigned long const &ModuleRAM::getTotalSwap() const
{
    return (_totalSwap);
}

unsigned long const &ModuleRAM::getFreeSwap() const
{
    return (_freeSwap);
}

unsigned long const &ModuleRAM::getBufferRam() const
{
    return (_bufferRam);
}
