//
// TModuleNetwork.hpp for  in /home/guitta_l/worktree/Piscine/cpp_gkrellm/text/include/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sun Jan 22 06:53:15 2017 Louis Guittard
// Last update Sun Jan 22 06:54:26 2017 Louis Guittard
//

#ifndef TMODULENETWORK_HPP_
# define TMODULENETWORK_HPP_

# include "Window.hpp"
# include "ModuleNetwork.hpp"

class				TModuleNetwork:		public Window, public ModuleNetwork
{
public:
    TModuleNetwork(int x = 0, int y = 0, int height = 16, int width = 80);
    ~TModuleNetwork();
    TModuleNetwork(TModuleNetwork const &ref);
    TModuleNetwork		&operator=(TModuleNetwork const &ref);

private:
    virtual void	drawContent() const;
    void			update();
};

#endif /* !TMODULENETWORK_HPP_ */
