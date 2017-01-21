//
// ModuleHostUser.hpp for  in /home/guitta_l/worktree/Training/ncurses/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sat Jan 21 15:08:43 2017 Louis Guittard
// Last update Sat Jan 21 22:28:36 2017 Louis Guittard
//

#ifndef MODULEHOSTUSER_HPP_
# define MODULEHOSTUSER_HPP_

# include "Window.hpp"
# include "ModuleHostname.hpp"

class				ModuleHostUser:		public Window, public ModuleHostname
{
public:
    ModuleHostUser(int x = 0, int y = 0, int height = 15, int width = 40);
    ~ModuleHostUser();
    ModuleHostUser(ModuleHostUser const &ref);
    ModuleHostUser	&operator=(ModuleHostUser const &ref);

private:
    void			drawContent() const;
};

#endif /* !MODULEHOSTUSER_HPP_ */
