
NAME		:= libmodule.a

INCDIR		:= include
SRCDIR		:= source
CXXFLAGS	:= -W -Wall -Wextra --std=c++11 -I$(INCDIR)
LDFLAGS		:= #Lib here

SRC		:= \
		ModuleException.cpp \
		ModuleHostname.cpp \
		ModuleDate.cpp \
		ModuleOS.cpp \
		ModuleCPU.cpp

SRC		:= $(addprefix $(SRCDIR)/, $(SRC))
OBJS		= $(SRC:.cpp=.o)

DEBUG_FLAG	:=

all:		$(NAME)

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
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
