//
// TModuleRAM.hpp for  in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/include/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sun Jan 22 05:40:54 2017 Louis Guittard
// Last update Sun Jan 22 05:57:04 2017 Louis Guittard
//

#ifndef TMODULERAM_HPP_
# define TMODULERAM_HPP_

# include "Window.hpp"
# include "ModuleRAM.hpp"

class				TModuleRAM:		public Window, public ModuleRAM
{
public:
    TModuleRAM(int x = 0, int y = 0, int height = 16, int width = 80);
    ~TModuleRAM();
    TModuleRAM(TModuleRAM const &ref);
    TModuleRAM		&operator=(TModuleRAM const &ref);

private:
    virtual void	drawContent() const;
    void			update();
};

#endif /* !TMODULERAM_HPP_ */
