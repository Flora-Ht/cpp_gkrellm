//
// Window.hpp for Rush in /home/guitta_l/worktree/Training/ncurses/
//
// Made by Louis Guittard
// Login   <guitta_l@epitech.eu>
//
// Started on  Sat Jan 21 10:36:10 2017 Louis Guittard
// Last update Sat Jan 21 22:27:38 2017 Louis Guittard
//

#ifndef WINDOW_HPP_
# define WINDOW_HPP_

# include <ncurses.h>
# include <iostream>

class				Window
{
public:
    Window(int x = 0, int y = 0, int height = 20, int width = 50);
    virtual ~Window();
    Window(Window const &ref);
    Window			*operator=(Window const &ref);

public:
    WINDOW 			*getWin() const;
    int				getHeight() const;
    int				getWidth() const;
    int				getX() const;
    int				getY() const;
    void			setWin(WINDOW *);
    void			setHeight(int);
    void			setWidth(int);
    void			setX(int);
    void			setY(int);

public:
    void			drawBorder(char = '|', char = '|', char = '-', char = '-', char = '+') const;
    virtual void	drawContent() const = 0;

protected:
    WINDOW			*_window;
    int				_height;
    int				_width;
    int				_x;
    int				_y;
    std::string		_error;
};

std::ostream		&operator<<(std::ostream &os, Window const &ref);

#endif
