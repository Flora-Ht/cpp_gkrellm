//
// ModuleCPU.cpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/source/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 21:24:58 2017 Benjamin Grange
// Last update Sun Jan 22 03:55:21 2017 Benjamin Grange
//

#include <algorithm>
#include <sstream>
#include <fstream>
#include "ModuleCPU.hpp"
#include "parsotron9000.hpp"

ModuleCPU::ModuleCPU()
: _cpu()
, _oldCpu()
, _first(true)
{}

ModuleCPU::~ModuleCPU() {}

template<typename T>
static void parseCpuLine(std::string const &line, char const *prefix, T &val) {
    std::string left = line.substr(0, line.find(':'));
    std::string right = line.substr(line.find(':') + 1, line.npos);
    if (left == prefix) {
        std::stringstream stream(right);
        stream >> val;
    }
}

#include <iostream>

void ModuleCPU::retrieveInformations(void) throw(ModuleException)
{
    std::ifstream stat;

    _cpu.clear();
    stat.open("/proc/cpuinfo");
    if (stat.is_open() == false) {
        throw ModuleException("Can't open file /proc/cpuinfo");
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

    stat.open("/proc/stat");
    if (stat.is_open() == false) {
        throw ModuleException("Can't open file /proc/stat");
    }
    getline(stat, line); // Skip general proc use.
    size_t i = 0;
    while (i < _cpu.size()) {
        std::vector<int> tokens;
        getline(stat, line);
        parsotron::split(tokens, line, ' ');

        _cpu[i]._stats = tokens;
        //			     user    nice   system  idle      iowait irq   softirq  steal  guest  guest_nice
        //			cpu  74608   2520   24433   1117073   6176   4054  0        0      0      0
        // index	0     1       2      3       4        5      6     7       8       9     10
        if (!_first && _cpu.size() == _oldCpu.size())
        {
            long prevIdle = _oldCpu[i]._stats[4] + _oldCpu[i]._stats[5];
            long idle = _cpu[i]._stats[4] + _cpu[i]._stats[5];

            long prevNonIdle = _oldCpu[i]._stats[1] + _oldCpu[i]._stats[2] + _oldCpu[i]._stats[3] + _oldCpu[i]._stats[6] + _oldCpu[i]._stats[7] + _oldCpu[i]._stats[8];
            long nonIdle = _cpu[i]._stats[1] + _cpu[i]._stats[2] + _cpu[i]._stats[3] + _cpu[i]._stats[6] + _cpu[i]._stats[7] + _cpu[i]._stats[8];

            long prevTotal = prevIdle + prevNonIdle;
            long total = idle + nonIdle;

            long totald = total - prevTotal;
            long idled = idle - prevIdle;
            if (totald == 0.0) {
                throw ModuleException("Error while calculating cpu percentage");
            }
            _cpu[i]._percent = ((double)(totald - idled) / (double)totald) * 100.0;
        }
        ++i;
    }
    _oldCpu = _cpu;
    _first = false;
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
, _percent()
, _stats()
{}

CPU::CPU(CPU const &ref)
: _vendor(ref._vendor)
, _name(ref._name)
, _mhz(ref._mhz)
, _percent(ref._percent)
, _stats(ref._stats)
{}

CPU &CPU::operator=(CPU ref) {
    std::swap(this->_vendor, ref._vendor);
    std::swap(this->_name, ref._name);
    std::swap(this->_mhz, ref._mhz);
    std::swap(this->_percent, ref._percent);
    std::swap(this->_stats, ref._stats);
    return (*this);
}

CPU::~CPU() {}
