//
// TModuleHostUser.hpp for  in /home/guitta_l/worktree/Training/ncurses/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sat Jan 21 15:08:43 2017 Louis Guittard
// Last update Sat Jan 21 22:45:41 2017 Louis Guittard
//

#ifndef TMODULEHOSTUSER_HPP_
# define TMODULEHOSTUSER_HPP_

# include "Window.hpp"
# include "ModuleHostname.hpp"

class				TModuleHostUser:		public Window, public ModuleHostname
{
public:
    TModuleHostUser(int x = 0, int y = 0, int height = 15, int width = 40);
    ~TModuleHostUser();
    TModuleHostUser(TModuleHostUser const &ref);
    TModuleHostUser	&operator=(TModuleHostUser const &ref);

private:
    void			drawContent() const;
};

#endif /* !MODULEHOSTUSER_HPP_ */
