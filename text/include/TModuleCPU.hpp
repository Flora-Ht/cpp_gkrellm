//
// TModuleCPU.hpp for Rush in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/source/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sun Jan 22 01:06:00 2017 Louis Guittard
// Last update Sun Jan 22 05:47:06 2017 Louis Guittard
//

#ifndef TMODULECPU_HPP_
# define TMODULECPU_HPP_

# include "Window.hpp"
# include "ModuleCPU.hpp"

class				TModuleCPU:		public Window, public ModuleCPU
{
public:
    TModuleCPU(int x = 0, int y = 0, int height = 16, int width = 80);
    ~TModuleCPU();
    TModuleCPU(TModuleCPU const &ref);
    TModuleCPU		&operator=(TModuleCPU const &ref);

private:
    virtual void	drawContent() const;
    void			update();
};

#endif /* !TMODULECPU_HPP_ */
