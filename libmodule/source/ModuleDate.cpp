//
// ModuleDate.cpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/source/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 17:58:25 2017 Benjamin Grange
// Last update Sat Jan 21 19:25:02 2017 Benjamin Grange
//

#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <ctime>
#include "ModuleDate.hpp"

ModuleDate::ModuleDate()
{}

ModuleDate::~ModuleDate() {}

ModuleDate::ModuleDate(ModuleDate const &ref)
: _day(ref._day)
, _month(ref._month)
, _year(ref._year)
, _hour(ref._hour)
, _minute(ref._minute)
, _sec(ref._sec)
{}

ModuleDate &ModuleDate::operator=(ModuleDate ref) {
    std::swap(_day, ref._day);
    std::swap(_month, ref._month);
    std::swap(_year, ref._year);
    std::swap(_hour, ref._hour);
    std::swap(_minute, ref._minute);
    std::swap(_sec, ref._sec);
    return (*this);
}

static int getTimeInteger(std::tm const &tm, char const *str) {
    std::ostringstream oss;

    oss << std::put_time(&tm, str);
    return (std::stoi(oss.str()));
}

void ModuleDate::retrieveInformations(void) throw(ModuleException)
{
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    _day = getTimeInteger(tm, "%d");
    _month = getTimeInteger(tm, "%m");
    _year = getTimeInteger(tm, "%Y");
    _hour = getTimeInteger(tm, "%H");
    _minute = getTimeInteger(tm, "%M");
    _sec = getTimeInteger(tm, "%S");
}

int ModuleDate::getDay() const
{
    return _day;
}

int ModuleDate::getMonth() const
{
    return _month;
}

int ModuleDate::getYear() const
{
    return _year;
}

int ModuleDate::getHour() const
{
    return _hour;
}

int ModuleDate::getMinute() const
{
    return _minute;
}

int ModuleDate::getSecond() const
{
    return _sec;
}
