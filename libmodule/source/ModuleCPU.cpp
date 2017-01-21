//
// ModuleCPU.cpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/source/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 21:24:58 2017 Benjamin Grange
// Last update Sat Jan 21 23:33:23 2017 Benjamin Grange
//

#include <algorithm>
#include <sstream>
#include <fstream>
#include "ModuleCPU.hpp"

ModuleCPU::ModuleCPU()
: _cpu()
{}

ModuleCPU::~ModuleCPU() {}

#include <iostream> //FIXME TODO

template<typename T>
static void parseCpuLine(std::string const &line, char const *prefix, T &val) {
    std::string left = line.substr(0, line.find(':'));
    std::string right = line.substr(line.find(':') + 1, line.npos);
    if (left == prefix) {
        std::stringstream stream(right);
        stream >> val;
    }
}

void ModuleCPU::retrieveInformations(void) throw(ModuleException)
{
    std::ifstream stat;

    _cpu.clear();
    stat.open("/proc/cpuinfo");
    if (stat.is_open() == false) {
        throw ModuleException("Can't open file /etc/passwd");
    }
    std::string line;
    while (getline(stat, line)) {
        if (line.compare(0, 9, "processor") == 0) {
            _cpu.push_back(CPU());
        }
        if (_cpu.size() > 0 && line.size() > line.find(':') + 2) {
            parseCpuLine<std::string>(line, "vendor_id\t", _cpu.back()._vendor);
            parseCpuLine<std::string>(line, "model name\t", _cpu.back()._name);
            parseCpuLine<double>(line, "cpu MHz\t\t", _cpu.back()._mhz);
        }
    }
    stat.close();
}

std::vector<CPU> const &ModuleCPU::getCPUs() const {
    return _cpu;
}

/******************************************************************************/

CPU::CPU()
: _vendor("Unknown")
, _name("Unknown")
, _mhz(0.0)
{}

CPU::~CPU() {}
