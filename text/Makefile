##
## Makefile for  in /home/grange_c/rendu/cpp_gkrellm/graphic/
##
## Made by Benjamin Grange
## Login   <grange_c@epitech.eu>
##
## Started on  Sat Jan 21 11:49:15 2017 Benjamin Grange
## Last update Sat Jan 21 15:01:29 2017 Benjamin Grange
##

NAME		:= my_gkrellm

INCDIR		:= include
SRCDIR		:= source
CXXFLAGS	:= -W -Wall -Wextra --std=c++11
LDFLAGS		:= -L.. -lmodule -lncurses

SRC		:= \
		main.cpp

SRC		:= $(addprefix $(SRCDIR)/, $(SRC))
OBJS		= $(SRC:.cpp=.o)

DEBUG_FLAG	:=

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)
		cp $(NAME) ../$(NAME)

clean:
		echo "Cleaning .o files..."
		rm -rf $(OBJS)

fclean: 	clean
		echo "Cleaning executable..."
		rm -rf $(NAME)
		rm -rf ../$(NAME)

re:		fclean all

run:		$(NAME)
		./$(NAME)

apply_debug:
		$(eval DEBUG_FLAG := -D_DEBUG)

debug:		apply_debug $(NAME)

%.o:		%.cpp
		echo "=>" $<
		$(CXX) -c $< -o $@ $(CXXFLAGS) $(DEBUG_FLAG)

.PHONY: all clean fclean re run debug

.SILENT: all $(NAME) clean fclean re run debug $(OBJS)
