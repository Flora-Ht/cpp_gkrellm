//
// TModuleOS.hpp for  in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/include/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sun Jan 22 00:13:35 2017 Louis Guittard
// Last update Sun Jan 22 00:25:02 2017 Louis Guittard
//

#ifndef TMODULEOS_HPP_
# define TMODULEOS_HPP_

# include "Window.hpp"
# include "ModuleOS.hpp"

class				TModuleOS:		public Window, public ModuleOS
{
public:
    TModuleOS(int x = 0, int y = 0, int height = 15, int width = 40);
    ~TModuleOS();
    TModuleOS(TModuleOS const &ref);
    TModuleOS		&operator=(TModuleOS const &ref);

private:
    virtual void	drawContent() const;
};

#endif /* !TMODULEOS_HPP_ */
