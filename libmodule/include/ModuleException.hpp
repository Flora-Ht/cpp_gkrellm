//
// ModuleException.hpp for  in /home/grange_c/rendu/cpp_gkrellm/libmodule/include/
//
// Made by Benjamin Grange
// Login   <grange_c@epitech.eu>
//
// Started on  Sat Jan 21 15:52:23 2017 Benjamin Grange
// Last update Sat Jan 21 16:04:42 2017 Benjamin Grange
//

#ifndef MODULEEXCEPTION_HPP
# define MODULEEXCEPTION_HPP

# include <exception>
# include <string>

class ModuleException : public std::exception
{
public:
    ModuleException();
    ModuleException(char const *);
    ModuleException(ModuleException const &);
    ModuleException &operator=(ModuleException);
    ~ModuleException();

    virtual const char* what(void) const throw() override;

private:
    std::string _error;
};


#endif /* !MODULEEXCEPTION_HPP */
