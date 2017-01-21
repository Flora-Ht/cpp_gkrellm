//
// TModuleDate.hpp for  in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/include/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sat Jan 21 22:50:37 2017 Louis Guittard
// Last update Sun Jan 22 00:09:46 2017 Louis Guittard
//

#ifndef TMODULEDATE_HPP_
# define TMODULEDATE_HPP_

# include "Window.hpp"
# include "ModuleDate.hpp"

class				TModuleDate:		public Window, public ModuleDate
{
public:
    TModuleDate(int x = 0, int y = 0, int height = 15, int width = 40);
    ~TModuleDate();
    TModuleDate(TModuleDate const &ref);
    TModuleDate		&operator=(TModuleDate const &ref);

private:
    virtual void	drawContent() const;
    void			update();
};

#endif /* !TMODULEDATE_HPP_ */
