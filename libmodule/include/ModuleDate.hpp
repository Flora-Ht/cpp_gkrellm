//
// ModuleDate.hpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/include/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 17:58:37 2017 Benjamin Grange
// Last update Sat Jan 21 19:17:08 2017 Benjamin Grange
//

#ifndef MODULEDATE_HPP
# define MODULEDATE_HPP

# include "IMonitorModule.hpp"
# include "ModuleException.hpp"

class ModuleDate : public IMonitorModule
{
public:
    ModuleDate();
    ModuleDate(ModuleDate const &);
    ModuleDate &operator=(ModuleDate);
    ~ModuleDate();

    virtual void retrieveInformations(void) throw(ModuleException) override;

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

private:
    int _day;
    int _month;
    int _year;
    int _hour;
    int _minute;
    int _sec;
};


#endif /* !MODULEDATE_HPP */
